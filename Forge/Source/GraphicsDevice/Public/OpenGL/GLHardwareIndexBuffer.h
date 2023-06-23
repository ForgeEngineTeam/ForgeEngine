#ifndef GL_HARDWARE_INDEX_BUFFER_H
#define GL_HARDWARE_INDEX_BUFFER_H

#include <Core/Public/Common/Common.h>

#include <GraphicsDevice/Public/OpenGL/GLHardwareBuffer.h>

namespace Forge {
	namespace Graphics
	{
		class GLHardwareIndexBuffer final : public GLHardwareBuffer
		{
		private:
			Size m_index_size;
			Size m_index_count;

		public:
			/**
			 * @brief Default constructor.
			 */
			GLHardwareIndexBuffer(ValueTypeMask index_type_mask, Size index_count,
				UsageModeMask usage_mode_mask = UsageModeMask::FORGE_GPU_ONLY, Bool is_shadowed = FORGE_FALSE);

		public:
			/**
			 * @brief Default destructor.
			 */
			~GLHardwareIndexBuffer(Void) = default;

		public:
			/**
			 * @brief Gets the size of a single vertex in the vertex buffer in
			 * bytes.
			 *
			 * @returns Size storing size of a single vertex in the vertex buffer
			 * in bytes.
			 */
			Size GetIndexSize(Void) const;

			/**
			 * @brief Gets the number of vertices in the vertex buffer.
			 *
			 * @returns Size storing the number of vertex in the vertex buffer.
			 */
			Size GetIndexCount(Void) const;

		};

		FORGE_TYPEDEF_DECL(GLHardwareIndexBuffer)
		
		FORGE_FORCE_INLINE GLHardwareIndexBuffer::GLHardwareIndexBuffer(ValueTypeMask index_type_mask, Size index_count, UsageModeMask usage_mode_mask, Bool is_shadowed)
			: GLHardwareBuffer(0, usage_mode_mask, BufferTypeMask::FORGE_INDEX_BUFFER, is_shadowed), 
			  m_index_size(ConvertToGLValueType(index_type_mask)),
			  m_index_count(index_count) 
		{
			m_size = m_index_size * m_index_count;
		}

		FORGE_FORCE_INLINE Size GLHardwareIndexBuffer::GetIndexSize(Void) const
		{
			return m_index_size;
		}
		FORGE_FORCE_INLINE Size GLHardwareIndexBuffer::GetIndexCount(Void) const
		{
			return m_index_count;
		}
	}
}

#endif // GL_HARDWARE_INDEX_BUFFER_H

