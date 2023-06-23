#ifndef INDEX_OUT_OF_RANGE_EXCEPTION_H
#define INDEX_OUT_OF_RANGE_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class IndexOutOfRangeException : public Exception
		{
		public:
			IndexOutOfRangeException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Index is out of range of the array") {}
			IndexOutOfRangeException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Index is out of range of the array", add_info) {}
		};
	}
}

#endif // INDEX_OUT_OF_RANGE_EXCEPTION_H
