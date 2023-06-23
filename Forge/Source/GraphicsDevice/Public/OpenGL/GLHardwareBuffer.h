#ifndef GL_HARDWARE_BUFFER_H
#define GL_HARDWARE_BUFFER_H

#include <Core/Public/Common/Common.h>
#include <Core/Public/Memory/MemoryUtilities.h>

#include <GraphicsDevice/Public/OpenGL/GL/gl.h>
#include <GraphicsDevice/Public/OpenGL/GLUtilities.h>
#include <GraphicsDevice/Public/Base/AbstractHardwareBuffer.h>

using namespace Forge::Memory;

namespace Forge {
	namespace Graphics
	{
		class FORGE_API GLHardwareBuffer : public AbstractHardwareBuffer
		{
		public:
			/**
			 * @brief Default constructor.
			 */
			GLHardwareBuffer(Size size, UsageModeMask usage_mode_mask, BufferTypeMask buffer_type_mask, Bool is_shadowed);

		public:
			/**
			 * @brief Default constructor.
			 */
			virtual ~GLHardwareBuffer(Void);

		public:
			/**
			 * @brief Locks the hardware buffer by mapping it to client address
			 * space for potentially reading and/or writing.
			 *
			 * @param lock_mode[in] The lock mode of the hardware buffer.
			 *
			 * @returns VoidPtr storing the starting address of the hardware
			 * buffer data.
			 * 
			 * @throws MemoryOutOfBoundsException if the offset combined with the
			 * length is out of bounds of the memory region.
			 */
			VoidPtr Lock(LockModeFlags lock_mode) override;

			/**
			 * @brief Locks the hardware buffer by mapping it to client address
			 * space for potentially reading and/or writing.
			 *
			 * @param offset[in]    The byte offset from the start of the hardware buffer.
			 * @param length[in]    The size of the data to read in bytes.
			 * @param lock_mode[in] The lock mode of the hardware buffer.
			 *
			 * @returns VoidPtr storing the starting address of the hardware
			 * buffer data.
			 * 
			 * @throws MemoryOutOfBoundsException if the offset combined with the
			 * length is out of bounds of the memory region.
			 */
			VoidPtr Lock(Size offset, Size length, LockModeFlags lock_mode) override;

		public:
			/**
			 * @brief Unlocks the hardware buffer by unmapping it from client
			 * address space.
			 *
			 * @returns True if unmapping operation was succesful, otherwise
			 * false.
			 */
			Bool Unlock(Void) override;

		public:
			/**
			 * @brief Reads data from the hardware buffer and places it in an area
			 * of system memory.
			 *
			 * The area of system memory must be large enough to contain the
			 * hardware buffer data, otherwise undefined behaviour might occur.
			 *
			 * @param dst[out]   The area of system memory data to be read from.
			 * @param offset[in] The byte offset from the start of the hardware buffer.
			 * @param length[in] The size of the data to read in bytes.
			 * 
			 * @throws MemoryOutOfBoundsException if the offset combined with the
			 * length is out of bounds of the memory region.
			 */
			Void ReadData(VoidPtr dst, Size offset, Size length) override;

			/**
			 * @brief Writes data to the hardware buffer from an area of system
			 * memory.
			 *
			 * The hardware buffer must be large enough to contain the system area
			 * data, otherwise undefined behaviour might occur.
			 *
			 * @param src[in]    The area of system memory data to be written.
			 * @param offset[in] The byte offset from the start of the hardware buffer.
			 * @param length[in] The size of the data to write in bytes.
			 * 
			 * @throws MemoryOutOfBoundsException if the offset combined with the
			 * length is out of bounds of the memory region.
			 */
			Void WriteData(VoidPtr src, Size offset, Size length) override;

			/**
			 * @brief Copys data from the hardware buffer and places it in another
			 * hardware buffer.
			 *
			 * @param src[in]        The hardware buffer to copy data from.
			 * @param src_offset[in] The byte offset from the start of the source buffer.
			 * @param dst_offset[in] The byte offset from the start of the destination buffer.
			 * @param length[in]     The size of the data to copy in bytes.
			 * 
			 * @throws MemoryOutOfBoundsException if the length passed is larger
			 * than the size of the buffer or if the offset combined with the
			 * length is out of bounds of the memory region.
			 */
			Void CopyData(AbstractHardwareBufferRef src, Size src_offset, Size dst_offset, Size length) override;
		};

		FORGE_TYPEDEF_DECL(GLHardwareBuffer)
	}
}

#endif // GL_HARDWARE_BUFFER_H
