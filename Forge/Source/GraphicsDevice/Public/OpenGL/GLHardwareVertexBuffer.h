#ifndef GL_HARDWARE_VERTEX_BUFFER_H
#define GL_HARDWARE_VERTEX_BUFFER_H

#include <Core/Public/Common/Common.h>

#include <GraphicsDevice/Public/OpenGL/GLHardwareBuffer.h>

namespace Forge {
	namespace Graphics
	{
		class GLHardwareVertexBuffer final : public GLHardwareBuffer
		{
		private:
			Bool m_is_instanced;

		private:
			Size m_vertex_size;
			Size m_vertex_count;
			Size m_vertex_instance_step_rate;

		public:
			/**
			 * @brief Default constructor.
			 */
			GLHardwareVertexBuffer(Size vertex_size, Size vertex_count, 
				UsageModeMask usage_mode_mask = UsageModeMask::FORGE_GPU_ONLY, Bool is_shadowed = FORGE_FALSE);

		public:
			/**
			 * @brief Default destructor.
			 */
			~GLHardwareVertexBuffer(Void) = default;

		public:
			/**
			 * @brief Checks if the vertex buffer is an instanced buffer.
			 *
			 * @returns True if the vertex buffer is an instanced buffer,
			 * otherwise false.
			 */
			Bool IsInstanced(Void) const;

		public:
			/**
			 * @brief Gets the size of a single vertex in the vertex buffer in
			 * bytes.
			 *
			 * @returns Size storing size of a single vertex in the vertex buffer
			 * in bytes.
			 */
			Size GetVertexSize(Void) const;

			/**
			 * @brief Gets the number of vertices in the vertex buffer.
			 *
			 * @returns Size storing the number of vertex in the vertex buffer.
			 */
			Size GetVertexCount(Void) const;

			/**
			 * @brief Gets the number of instances to draw using the same
			 * per-instance data before advancing in the vertex buffer.
			 *
			 * @returns Size storing the number of instances to draw using the
			 * same per-instance data.
			 */
			Size GetVertexInstanceStepRate(Void) const;

		public:
			/**
			 * @brief Sets wehther the vertex buffer is instanced or not.
			 * 
			 * @param is_instanced[in] The flag wether the vertex buffer is
			 * instanced or not.
			 */
			Void SetIsInstanced(Bool is_instanced);

			/**
			 * @brief Sets the number of instances to draw using the same
			 * per-instance data before advancing in the vertex buffer.
			 *
			 * @param vertex_instance_step_rate[in] The step rate of instances to
			 * draw using the same per-instance data.
			 */
			Void SetVertexInstanceStepRate(Size vertex_instance_step_rate);
		};

		FORGE_TYPEDEF_DECL(GLHardwareVertexBuffer)

		FORGE_FORCE_INLINE GLHardwareVertexBuffer::GLHardwareVertexBuffer(Size vertex_size, Size vertex_count, UsageModeMask usage_mode_mask, Bool is_shadowed)
				: GLHardwareBuffer(vertex_size * vertex_count, usage_mode_mask, BufferTypeMask::FORGE_VERTEX_BUFFER, is_shadowed), 
			      m_vertex_size(vertex_size), 
			      m_vertex_count(vertex_count) {}

		FORGE_FORCE_INLINE Bool GLHardwareVertexBuffer::IsInstanced(Void) const
		{
			return m_is_instanced;
		}

		FORGE_FORCE_INLINE Size GLHardwareVertexBuffer::GetVertexSize(Void) const
		{
			return m_vertex_size;
		}
		FORGE_FORCE_INLINE Size GLHardwareVertexBuffer::GetVertexCount(Void) const
		{
			return m_vertex_count;
		}
		FORGE_FORCE_INLINE Size GLHardwareVertexBuffer::GetVertexInstanceStepRate(Void) const
		{
			return m_vertex_instance_step_rate;
		}

		FORGE_FORCE_INLINE Void GLHardwareVertexBuffer::SetIsInstanced(Bool is_instanced)
		{
			m_is_instanced = is_instanced;
		}
		FORGE_FORCE_INLINE Void GLHardwareVertexBuffer::SetVertexInstanceStepRate(Size vertex_instance_step_rate)
		{
			if (m_is_instanced)
				m_vertex_instance_step_rate = vertex_instance_step_rate;
		}
	}
}

#endif // GL_HARDWARE_VERTEX_BUFFER_H
