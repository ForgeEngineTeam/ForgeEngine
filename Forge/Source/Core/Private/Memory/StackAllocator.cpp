#include "Core/Public/Memory/StackAllocator.h"

namespace Forge {
	namespace Memory
	{
		StackAllocator::StackAllocator(Size total_size)
			: AbstractAllocator(nullptr, total_size)
		{
			m_start_ptr = malloc(total_size);

			m_is_mem_owned = true;
			m_prev_address = nullptr;
			m_offset_ptr = m_start_ptr;

			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
		StackAllocator::StackAllocator(VoidPtr start, Size total_size)
			: AbstractAllocator(start, total_size)
		{
			m_is_mem_owned = false;
			m_prev_address = nullptr;
			m_offset_ptr = m_start_ptr;

			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
		
		StackAllocator::~StackAllocator()
		{
			if (m_is_mem_owned)
				free(m_start_ptr);
			else
				MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}

		VoidPtr StackAllocator::Allocate(Size size, Byte alignment)
		{
			Size header_size = sizeof(AllocationHeader);
			Byte adjustment = AlignAddressUpwardAdjustment(m_offset_ptr, alignment);

			if ((m_stats.m_used_memory + size + adjustment + header_size) > m_stats.m_total_size)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_BAD_ALLOCATION_EXCEPTION, "No sufficent space for required Size")*/
			}

			VoidPtr aligned_address = AddAddress(m_offset_ptr, adjustment);

			AllocationHeader* header = (AllocationHeader*)aligned_address;
			header->m_padding = adjustment;
			
			m_prev_address = AddAddress(aligned_address, header_size);

			m_offset_ptr = AddAddress(m_prev_address, size);

			if (m_stats.m_peak_size < size) { m_stats.m_peak_size = size; }

			m_stats.m_used_memory += size + adjustment + header_size;
			m_stats.m_num_of_allocs++;

			return m_prev_address;
		}
		VoidPtr StackAllocator::Reallocate(VoidPtr address, Size size, Byte alignment)
		{
			if (!WithinAddressBounds(m_start_ptr, address, m_stats.m_total_size))
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_MEMORY_OUT_OF_BOUNDS_EXCEPTION)*/
			}

			if (m_offset_ptr < address)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_BAD_ALLOCATION_EXCEPTION, "Address has not been allocated in the memory pool")*/
			}

			if (m_prev_address != address)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "Stack allocator only supports reallocation of the most recently allocated memroy")*/
			}

			Size amt_to_shift = size - (U64)SubAddress(m_offset_ptr, address);
			m_offset_ptr = AddAddress(m_offset_ptr, amt_to_shift);

			m_stats.m_used_memory += amt_to_shift;

			return address;
		}
		Void    StackAllocator::Deallocate(VoidPtr address)
		{
			if (!WithinAddressBounds(m_start_ptr, address, m_stats.m_total_size))
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_MEMORY_OUT_OF_BOUNDS_EXCEPTION)*/
			}

			if (m_offset_ptr < address)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_MEMORY_OUT_OF_BOUNDS_EXCEPTION, "Address has not been allocated in the memory pool")*/
			}

			if (m_prev_address != address)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "Stack allocator only supports deallocation of the most recently allocated memory")*/
			}
			
			Size header_size = sizeof(AllocationHeader);
			AllocationHeader* header = (AllocationHeader*)SubAddress(address, header_size);

			Size dealloc_size = reinterpret_cast<U64>(SubAddress(m_offset_ptr, address)) + header_size + header->m_padding;

			m_offset_ptr = SubAddress(header, header->m_padding);

			MemorySet(m_offset_ptr, 0, dealloc_size);
		
			m_stats.m_used_memory -= dealloc_size;
			m_stats.m_num_of_allocs--;
		}

		Void StackAllocator::Reset(void)
		{
			m_offset_ptr = m_start_ptr;

			m_stats.m_peak_size = 0;
			m_stats.m_used_memory = 0;
			m_stats.m_num_of_allocs = 0;
		
			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
	}
}