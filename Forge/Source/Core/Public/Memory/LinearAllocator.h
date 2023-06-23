#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include <stdlib.h>

#include "MemoryUtilities.h"
#include "AbstractAllocator.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

namespace Forge {
	namespace Memory
	{
		/**
		 * @brief Manages memory in a stack-like behaviour.
		 * 
		 * The linear allocator constrains allocations from being performed in a
		 * random order, and only allocates chunks right on top of the previously
		 * allocated chunks. The linear allocator also prevents reallocation and
		 * deallocation of memory chunks. 
		 * 
		 * To free memory, the entire memory pool must be reset. This makes the
		 * linear allocator useful for single-frame allocations.
		 *
		 * @author Karim Hisham
		 */
		class FORGE_API LinearAllocator : public AbstractAllocator
		{
		private:
			VoidPtr m_offset_ptr;

		public:
			LinearAllocator(Size total_size);
			LinearAllocator(VoidPtr start, Size total_size);

		public:
		   ~LinearAllocator();

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
			 * @brief The linear allocator does not support reallocations to        
			 * previously allocated memory chunks.
			 *
			 * @throws InvalidOperationException if attempted to reallocate an  
			 * address.
			 */
			VoidPtr Reallocate(VoidPtr address, Size Size, Byte alignment = 4) override;

			/**
			 * @brief The linear allocator does not support deallocations to
			 * previously allocated memory chunks.
			 *
			 * @throws InvalidOperationException if attempted to deallocate an
			 * address.
			 */
			Void Deallocate(VoidPtr address) override;

		public:
			/**
			 * @brief Resets the whole memory pool.
			 * 
			 * This function sets the entire allocated memory pool to zeros.
			 */
			Void Reset(void) override;
		};
	}
}

#endif // LINEAR_ALLOCATOR_H
