#ifndef ABSTRACT_GRAPHICS_CONTEXT_H
#define ABSTRACT_GRAPHICS_CONTEXT_H

#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>

#include <Platform/Public/Window.h>
#include <Platform/Public/Platform.h>

using namespace Forge::Common;
using namespace Forge::Platform;

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Abstract class defining common features for graphics context
		 * managers, which are responsible for creating and managing graphics
		 * context.
		 * 
		 * @author Karim Hisham.
		 */
		class AbstractGraphicsContext
		{
		public:
			struct FrameBufferConfig
			{
				/**
				 * @brief Specifies the number of red bitplanes in each RGBA
				 * color buffer.
				 */
				U32 red_bits = 8;

				/**
				 * @brief Specifies the number of green bitplanes in each RGBA
				 * color buffer.
				 */
				U32	green_bits = 8;

				/**
				 * @brief Specifies the number of blue bitplanes in each RGBA
				 * color buffer.
				 */
				U32	blue_bits = 8;

				/**
				 * @brief Specifies the number of red bitplanes in each RGBA
				 * color buffer.
				 */
				U32	alpha_bits = 8;

				/**
				 * @brief Specifies the depth of the depth (z-axis) buffer.
				 */
				U32 depth_bits = 24;

				/**
				 * @brief Specifies the depth of the stencil buffer.
				 */
				U32 stencil_bits = 8;

				U32 multisamples = 0;

				/**
				 * @brief Specifies wether the color buffer has left/right pairs.
				 */
				Bool is_stereo = false; 


				Bool is_srgb_capable = false; 

				/**
				 * @brief Specifies wether the color buffer has back/front pairs.
				 */
				Bool is_double_buffered = true;
			};

		protected:
			TSharedPtr<Window> m_window;

		public:
			/**
			 * @brief Default Constructor.
			 */
			AbstractGraphicsContext(TSharedPtr<Window> window);

		public:
			/**
			 * @brief Default Destructor.
			 */
			virtual ~AbstractGraphicsContext(Void) = default;

		public:
			/**
			 * @brief Gets the window associated with the current graphics
			 * context.
			 * 
			 * @returns TSharedPtr<Window> storing the window associated with the
			 * current graphics context.
			 */
			TSharedPtr<Window> GetWindow(Void);

		public:
			/**
			 * @brief Pre-initializes the graphics context.
			 *
			 * @throw InvalidIOException if failed to load dynamic library or
			 * failed to load dynamic library symbol.
			 * 
			 * @throws InvalidOperationException if failed to pre-initialize
			 * the graphics context.
			 */
			virtual Void PreInitialize(Void) = 0;

			/**
			 * @brief Initializes the graphics context.
			 *
			 * @throws InvalidOperationException if failed to initialize the
			 * graphics context.
			 */
			virtual Void Initialize(Void) = 0;
			
			/**
			 * @brief Terminates the graphics context.
			 * 
			 * @throws InvalidOperationException if failed to terminate
			 * the graphics context.
			 */
			virtual Void Terminate(Void) = 0;

		public:
			/**
			 * @brief Sets the graphics context as the current context for the
			 * associated window.
			 *
			 * @throws InvalidOperationException if failed to make the graphics
			 * context current.
			 */
			virtual Void SetCurrent(Void) = 0;

			/**
			 * @brief Ends the graphics context for the associated window but
			 * does not release the context.
			 */
			virtual Void EndCurrent(Void) = 0;

		public:
			/**
			 * @brief Swaps the front- and back-buffers if the current pixel
			 * format of the associated window includes a backbuffer.
			 * 
			 * @param interval[in] The number of screen updates to wait from the
			 * time the function was called before swapping the buffers and
			 * returning. This is known as Vertical Synchronization.
			 * 
			 * @throws InvalidOperationException if failed to swap buffers.
			 */
			virtual Void SwapBuffers(I32 interval = 0) = 0;
		};

		FORGE_TYPEDEF_DECL(AbstractGraphicsContext)

		FORGE_FORCE_INLINE AbstractGraphicsContext::AbstractGraphicsContext(TSharedPtr<Window> window)
				: m_window(window) {}

		FORGE_FORCE_INLINE TSharedPtr<Window> AbstractGraphicsContext::GetWindow(Void)
		{ 
			return m_window; 
		}
	}
}

#endif
