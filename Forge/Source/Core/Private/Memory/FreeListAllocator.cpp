#include "Core/Public/Memory/FreeListAllocator.h"

namespace Forge {
	namespace Memory
	{
		FreeListAllocator::FreeListAllocator(Size capacity)
			: AbstractAllocator(nullptr, capacity)
		{
			m_is_mem_owned = true;

			m_start_ptr = malloc(this->m_stats.m_total_size);

			MemorySet(m_start_ptr, 0, this->m_stats.m_total_size);

			m_free_list = reinterpret_cast<FreeBlockNode*>(m_start_ptr);
			m_free_list->m_block_size = this->m_stats.m_total_size;
			m_free_list->m_link = nullptr;
		}
		FreeListAllocator::FreeListAllocator(VoidPtr start, Size capacity)
			: AbstractAllocator(start, capacity)
		{
			m_is_mem_owned = false;

			MemorySet(m_start_ptr, 0, this->m_stats.m_total_size);

			m_free_list = reinterpret_cast<FreeBlockNode*>(m_start_ptr);
			m_free_list->m_block_size = this->m_stats.m_total_size;
			m_free_list->m_link = nullptr;
		}

		FreeListAllocator::~FreeListAllocator()
		{
			if (m_is_mem_owned)
				free(m_start_ptr);
			else
				MemorySet(m_start_ptr, 0, this->m_stats.m_total_size);
		}

		VoidPtr FreeListAllocator::Allocate(Size size, Byte alignment)
		{
			if (!size)
			{
				/// Throw Expection
			}

			FreeBlockNode* prev_block = nullptr;
			FreeBlockNode* best_block = nullptr;
			FreeBlockNode* curr_block = this->m_free_list;

			Byte adjustment, required_space;

			Size smallest_diff = ~(Size)0;

			while (curr_block)
			{
				adjustment = AlignAddressUpwardAdjustment(curr_block, alignment);
				required_space = size + adjustment + sizeof(AllocationHeader);

				if (required_space > this->m_stats.m_total_size)
				{
					/// Throw Exception
				}

				if (curr_block->m_block_size >= required_space &&
				   (curr_block->m_block_size - required_space) < smallest_diff)
				{
					prev_block = best_block;
					best_block = curr_block;

					smallest_diff = curr_block->m_block_size - required_space;
				}

				curr_block = curr_block->m_link;
			}

			Size remaining_size = best_block->m_block_size - required_space;
			
			if (remaining_size)
			{
				FreeBlockNode* new_block = reinterpret_cast<FreeBlockNode*>(AddAddress(best_block, required_space));

				new_block->m_block_size = remaining_size;
				new_block->m_link = best_block->m_link;

				if (prev_block)
					prev_block->m_link = new_block;
				else
					m_free_list = new_block;
			}

			VoidPtr aligned_address = AddAddress(best_block, adjustment);

			AllocationHeader* header = reinterpret_cast<AllocationHeader*>(best_block);

			header->m_padding = adjustment;
			header->m_alloc_size = size;

			if (this->m_stats.m_peak_size < size)
				this->m_stats.m_peak_size = size;

			this->m_stats.m_used_memory += required_space;
			this->m_stats.m_num_of_allocs++;

			return AddAddress(aligned_address, sizeof(AllocationHeader));
		}
		VoidPtr FreeListAllocator::Reallocate(VoidPtr address, Size size, Byte alignment)
		{
			if (!address)
			{
				/// Throw Expection
			}

			if (size > this->m_stats.m_total_size)
			{
				/// Throw Exception
			}

			if (!WithinAddressBounds(this->m_start_ptr, address, this->m_stats.m_total_size))
			{
				/// Throw Expection
			}

			FreeBlockNode* curr_block = this->m_free_list;
			FreeBlockNode* prev_block = nullptr;
			FreeBlockNode* next_block = nullptr;

			AllocationHeader* header = reinterpret_cast<AllocationHeader*>(SubAddress(address, sizeof(AllocationHeader)));

			Size amt_to_shift = size - header->m_alloc_size;

			while (curr_block)
			{
				next_block = curr_block->m_link;

				if (address < curr_block)
				{
					MemorySet(curr_block, 0, curr_block->m_block_size);

					if (!prev_block)
					{
						this->m_free_list = reinterpret_cast<FreeBlockNode*>(AddAddress(curr_block, amt_to_shift));
						this->m_free_list->m_link = next_block;
					}
					else
					{
						prev_block->m_link = reinterpret_cast<FreeBlockNode*>(AddAddress(curr_block, amt_to_shift));
						prev_block->m_link->m_link = next_block;
					}
				}

				prev_block = curr_block;
				curr_block = curr_block->m_link;
			}

			return address;
		}
		Void    FreeListAllocator::Deallocate(VoidPtr address)
		{
			if (!address)
			{
				/// Throw Expection
			}

			if (!WithinAddressBounds(this->m_start_ptr, address, this->m_stats.m_total_size))
			{
				/// Throw Expection
			}

			FreeBlockNode* curr_block = this->m_free_list;
			FreeBlockNode* prev_block = nullptr;

			AllocationHeader* header = reinterpret_cast<AllocationHeader*>(SubAddress(address, sizeof(AllocationHeader)));

			Size padding = header->m_padding;
			Size alloc_size = header->m_alloc_size;
			Size total_size = padding + alloc_size + sizeof(AllocationHeader);

			FreeBlockNode* free_block = reinterpret_cast<FreeBlockNode*>(SubAddress(header, padding));
			
			MemorySet(free_block, 0, total_size);

			free_block->m_block_size = total_size;
			free_block->m_link = nullptr;

			while (curr_block)
			{
				if (address < curr_block)
				{
					if (!prev_block)
					{
						this->m_free_list = free_block;
						break;
					}

					prev_block->m_link = free_block;
					free_block->m_link = curr_block;
				}

				prev_block = curr_block;
				curr_block = curr_block->m_link;
			}

			if (free_block->m_link &&
				AddAddress(free_block, free_block->m_block_size) == free_block->m_link)
			{
				free_block->m_block_size += free_block->m_link->m_block_size;
				free_block->m_link = free_block->m_link->m_link;

				MemorySet(free_block->m_link, 0, free_block->m_block_size);
			}

			if (prev_block && prev_block->m_link &&
				AddAddress(prev_block, prev_block->m_block_size) == prev_block->m_link)
			{
				prev_block->m_block_size += prev_block->m_link->m_block_size;
				prev_block->m_link = prev_block->m_link->m_link;

				MemorySet(prev_block->m_link, 0, prev_block->m_block_size);
			}
		}

		Void FreeListAllocator::Reset(void)
		{
			MemorySet(m_start_ptr, 0, this->m_stats.m_total_size);

			m_free_list = reinterpret_cast<FreeBlockNode*>(m_start_ptr);
			m_free_list->m_block_size = this->m_stats.m_total_size;
			m_free_list->m_link = nullptr;
		}
	}
}
