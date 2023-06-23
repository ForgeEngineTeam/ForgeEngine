#ifndef IO_EXCEPTION_H
#define IO_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class InvalidIOException : public Exception
		{
		public:
			InvalidIOException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Failed to perform I/O operation") {}
			InvalidIOException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Failed to perform I/O operation", add_info) {}
		};
	}
}

#endif // IO_EXCEPTION_H
