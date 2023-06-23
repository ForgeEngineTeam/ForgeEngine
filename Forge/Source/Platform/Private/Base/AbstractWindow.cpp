#include <Platform/Public/Base/AbstractWindow.h>

#include <Platform/Public/Windows/WindowsPlatform.h>

namespace Forge {
	namespace Platform
	{
		AbstractWindow::AbstractWindow(const WindowDesc& description)
			: m_window_handle(nullptr), 
			  m_is_closing(false),
			  m_cache_is_visible(false), 
			  m_cache_is_focused(false), 
			  m_cache_is_minimized(false), 
			  m_cache_is_maximized(false), 
			  m_window_description(description)
		{
			if (m_window_description.m_window_start_position == WindowStartPositionMode::CENTER_SCREEN ||
				m_window_description.m_window_start_position == WindowStartPositionMode::CENTER_PARENT)
			{
				RectangleF32 parent_bounds = RectangleF32({ 0, 0 }, Platform::GetInstance().GetPrimaryMonitorSize());

				if (m_window_description.m_window_parent != nullptr &&
					m_window_description.m_window_start_position == WindowStartPositionMode::CENTER_PARENT)
					parent_bounds = m_window_description.m_window_parent->GetClientBounds();

				m_window_description.m_client_position = parent_bounds.GetTopLeft() + (parent_bounds.GetSize() - m_window_description.m_client_size) * 0.5f;
			}
		}

		ConstVoidPtr AbstractWindow::GetNativeHandle(Void) const
		{
			FORGE_ASSERT(m_window_handle != nullptr, "Window handle is null")

			return m_window_handle;
		}
		WindowDesc AbstractWindow::GetWindowDescription(Void) const
		{
			return m_window_description;
		}

		String AbstractWindow::GetTitle(Void) const
		{
			return m_window_description.m_window_title;
		}

		F32 AbstractWindow::GetOpacity(Void) const
		{
			return m_window_description.m_window_opacity;
		}

		Vector2 AbstractWindow::GetClientSize(Void) const
		{
			return m_window_description.m_client_size;
		}
		Vector2 AbstractWindow::GetClientPosition(Void) const
		{
			return m_window_description.m_client_position;
		}
		RectangleF32 AbstractWindow::GetClientBounds(Void) const
		{
			return RectangleF32(GetClientPosition(), GetClientSize());
		}

		WindowCursorType AbstractWindow::GetCursorType(Void) const
		{
			return m_window_description.m_window_cursor_type;
		}

		Bool AbstractWindow::IsClosing(Void) const
		{
			return m_is_closing;
		}

		Bool AbstractWindow::IsVisable(Void) const
		{
			return m_window_description.m_is_visable;
		}
		Bool AbstractWindow::IsFocused(Void) const
		{
			return m_cache_is_focused;
		}
		Bool AbstractWindow::IsResizable(Void) const
		{
			return m_window_description.m_is_resizable;
		}
		Bool AbstractWindow::IsDecorated(Void) const
		{
			return m_window_description.m_is_decorated;
		}
		Bool AbstractWindow::IsMinimized(Void) const
		{
			return m_cache_is_minimized;
		}
		Bool AbstractWindow::IsMaximized(Void) const
		{
			return m_cache_is_maximized;
		}
		Bool AbstractWindow::IsFullscreen(Void) const
		{
			return m_window_description.m_is_fullscreen;
		}
		Bool AbstractWindow::IsTransparent(Void) const
		{
			return m_window_description.m_is_transparent;
		}

		Void AbstractWindow::OnClose(TDelegate<Void(Void)> callback)
		{
			m_window_close_callback = Move(callback);
		}
		Void AbstractWindow::OnFocus(Common::TDelegate<Void(Bool)> callback)
		{
			m_window_focus_callback = Move(callback);
		}
		Void AbstractWindow::OnMinimize(Common::TDelegate<Void(Bool)> callback)
		{
			m_window_minimize_callback = Move(callback);
		}
		Void AbstractWindow::OnMaximize(Common::TDelegate<Void(Bool)> callback)
		{
			m_window_maximize_callback = Move(callback);
		}
		Void AbstractWindow::OnMove(Common::TDelegate<Void(U32, U32)> callback)
		{
			m_window_move_callback = Move(callback);
		}
		Void AbstractWindow::OnResize(Common::TDelegate<Void(U32, U32)> callback)
		{
			m_window_resize_callback = Move(callback);
		}
	}
}
