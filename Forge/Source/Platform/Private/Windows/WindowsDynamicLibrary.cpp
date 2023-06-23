#include <Platform/Public/Windows/WindowsDynamicLibrary.h>

namespace Forge {
	namespace Platform
	{
		WindowsDynamicLibrary::WindowsDynamicLibrary(ConstCharPtr filename)
			: AbstractDynamicLibrary(filename)
		{
			/**
			* TODO: Check if the filename ends with .dll, if not then add .dll suffix.
			* 
			* TODO: Check if the filename is a filename, absloute path or relative path,
			*       then perform the most efficeint search for the library.
			*/

			m_handle = LoadLibrary(filename);

			if (!m_handle)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_IO, "Faild to load dynamic library");
		}

		WindowsDynamicLibrary::~WindowsDynamicLibrary(Void)
		{
			if (m_handle)
				FreeLibrary(m_handle);
		}

		ConstVoidPtr WindowsDynamicLibrary::GetLibrarySymbol(ConstCharPtr symbol)
		{
			ConstVoidPtr symbol_result = GetProcAddress(m_handle, symbol); 
			
			if (!symbol_result)
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_IO, "Faild to load dynamic library symbol");

			return symbol_result; 
		}
	}
}