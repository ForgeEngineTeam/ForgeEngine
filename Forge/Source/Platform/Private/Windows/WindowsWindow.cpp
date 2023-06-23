#include "Platform/Public/Platform.h"
#include "Platform/Public/Windows/WindowsWindow.h"

#if defined(FORGE_PLATFORM_WINDOWS)
	
#if defined(FORGE_RENDER_API_OPENGL)
	#include "GraphicsDevice/Public/OpenGL/GLGraphicsContext.h"
#endif

namespace Forge {
	namespace Platform
	{
		WindowsWindow::WindowsWindow(const WindowDesc& description)
			: AbstractWindow(description)
		{
			U32 window_style = 0, ex_window_style = 0;

			if (m_window_description.m_is_visable)
				window_style |= WS_VISIBLE;

			if (m_window_description.m_is_resizable &&
				!m_window_description.m_is_fullscreen)
				window_style |= WS_MAXIMIZEBOX | WS_THICKFRAME;

			if (m_window_description.m_is_decorated &&
				!m_window_description.m_is_fullscreen)
			{
				window_style |= WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER;

				RECT windows_rect = { 0, 0, 
					m_window_description.m_client_size.x, 
					m_window_description.m_client_size.y 
				};

				AdjustWindowRectEx(&windows_rect, window_style, false, ex_window_style);

				m_window_description.m_client_position.x += windows_rect.left;
				m_window_description.m_client_position.y += windows_rect.top;

				m_window_description.m_client_size.x = windows_rect.right - windows_rect.left;
				m_window_description.m_client_size.y = windows_rect.bottom - windows_rect.top;
			}

			if (m_window_description.m_is_minimized &&
				!m_window_description.m_is_maximized &&
				!m_window_description.m_is_fullscreen)
				window_style |= WS_MINIMIZE;
			
			if (m_window_description.m_is_maximized &&
				!m_window_description.m_is_minimized &&
				!m_window_description.m_is_fullscreen)
				window_style |= WS_MAXIMIZE;

			if (m_window_description.m_is_fullscreen)
			{
				MONITORINFO monitor_info = { sizeof(monitor_info) };
				GetMonitorInfoW(MonitorFromWindow((HWND)m_window_handle, MONITOR_DEFAULTTONEAREST), &monitor_info);

				m_window_description.m_client_position.x = monitor_info.rcMonitor.left;
				m_window_description.m_client_position.y = monitor_info.rcMonitor.top;

				m_window_description.m_client_size.x = monitor_info.rcMonitor.right - monitor_info.rcMonitor.left;
				m_window_description.m_client_size.y = monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top;
			}

			if (!m_window_description.m_allow_minimize &&
				!m_window_description.m_is_fullscreen)
				window_style ^= WS_MINIMIZEBOX;

			if (!m_window_description.m_allow_maximize &&
				!m_window_description.m_is_fullscreen)
				window_style ^= WS_MAXIMIZEBOX;

			m_window_handle = CreateWindowExA(
				ex_window_style,
				Platform::GetInstance().m_application_window_class,
				m_window_description.m_window_title,
				window_style,
				m_window_description.m_client_position.x, m_window_description.m_client_position.y,
				m_window_description.m_client_size.x, m_window_description.m_client_size.y,
				m_window_description.m_window_parent ? (HWND)(m_window_description.m_window_parent->GetNativeHandle()) : nullptr,
				nullptr,
				(HINSTANCE)Platform::GetInstance().GetPlatformHandle(),
				nullptr
			);

			if (m_window_description.m_is_transparent &&
				!m_window_description.m_is_fullscreen)
			{
				LONG window_style = (GetWindowLong((HWND)m_window_handle, GWL_EXSTYLE) | WS_EX_LAYERED);

				SetWindowLongPtr((HWND)m_window_handle, GWL_EXSTYLE, window_style);
				
				SetLayeredWindowAttributes((HWND)m_window_handle, 0, static_cast<BYTE>(m_window_description.m_window_opacity * 255.0f), LWA_ALPHA);
			}

			if (!m_window_description.m_allow_input)
				EnableWindow((HWND)m_window_handle, false);
		}

		Vector2 WindowsWindow::GetWindowSize(Void) const
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			RECT windows_rect;

			GetWindowRect((HWND)m_window_handle, &windows_rect);

			return Vector2(static_cast<F32>(windows_rect.right - windows_rect.left), static_cast<F32>(windows_rect.bottom - windows_rect.top));
		}
		Vector2 WindowsWindow::GetWindowPosition(Void) const
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			RECT windows_rect;

			GetWindowRect((HWND)m_window_handle, &windows_rect);

			return Vector2(static_cast<F32>(windows_rect.left), static_cast<F32>(windows_rect.top));
		}
	
		Vector2 WindowsWindow::GetClientToScreen(Vector2 client_position) const
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			POINT windows_point;
			windows_point.x = static_cast<LONG>(client_position.x);
			windows_point.y = static_cast<LONG>(client_position.y);

			ClientToScreen((HWND)m_window_handle, &windows_point);

			return Vector2(static_cast<F32>(windows_point.x), static_cast<F32>(windows_point.y));
		}
		Vector2 WindowsWindow::GetScreenToClient(Vector2 screen_position) const
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			POINT windows_point;
			windows_point.x = static_cast<LONG>(screen_position.x);
			windows_point.y = static_cast<LONG>(screen_position.y);

			ScreenToClient((HWND)m_window_handle, &windows_point);

			return Vector2(static_cast<F32>(windows_point.x), static_cast<F32>(windows_point.y));
		}

		Void WindowsWindow::SetTitle(ConstCharPtr title)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_window_description.m_is_decorated)
				return;

			m_window_description.m_window_title = title;

			SetWindowText((HWND)m_window_handle, static_cast<LPCSTR>(m_window_description.m_window_title));
		}

		Void WindowsWindow::SetOpacity(F32 opacity)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_window_description.m_is_transparent)
				return;

			m_window_description.m_window_opacity = opacity;

			SetLayeredWindowAttributes((HWND)m_window_handle, 0, static_cast<BYTE>(m_window_description.m_window_opacity), LWA_ALPHA);
		}

		Void WindowsWindow::SetClientSize(const Vector2 size)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			//TODO: Check if new size is near equal to current size.

			m_window_description.m_client_size.x = size.x;
			m_window_description.m_client_size.y = size.y;

			if (m_window_description.m_is_decorated)
			{
				WINDOWINFO winInfo;
				MemorySet(&winInfo, 0, sizeof(WINDOWINFO));

				winInfo.cbSize = sizeof(winInfo);
				GetWindowInfo((HWND)m_window_handle, &winInfo);

				RECT windows_rect = {
					0,
					0,
					m_window_description.m_client_size.x,
					m_window_description.m_client_size.y
				};

				AdjustWindowRectEx(&windows_rect, winInfo.dwStyle, FALSE, winInfo.dwExStyle);

				m_window_description.m_client_size.x =  windows_rect.right - windows_rect.left;
				m_window_description.m_client_size.y =  windows_rect.bottom - windows_rect.top;
			}

			SetWindowPos(
				(HWND)m_window_handle,
				nullptr,
				0,
				0,
				m_window_description.m_client_size.x,
				m_window_description.m_client_size.y,
				SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOOWNERZORDER
			);
		}
		Void WindowsWindow::SetClientPosition(const Vector2 position)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			//TODO: Check if new position is near equal to current position.

			m_window_description.m_client_position.x = position.x;
			m_window_description.m_client_position.y = position.y;

			if (m_window_description.m_is_decorated)
			{
				WINDOWINFO winInfo;
				MemorySet(&winInfo, 0, sizeof(WINDOWINFO));

				winInfo.cbSize = sizeof(winInfo);
				GetWindowInfo((HWND)m_window_handle, &winInfo);

				RECT windows_rect = { 
					m_window_description.m_client_position.x, 
					m_window_description.m_client_position.y, 
					m_window_description.m_client_size.x,
					m_window_description.m_client_size.y
				};

				AdjustWindowRectEx(&windows_rect, winInfo.dwStyle, FALSE, winInfo.dwExStyle);

				m_window_description.m_client_position.x = windows_rect.left;
				m_window_description.m_client_position.y = windows_rect.top;
			}

			SetWindowPos(
				(HWND)m_window_handle,
				nullptr,
				m_window_description.m_client_position.x,
				m_window_description.m_client_position.y,
				0,
				0,
				SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOOWNERZORDER
			);
		}
		Void WindowsWindow::SetClientBounds(const RectangleF32 bounds)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			//TODO: Check if new bounds is near equal to current bounds.

			m_window_description.m_client_position.x = bounds.GetX();
			m_window_description.m_client_position.y = bounds.GetY();

			m_window_description.m_client_size.x = bounds.GetWidth();
			m_window_description.m_client_size.y = bounds.GetHeight();

			if (m_window_description.m_is_decorated)
			{
				WINDOWINFO winInfo;
				MemorySet(&winInfo, 0, sizeof(WINDOWINFO));

				winInfo.cbSize = sizeof(winInfo);
				GetWindowInfo((HWND)m_window_handle, &winInfo);

				RECT windows_rect = { 
					0, 
					0, 
					m_window_description.m_client_size.x, 
					m_window_description.m_client_size.y 
				};

				AdjustWindowRectEx(&windows_rect, winInfo.dwStyle, FALSE, winInfo.dwExStyle);
				
				m_window_description.m_client_position.x += windows_rect.left;
				m_window_description.m_client_position.y += windows_rect.top;

				m_window_description.m_client_size.x = windows_rect.right - windows_rect.left;
				m_window_description.m_client_size.y = windows_rect.bottom - windows_rect.top;
			}

			SetWindowPos(
				(HWND)m_window_handle, 
				nullptr, 
				m_window_description.m_client_position.x, 
				m_window_description.m_client_position.y, 
				m_window_description.m_client_size.x, 
				m_window_description.m_client_size.y, 
				SWP_NOZORDER | SWP_NOACTIVATE
			);
		}

		Void WindowsWindow::SetWindowSize(const Vector2 size)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			SetWindowPos((HWND)m_window_handle, nullptr, 0, 0, size.x, size.y, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOOWNERZORDER);
		}
		Void WindowsWindow::SetWindowPosition(const Vector2 position)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			SetWindowPos((HWND)m_window_handle, nullptr, position.x, position.y, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOOWNERZORDER);
		}

		Void WindowsWindow::SetCursorType(WindowCursorType cursor_type)
		{
			static const LPCSTR windows_cursors[] = {
				IDC_ARROW,
				IDC_CROSS,
				IDC_HAND,
				IDC_HELP,
				IDC_IBEAM,
				IDC_NO,
				IDC_SIZEALL,
				IDC_SIZENESW,
				IDC_SIZENS,
				IDC_SIZENWSE,
				IDC_SIZEWE,
				IDC_UPARROW,
				IDC_WAIT
			};

			m_window_description.m_window_cursor_type = cursor_type;

			if (m_window_description.m_window_cursor_type == WindowCursorType::HIDDEN)
			{
				SetCursor(nullptr);
				return;
			}

			U32 index = 0;
			switch (m_window_description.m_window_cursor_type)
			{
			case WindowCursorType::ARROW:
				index = 0;
				break;
			case WindowCursorType::CROSS:
				index = 1;
				break;
			case WindowCursorType::HAND:
				index = 2;
				break;
			case WindowCursorType::HELP:
				index = 3;
				break;
			case WindowCursorType::IBEAM:
				index = 4;
				break;
			case WindowCursorType::NO:
				index = 5;
				break;
			case WindowCursorType::SIZE_ALL:
				index = 6;
				break;
			case WindowCursorType::SIZE_NESW:
				index = 7;
				break;
			case WindowCursorType::SIZE_NS:
				index = 8;
				break;
			case WindowCursorType::SIZE_NWSE:
				index = 9;
				break;
			case WindowCursorType::SIZE_WE:
				index = 10;
				break;
			case WindowCursorType::UP_ARROW:
				index = 11;
				break;
			case WindowCursorType::WAIT:
				index = 12;
				break;
			}

			const HCURSOR cursor = LoadCursor(nullptr, windows_cursors[index]);
			SetCursor(cursor);
		}

		Void WindowsWindow::SetIsResizable(Bool is_resizable)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (m_window_description.m_is_resizable && is_resizable)
				return;

			m_window_description.m_is_resizable = is_resizable;

			LONG window_style = GetWindowLong((HWND)m_window_handle, GWL_STYLE);

			if(m_window_description.m_is_resizable)
				window_style |= WS_MAXIMIZEBOX | WS_THICKFRAME;
			else
				window_style ^= WS_MAXIMIZEBOX | WS_THICKFRAME;

			SetWindowLongPtr((HWND)m_window_handle, GWL_STYLE, window_style);

		}
		Void WindowsWindow::SetIsDecorated(Bool is_decorated)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (m_window_description.m_is_decorated && is_decorated)
				return;

			m_window_description.m_is_decorated = is_decorated;

			LONG window_style = GetWindowLong((HWND)m_window_handle, GWL_STYLE);

			if (m_window_description.m_is_decorated)
				window_style |= WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER;
			else
				window_style ^= WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER;

			SetWindowLongPtr((HWND)m_window_handle, GWL_STYLE, window_style);
		}
		Void WindowsWindow::SetIsFullscreen(Bool is_fullscreen)
		{
			// TODO: Impelemt WindowsWindow::SetIsFullscreen
		}
		Void WindowsWindow::SetIsTransparent(Bool is_transparent)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (m_window_description.m_is_transparent && is_transparent)
				return;

			m_window_description.m_is_transparent = is_transparent;

			LONG window_style = GetWindowLong((HWND)m_window_handle, GWL_EXSTYLE);

			if (m_window_description.m_is_resizable)
				window_style |= WS_EX_LAYERED;
			else
				window_style ^= WS_EX_LAYERED;

			SetWindowLongPtr((HWND)m_window_handle, GWL_EXSTYLE, window_style);
		}

		Void WindowsWindow::Show(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_cache_is_visible)
			{
				m_cache_is_visible = true;

				if (m_cache_is_focused)
					ShowWindow((HWND)m_window_handle, SW_SHOW);
				else
					ShowWindow((HWND)m_window_handle, SW_SHOWNA);
			}
		}
		Void WindowsWindow::Hide(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (m_cache_is_visible)
			{
				m_cache_is_focused = false;

				m_cache_is_visible = false;

				ShowWindow((HWND)m_window_handle, SW_HIDE);
			}
		}
		Void WindowsWindow::Focus(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_cache_is_focused)
			{
				m_cache_is_focused = true;

				BringWindowToTop((HWND)m_window_handle);
				SetForegroundWindow((HWND)m_window_handle);
				SetFocus((HWND)m_window_handle);
			}
		}
		Void WindowsWindow::Flash(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (m_cache_is_focused)
				return;

			FlashWindow((HWND)m_window_handle, true);
		}
		Void WindowsWindow::Minimize(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_window_description.m_allow_minimize || 
				!m_cache_is_visible)
				return;

			m_cache_is_focused = false;

			m_cache_is_minimized = true;
			m_cache_is_maximized = false;

			ShowWindow((HWND)m_window_handle, SW_MINIMIZE);
		}
		Void WindowsWindow::Maximize(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			if (!m_window_description.m_allow_maximize ||
				!m_cache_is_visible)
				return;

			m_cache_is_focused = true;

			m_cache_is_maximized = true;
			m_cache_is_minimized = false;

			ShowWindow((HWND)m_window_handle, SW_MAXIMIZE);
		}
		Void WindowsWindow::Activate(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			m_window_description.m_allow_input = true;

			EnableWindow((HWND)m_window_handle, true);
		}
		Void WindowsWindow::Deactivate(Void)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			m_window_description.m_allow_input = false;

			EnableWindow((HWND)m_window_handle, false);
		}
		Void WindowsWindow::BringToFront(Void)
		{
			// TODO: Impelemt WindowsWindow::BringToFront
		}
		Void WindowsWindow::Close(WindowClosingReason window_closing_reason)
		{
			FORGE_ASSERT(m_window_handle, "Window handle is null")

			DestroyWindow((HWND)m_window_handle);

			m_window_handle = nullptr;

			m_is_closing = true;
		}
	}
}

#endif
