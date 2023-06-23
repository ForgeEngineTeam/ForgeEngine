#ifndef ABSTRACT_HARDWARE_BUFFER_H
#define ABSTRACT_HARDWARE_BUFFER_H

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Types/TMemoryRegion.h>
#include <Core/Public/Algorithm/GeneralUtilities.h>

#include <GraphicsDevice/Public/GraphicsTypes.h>
#include <GraphicsDevice/Public/GraphicsObject.h>

using namespace Forge::Debug;
using namespace Forge::Common;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Abstract class defining common features of hardware buffers.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API AbstractHardwareBuffer : public GraphicsObject
		{
		protected:
			Size m_size;
			Size m_lock_offset;
			Size m_lock_length;

		protected:
			Bool m_is_locked;
			Bool m_is_shadowed;

		protected:
			UsageModeMask m_usage_mode_mask;
			BufferTypeMask m_buffer_type_mask;

		protected:
			TMemoryRegion<Byte> m_shadow_buffer;

		public:
			/**
			 * @brief Default constructor.
			 */
			AbstractHardwareBuffer(Size size, UsageModeMask usage_mode_mask, BufferTypeMask buffer_type_mask, Bool is_shadowed);

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~AbstractHardwareBuffer(Void) = default;

		public:
			/**
			 * @Checks wether the hardware buffer is locked or not.
			 *
			 * @returns True if locked, otherwise false.
			 */
			Bool IsLocked(Void) const;

			/**
			 * @brief Checks wether the hardware buffer has a shadow buffer or not.
			 *
			 * @returns True if hardware buffer is shadowed, otherwise false.
			 */
			Bool IsShadowed(Void) const;

		public:
			/**
			 * @brief Gets the size of the hardware buffer in bytes.
			 * 
			 * @returns Size storing the size of the hardware buffer in bytes. 
			 */
			Size GetSize(Void) const;

			/**
			 * @brief Gets the usage mode of the hardware buffer.
			 * 
			 * @returns UsageModeMask storing the usage mode of the hardware
			 * buffer. 
			 */
			UsageModeMask GetUsageMode(Void) const;

			/**
			 * @brief Gets the hardware buffer type.
			 *
			 * @returns BufferTypeMask storing the hardware buffer type.
			 */
			BufferTypeMask GetBufferType(Void) const;

			/**
			 * @brief Gets the shadow buffer of the hardware buffer.
			 *
			 * @returns TMemoryRegion storing the data of the hardware buffer
			 * in system memory.
			 */
			TMemoryRegion<Byte> GetShadowBuffer(Void);

			/**
			 * @brief Gets the shadow buffer of the hardware buffer.
			 * 
			 * @returns ConstTMemoryRegion storing the data of the hardware buffer
			 * in system memory.
			 */
			ConstTMemoryRegion<Byte> GetConstShadowBuffer(Void) const;

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
			virtual VoidPtr Lock(LockModeFlags lock_mode) = 0;

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
			virtual VoidPtr Lock(Size offset, Size length, LockModeFlags lock_mode) = 0;

		public:
			/**
			 * @brief Unlocks the hardware buffer by unmapping it from client
			 * address space.
			 * 
			 * @returns True if unmapping operation was succesful, otherwise
			 * false.
			 */
			virtual Bool Unlock(Void) = 0;

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
			virtual Void ReadData(VoidPtr dst, Size offset, Size length) = 0;

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
			virtual Void WriteData(VoidPtr src, Size offset, Size length) = 0;

			/**
			 * @brief Copys data from the hardware buffer and places it in another
			 * hardware buffer.
			 *
			 * Both hardware buffers must be equal in size, otherwise undefined 
			 * behaviour might occur.
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
			virtual Void CopyData(AbstractHardwareBuffer& src, Size src_offset, Size dst_offset, Size length) = 0;
		};

		FORGE_TYPEDEF_DECL(AbstractHardwareBuffer)

		FORGE_FORCE_INLINE AbstractHardwareBuffer::AbstractHardwareBuffer(Size size, UsageModeMask usage_mode_mask, BufferTypeMask buffer_type_mask, Bool is_shadowed)
			: m_size(size), 
			  m_lock_offset(0), 
			  m_lock_length(0), 
			  m_is_locked(false), 
			  m_is_shadowed(is_shadowed), 
			  m_usage_mode_mask(usage_mode_mask), 
			  m_buffer_type_mask(buffer_type_mask)
		{
			if (m_is_shadowed && m_usage_mode_mask == UsageModeMask::FORGE_GPU_TO_CPU)
				m_usage_mode_mask = UsageModeMask::FORGE_GPU_ONLY;
		}
		
		FORGE_FORCE_INLINE Bool AbstractHardwareBuffer::IsLocked(Void) const
		{
			return m_is_locked;
		}
		FORGE_FORCE_INLINE Bool AbstractHardwareBuffer::IsShadowed(Void) const
		{
			return m_is_shadowed;
		}

		FORGE_FORCE_INLINE Size AbstractHardwareBuffer::GetSize(Void) const
		{ 
			return m_size; 
		}
		FORGE_FORCE_INLINE UsageModeMask AbstractHardwareBuffer::GetUsageMode(Void) const
		{ 
			return m_usage_mode_mask; 
		}
		FORGE_FORCE_INLINE BufferTypeMask AbstractHardwareBuffer::GetBufferType(Void) const
		{
			return m_buffer_type_mask;
		}
		FORGE_FORCE_INLINE TMemoryRegion<Byte> AbstractHardwareBuffer::GetShadowBuffer(Void) 
		{ 
			return m_shadow_buffer; 
		}
		FORGE_FORCE_INLINE ConstTMemoryRegion<Byte> AbstractHardwareBuffer::GetConstShadowBuffer(Void) const
		{
			return m_shadow_buffer;
		}
	}
}

#endif // ABSTRACT_HARDWARE_BUFFER_H
