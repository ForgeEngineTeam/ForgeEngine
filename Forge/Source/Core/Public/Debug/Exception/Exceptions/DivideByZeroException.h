#ifndef DIVIDE_BY_ZERO_EXCEPTION_H
#define DIVIDE_BY_ZERO_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class DivideByZeroException : public Exception
		{
		public:
			DivideByZeroException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Cannot divide by zero") {}
			DivideByZeroException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Cannot divide by zero", add_info) {}
		};
	}
}

#endif // DIVIDE_BY_ZERO_EXCEPTION_H