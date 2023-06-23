#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include <stdlib.h>

#include "MemoryUtilities.h"
#include "AbstractAllocator.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

namespace Forge {
	namespace Memory
	{
		/**
		 * @brief Manages memory in stack-like behaviour, however unlike the linear
		 * allocator follows LIFO principle.
		 * 
		 * The stack allocator constrains allocations from being performed in a
		 * random order, and only allocates chunks right on top of the previously
		 * allocated chunks. The stack allocator only allows reallocation and
		 * deallocations to the most recent address allocated, enforcing the LIFO
		 * principle.
		 * 
		 * @author Karim Hisham
		 */
		class FORGE_API StackAllocator : public AbstractAllocator
		{
		private:
			struct AllocationHeader
			{
				Byte m_padding;
			};


		private:
			VoidPtr m_offset_ptr;
			VoidPtr m_prev_address;

		public:
			StackAllocator(Size total_size);
			StackAllocator(VoidPtr start, Size total_size);

		public:
		   ~StackAllocator();

		public:
			/**
			 * @brief Retrieves a properly aligned memory address from the
			 * pre-allocated memory pool.
			 *
			 * @param[in] size      The size of chunk to retrieve in bytes.
			 * @param[in] alignment The alignment of memory, must be power of two.
			 *
			 * @return VoidPtr storing the address to start of the allocated chunk.
			 *
			 * @throws BadAllocationException if size requsted is larger than the
			 * memory pool.
			 */
			VoidPtr Allocate(Size size, Byte alignment = 4) override;

			/**
			 * @brief Resizes the most recent address allocated to a new size and 
			 * copies its content to the new chunk.
			 *
			 * @param[in] address   The address of the chunk to resize.
			 * @param[in] size      The new size of the chunk to reallocate in bytes.
			 * @param[in] alignment The Alignment of memory, must be power of two.
			 *
			 * @returns VoidPtr storing the address to the start of the reallocated
			 * chunk.
			 *
			 * @throws InvalidOperationException if address is not the most 
			 * recently allocated.
			 *
			 * @throws BadAllocationException if size requsted is larger than the
			 * memory pool.
			 *
			 * @throws MemoryOutOfBoundsException if the address provided is out
			 * of the memory pool bounds.
			 */
			VoidPtr Reallocate(VoidPtr address, Size size, Byte alignment = 4) override;

			/**
			 * @brief Frees the most recent address previously allocated from the 
			 * pre-allocated memory pool.
			 *
			 * @param[in] address The address of the chunk to free.
			 *
			 * @throws InvalidOperationException if address is not the most 
			 * recently allocated.
			 *
			 * @throws BadAllocationException if the address was not previously
			 * allocated.
			 *
			 * @throws MemoryOutOfBoundsException if the address provided is out
			 * of the memory pool bounds.
			 */
			Void  Deallocate(VoidPtr address) override;

		public:
			/**
			 * @brief Resets the whole memory pool.
			 */
			Void  Reset(void) override;
		};
	}
}

#endif // STACK_ALLOCATOR_H
