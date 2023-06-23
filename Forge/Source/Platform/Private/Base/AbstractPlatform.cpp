#include "Platform/Public/Base/AbstractPlatform.h"

namespace Forge {
	namespace Platform
	{
		Void AbstractPlatform::LogSystemInfo(Void)
		{
			// TODO: Impelemt AbstractPlatform::LogSystemInfo
		}
		Void AbstractPlatform::Info(ConstCharPtr message)
		{
			ShowMessageBox(nullptr, message, "Info", MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_INFORMATION);
		}
		Void AbstractPlatform::Warn(ConstCharPtr message)
		{
			ShowMessageBox(nullptr, message, "Warning", MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_WARNING);
		}
		Void AbstractPlatform::Error(ConstCharPtr message)
		{
			ShowMessageBox(nullptr, message, "Error", MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_ERROR);
		}
		Void AbstractPlatform::Fatal(ConstCharPtr message, VoidPtr context)
		{
			Error(message);

			ExitProcess(-1);
		}

		Void AbstractPlatform::Crash(I32 line, ConstCharPtr file)
		{
			// TODO: Impelemt AbstractPlatform::Crash
		}
		Void AbstractPlatform::OutOfMemory(I32 line, ConstCharPtr file)
		{
			// TODO: Impelemt AbstractPlatform::OutOfMemory
		}
		Void AbstractPlatform::MissingCode(I32 line, ConstCharPtr file)
		{
			// TODO: Impelemt AbstractPlatform::MissingCode
		}
		Void AbstractPlatform::AssertionCheck(I32 line, ConstCharPtr file, ConstCharPtr message)
		{
			// TODO: Impelemt AbstractPlatform::Assert
		}

		VoidPtr AbstractPlatform::GetPlatformHandle(Void)
		{
			return m_instance_handle;
		}

		PlatformType AbstractPlatform::GetPlatformType(Void)
		{
#if defined(FORGE_PLATFORM_ANDROID)
			return PlatformType::FORGE_ANDROID;
#elif defined(FORGE_PLATFORM_LINUX)
			return PlatformType::FORGE_LINUX;
#elif defined(FORGE_PLATFORM_MACOS)
			return PlatformType::FORGE_MAC
#elif defined(FORGE_PLATFORM_WINDOWS)
			return PlatformType::FORGE_WINDOWS;
#endif
		}
		ArchitectureType AbstractPlatform::GetArchitectureType(Void)
		{
#if defined(FORGE_CPU_X86) && defined(FORGE_ARCHITECTURE_32BIT)
			return ArchitectureType::FORGE_X86;
#elif defined(FORGE_CPU_X86) && defined(FORGE_ARCHITECTURE_64BIT)
			return ArchitectureType::FORGE_X64;
#elif defined(FORGE_CPU_ARM) && defined(FORGE_ARCHITECTURE_32BIT)
			return ArchitectureType::FORGE_ARM;
#elif defined(FORGE_CPU_ARM) && defined(FORGE_ARCHITECTURE_64BIT)
			return ArchitectureType::FORGE_ARM64;
#endif
		}

		ConstCharPtr AbstractPlatform::GetUserLogName(Void)
		{
			return m_user_name;
		}
		ConstCharPtr AbstractPlatform::GetMachineName(Void)
		{
			return m_machine_name;
		}
		ConstCharPtr AbstractPlatform::GetUserLocaleName(Void)
		{
			return m_locale_name;
		}

		AbstractPlatform::CPUInfo AbstractPlatform::GetCPUInfo(Void)
		{
			return m_cpu_info;
		}

		Void AbstractPlatform::SetWindowCloseCallback(TDelegate<Void(WindowPtr)> callback)
		{
			m_window_close_callback = Move(callback);
		}
		Void AbstractPlatform::SetWindowFocusCallback(TDelegate<Void(WindowPtr, Bool)> callback)
		{
			m_window_focus_callback = Move(callback);
		}
		Void AbstractPlatform::SetWindowMinimizeCallback(TDelegate<Void(WindowPtr, Bool)> callback)
		{
			m_window_minimize_callback = Move(callback);
		}
		Void AbstractPlatform::SetWindowMaximizeCallback(TDelegate<Void(WindowPtr, Bool)> callback)
		{
			m_window_maximize_callback = Move(callback);
		}
		Void AbstractPlatform::SetWindowMoveCallback(TDelegate<Void(WindowPtr, U32, U32)> callback)
		{
			m_window_move_callback = Move(callback);
		}
		Void AbstractPlatform::SetWindowResizeCallback(TDelegate<Void(WindowPtr, U32, U32)> callback)
		{
			m_window_resize_callback = Move(callback);
		}
		Void AbstractPlatform::SetMouseMoveCallback(TDelegate<Void(WindowPtr, I32, I32)> callback)
		{
			m_mouse_move_callback = Move(callback);
		}
		Void AbstractPlatform::SetMouseScrollCallback(TDelegate<Void(WindowPtr, I32, I32)> callback)
		{
			m_mouse_scroll_callback = Move(callback);
		}
		Void AbstractPlatform::SetMouseButtonCallback(TDelegate<Void(WindowPtr, I32, I32, I32)> callback)
		{
			m_mouse_button_callback = Move(callback);
		}
		Void AbstractPlatform::SetKeyboardCallback(TDelegate<Void(WindowPtr, I32, I32, I32, I32)> callback)
		{
			m_keyboard_button_callback = Move(callback);
		}

		MessageBoxResult AbstractPlatform::ShowMessageBox(ConstCharPtr text)
		{
			return ShowMessageBox(nullptr, text, "Info", MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(WindowPtr parent, ConstCharPtr text)
		{
			return ShowMessageBox(parent, text, "Info", MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(ConstCharPtr text, ConstCharPtr caption)
		{
			return ShowMessageBox(nullptr, text, caption, MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption)
		{
			return ShowMessageBox(parent, text, caption, MessageBoxButton::FORGE_OK, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button)
		{
			return ShowMessageBox(nullptr, text, caption, button, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button)
		{
			return ShowMessageBox(parent, text, caption, button, MessageBoxIcon::FORGE_NONE);
		}
		MessageBoxResult AbstractPlatform::ShowMessageBox(ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button, MessageBoxIcon icon)
		{
			return ShowMessageBox(nullptr, text, caption, button, icon);
		}
	
		TWeakPtr<DynamicLibrary> AbstractPlatform::LoadDynamicLibrary(ConstCharPtr filename)
		{
			return m_dynamic_library_manager.LoadDynamicLibrary(filename);
		}
		Void AbstractPlatform::UnloadDynamicLibrary(TWeakPtr<DynamicLibrary> dynamic_library)
		{
			m_dynamic_library_manager.UnloadDynamicLibrary(dynamic_library);
		}
	}
}
