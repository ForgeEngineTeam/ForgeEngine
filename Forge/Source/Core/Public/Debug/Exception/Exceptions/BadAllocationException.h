#ifndef BAD_ALLOCATION_EXCEPTION_H
#define BAD_ALLOCATION_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class BadAllocationException : public Exception
		{
		public:
			BadAllocationException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Failed to perform allocation storage") {}
			BadAllocationException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Failed to perform allocation storage", add_info) {}
		};
	}
}

#endif // BAD_ALLOCATION_EXCEPTION_H
