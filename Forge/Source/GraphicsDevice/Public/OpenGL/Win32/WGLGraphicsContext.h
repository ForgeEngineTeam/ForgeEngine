#ifndef GL_WINDOWS_GRAPHICS_CONTEXT_H
#define GL_WINDOWS_GRAPHICS_CONTEXT_H

#include <string>

#include <Core/Public/Memory/MemoryUtilities.h>

#include <GraphicsDevice/Public/OpenGL/Win32/WGLLoader.h>
#include <GraphicsDevice/Public/Base/AbstractGraphicsContext.h>

using namespace Forge::Memory;
using namespace Forge::Platform;

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Graphics Context Manager implementation for OpenGL.
		 *
		 * @author Karim Hisham.
		 */
		class FORGE_API WGLGraphicsContext final : public AbstractGraphicsContext
		{
		private:
			using NativeDeviceContext = HDC;
			using NativeRenderContext = HGLRC;

		private:
			struct GLContextSupportedExtensions
			{
				/**
				 * @brief Is ARB pixel format extension enabled?
				 */
				Bool m_has_arb_pixel_format;

				/**
				 * @brief Is ARB create context extension enabled?
				 */
				Bool m_has_arb_create_context;

				/**
				 * @brief Is ARB flush control extension enabled?
				 */
				Bool m_has_arb_context_flush_control;

				/**
				 * @brief Is ARB create context profile extension enabled?
				 */
				Bool m_has_arb_create_context_profile;

				/**
				 * @brief Is ARB create context no error enabled?
				 */
				Bool m_has_arb_create_context_no_error;

				/**
				 * @brief Is ARB create context robustness extension enabled?
				 */
				Bool m_has_arb_create_context_robustness;

				/**
				 * @brief Is EXT swap control extension enabled?
				 */
				Bool m_has_ext_swap_control;
				
				/**
				 * @brief Is EXT create context es2 extension enabled?
				 */
				Bool m_has_ext_create_context_es2_profile;
			} m_context_supported_extensions;

		private:
			WGLLoader m_loader;

		private:
			CharPtr m_context_vendor;
			CharPtr m_context_renderer;
			CharPtr m_context_shader_version;

		private:
			GLContextFlags m_context_flags;
			GLContextProfileMask m_context_profile;

		private:
			FrameBufferConfig m_framebuffer_config;

		private:
			NativeDeviceContext m_context_device_handle;
			NativeRenderContext m_context_render_handle;

		private:
			Bool InternalIsExtenstionSupported(ConstCharPtr extension);
			Void InternalCreateDummyRenderContext(HWND& dummy_window, HDC& dummy_context_device, HGLRC& dummy_context_render);

		public:
			/**
			 * @brief Default Constructor.
			 */
			WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor);

			/**
			 * @brief Default Constructor.
			 */
			WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor, GLContextProfileMask profile, GLContextFlags flags);

			/**
			 * @brief Default Constructor.
			 */
			WGLGraphicsContext(TSharedPtr<Window> window, I32 major, I32 minor, GLContextProfileMask profile, GLContextFlags flags, FrameBufferConfig config);

		public:
			/**
			 * @brief Gets major release number of the renderer API.
			 *
			 * @returns ConstCharPtr storing the release number of the renderer
			 * API.
			 */
			I32 GetMajorVersion(Void);

			/**
			 * @brief Gets minor release number of the renderer API.
			 *
			 * @returns ConstCharPtr storing the release number of the renderer
			 * API.
			 */
			I32 GetMinorVersion(Void);

		public:
			/**
			 * @brief Gets the company responsible for this renderer
			 * implementation.
			 *
			 * @returns ConstCharPtr storing the company responsible for this
			 * renderer implementation.
			 */
			ConstCharPtr GetVendor(Void);

			/**
			 * @brief Gets the name of the hardware renderer.
			 *
			 * @returns ConstCharPtr storing the name of the hardware renderer.
			 */
			ConstCharPtr GetRenderer(Void);

			/**
			 * @brief Gets release number of the shader language.
			 *
			 * @returns ConstCharPtr storing the release number the shader
			 * language.
			 */
			ConstCharPtr GetShaderVersion(Void);

		public:
			/**
			 * @brief Pre-initializes the graphics context.
			 *
			 * @throw InvalidIOException if failed to load dynamic library or
			 * failed to load dynamic library symbol.
			 */
			Void PreInitialize(Void) override;

			/**
			 * @brief Initializes the graphics context
			 * 
			 * @throws InvalidOperationException if failed to initialize the
			 * graphics context.
			 */
			Void Initialize(Void) override;

			/**
			 * @brief Terminates the graphics context.
			 * 
			 * @throws InvalidOperationException if failed to terminate
			 * the graphics context.
			 */
			Void Terminate(Void) override;

		public:
			/**
			 * @brief Sets the graphics context as the current context for the
			 * associated window.
			 *
			 * @throws InvalidOperationException if failed to make the graphics
			 * context current.
			 */
			Void SetCurrent(Void) override;

			/**
			 * @brief Ends the graphics context for for the associated window but
			 * does not release the context.
			 */
			Void EndCurrent(Void) override;

		public:
			/**
			 * @brief Swaps the front and back buffers if the current pixel format
			 * for the window referenced by the graphics context includes a back
			 * buffer.
			 *
			 * @param swap_internval The number of screen updates to wait from the
			 * time SwapBuffers was called before swapping the buffers and
			 * returning. This is known as Vertical Synchronization.
			 * 
			 * @throws InvalidOperationException if failed to swap buffers.
			 */
			Void SwapBuffers(I32 swap_interval = 0) override;
		};

		FORGE_TYPEDEF_DECL(WGLGraphicsContext)

		FORGE_FORCE_INLINE I32 WGLGraphicsContext::GetMajorVersion(Void)
		{ 
			return m_loader.GetContextMajorVersion();
		}
		FORGE_FORCE_INLINE I32 WGLGraphicsContext::GetMinorVersion(Void)
		{ 
			return m_loader.GetContextMinorVersion();
		}

		FORGE_FORCE_INLINE ConstCharPtr WGLGraphicsContext::GetVendor(Void)
		{ 
			return m_context_vendor; 
		}
		FORGE_FORCE_INLINE ConstCharPtr WGLGraphicsContext::GetRenderer(Void)
		{ 
			return m_context_renderer; 
		}
		FORGE_FORCE_INLINE ConstCharPtr WGLGraphicsContext::GetShaderVersion(Void)
		{ 
			return m_context_shader_version; 
		}	
	}
}

#endif
