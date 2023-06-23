#ifndef GL_GRAPHICS_CONTEXT_STATE_H
#define GL_GRAPHICS_CONTEXT_STATE_H

#include <GraphicsDevice/Public/OpenGL/GL/gl.h>
#include <GraphicsDevice/Public/OpenGL/GLUtilities.h>
#include <GraphicsDevice/Public/Base/AbstractGraphicsContextState.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief OpenGL context state implementation.
		 *
		 * @author Karim Hisham.
		 */
		class FORGE_API GLGraphicsContextState final : public AbstractGraphicsContextState
		{
		private:
			struct GLContextLimits
			{
				/**
				 * @brief The maximum number of simultaneous outputs that may be
				 * written in a fragment shader.
				 */
				I32 max_draw_buffers = 0;
				
				/**
				 * @brief The maximum supported size for textures.
				 */
				I32 max_texture_size = 0;

				/**
				 * @brief The maximum supported size for renderbuffers.
				 */
				I32 max_renderbuffer_size = 0;

				/**
				 * @brief The maximum supported number of values that can be held
				 * in uniform variable storage for a vertex shader.
				 */
				I32 max_vertex_uniform_components = 0;

				/**
				 * @brief The maximum supported number of values that can be held
				 * in uniform variable storage for a fragment shader.
				 */
				I32 max_fragment_uniform_components = 0;

				/**
				 * @brief The maximum supported texture units that can be accessed.
				 */
				I32 max_combind_texture_image_units = 0;
			} m_context_limits;
			
			FORGE_TYPEDEF_DECL(GLContextLimits)

		public:
			/**
			 * @brief Default Constructor.
			 */
			GLGraphicsContextState(TSharedPtr<Window> window);

		public:
			/**
			 * @brief Enables or disbales depth test.
			 *
			 * @param enable The state of depth testing.
			 */
			Void EnableDepthTest(Bool enable) override;

			/**
			 * @brief Enables or disbales stencil test.
			 *
			 * @param enable The state of stencil testing.
			 */
			Void EnableStencilTest(Bool enable) override;

			/**
			 * @brief Enables or disbales scissor test.
			 *
			 * @param enable The state of scissor testing.
			 */
			Void EnableScissorTest(Bool enable) override;

			/**
			 * @brief Enables or disables polygon culling based on their winding.
			 *
			 * @param enable The state of face culling.
			 */
			Void EnableFaceCulling(Bool enable) override;

			/**
			 * @brief Enables or disables blending of the computed fragment color
			 * values with the values in the color buffer.
			 *
			 * @param enable The state of blending.
			 */
			Void EnableColorBlending(Bool enable) override;
		
		public:
			/**
			 * @brief Gets the context limits.
			 *
			 * @returns ConstContextLimits storing the limits of the current context.
			 */
			ConstGLContextLimits GetContextLimits(Void);

		public:
			/**
			 * @brief Sets a mask to enable and disable writing in the depth
			 * buffer.
			 *
			 * @param mask The mask to enable and disable writing in the depth
			 * buffer.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetDepthWriteMask(Bool mask) override;

			/**
			 * @brief Sets a depth buffer comparison function.
			 * 
			 * @param function The comparison function to use for depth testing.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetDepthComparisonFunction(ComparisonFuncMask function) override;

		public:
			/**
			 * @brief Sets a bit mask to enable and disable writing of individual
			 * bits in the stencil planes.
			 *
			 * @param mask The bit mask to enable and disable writing of
			 * individual bits.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetStencilWriteMask(Byte mask) override;

			/**
			 * @brief Sets a stencil buffer comparison function and reference
			 * value.
			 *
			 * @param function The comparison function to use for depth testing.
			 * @param ref The reference value for the stencil test.
			 * @param mask The mask that is ANDed with both the reference value
			 * and the stored stencil value when the test is done.
			 *
			 * @returns True if enabled, otherwise false.
			 */
			virtual Bool SetStencilComparisonFunction(ComparisonFuncMask function, I32 ref, U32 mask) override;

		public:
			/**
			 * @brief Sets a scissor bounding region where fragments outside
			 * will be discarded.
			 *
			 * @param x      The left corner of the bounding region.
			 * @param y      The lower corner of the bounding region.
			 * @param width  The width of the bounding region.
			 * @param height The height of the bounding region.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetScissorBoundingRegion(I32 x, I32 y, I32 width, I32 height) override;

		public:
			/**
			 * @brief Sets whether front or back facing polygons are candidates
			 * for culling.
			 *
			 * @param FaceCullMask The face culling mode to use.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetFaceCullingMode(FaceCullMask mode) override;

		public:
			/**
			 * @brief Sets a constant blend color that is used when blending the
			 * source and destination colors during the blending operation.
			 *
			 * @param red   The blend color red component.
			 * @param green The blend color green component.
			 * @param blue  The blend color blue component.
			 * @param alpha The blend color alpha component.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetColorBlendingConstant(F32 red, F32 green, F32 blue, F32 alpha) override;

			/**
			 * @brief Sets a blend function used to calculate blending factor.
			 *
			 * @param src_function The source function to compute the blending factor.
			 * @param dst_function The destination function to compute the blending factor.
			 * 
			 * @returns True if enabled, otherwise false.
			 */
			Bool SetColorBlendingFunction(BlendFuncMask src_function, BlendFuncMask dst_function) override;

		public:
			/**
			 * @brief Sets the width of rasterized lines.
			 *
			 * @param width The width of the rasterized line.
			 */
			Void SetLineWidth(F32 width) override;

			/**
			 * @brief Sets a texture unit as active.
			 *
			 * @param index The index of the texture unit to activate.
			 */
			Void SetActiveTextureUnit(U32 index) override;

			/**
			 * @brief Sets a fill rasterizaton mode, which specifies how polygons
			 * will be rendered on screen.
			 * 
			 * @param mode The fill rasterization mode.
			 */
			Void SetFillMode(PolygonFillMask mode) override;
			
			/**
			 * @brief Sets the orientation of front facing polygons.
			 *
			 * @param front_face The front face orientation to use.
			 */
			Void SetFrontFace(FrontFaceMask front_face) override;

			/**
			 * @brief Sets a pixel storage mode.
			 * 
			 * @param mode  The pixel storage mode to be set.
			 * @param value The value of the pixel storage mode.
			 */
			Void SetPixelStorage(PixelStorageMask mode, I32 value) override;

			/**
			 * @brief Sets a  clear values for the color buffers.
			 *
			 * @param red   The color buffer red component.
			 * @param green The color buffer green component.
			 * @param blue  The color buffer blue component.
			 * @param alpha The color buffer alpha component.
			 */
			Void SetColorClear(F32 red, F32 green, F32 blue, F32 alpha) override;

			/**
			 * @brief Sets a mask to enable and disable writing of individual
			 * components of the color buffer.
			 *
			 * @param red   The color buffer red component.
			 * @param green The color buffer green component.
			 * @param blue  The color buffer blue component.
			 * @param alpha The color buffer alpha component.
			 */
			Void SetColorWriteMask(F32 red, F32 green, F32 blue, F32 alpha) override;

		public:
			/**
			 * @brief Initializes the entire context state with default values and
			 * stores the states.
			 */
			Void InitializeCache(Void) override;

			/**
			 * @brief Invalidates the entire context state and unbinds all bounded
			 * textures, buffers, shaders, and vertex arrays.
			 */
			Void InvalidateCache(Void) override;

		public:
			/**
			 * @brief Binds a hardware buffer.
			 *
			 * @throws InvalidOperationException if the TWeakPtr is expired.
			 */
			Void BindHardwareBuffer(TWeakPtr<AbstractHardwareBuffer> hardware_buffer) override;

			/**
			 * @brief Binds a vertex decleration.
			 *
			 * @throws InvalidOperationException if the TWeakPtr is expired.
			 */
			Void BindVertexDecleration(TWeakPtr<AbstractVertexDecleration> vertex_decleration) override;

		public:
			/**
			 * @brief Unbinds a hardware buffer.
			 *
			 * @param buffer_type_mask[in] The hardware buffer type to unbind.
			 */
			Void UnbindHardwareBuffer(BufferTypeMask buffer_type_mask) override;

			/**
			 * @brief Unbinds a vertex decleration.
			 */
			Void UnbindVertexDecleration(Void) override;
		};

		FORGE_TYPEDEF_DECL(GLGraphicsContextState)

		FORGE_FORCE_INLINE GLGraphicsContextState::ConstGLContextLimits GLGraphicsContextState::GetContextLimits(Void) { return m_context_limits; }
	}
}

#endif
