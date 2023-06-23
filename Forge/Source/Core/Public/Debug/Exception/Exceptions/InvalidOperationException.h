#ifndef INVALID_OPERATION_EXCEPTION_H
#define INVALID_OPERATION_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class InvalidOperationException : public Exception
		{
		public:
			InvalidOperationException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Failed to perform operation on object") {}
			InvalidOperationException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Failed to perform operation on object", add_info) {}
		};
	}
}

#endif // INVALID_OPERATION_EXCEPTION_H
