#include <GraphicsDevice/Public/OpenGL/GLHardwareBuffer.h>

namespace Forge {
	namespace Graphics
	{
		GLHardwareBuffer::GLHardwareBuffer(Size size, UsageModeMask usage_mode_mask, BufferTypeMask buffer_type_mask, Bool is_shadowed)
			: AbstractHardwareBuffer(size, usage_mode_mask, buffer_type_mask, is_shadowed)
		{
			if (m_is_shadowed)
				m_shadow_buffer = Move(TMemoryRegion<Byte>(new Byte[size], size));

			FORGE_GL_CHECK_ERROR(glGenBuffers(1, &m_handle.m_id_num))

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(glBufferData(ConvertToGLBufferType(m_buffer_type_mask), m_size, nullptr, ConvertToGLBufferUsage(m_usage_mode_mask)))

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), 0));
		}

		GLHardwareBuffer::~GLHardwareBuffer(Void)
		{
			m_shadow_buffer.Reset();
		}

		VoidPtr GLHardwareBuffer::Lock(LockModeFlags lock_mode)
		{
			return Lock(0, m_size, lock_mode);
		}
		VoidPtr GLHardwareBuffer::Lock(Size offset, Size length, LockModeFlags lock_mode)
		{
			if (offset + length > m_size)
				FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

			GLenum gl_lock_mode = 0;
			
			VoidPtr buffer = nullptr;

			if (lock_mode & LockModeFlags::FORGE_WRITE_ONLY)
			{
				gl_lock_mode |= GL_MAP_WRITE_BIT;

				if (lock_mode & LockModeFlags::FORGE_DISCARD)
					gl_lock_mode |= GL_MAP_INVALIDATE_BUFFER_BIT;
			}
			
			if((lock_mode & LockModeFlags::FORGE_READ_ONLY) && !(lock_mode & LockModeFlags::FORGE_DISCARD))
				gl_lock_mode |= GL_MAP_READ_BIT;
			
			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(buffer = glMapBufferRange(ConvertToGLBufferType(m_buffer_type_mask), offset, length, gl_lock_mode))

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), 0))

			return buffer;
		}

		Bool GLHardwareBuffer::Unlock(Void)
		{
			GLboolean result;

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(result = glUnmapBuffer(ConvertToGLBufferType(m_buffer_type_mask)))

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), 0))

			return result;
		}

		Void GLHardwareBuffer::ReadData(VoidPtr dst, Size offset, Size length)
		{
			if (offset + length > m_size)
				FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

			if (m_is_shadowed)
			{
				MemoryCopy(dst, m_shadow_buffer.GetPointer() + offset, length);
				return;
			}

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(glGetBufferSubData(ConvertToGLBufferType(m_buffer_type_mask), offset, length, dst));

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), 0))
		}
		Void GLHardwareBuffer::WriteData(VoidPtr src, Size offset, Size length)
		{
			if (offset + length > m_size)
				FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

			if (m_is_shadowed)
				MemoryCopy(m_shadow_buffer.GetPointer() + offset, src, length);
			
			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(glBufferSubData(ConvertToGLBufferType(m_buffer_type_mask), offset, length, src));

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), 0))
		}
		Void GLHardwareBuffer::CopyData(AbstractHardwareBufferRef src, Size src_offset, Size dst_offset, Size length)
		{
			if (dst_offset + length > m_size)
				FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

			if (src_offset + length > src.GetSize())
				FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

			if (m_is_shadowed)
				MemoryCopy(m_shadow_buffer.GetPointer() + dst_offset, src.GetShadowBuffer().GetPointer() + src_offset, length);

			FORGE_GL_CHECK_ERROR(glBindBuffer(ConvertToGLBufferType(m_buffer_type_mask), m_handle.m_id_num))
			FORGE_GL_CHECK_ERROR(glBufferData(ConvertToGLBufferType(m_buffer_type_mask), length, nullptr, ConvertToGLBufferUsage(m_usage_mode_mask)))

			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_READ_BUFFER, src.GetNativeHandle().m_id_num))
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_WRITE_BUFFER, m_handle.m_id_num))

			FORGE_GL_CHECK_ERROR(glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, src_offset, dst_offset, length));

			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_READ_BUFFER, 0))
			FORGE_GL_CHECK_ERROR(glBindBuffer(GL_COPY_WRITE_BUFFER, 0))
		}
	}
}
