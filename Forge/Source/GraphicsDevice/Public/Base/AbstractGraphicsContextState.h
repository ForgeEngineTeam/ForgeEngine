#ifndef ABSTRACT_GRAPHICS_CONTEXT_STATE_H
#define ABSTRACT_GRAPHICS_CONTEXT_STATE_H

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>

#include <Core/Public/Containers/TStaticArray.h>

#include <GraphicsDevice/Public/GraphicsTypes.h>
#include <GraphicsDevice/Public/GraphicsObject.h>
#include <GraphicsDevice/Public/Base/AbstractHardwareBuffer.h>
#include <GraphicsDevice/Public/Base/AbstractGraphicsContext.h>
#include <GraphicsDevice/Public/Base/AbstractVertexDecleration.h>

#include <Platform/Public/Window.h>

using namespace Forge::Debug;
using namespace Forge::Common;
using namespace Forge::Containers;

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Abstract class defining common features of Context state
		 * managers, which is responsible for managing the state of
		 * the graphics pipeline. 
		 * 
		 * @author Karim Hisham.
		 */
		class AbstractGraphicsContextState
		{
		public:
			using ActiveBufferTable = TStaticArray<GraphicsObject::Handle, 
				static_cast<Size>(BufferTypeMask::MAX)>;

		protected:
			struct RasterizerState
			{
				/**
				 * @brief The raster line width.
				 */
				F32 line_width;

				/**
				 * @brief The current clear color to use.
				 */
				Byte color_clear[4];

				/**
				 * @brief The current color write mask to use.
				 */
				Byte color_write_mask[4];

				/**
				 * @brief The current front face winding to use.
				 */
				FrontFaceMask front_face_mode;

				/**
				 * @brief The current fill mode of polygons to use.
				 */
				PolygonFillMask polygon_fill_mode;

				struct DepthState
				{
					/**
					 * @brief Is depth testing enabled or not?
					 */
					Bool is_enabled;

					/**
					 * @brief The current depth write mask used.
					 */
					Bool write_mask;

					/**
					 * @brief The current depth comparison function used.
					 */
					ComparisonFuncMask comparison_function;
				} depth_state;

				struct StencilState
				{
					/**
					 * @brief Is stencil testing enabled or not?
					 */
					Bool is_enabled;

					/**
					 * @brief The current stencil write mask used.
					 */
					Byte write_mask;

					/**
					 * @brief The current stencil comparison function used.
					 */
					ComparisonFuncMask comparison_function;
				} stencil_state;

				struct ScissorState
				{
					/**
					 * @brief Is scissor testing enabled or not?
					 */
					Bool is_enabled;

					/**
					 * @brief The current scissor bounding region used.
					 */
					I32 bounding_region[4];
				} scissor_state;

				struct FaceCullingState
				{
					/**
					 * @brief Is face culling enabled or not?
					 */
					Bool is_enabled;

					/**
					 * @brief The current face culling mode to use.
					 */
					FaceCullMask mode;
				} face_culling_state;

				struct ColorBlendingState
				{
					/**
					 * @brief Is color blending enabled or not?
					 */
					Bool is_enabled;

					/**
					 * @brief The current constant blending color to use.
					 */
					F32 constant[4];

					/**
					 * @brief The current blending source function to use.
					 */
					BlendFuncMask src_function;

					/**
					 * @brief The current blending destination function to use.
					 */
					BlendFuncMask dst_function;

				} color_blending_state;
			} m_rasterizer_state;
		
		protected:
			TSharedPtr<Window> m_window;

		protected:
			ActiveBufferTable m_active_buffers;
		
		protected:
			GraphicsObject::Handle m_active_texture;
			GraphicsObject::Handle m_active_gpu_program;
			GraphicsObject::Handle m_active_read_framebuffer;
			GraphicsObject::Handle m_active_write_framebuffer;
			GraphicsObject::Handle m_active_vertex_decleration;

		public:
			/**
			 * @brief Default Constructor.
			 */
			AbstractGraphicsContextState(TSharedPtr<Window> window);

		public:
			/**
			 * @brief Destructor.
			 */
			virtual ~AbstractGraphicsContextState(Void) = default;

		public:
			/**
			 * @brief Gets the currently bound texture.
			 *
			 * @returns U32 storing the currently bound texture.
			 * 
			 * @throws InvalidOperation exception if no texture is bound.
			 */
			GraphicsObject::Handle GetActiveTexture(Void);

			/**
			 * @brief Gets the currently bound GPU program.
			 *
			 * @returns U32 storing the currently bound GPU program.
			 * 
			 * @throws InvalidOperation exception if no GPU program is bound.
			 */
			GraphicsObject::Handle GetActiveGPUProgram(Void);

			/**
			 * @brief Gets the currently bound read framebuffer.
			 *
			 * @returns U32 storing the currently bound read framebuffer.
			 * 
			 * @throws InvalidOperation exception if no read framebuffer is bound.
			 */
			GraphicsObject::Handle GetActiveReadFramebuffer(Void);

			/**
			 * @brief Gets the currently bound write framebuffer.
			 *
			 * @returns U32 storing the currently bound write framebuffer.
			 * 
			 * @throws InvalidOperation exception if no write framebuffer is
			 * bound.
			 */
			GraphicsObject::Handle GetActiveWriteFramebuffer(Void);

			/**
			 * @brief Gets the currently bound vertex decleration.
			 *
			 * @returns U32 storing the currently bound vertex decleration.
			 * 
			 * @throws InvalidOperation exception if no vertex decleration is
			 * bound.
			 */
			GraphicsObject::Handle GetActiveVertexDecleration(Void);

		public:
			/**
			 * @brief Gets the currently bound hardware buffers.
			 * 
			 * @returns BoundBufferTable storing the currently bound hardware
			 * buffers.
			 */
			ActiveBufferTable GetActiveHardwareBuffers(Void);

		public:
			/**
			 * @brief Enables or disbales depth test.
			 *
			 * @param enable The state of depth testing.
			 */
			virtual Void EnableDepthTest(Bool enable) = 0;

			/**
			 * @brief Enables or disbales stencil test.
			 *
			 * @param enable The state of stencil testing.
			 */
			virtual Void EnableStencilTest(Bool enable) = 0;

			/**
			 * @brief Enables or disbales scissor test.
			 *
			 * @param enable The state of scissor testing.
			 */
			virtual Void EnableScissorTest(Bool enable) = 0;

			/**
			 * @brief Enables or disables polygon culling based on their winding.
			 *
			 * @param enable The state of face culling.
			 */
			virtual Void EnableFaceCulling(Bool enable) = 0;

			/**
			 * @brief Enables or disables blending of the computed fragment color
			 * values with the values in the color buffer.
			 *
			 * @param enable The state of blending.
			 */
			virtual Void EnableColorBlending(Bool enable) = 0;

		public:
			/**
			 * @brief Sets a mask to enable and disable writing in the depth
			 * buffer.
			 *
			 * @param mask[in] The mask to enable and disable writing in the depth
			 * buffer.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetDepthWriteMask(Bool mask) = 0;

			/**
			 * @brief Sets a depth buffer comparison function.
			 *
			 * @param function[in] The comparison function to use for depth testing.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetDepthComparisonFunction(ComparisonFuncMask function) = 0;

		public:
			/**
			 * @brief Sets a bit mask to enable and disable writing of individual
			 * bits in the stencil planes.
			 *
			 * @param mask[in] The bit mask to enable and disable writing of individual bits.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetStencilWriteMask(Byte mask) = 0;

			/**
			 * @brief Sets a stencil buffer comparison function and reference
			 * value.
			 *
			 * @param function[in]  The comparison function to use for stencil testing.
			 * @param reference[in] The reference value for the stencil test.
			 * @param mask[in]      The mask that is ANDed with both the reference value and the stored stencil value. 
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetStencilComparisonFunction(ComparisonFuncMask function, I32 reference, U32 mask) = 0;

		public:
			/**
			 * @brief Sets a scissor bounding region where fragments outside
			 * will be discarded.
			 *
			 * @param x[in]      The left corner of the bounding region.
			 * @param y[in]      The lower corner of the bounding region.
			 * @param width[in]  The width of the bounding region.
			 * @param height[in] The height of the bounding region.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetScissorBoundingRegion(I32 x, I32 y, I32 width, I32 height) = 0;

		public:
			/**
			 * @brief Sets whether front or back facing polygons are candidates
			 * for culling.
			 *
			 * @param mode[in] The face culling mode to use.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetFaceCullingMode(FaceCullMask mode) = 0;

		public:
			/**
			 * @brief Sets a constant blend color that is used when blending the
			 * source and destination colors during the blending operation.
			 *
			 * @param red[in]   The blend color red component.
			 * @param green[in] The blend color green component.
			 * @param blue[in]  The blend color blue component.
			 * @param alpha[in] The blend color alpha component.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetColorBlendingConstant(F32 red, F32 green, F32 blue, F32 alpha) = 0;

			/**
			 * @brief Sets a blend function used to calculate blending factor.
			 *
			 * @param src_function[in] The source function to compute the blending factor.
			 * @param dst_function[in] The destination function to compute the blending factor.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetColorBlendingFunction(BlendFuncMask src_function, BlendFuncMask dst_function) = 0;

		public:
			/**
			 * @brief Sets the width of rasterized lines.
			 *
			 * @param width[in] The width of the rasterized line.
			 */
			virtual Void SetLineWidth(F32 width) = 0;

			/**
			 * @brief Sets a texture unit as active.
			 * 
			 * @param index[in] The index of the texture unit to activate.
			 */
			virtual Void SetActiveTextureUnit(U32 index) = 0;

			/**
			 * @brief Sets a fill rasterizaton mode, which specifies how polygons
			 * will be rendered on screen.
			 *
			 * @param mode[in] The fill rasterization mode.
			 */
			virtual Void SetFillMode(PolygonFillMask mode) = 0;

			/**
		     * @brief Sets the orientation of front facing polygons.
		     *
		     * @param front_facr[in] The front face orientation to use.
		     */
			virtual Void SetFrontFace(FrontFaceMask front_face) = 0;

			/**
			 * @brief Sets a pixel storage mode.
			 *
			 * @param mode[in]  The pixel storage mode to be set.
			 * @param value[in] The value of the pixel storage mode.
			 */
			virtual Void SetPixelStorage(PixelStorageMask mode, I32 value) = 0;

			/**
			 * @brief Sets a  clear values for the color buffers.
			 * 
			 * @param red[in]   The color buffer red component.
			 * @param green[in] The color buffer green component.
			 * @param blue[in]  The color buffer blue component.
			 * @param alpha[in] The color buffer alpha component.
			 */
			virtual Void SetColorClear(F32 red, F32 green, F32 blue, F32 alpha) = 0;
			
			/**
			 * @brief Sets a mask to enable and disable writing of individual 
			 * components of the color buffer.
			 * 
			 * @param red[in]   The color buffer red component.
			 * @param green[in] The color buffer green component.
			 * @param blue[in]  The color buffer blue component.
			 * @param alpha[in] The color buffer alpha component.
			 */
			virtual Void SetColorWriteMask(F32 red, F32 green, F32 blue, F32 alpha) = 0;

		public:
			/**
			 * @brief Initializes the entire context state with default values and
			 * stores the states.
			 */
			virtual Void InitializeCache(Void) = 0;

			/**
			 * @brief Invalidates the entire context state and unbinds all bounded
			 * textures, buffers, shaders, and vertex array.
			 */
			virtual Void InvalidateCache(Void) = 0;

		public:
			/**
			 * @brief Binds a hardware buffer.
			 * 
			 * @throws InvalidOperationException if the TWeakPtr is expired.
			 */
			virtual Void BindHardwareBuffer(TWeakPtr<AbstractHardwareBuffer> hardware_buffer) = 0;

			/**
			 * @brief Binds a vertex decleration.
			 *
			 * @throws InvalidOperationException if the TWeakPtr is expired.
			 */
			virtual Void BindVertexDecleration(TWeakPtr<AbstractVertexDecleration> vertex_decleration) = 0;

		public:
			/**
			 * @brief Unbinds a hardware buffer.
			 * 
			 * @param buffer_type_mask[in] The hardware buffer type to unbind.
			 */
			virtual Void UnbindHardwareBuffer(BufferTypeMask buffer_type_mask) = 0;

			/**
			 * @brief Unbinds a vertex decleration.
			 */
			virtual Void UnbindVertexDecleration(Void) = 0;
		};

		FORGE_TYPEDEF_DECL(AbstractGraphicsContextState)

		FORGE_FORCE_INLINE AbstractGraphicsContextState::AbstractGraphicsContextState(TSharedPtr<Window> window)
			: m_window(window) {}

		FORGE_FORCE_INLINE GraphicsObject::Handle AbstractGraphicsContextState::GetActiveTexture(Void)
		{
			if(!m_active_texture)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			return m_active_texture;
		}
		FORGE_FORCE_INLINE GraphicsObject::Handle AbstractGraphicsContextState::GetActiveGPUProgram(Void)
		{
			if (!m_active_gpu_program)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			return m_active_gpu_program;
		}
		FORGE_FORCE_INLINE GraphicsObject::Handle AbstractGraphicsContextState::GetActiveReadFramebuffer(Void)
		{
			if (!m_active_read_framebuffer)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			return m_active_read_framebuffer;
		}
		FORGE_FORCE_INLINE GraphicsObject::Handle AbstractGraphicsContextState::GetActiveWriteFramebuffer(Void)
		{
			if (!m_active_write_framebuffer)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			return m_active_write_framebuffer;
		}
		FORGE_FORCE_INLINE GraphicsObject::Handle AbstractGraphicsContextState::GetActiveVertexDecleration(Void)
		{
			if (!m_active_vertex_decleration)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

				return m_active_vertex_decleration;
		}

		FORGE_FORCE_INLINE AbstractGraphicsContextState::ActiveBufferTable AbstractGraphicsContextState::GetActiveHardwareBuffers(Void)
		{
			return m_active_buffers;
		}
	}
}

#endif // ABSTRACT_GRAPHICS_CONTEXT_STATE_H
