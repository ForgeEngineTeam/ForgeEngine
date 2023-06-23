#include <GraphicsDevice/Public/OpenGL/GLGraphicsContextState.h>

namespace Forge {
	namespace Graphics
	{
		GLGraphicsContextState::GLGraphicsContextState(TSharedPtr<Window> window)
			: AbstractGraphicsContextState(window)
		{
			FORGE_GL_CHECK_ERROR(glGetIntegerv(GL_MAX_DRAW_BUFFERS, &m_context_limits.max_draw_buffers))
			FORGE_GL_CHECK_ERROR(glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &m_context_limits.max_renderbuffer_size))
			FORGE_GL_CHECK_ERROR(glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &m_context_limits.max_vertex_uniform_components))
			FORGE_GL_CHECK_ERROR(glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, &m_context_limits.max_fragment_uniform_components))
			FORGE_GL_CHECK_ERROR(glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_context_limits.max_combind_texture_image_units))

			InvalidateCache();
			InitializeCache();
		}

		Void GLGraphicsContextState::EnableDepthTest(Bool enable)
		{
			if (m_rasterizer_state.depth_state.is_enabled != enable)
			{
				if (enable)
				{
					FORGE_GL_CHECK_ERROR(glEnable(GL_DEPTH_TEST))
					m_rasterizer_state.depth_state.is_enabled = FORGE_TRUE;
				}
				else
				{
					FORGE_GL_CHECK_ERROR(glDisable(GL_DEPTH_TEST))
					m_rasterizer_state.depth_state.is_enabled = FORGE_FALSE;
				}
			}
		}
		Void GLGraphicsContextState::EnableStencilTest(Bool enable)
		{
			if (m_rasterizer_state.stencil_state.is_enabled != enable)
			{
				if (enable)
				{
					FORGE_GL_CHECK_ERROR(glEnable(GL_STENCIL_TEST))
					m_rasterizer_state.stencil_state.is_enabled = FORGE_TRUE;
				}
				else
				{
					FORGE_GL_CHECK_ERROR(glDisable(GL_STENCIL_TEST))
					m_rasterizer_state.stencil_state.is_enabled = FORGE_FALSE;
				}
			}
		}
		Void GLGraphicsContextState::EnableScissorTest(Bool enable)
		{
			if (m_rasterizer_state.scissor_state.is_enabled != enable)
			{
				if (enable)
				{
					FORGE_GL_CHECK_ERROR(glEnable(GL_SCISSOR_TEST))
					m_rasterizer_state.scissor_state.is_enabled = FORGE_TRUE;
				}
				else
				{
					FORGE_GL_CHECK_ERROR(glDisable(GL_SCISSOR_TEST))
					m_rasterizer_state.scissor_state.is_enabled = FORGE_FALSE;
				}
			}
		}
		Void GLGraphicsContextState::EnableFaceCulling(Bool enable)
		{
			if (m_rasterizer_state.face_culling_state.is_enabled != enable)
			{
				if (enable)
				{
					FORGE_GL_CHECK_ERROR(glEnable(GL_CULL_FACE))
					m_rasterizer_state.face_culling_state.is_enabled = FORGE_TRUE;
				}
				else
				{
					FORGE_GL_CHECK_ERROR(glDisable(GL_CULL_FACE))
					m_rasterizer_state.face_culling_state.is_enabled = FORGE_FALSE;
				}
			}
		}
		Void GLGraphicsContextState::EnableColorBlending(Bool enable)
		{
			if (m_rasterizer_state.color_blending_state.is_enabled != enable)
			{
				if (enable)
				{
					FORGE_GL_CHECK_ERROR(glEnable(GL_BLEND))
					m_rasterizer_state.color_blending_state.is_enabled = FORGE_TRUE;
				}
				else
				{
					FORGE_GL_CHECK_ERROR(glDisable(GL_BLEND))
					m_rasterizer_state.color_blending_state.is_enabled = FORGE_FALSE;
				}
			}
		}

		Bool GLGraphicsContextState::SetDepthWriteMask(Bool mask)
		{
			if (m_rasterizer_state.depth_state.is_enabled)
			{
				if (m_rasterizer_state.depth_state.write_mask != mask)
				{
					FORGE_GL_CHECK_ERROR(glDepthMask(mask))
					m_rasterizer_state.depth_state.write_mask = mask;
				}

				return FORGE_TRUE;
			}
			
			return FORGE_FALSE;
		}
		Bool GLGraphicsContextState::SetDepthComparisonFunction(ComparisonFuncMask function)
		{
			if (m_rasterizer_state.depth_state.is_enabled)
			{
				if (m_rasterizer_state.depth_state.comparison_function != function)
				{
					FORGE_GL_CHECK_ERROR(glDepthFunc(ConvertToGLCompareFunction(function)))
					m_rasterizer_state.depth_state.comparison_function = function;
				}

				return FORGE_TRUE;
			}
			
			FORGE_FALSE;
		}

		Bool GLGraphicsContextState::SetStencilWriteMask(Byte mask)
		{
			if (m_rasterizer_state.stencil_state.is_enabled)
			{
				if (m_rasterizer_state.stencil_state.write_mask != mask)
				{
					FORGE_GL_CHECK_ERROR(glStencilMask(mask))
					m_rasterizer_state.stencil_state.write_mask = mask;
				}

				return FORGE_TRUE;
			}

			return FORGE_FALSE;
			
		}
		Bool GLGraphicsContextState::SetStencilComparisonFunction(ComparisonFuncMask function, I32 ref, U32 mask)
		{
			if (m_rasterizer_state.stencil_state.is_enabled)
			{
				if (m_rasterizer_state.stencil_state.comparison_function != function)
				{
					FORGE_GL_CHECK_ERROR(glStencilFunc(ConvertToGLCompareFunction(function), ref, mask))
					m_rasterizer_state.stencil_state.comparison_function = function;
				}

				return FORGE_TRUE;
			}
			
			return FORGE_FALSE;
		}

		Bool GLGraphicsContextState::SetScissorBoundingRegion(I32 x, I32 y, I32 width, I32 height)
		{
			if (m_rasterizer_state.scissor_state.is_enabled)
			{
				if (m_rasterizer_state.scissor_state.bounding_region[0] != x     ||
					m_rasterizer_state.scissor_state.bounding_region[1] != y     ||
					m_rasterizer_state.scissor_state.bounding_region[2] != width ||
					m_rasterizer_state.scissor_state.bounding_region[3] != height)
				{
					FORGE_GL_CHECK_ERROR(glScissor(x, y, width, height))
					m_rasterizer_state.scissor_state.bounding_region[0] = x;
					m_rasterizer_state.scissor_state.bounding_region[1] = y;
					m_rasterizer_state.scissor_state.bounding_region[2] = width;
					m_rasterizer_state.scissor_state.bounding_region[3] = height;
				}

				return FORGE_TRUE;
			}

			return FORGE_FALSE;
		}

		Bool GLGraphicsContextState::SetFaceCullingMode(FaceCullMask mode)
		{
			if (m_rasterizer_state.face_culling_state.is_enabled)
			{
				if (m_rasterizer_state.face_culling_state.mode != mode)
				{
					FORGE_GL_CHECK_ERROR(glCullFace(mode == FaceCullMask::FORGE_BACK  ? GL_BACK  : 
						                            mode == FaceCullMask::FORGE_FRONT ? GL_FRONT : GL_FRONT_AND_BACK))
					m_rasterizer_state.face_culling_state.mode = mode;
				}

				return FORGE_TRUE;
			}

			return FORGE_FALSE;
		}
		
		Bool GLGraphicsContextState::SetColorBlendingConstant(F32 red, F32 green, F32 blue, F32 alpha)
		{
			if (m_rasterizer_state.color_blending_state.is_enabled)
			{
				if (m_rasterizer_state.color_blending_state.constant[0] != red   ||
					m_rasterizer_state.color_blending_state.constant[1] != green ||
					m_rasterizer_state.color_blending_state.constant[2] != blue  ||
					m_rasterizer_state.color_blending_state.constant[0] != alpha)
				{
					FORGE_GL_CHECK_ERROR(glBlendColor(red, green, blue, alpha))
					m_rasterizer_state.color_blending_state.constant[0] = red;
					m_rasterizer_state.color_blending_state.constant[1] = green;
					m_rasterizer_state.color_blending_state.constant[2] = blue;
					m_rasterizer_state.color_blending_state.constant[3] = alpha;
				}

				return FORGE_TRUE;
			}

			return FORGE_FALSE;
		}
		Bool GLGraphicsContextState::SetColorBlendingFunction(BlendFuncMask src_function, BlendFuncMask dst_function)
		{
			if (m_rasterizer_state.color_blending_state.is_enabled)
			{
				if (m_rasterizer_state.color_blending_state.src_function != src_function ||
					m_rasterizer_state.color_blending_state.dst_function != dst_function)
				{
					
					FORGE_GL_CHECK_ERROR(glBlendFunc(ConvertToGLBlendFunction(src_function), 
						                             ConvertToGLBlendFunction(dst_function)))
					m_rasterizer_state.color_blending_state.src_function = src_function;
					m_rasterizer_state.color_blending_state.dst_function = dst_function;
				}

				return FORGE_TRUE;
			}

			return FORGE_FALSE;
		}
		
		Void GLGraphicsContextState::SetLineWidth(F32 width)
		{
			if (m_rasterizer_state.line_width != width)
			{
				FORGE_GL_CHECK_ERROR(glLineWidth(width))
				m_rasterizer_state.line_width = width;
			}
		}
		Void GLGraphicsContextState::SetActiveTextureUnit(U32 index)
		{
			FORGE_NOT_IMPLEMENTED()
		}
		Void GLGraphicsContextState::SetFillMode(PolygonFillMask mode)
		{
			if (m_rasterizer_state.polygon_fill_mode != mode)
			{
				FORGE_GL_CHECK_ERROR(glPolygonMode(GL_FRONT_AND_BACK, mode == PolygonFillMask::FORGE_SOLID ? GL_FILL : GL_LINE))
				m_rasterizer_state.polygon_fill_mode = mode;
			}
		}
		Void GLGraphicsContextState::SetFrontFace(FrontFaceMask front_face)
		{
			if (m_rasterizer_state.front_face_mode != front_face)
			{
				FORGE_GL_CHECK_ERROR(glFrontFace(front_face == FrontFaceMask::FORGE_CW ? GL_CW : GL_CCW))
				m_rasterizer_state.front_face_mode = front_face;
			}
		}
		Void GLGraphicsContextState::SetPixelStorage(PixelStorageMask mode, I32 value)
		{
			FORGE_NOT_IMPLEMENTED()
		}
		Void GLGraphicsContextState::SetColorClear(F32 red, F32 green, F32 blue, F32 alpha)
		{
			if(m_rasterizer_state.color_clear[0] != red   ||
			   m_rasterizer_state.color_clear[1] != green ||
			   m_rasterizer_state.color_clear[2] != blue  ||
			   m_rasterizer_state.color_clear[3] != alpha)
			{
				FORGE_GL_CHECK_ERROR(glClearColor(red, green, blue, alpha))
				m_rasterizer_state.color_clear[0] = red;
				m_rasterizer_state.color_clear[1] = green;
				m_rasterizer_state.color_clear[2] = blue;
				m_rasterizer_state.color_clear[3] = alpha;
			}
		}
		Void GLGraphicsContextState::SetColorWriteMask(F32 red, F32 green, F32 blue, F32 alpha)
		{
			if (m_rasterizer_state.color_write_mask[0] != red   ||
				m_rasterizer_state.color_write_mask[1] != green ||
				m_rasterizer_state.color_write_mask[2] != blue  ||
				m_rasterizer_state.color_write_mask[3] != alpha)
			{
				FORGE_GL_CHECK_ERROR(glColorMask(red, green, blue, alpha))
				m_rasterizer_state.color_write_mask[0] = red;
				m_rasterizer_state.color_write_mask[1] = green;
				m_rasterizer_state.color_write_mask[2] = blue;
				m_rasterizer_state.color_write_mask[3] = alpha;
			}
		}

		Void GLGraphicsContextState::InitializeCache(Void)
		{
			if(m_rasterizer_state.depth_state.is_enabled)
				FORGE_GL_CHECK_ERROR(glEnable(GL_DEPTH_TEST))
			else 
				FORGE_GL_CHECK_ERROR(glDisable(GL_DEPTH_TEST))

			if (m_rasterizer_state.stencil_state.is_enabled)
				FORGE_GL_CHECK_ERROR(glEnable(GL_STENCIL_TEST))
			else
				FORGE_GL_CHECK_ERROR(glDisable(GL_STENCIL_TEST))

			if (m_rasterizer_state.scissor_state.is_enabled)
				FORGE_GL_CHECK_ERROR(glEnable(GL_SCISSOR_TEST))
			else
				FORGE_GL_CHECK_ERROR(glDisable(GL_SCISSOR_TEST))

			if(m_rasterizer_state.face_culling_state.is_enabled)
				FORGE_GL_CHECK_ERROR(glEnable(GL_CULL_FACE))
			else
				FORGE_GL_CHECK_ERROR(glDisable(GL_CULL_FACE))

			if (m_rasterizer_state.color_blending_state.is_enabled)
				FORGE_GL_CHECK_ERROR(glEnable(GL_BLEND))
			else
				FORGE_GL_CHECK_ERROR(glDisable(GL_BLEND))

			FORGE_GL_CHECK_ERROR(glDepthMask(m_rasterizer_state.depth_state.write_mask))
			FORGE_GL_CHECK_ERROR(glDepthFunc(ConvertToGLCompareFunction(m_rasterizer_state.stencil_state.comparison_function)))

			FORGE_GL_CHECK_ERROR(glStencilMask(m_rasterizer_state.stencil_state.write_mask))
			FORGE_GL_CHECK_ERROR(glStencilFunc(ConvertToGLCompareFunction(m_rasterizer_state.stencil_state.comparison_function), 0, ~((U32)0)))


			FORGE_GL_CHECK_ERROR(glScissor(m_rasterizer_state.scissor_state.bounding_region[0], 
				                           m_rasterizer_state.scissor_state.bounding_region[1],
				                           m_rasterizer_state.scissor_state.bounding_region[2], 
				                           m_rasterizer_state.scissor_state.bounding_region[3]))
			

			FORGE_GL_CHECK_ERROR(glCullFace(m_rasterizer_state.face_culling_state.mode == FaceCullMask::FORGE_BACK  ? GL_BACK  :
											m_rasterizer_state.face_culling_state.mode == FaceCullMask::FORGE_FRONT ? GL_FRONT : GL_FRONT_AND_BACK))


			FORGE_GL_CHECK_ERROR(glBlendColor(m_rasterizer_state.color_blending_state.constant[0], 
				                              m_rasterizer_state.color_blending_state.constant[1], 
				                              m_rasterizer_state.color_blending_state.constant[2], 
				                              m_rasterizer_state.color_blending_state.constant[3]))
			FORGE_GL_CHECK_ERROR(glBlendFunc(ConvertToGLBlendFunction(m_rasterizer_state.color_blending_state.src_function), 
				                             ConvertToGLBlendFunction(m_rasterizer_state.color_blending_state.dst_function)))

			FORGE_GL_CHECK_ERROR(glLineWidth(m_rasterizer_state.line_width))

			FORGE_GL_CHECK_ERROR(glPolygonMode(GL_FRONT_AND_BACK, m_rasterizer_state.polygon_fill_mode == PolygonFillMask::FORGE_SOLID ? GL_FILL : GL_LINE))
			
			FORGE_GL_CHECK_ERROR(glFrontFace(m_rasterizer_state.front_face_mode == FrontFaceMask::FORGE_CW ? GL_CW : GL_CCW))
			
			FORGE_GL_CHECK_ERROR(glClearColor(m_rasterizer_state.color_clear[0],
				                              m_rasterizer_state.color_clear[1],
				                              m_rasterizer_state.color_clear[2],
				                              m_rasterizer_state.color_clear[3]))

			FORGE_GL_CHECK_ERROR(glColorMask(m_rasterizer_state.color_write_mask[0],
				                             m_rasterizer_state.color_write_mask[1],
				                             m_rasterizer_state.color_write_mask[2],
				                             m_rasterizer_state.color_write_mask[3]))
		}
		Void GLGraphicsContextState::InvalidateCache(Void)
		{
			FORGE_GL_CHECK_ERROR(glUseProgram(0))

			FORGE_GL_CHECK_ERROR(glBindVertexArray(0))

			FORGE_GL_CHECK_ERROR(glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0))
			FORGE_GL_CHECK_ERROR(glBindFramebuffer(GL_READ_FRAMEBUFFER, 0))
			
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_ARRAY_BUFFER,         0))
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0))
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_READ_BUFFER,     0))
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_WRITE_BUFFER,    0))

			m_active_buffers.Clear();

			m_active_texture            = (U32)0;
			m_active_gpu_program        = (U32)0;
			m_active_read_framebuffer   = (U32)0;
			m_active_write_framebuffer  = (U32)0;
			m_active_vertex_decleration = (U32)0;

			m_rasterizer_state.depth_state.is_enabled          = true;
			m_rasterizer_state.stencil_state.is_enabled        = false;
			m_rasterizer_state.scissor_state.is_enabled        = false;
			m_rasterizer_state.face_culling_state.is_enabled   = true;
			m_rasterizer_state.color_blending_state.is_enabled = true;

			m_rasterizer_state.depth_state.write_mask          = 0xFF;
			m_rasterizer_state.depth_state.comparison_function = ComparisonFuncMask::FORGE_LESS;

			m_rasterizer_state.stencil_state.write_mask          = 0xFF;
			m_rasterizer_state.stencil_state.comparison_function = ComparisonFuncMask::FORGE_ALWAYS;

			m_rasterizer_state.scissor_state.bounding_region[0] = 0;
			m_rasterizer_state.scissor_state.bounding_region[1] = 0;
			m_rasterizer_state.scissor_state.bounding_region[2] = m_window->GetClientSize().x;
			m_rasterizer_state.scissor_state.bounding_region[3] = m_window->GetClientSize().y;

			m_rasterizer_state.face_culling_state.mode = FaceCullMask::FORGE_BACK;

			m_rasterizer_state.color_blending_state.constant[0]  = 0.0f;
			m_rasterizer_state.color_blending_state.constant[1]  = 0.0f;
			m_rasterizer_state.color_blending_state.constant[2]  = 0.0f;
			m_rasterizer_state.color_blending_state.constant[3]  = 0.0f;
			m_rasterizer_state.color_blending_state.src_function = BlendFuncMask::FORGE_SRC_ALPHA;
			m_rasterizer_state.color_blending_state.dst_function = BlendFuncMask::FORGE_ONE_MINUS_SRC_ALPHA;

			m_rasterizer_state.line_width = 1.0f;

			m_rasterizer_state.front_face_mode = FrontFaceMask::FORGE_CW;

			m_rasterizer_state.polygon_fill_mode = PolygonFillMask::FORGE_SOLID;

			m_rasterizer_state.color_clear[0] = 0.0f;
			m_rasterizer_state.color_clear[1] = 0.0f;
			m_rasterizer_state.color_clear[2] = 0.0f;
			m_rasterizer_state.color_clear[3] = 0.0f;

			m_rasterizer_state.color_write_mask[0] = 0xFF;
			m_rasterizer_state.color_write_mask[1] = 0xFF;
			m_rasterizer_state.color_write_mask[2] = 0xFF;
			m_rasterizer_state.color_write_mask[3] = 0xFF;
		}

		Void GLGraphicsContextState::BindHardwareBuffer(TWeakPtr<AbstractHardwareBuffer> hardware_buffer)
		{
			if(hardware_buffer.IsExpired())
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			U32 new_id = hardware_buffer.Lock()->GetNativeHandle().m_id_num;
			U32 old_id = this->m_active_buffers[static_cast<Size>(hardware_buffer.Lock()->GetBufferType())].m_id_num;

			if (new_id != old_id)
			{
				this->m_active_buffers[static_cast<Size>(hardware_buffer.Lock()->GetBufferType())] = new_id;

				FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(hardware_buffer.Lock()->GetBufferType()), new_id))
			}
			
		}
		Void GLGraphicsContextState::BindVertexDecleration(TWeakPtr<AbstractVertexDecleration> vertex_decleration)
		{
			if (vertex_decleration.IsExpired())
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

			U32 new_id = vertex_decleration.Lock()->GetNativeHandle().m_id_num;

			if(new_id != m_active_vertex_decleration.m_id_num)
			{
				m_active_vertex_decleration.m_id_num = new_id;

				FORGE_GL_CHECK_ERROR(glBindVertexArray(new_id))
			}
		}

		Void GLGraphicsContextState::UnbindHardwareBuffer(BufferTypeMask buffer_type_mask)
		{
			if (m_active_buffers[static_cast<Size>(buffer_type_mask)])
			{
				m_active_buffers[static_cast<Size>(buffer_type_mask)].m_id_num = 0;
				FORGE_GL_CHECK_ERROR(glBindBuffer(1, 0));
			}

		}
		Void GLGraphicsContextState::UnbindVertexDecleration(Void)
		{
			if (m_active_vertex_decleration)
			{
				m_active_vertex_decleration.m_id_num = 0;
				FORGE_GL_CHECK_ERROR(glBindVertexArray(0));
			}
		}
	}
}
