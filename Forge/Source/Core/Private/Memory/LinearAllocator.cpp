#include "Core/Public/Memory/LinearAllocator.h"

namespace Forge {
	namespace Memory
	{
		LinearAllocator::LinearAllocator(Size total_size)
			: AbstractAllocator(nullptr, total_size)
		{
			m_start_ptr = malloc(total_size);

			m_is_mem_owned = true;
			m_offset_ptr = m_start_ptr;

			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
		LinearAllocator::LinearAllocator(VoidPtr start, Size total_size)
			: AbstractAllocator(start, total_size)
		{
			m_is_mem_owned = false;
			m_offset_ptr = m_start_ptr;

			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
		
		LinearAllocator::~LinearAllocator()
		{
			if (m_is_mem_owned)
				free(m_start_ptr);
			else
				MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}

		VoidPtr LinearAllocator::Allocate(Size size, Byte alignment)
		{
			Byte adjustment = AlignAddressUpwardAdjustment(m_offset_ptr, alignment);

			if ((m_stats.m_used_memory + size + adjustment) > m_stats.m_total_size)
			{
				/*FORGE_EXCEPT(Debug::Exception::ERR_BAD_ALLOCATION_EXCEPTION, "No sufficent space for required Size")*/
			}

			VoidPtr aligned_address = AddAddress(m_offset_ptr, adjustment);
			m_offset_ptr = AddAddress(aligned_address, size);

			if (m_stats.m_peak_size < size) { m_stats.m_peak_size = size; }

			m_stats.m_used_memory += size + adjustment;
			m_stats.m_num_of_allocs++;

			return aligned_address;
		}
		VoidPtr LinearAllocator::Reallocate(VoidPtr address, Size size, Byte alignment)
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "Linear allocator does not support reallocation of memory addresses")*/

			return nullptr;
		}
		Void    LinearAllocator::Deallocate(VoidPtr address)
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION,"Linear allocator does not support deallocation of memory addresses")*/
		}

		Void LinearAllocator::Reset(void)
		{
			m_offset_ptr = m_start_ptr;

			m_stats.m_peak_size = 0;
			m_stats.m_used_memory = 0;
			m_stats.m_num_of_allocs = 0;

			MemorySet(m_start_ptr, 0, m_stats.m_total_size);
		}
	}
}