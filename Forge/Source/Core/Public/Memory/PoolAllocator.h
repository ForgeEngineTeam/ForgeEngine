#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stdlib.h>

#include "MemoryUtilities.h"
#include "AbstractAllocator.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

namespace Forge {
	namespace Memory
	{
		/**
		 * @brief Manages memory in fixed-size chunks and doest not impose any
		 * constraints 
		 * 
		 */
		class FORGE_API PoolAllocator : public AbstractAllocator
		{
		private:
			VoidPtr* m_head;

		private:
			Size m_chunk_size;

		public:
			PoolAllocator(Size chunk_size, Size capacity);
			PoolAllocator(VoidPtr start, Size chunk_size, Size capacity);

		public:
		   ~PoolAllocator();

		public:
			/**
			 * @brief Gets the maximum chunk size the pool allocator is capable of
			 * allocation.
			 * 
			 * @return Size storing the chunk size in bytes.
			 */
			Size GetChunktSize(void);

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
			 * @brief The pool allocator does not allow reallocations to previously
			 * allocated memory chunks.
			 *
			 * @throws InvalidOperationException if attempted to reallocate an
			 * address.
			 */
			VoidPtr Reallocate(VoidPtr address, Size size, Byte alignment = 4) override;

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
			Void Deallocate(VoidPtr address) override;

		public:
			/**
			 * @brief Resets the whole memory pool.
			 */
			Void  Reset(void) override;
		};

		FORGE_FORCE_INLINE Size PoolAllocator::GetChunktSize(void) { return m_chunk_size; }
	}
}

#endif // POOL_ALLOCATOR_H
