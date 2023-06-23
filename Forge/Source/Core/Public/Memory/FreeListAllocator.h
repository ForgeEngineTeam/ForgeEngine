#ifndef FREE_LIST_ALLOCATOR_H
#define FREE_LIST_ALLOCATOR_H

#include <stdlib.h>

#include "MemoryUtilities.h"
#include "AbstractAllocator.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

namespace Forge {
	namespace Memory
	{
		class FORGE_API FreeListAllocator : public AbstractAllocator
		{
		private:
			struct AllocationHeader
			{
				Byte m_padding;
				Size m_alloc_size;
			};

			struct FreeBlockNode
			{
				Size m_block_size;
				FreeBlockNode* m_link;
			};

		private:
			FreeBlockNode* m_free_list;

		public:
			/**
			 * @brief Constructs a free list allocator object.
			 * 
			 * The free list allocator object will allocate a memory pool that will
			 * be owned and managed by it.
			 * 
			 * @param[in] capacity Size of the memory pool in bytes.
			 */
			FreeListAllocator(Size capacity);

			/**
			 * @brief Constructs a free list allocator object.
			 * 
			 * The free list allocater is supplied a pre-allocated memory pool that
			 * is managed by another object.
			 * 
			 * @oaram[in] start Address of start of the pre-allocated memory pool.
			 * @param[in] capacity Size of the memory pool in bytes.
			 */
			FreeListAllocator(VoidPtr start, Size capacity);

		public:
			~FreeListAllocator();

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
			VoidPtr Allocate(Size size, Byte alignment = 4);

			/**
			 * @brief Resizes an allocated address to a new size and copies its
			 * content to the new chunk.
			 *
			 * @param[in] address   The address of the chunk to resize.
			 * @param[in] size      The new size of the chunk to reallocate in bytes.
			 * @param[in] alignment The Alignment of memory, must be power of two.
			 *
			 * @returns VoidPtr storing the address to the start of the reallocated
			 * chunk.
			 *
			 * @throws BadAllocationException if size requsted is larger than the
			 * memory pool.
			 *
			 * @throws MemoryOutOfBoundsException if the address provided is out
			 * of the memory pool bounds.
			 */
			VoidPtr Reallocate(VoidPtr address, Size size, Byte alignment = 4);

			/**
			 * @brief Frees the address previously allocated from the pre-allocated
			 * memory pool.
			 *
			 * @param[in] address The address of the chunk to free.
			 *
			 * @throws BadAllocationException if the address was not previously
			 * allocated.
			 *
			 * @throws MemoryOutOfBoundsException if the address provided is out
			 * of the memory pool bounds.
			 */
			Void Deallocate(VoidPtr address);

		public:
			/**
			 * @brief Resets the whole memory pool.
			 *
			 * This function sets the entire allocated memory pool to zeros.
			 */
			Void Reset(void);
		};
	}
}

#endif
