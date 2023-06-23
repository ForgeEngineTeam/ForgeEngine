#ifndef MEMORY_OUT_OF_BOUNDS_EXCEPTION_H
#define MEMORY_OUT_OF_BOUNDS_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class MemoryOutOfBoundsException : public Exception
		{
		public:
			MemoryOutOfBoundsException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Memory address is out of bounds") {}
			MemoryOutOfBoundsException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Memory address is out of bounds", add_info) {}
		};
	}
}

#endif // MEMORY_OUT_OF_BOUNDS_EXCEPTION_H