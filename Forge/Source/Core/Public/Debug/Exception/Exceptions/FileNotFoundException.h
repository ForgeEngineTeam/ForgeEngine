#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H

#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		class FileNotFoundException : public Exception
		{
		public:
			FileNotFoundException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
				: Exception(line, file, function, "Failed to find file") {}
			FileNotFoundException(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr add_info)
				: Exception(line, file, function, "Failed to find file", add_info) {}
		};
	}
}

#endif // FILE_NOT_FOUND_EXCEPTION_H
