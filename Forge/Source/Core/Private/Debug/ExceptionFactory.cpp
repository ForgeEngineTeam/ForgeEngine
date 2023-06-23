#include <Core/Public/Debug/Exception/ExceptionFactory.h>

namespace Forge {
	namespace Debug
	{
		Void ExceptionFactory::ThrowException(ExceptionType type, ConstCharPtr line, ConstCharPtr file, ConstCharPtr function)
		{
			switch (type)
			{
			case ExceptionType::FORGE_TIMEOUT:              throw TimeoutException(line, file, function);
			case ExceptionType::FORGE_INVALID_IO:			throw InvalidIOException(line, file, function);
			case ExceptionType::FORGE_DIVIDE_BY_ZERO:       throw DivideByZeroException(line, file, function);
			case ExceptionType::FORGE_FILE_NOT_FOUND:	    throw FileNotFoundException(line, file, function);
			case ExceptionType::FORGE_BAD_ALLOCATION:       throw BadAllocationException(line, file, function);
			case ExceptionType::FORGE_INDEX_OUT_RANGE:	    throw IndexOutOfRangeException(line, file, function);
			case ExceptionType::FORGE_INVALID_OPERATION:    throw InvalidOperationException(line, file, function);
			case ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS: throw MemoryOutOfBoundsException(line, file, function);
			}
		}
		Void ExceptionFactory::ThrowException(ExceptionType type, ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr info)
		{
			switch (type)
			{
			case ExceptionType::FORGE_TIMEOUT:              throw TimeoutException(line, file, function, info);
			case ExceptionType::FORGE_INVALID_IO:			throw InvalidIOException(line, file, function, info);
			case ExceptionType::FORGE_DIVIDE_BY_ZERO:       throw DivideByZeroException(line, file, function, info);
			case ExceptionType::FORGE_FILE_NOT_FOUND:	    throw FileNotFoundException(line, file, function, info);
			case ExceptionType::FORGE_BAD_ALLOCATION:       throw BadAllocationException(line, file, function, info);
			case ExceptionType::FORGE_INDEX_OUT_RANGE:	    throw IndexOutOfRangeException(line, file, function, info);
			case ExceptionType::FORGE_INVALID_OPERATION:    throw InvalidOperationException(line, file, function, info);
			case ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS: throw MemoryOutOfBoundsException(line, file, function, info);
			}
		}
	}
}