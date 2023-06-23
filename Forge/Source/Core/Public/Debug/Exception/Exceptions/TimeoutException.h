#ifndef TIMEOUT_EXCEPTION_H
#define TIMEOUT_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class TimeoutException : public Exception
		{
		public:
			TimeoutException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Current operation has timed out") {}
			TimeoutException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Current operation has timed out", add_info) {}
		};
	}
}

#endif // TIMEOUT_EXCEPTION_H
