#include "Core/Public/Memory/CAllocator.h"

namespace Forge {
	namespace Memory
	{
		CAllocator::CAllocator()
			: AbstractAllocator(nullptr, 0) {}

		VoidPtr CAllocator::GetStartAddress()
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "C allocator does not track starting address")*/

			return nullptr;
		}
		Size  CAllocator::GetPeakSize()
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "C allocator does not track peak Size")*/

			return 0;
		}
		Size  CAllocator::GetTotalSize()
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "C allocator does not track total memory Size")*/

			return 0;
		}
		Size  CAllocator::GetUsedMemory()
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "C allocator does not track used memory")*/

			return 0;
		}

		VoidPtr CAllocator::Allocate(Size size, Byte alignment)
		{
			m_stats.m_num_of_allocs++;
			return _aligned_malloc(size, alignment);
		}
		VoidPtr CAllocator::Reallocate(VoidPtr address, Size size, Byte alignment)
		{
			return _aligned_realloc(address, size, alignment);
		}
		Void    CAllocator::Deallocate(VoidPtr address)
		{
			free(address);
			m_stats.m_num_of_allocs--;
		}

		Void  CAllocator::Reset()
		{
			/*FORGE_EXCEPT(Debug::Exception::ERR_INVALID_OPERATION_EXCEPTION, "C allocator does not support reseting of memory pool")*/
		}
	}
}