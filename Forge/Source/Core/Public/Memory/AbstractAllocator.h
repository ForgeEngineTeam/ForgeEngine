#ifndef ABSTRACT_ALLOCATOR_H
#define ABSTRACT_ALLOCATOR_H

#include "Core/Public/Debug/Debug.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"
#include "Core/Public/Common/TypeTraits.h"

namespace Forge {
	namespace Memory
	{
		/**
		 * @brief Base class for memory allocators that define memory access
		 * patterns to be used within the engine.
		 * 
		 * Memory allocators work by pre-allocating a large memory pool usually
		 * at initilization time and manages this pool using certain policies
		 * specific to the type of the allocator. This ensures that allocation
		 * is actually perfomed once at program start.
		 * 
		 * It is advised to always depend on the memory allocators provided by
		 * the engine for allocation and deallocation of memory addresses, and
		 * completely avoid the usage of the standard heap allocation operators
		 * new/malloc() and delete/free() as they greatly impact perfomance if
		 * used frequently.
		 * 
		 * @author Karim Hisham
		 */
		class AbstractAllocator
		{
		FORGE_CLASS_NONCOPYABLE(AbstractAllocator)

		protected:
			VoidPtr m_start_ptr;

		protected:
			struct AllocatorStats
			{
				Size m_peak_size;
				Size m_total_size;
				Size m_used_memory;
				Size m_num_of_allocs;
				Size m_num_of_deallocs;
			} m_stats = {0, 0, 0, 0, 0};
		
		protected:
			Bool m_is_mem_owned;

		public:
			AbstractAllocator(VoidPtr start, Size capacity)
				: m_start_ptr(start), m_stats({ 0, capacity, 0, 0 }) {}

		public:
			virtual ~AbstractAllocator() = default;
		
		private:
			template<typename InElementType, typename... Args>
			InElementType* ConstructImpl(Args&&... args, Common::TypeIsPod)
			{
				return reinterpret_cast<InElementType*>(Allocate(sizeof(InElementType)));
			}
			template<typename InElementType, typename... Args>
			InElementType* ConstructImpl(Args&&... args, Common::TypeIsClass)
			{
				return new (Allocate(sizeof(InElementType))) InElementType(args...);
			}

			template<typename InElementType>
			Void DestructImpl(InElementType* address, Common::TypeIsPod)
			{
				Deallocate(address);
			}
			template<typename InElementType>
			Void DestructImpl(InElementType* address, Common::TypeIsClass)
			{
				address->~InElementType();
				Deallocate(address);
			}

			template<typename InElementType>
			InElementType* ConstructArrayImpl(Size size, Common::TypeIsPod)
			{
				return reinterpret_cast<InElementType*>(Allocate(sizeof(InElementType) * size));
			}
			template<typename InElementType>
			InElementType* ConstructArrayImpl(Size size, Common::TypeIsClass)
			{
				InElementType* address = reinterpret_cast<InElementType*>(Allocate(sizeof(InElementType) * size));

				for (I32 i = 0; i < size; i++)
					new (address + i) InElementType();

				return address;
			}

			template<typename InElementType>
			InElementType* DeconstructArrayImpl(Size size, InElementType* address, Common::TypeIsPod)
			{
				Deallocate(address);
			}
			template<typename InElementType>
			InElementType* DeconstructArrayImpl(Size size, InElementType* address, Common::TypeIsClass)
			{
				for (I32 i = 0; i < size; i++)
					(address + i)->~InElementType();

				Deallocate(address);
			}

		public:
			/**
			 * @brief Gets the starting address of the memory pool.
			 * 
			 * @return VoidPtr storing the starting address.
			 */
			virtual VoidPtr GetStartAddress(void);

		public:
			/**
			 * @brief Gets the maximum size allocated during lifetime of the 
			 * allocator.
			 * 
			 * @return Size storing the peak size allocated in bytes.
			 */
			virtual Size GetPeakSize(void);

			/**
			 * @brief Gets the total size allocated for the memory pool.
			 * 
			 * @return Size storing the total size allocated in bytes.
			 */
			virtual Size GetTotalSize(void);

			/**
			 * @brief Gets the currently occupied space in the memory pool.
			 * 
			 * @return Size storing the occupied space in bytes.
			 */
			virtual Size GetUsedMemory(void);

			/**
			 * @brief Gets the number of allocations made by the allocator object
			 * during its lifetime.
			 * 
			 * @return Size storting the number of allocations made.
			 */
			virtual Size GetNumOfAllocs(void);

			/**
			 * @brief Gets the number of deallocations made by the allocator object
			 * during its lifetime.
			 *
			 * @return Size storting the number of deallocations made.
			 */
			virtual Size GetNumOfDeallocs(void);

		public:
			/**
			 * @brief Checks wether the memory pool is owned by this allocator or
			 * provided by another allocator that owns it.
			 * 
			 * @return True if this allocator owns the memory pool.
			 */
			Bool IsMemoryOwned(void);

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
			 * @throws InvalidOperationException if not supported by the allocator.
			 * 
			 * @throws BadAllocationException if size requsted is larger than the
			 * memory pool.
			 */
			virtual VoidPtr Allocate(Size size, Byte alignment = 4) = 0;

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
			 * @throws InvalidOperationException if operation is not supported by
			 * the allocator.
			 * 
			 * @throws BadAllocationException if size requsted is larger than the
			 * memory pool.
			 * 
			 * @throws MemoryOutOfBoundsException if the address provided is out 
			 * of the memory pool bounds.
			 */
			virtual VoidPtr Reallocate(VoidPtr address, Size size, Byte alignment = 4) = 0;

			/**
			 * @brief Frees the address previously allocated from the pre-allocated
			 * memory pool.
			 * 
			 * @param[in] address The address of the chunk to free.
			 * 
			 * @throws InvalidOperationException if operation is not supported by
			 * the allocator.
			 * 
			 * @throws BadAllocationException if the address was not previously 
			 * allocated.
			 * 
			 * @throws MemoryOutOfBoundsException if the address provided is out
			 * of the memory pool bounds.
			 */
			virtual Void Deallocate(VoidPtr address) = 0;

		public:
			/**
			 * @brief Constructs an element object using this allocator.
			 * 
			 * @param[in] args The arguments to pass to the object's constructor.
			 * 
			 * @return InElementType* storing the address of the constructed
			 * element.
			 */
			template<typename InElementType, typename... Args>
			InElementType* Construct(Args&&... args)
			{
				ConstructImpl(args, Common::TTraitInt<Common::TIsPod<InElementType>::Value>);
			}
			
			/**
			 * @brief Deconstructs an element object using this allocator.
			 * 
			 * @param[in] address The address of the element object.
			 * 
			 * @throws InvalidOperationException if operation is not supported by
			 * the allocator
			 */
			template<typename InElementType>
			Void Destruct(InElementType* address)
			{
				DestructImpl(address, Common::TTraitInt<Common::TIsPod<InElementType>::Value>);
			}

			/**
			 * @brief Constructs an element object array using this allocator.
			 *
			 * @param[in] size The size of the array.
			 *
			 * @return InElementType* storing the address of the constructed
			 * element array.
			 */
			template<typename InElementType>
			InElementType* ConstructArray(Size size)
			{
				ConstructArrayImpl(size, Common::TTraitInt<Common::TIsPod<InElementType>::Value>);
			}

			/**
			 * @brief Deconstructs an element object array using this allocator.
			 *
			 * @param[in] size    The size of the array.
			 * @param[in] address The address of the element object array.
			 *
			 * @throws InvalidOperationException if operation is not supported by
			 * the allocator
			 */
			template<typename InElementType>
			InElementType* DeconstructArray(Size size, InElementType* address)
			{
				DeconstructArrayImpl(size, address, Common::TTraitInt<Common::TIsPod<InElementType>::Value>);
			}

		public:
			/**
			 * @brief Resets the whole memory pool.
			 * 
			 * This function sets the entire allocated memory pool to zeros.
			 */
			virtual Void Reset(void) = 0;
		};

		FORGE_FORCE_INLINE VoidPtr AbstractAllocator::GetStartAddress(void) { return m_start_ptr; }

		FORGE_FORCE_INLINE Size AbstractAllocator::GetPeakSize(void)      { return m_stats.m_peak_size;     }
		FORGE_FORCE_INLINE Size AbstractAllocator::GetTotalSize(void)     { return m_stats.m_total_size;    }
		FORGE_FORCE_INLINE Size AbstractAllocator::GetUsedMemory(void)    { return m_stats.m_used_memory;   }
		FORGE_FORCE_INLINE Size AbstractAllocator::GetNumOfAllocs(void)   { return m_stats.m_num_of_allocs; }
		FORGE_FORCE_INLINE Size AbstractAllocator::GetNumOfDeallocs(void) { return m_stats.m_num_of_deallocs; }

		FORGE_FORCE_INLINE Bool AbstractAllocator::IsMemoryOwned(void) { return m_is_mem_owned; }
	}
}

#endif // ABSTRACT_ALLOCATOR_H
