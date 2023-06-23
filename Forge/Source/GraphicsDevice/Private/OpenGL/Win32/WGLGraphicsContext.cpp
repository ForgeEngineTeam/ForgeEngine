#include <GraphicsDevice/Public/OpenGL/Win32/WGLGraphicsContext.h>

#define SET_FLAG(__VALUE__)	\
	{ context_flags |= __VALUE__; }

#define SET_MASK(__VALUE__)	\
	{ context_profile_mask |= __VALUE__;}

#define SET_ATTRIB(__KEY__, __VALUE__) \
	{ attribute_list[attribute_list_index++] = __KEY__; attribute_list[attribute_list_index++] = __VALUE__; }

namespace Forge {
	namespace Graphics
	{
		Bool WGLGraphicsContext::InternalIsExtenstionSupported(ConstCharPtr extension)
		{
			ConstCharPtr extensions = wglGetExtensionsStringARB(m_context_device_handle);
			if (!extensions)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
					"WGL: Failed to describe pixel format")

			ConstCharPtr start = extensions;

			for (;;)
			{
				const char* where;
				const char* terminator;

				where = strstr(start, extension);

				if (!where)
					return FORGE_FALSE;

				terminator = where + strlen(extension);

				if (where == start || *(where - 1) == ' ')
				{
					if (*terminator == ' ' || *terminator == '\0')
						break;
				}

				start = terminator;
			}

			return FORGE_TRUE;
		}
		Void WGLGraphicsContext::InternalCreateDummyRenderContext(HWND& dummy_window, HDC& dummy_context_device, HGLRC& dummy_context_render)
		{
			Bool result;

			WNDCLASS dummy_window_class;

			I32 pixel_format_descriptor_index;
			PIXELFORMATDESCRIPTOR pixel_format_descriptor;

			m_loader.PreInitialize();

			MemorySet(&dummy_window_class, 0, sizeof(WNDCLASS));
			MemorySet(&pixel_format_descriptor, 0, sizeof(pixel_format_descriptor));

			dummy_window_class.style = CS_OWNDC;
			dummy_window_class.hInstance = (HINSTANCE)Platform::Platform::GetInstance().GetPlatformHandle();
			dummy_window_class.lpfnWndProc = DefWindowProc;
			dummy_window_class.lpszClassName = "dummy_window_class";

			pixel_format_descriptor.nSize = sizeof(pixel_format_descriptor);
			pixel_format_descriptor.nVersion = 1;
			pixel_format_descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pixel_format_descriptor.iPixelType = PFD_TYPE_RGBA;
			pixel_format_descriptor.cColorBits = 24;

			RegisterClass(&dummy_window_class);

			dummy_window = CreateWindow(
				"dummy_window_class", "dummy_window",
				WS_POPUP | WS_CLIPCHILDREN,
				0, 0, 32, 32,
				nullptr, nullptr,
				(HINSTANCE)Platform::Platform::GetInstance().GetPlatformHandle(),
				nullptr
			);

			dummy_context_device = GetDC(dummy_window);

			pixel_format_descriptor_index = ChoosePixelFormat(dummy_context_device, &pixel_format_descriptor);

			result = SetPixelFormat(dummy_context_device, pixel_format_descriptor_index, &pixel_format_descriptor);
			if (!result)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Win32: Failed to set pixel format for dummy context")

				dummy_context_render = m_loader.m_backend_procedures.m_fptr_wglCreateContext(dummy_context_device);
			if (!dummy_context_render)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to create dummy render context")

				result = m_loader.m_backend_procedures.m_fptr_wglMakeCurrent(dummy_context_device, dummy_context_render);
			if (!result)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to make dummy context current")
		}

		WGLGraphicsContext::WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor)
			: AbstractGraphicsContext(window),
			  m_context_flags(GLContextFlags::FORGE_NONE),
			  m_context_profile(GLContextProfileMask::FORGE_CORE),
			  m_context_device_handle(nullptr),
			  m_context_render_handle(nullptr)
		{
			FORGE_ASSERT(window != nullptr, "Window is null")

			m_context_device_handle = GetDC((HWND)m_window->GetNativeHandle());
			if (!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to retrieve DC for window")

			m_loader.SetContextVersion(major, minor);
		}
		WGLGraphicsContext::WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor, GLContextProfileMask profile, GLContextFlags flags)
			: AbstractGraphicsContext(window),
			  m_context_flags(flags),
			  m_context_profile(profile),
			  m_context_device_handle(nullptr),
			  m_context_render_handle(nullptr)
		{
			FORGE_ASSERT(window != nullptr, "Window is null")

			m_context_device_handle = GetDC((HWND)m_window->GetNativeHandle());
			if (!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to retrieve DC for window")

			m_loader.SetContextVersion(major, minor);
		}
		WGLGraphicsContext::WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor, GLContextProfileMask profile, GLContextFlags flags, FrameBufferConfig config)
			: AbstractGraphicsContext(window),
			  m_context_flags(flags),
			  m_context_profile(profile),
			  m_framebuffer_config(config),
			  m_context_device_handle(nullptr),
			  m_context_render_handle(nullptr)
		{
			FORGE_ASSERT(window != nullptr, "Window is null")

			m_context_device_handle = GetDC((HWND)m_window->GetNativeHandle());
			if (!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to retrieve DC for window")

			m_loader.SetContextVersion(major, minor);
		}

		Void WGLGraphicsContext::PreInitialize(Void)
		{
			HWND dummy_window;

			HDC dummy_context_device;
			HGLRC dummy_context_render;

			this->InternalCreateDummyRenderContext(
				dummy_window, 
				dummy_context_device, 
				dummy_context_render
			);

			this->m_loader.SetExtensionHint(FORGE_WGL_EXT_swap_control,      FORGE_TRUE);
			this->m_loader.SetExtensionHint(FORGE_WGL_ARB_pixel_format,      FORGE_TRUE);
			this->m_loader.SetExtensionHint(FORGE_WGL_ARB_create_context,    FORGE_TRUE);
			this->m_loader.SetExtensionHint(FORGE_WGL_ARB_extensions_string, FORGE_TRUE);

			this->m_loader.Initialize();

			this->m_context_supported_extensions.m_has_arb_pixel_format = InternalIsExtenstionSupported("WGL_ARB_pixel_format");
			this->m_context_supported_extensions.m_has_arb_create_context = InternalIsExtenstionSupported("WGL_ARB_create_context");
			this->m_context_supported_extensions.m_has_arb_context_flush_control = InternalIsExtenstionSupported("WGL_ARB_context_flush_control");
			this->m_context_supported_extensions.m_has_arb_create_context_profile = InternalIsExtenstionSupported("WGL_ARB_create_context_profile");
			this->m_context_supported_extensions.m_has_arb_create_context_no_error = InternalIsExtenstionSupported("WGL_ARB_create_context_no_error");
			this->m_context_supported_extensions.m_has_arb_create_context_robustness = InternalIsExtenstionSupported("WGL_ARB_create_context_robustness");

			this->m_context_supported_extensions.m_has_ext_swap_control = InternalIsExtenstionSupported("WGL_EXT_swap_control");
			this->m_context_supported_extensions.m_has_ext_create_context_es2_profile = InternalIsExtenstionSupported("WGL_EXT_create_context_es2_profile");

			this->m_loader.m_backend_procedures.m_fptr_wglMakeCurrent(m_context_device_handle, m_context_render_handle);
			this->m_loader.m_backend_procedures.m_fptr_wglDeleteContext(dummy_context_render);

			DestroyWindow(dummy_window);
			UnregisterClass("dummy_window_class", (HINSTANCE)Platform::Platform::GetInstance().GetPlatformHandle());
		}
		Void WGLGraphicsContext::Initialize(Void)
		{
			Bool result;

			I32 pixel_format_descriptor_index;
			U32 pixel_format_descriptors_found;
			PIXELFORMATDESCRIPTOR pixel_format_descriptor;

			I32 attribute_list[64];
			I32 attribute_list_index = 0;
			
			I32 context_flags = 0;
			I32 context_profile_mask = 0;

			if (m_context_supported_extensions.m_has_arb_pixel_format)
			{
				I32 pixel_attributes[] = {
					WGL_DRAW_TO_WINDOW_ARB, FORGE_TRUE,
					WGL_DRAW_TO_BITMAP_ARB, FORGE_FALSE,

					WGL_SUPPORT_OPENGL_ARB, FORGE_TRUE,

					WGL_PIXEL_TYPE_ARB,		WGL_TYPE_RGBA_ARB,

					WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,

					WGL_RED_BITS_ARB,       m_framebuffer_config.red_bits,
					WGL_GREEN_BITS_ARB,     m_framebuffer_config.green_bits,
					WGL_BLUE_BITS_ARB,      m_framebuffer_config.blue_bits,

					WGL_DEPTH_BITS_ARB,     m_framebuffer_config.depth_bits,
					WGL_STENCIL_BITS_ARB,   m_framebuffer_config.stencil_bits,

					WGL_DOUBLE_BUFFER_ARB,  m_framebuffer_config.is_double_buffered,
					WGL_STEREO_ARB,         m_framebuffer_config.is_stereo,

					WGL_COLOR_BITS_ARB,     m_framebuffer_config.red_bits   +
											m_framebuffer_config.green_bits +
											m_framebuffer_config.blue_bits  +
											m_framebuffer_config.alpha_bits,
					0,
				};

				result = wglChoosePixelFormatARB(m_context_device_handle, pixel_attributes, nullptr, 1, &pixel_format_descriptor_index, &pixel_format_descriptors_found);
				if (!result)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"WGL: Failed to choose pixel format")

				result = DescribePixelFormat(m_context_device_handle, pixel_format_descriptor_index, sizeof(pixel_format_descriptor), &pixel_format_descriptor);
				if (!result)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"Win32: Failed to describe pixel format")

				result = SetPixelFormat(m_context_device_handle, pixel_format_descriptor_index, &pixel_format_descriptor);
				if (!result)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"Win32: Failed to set pixel format")
			}
			else
			{
				pixel_format_descriptor.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
				pixel_format_descriptor.nVersion     = 1;
				pixel_format_descriptor.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
				pixel_format_descriptor.iPixelType   = PFD_TYPE_RGBA;
				pixel_format_descriptor.cColorBits   = 32;
				pixel_format_descriptor.cDepthBits   = 24;
				pixel_format_descriptor.cStencilBits = 8;

				pixel_format_descriptor_index = ChoosePixelFormat(m_context_device_handle, &pixel_format_descriptor);
				if (!pixel_format_descriptor_index)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"Win32: Failed to choose pixel format")

				result = SetPixelFormat(m_context_device_handle, pixel_format_descriptor_index, &pixel_format_descriptor);
				if (!result)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"Win32: Failed to set pixel format")
			}

			if (m_context_supported_extensions.m_has_arb_create_context)
			{
				if ((m_loader.GetContextMajorVersion() == 1 && (m_loader.GetContextMinorVersion() >= 0 || m_loader.GetContextMinorVersion() <= 5)) ||
					(m_loader.GetContextMajorVersion() == 2 && (m_loader.GetContextMinorVersion() >= 0 || m_loader.GetContextMinorVersion() <= 1)) ||
					(m_loader.GetContextMajorVersion() == 3 && (m_loader.GetContextMinorVersion() >= 0 || m_loader.GetContextMinorVersion() <= 3)) ||
					(m_loader.GetContextMajorVersion() == 4 && (m_loader.GetContextMinorVersion() >= 0 || m_loader.GetContextMinorVersion() <= 6)))
				{
					SET_ATTRIB(WGL_CONTEXT_MAJOR_VERSION_ARB, m_loader.GetContextMajorVersion())
					SET_ATTRIB(WGL_CONTEXT_MINOR_VERSION_ARB, m_loader.GetContextMinorVersion())
				}
				else
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"WGL: Invalid OpenGL version requested")

				if (m_context_supported_extensions.m_has_arb_create_context_profile)
				{
					if (m_context_profile == GLContextProfileMask::FORGE_CORE)
						SET_MASK(WGL_CONTEXT_CORE_PROFILE_BIT_ARB)
					else if (m_context_profile == GLContextProfileMask::FORGE_COMPAT)
						SET_MASK(WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB)
				}
				else
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"WGL: OpenGL profile requested but WGL_ARB_create_context_profile is unavailable")

				if(m_context_supported_extensions.m_has_ext_create_context_es2_profile && m_context_profile == GLContextProfileMask::FORGE_ES)
						SET_MASK(WGL_CONTEXT_ES2_PROFILE_BIT_EXT)
				else if(!m_context_supported_extensions.m_has_ext_create_context_es2_profile && m_context_profile == GLContextProfileMask::FORGE_ES)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"WGL: OpenGL ES2 profile requested but WGL_ARB_create_context_es2_profile is unavailable")

				if (m_context_supported_extensions.m_has_arb_create_context_no_error && m_context_flags & GLContextFlags::FORGE_NO_ERROR)
						SET_ATTRIB(WGL_CONTEXT_OPENGL_NO_ERROR_ARB, FORGE_TRUE)
				else if (!m_context_supported_extensions.m_has_arb_create_context_no_error && m_context_flags & GLContextFlags::FORGE_NO_ERROR)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION, 
						"WGL: OpenGL no error requested but WGL_ARB_create_context_no_error is unavailable")

				if (m_context_supported_extensions.m_has_arb_create_context_robustness && m_context_flags & GLContextFlags::FORGE_ROBUSTNESS)
						SET_FLAG(WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB)
				else if (!m_context_supported_extensions.m_has_arb_create_context_robustness && m_context_flags & GLContextFlags::FORGE_ROBUSTNESS)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"WGL: OpenGL context robustness requested but WGL_ARB_create_context_robustness is unavailable")

				if (m_context_supported_extensions.m_has_arb_context_flush_control && m_context_flags & GLContextFlags::FORGE_RELEASE_FLUSH)
						SET_ATTRIB(WGL_CONTEXT_RELEASE_BEHAVIOR_ARB, WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB)
				else if (!m_context_supported_extensions.m_has_arb_context_flush_control && m_context_flags & GLContextFlags::FORGE_RELEASE_FLUSH)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"WGL: OpenGL flush control requested but WGL_ARB_context_flush_control is unavailable")

				if (m_context_flags & GLContextFlags::FORGE_DEBUG)
					SET_FLAG(WGL_CONTEXT_DEBUG_BIT_ARB)

				if (m_context_flags & GLContextFlags::FORGE_FORWARD_COMPAT)
					SET_FLAG(WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB)

				if (context_flags)
					SET_ATTRIB(WGL_CONTEXT_FLAGS_ARB, context_flags)

				if (context_profile_mask)
					SET_ATTRIB(WGL_CONTEXT_PROFILE_MASK_ARB, context_profile_mask)

				SET_ATTRIB(0, 0)

				m_context_render_handle = wglCreateContextAttribsARB(m_context_device_handle, nullptr, attribute_list);
				if (!m_context_render_handle)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"WGL: Failed to create context")
			}
			else
			{
				m_context_render_handle = m_loader.m_backend_procedures.m_fptr_wglCreateContext(m_context_device_handle);
				if (!m_context_render_handle)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"WGL: Failed to create context")
			}

			result = m_loader.m_backend_procedures.m_fptr_wglMakeCurrent(m_context_device_handle, m_context_render_handle);
			if (!result)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to make context current")
			
			m_context_vendor         = (CharPtr)glGetString(GL_VENDOR);
			m_context_renderer       = (CharPtr)glGetString(GL_RENDERER);
			m_context_shader_version = (CharPtr)glGetString(GL_SHADING_LANGUAGE_VERSION);
		}
		Void WGLGraphicsContext::Terminate(Void)
		{
			if (!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Device handle is null")

			if (!m_context_render_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Render handle is null")

			m_loader.m_backend_procedures.m_fptr_wglDeleteContext(m_context_render_handle);

			m_loader.Terminate();

			DeleteDC(m_context_device_handle);

			m_context_device_handle = nullptr;
			m_context_render_handle = nullptr;
		}

		Void WGLGraphicsContext::SetCurrent(Void)
		{
			if(!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Device handle is null")

			if(!m_context_render_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Render handle is null")

			if(!m_loader.m_backend_procedures.m_fptr_wglMakeCurrent(m_context_device_handle, m_context_render_handle))
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Failed to make context current")
		}
		Void WGLGraphicsContext::EndCurrent(Void)
		{
			m_loader.m_backend_procedures.m_fptr_wglMakeCurrent(nullptr, nullptr);
		}

		Void WGLGraphicsContext::SwapBuffers(I32 swap_interval)
		{
			if(!m_context_device_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Device handle is null")

			if (m_context_supported_extensions.m_has_ext_swap_control)
				wglSwapIntervalEXT(swap_interval);
			else
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"WGL: Swap Interval requested but WGL_EXT_swap_control is unavailable")
				
			::SwapBuffers(m_context_device_handle);
		}
	}
}
