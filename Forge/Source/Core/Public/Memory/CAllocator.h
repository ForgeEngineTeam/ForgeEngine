#ifndef C_ALLOCATOR_H
#define C_ALLOCATOR_H

#include <stdlib.h>

#include "MemoryUtilities.h"
#include "AbstractAllocator.h"

namespace Forge {
	namespace Memory
	{
		/// @brief The standard C allocator
		class FORGE_API CAllocator : public AbstractAllocator
		{
		public:
			CAllocator();
		   ~CAllocator() = default;

		public:
			/// @brief The C allocator does not track the starting address,
			/// as it does not own a pre-allocated memory pool, thus this function should 
			/// not be used at all.
			/// 
			/// @throw Will throw invalid operation error if attempted to obtain start address.
			VoidPtr GetStartAddress() override;

			/// @brief The C allocator does not track the peak Size,
			/// as it does not own a pre-allocated memory pool, thus this function should 
			/// not be used at all.
			/// 
			/// @throw Will throw invalid operation error if attempted to obtain peak Size.
			Size  GetPeakSize() override;

			/// @brief The C allocator does not track the total memory Size,
			/// as it does not own a pre-allocated memory pool, thus this function should 
			/// not be used at all.
			/// 
			/// @throw Will throw invalid operation error if attempted to obtain used memory.
			Size GetTotalSize() override;

			/// @brief The C allocator does not track the used memory,
			/// as it does not own a pre-allocated memory pool, thus this function should 
			/// not be used at all.
			/// 
			/// @throw Will throw invalid operation error if attempted to obtain used memory.
			Size GetUsedMemory() override;

		public:
			/// @brief Allocates properly aligned memory address.
			/// 
			/// @param[in] size      The size of memory to allocate in Bytes.
			/// @param[in] alignment The Alignment requirment of the memory, must be power of two.
			/// 
			/// @returns Address to the start of the allocated memory.
			virtual VoidPtr Allocate(Size size, Byte alignment = 4) override;

			/// @brief ReSizes an allocated address to a new Size and copies its content
			/// to the new chunk.
			/// 
			/// @param[in] address   The address to reSize.
			/// @param[in] size      The new size of memory to reallocate in Bytes.
			/// @param[in] alignment The Alignment requirment of the memory, must be power of two.
			/// 
			/// @returns Address to the start of the reallocated memory.
			/// 
			// @throw Will throw bad allocation error if not allocated.
			virtual VoidPtr Reallocate(VoidPtr address, Size Size, Byte alignment = 4) override;

			/// @brief Frees the address present in the pre-allocated memory pool.
			/// 
			/// @param[in] address The address to deallocate.
			/// 
			// @throw Will throw bad allocation error if not allocated.
			virtual Void  Deallocate(VoidPtr address) override;

		public:
			/// @brief The C allocator does not support resetting of memory pool, as it
			/// does not own a pre-allocated memory pool, thus this function should 
			/// not be used at all.
			/// 
			/// @throw Will throw invalid operation error if attempted to reset.
			virtual Void  Reset() override;
		};
	}
}

#endif // C_ALLOCATOR_H
