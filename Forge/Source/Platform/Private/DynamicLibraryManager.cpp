#include <Platform/Public/DynamicLibraryManager.h>

namespace Forge {
	namespace Platform
	{
		TWeakPtr<DynamicLibrary> DynamicLibraryManager::LoadDynamicLibrary(ConstCharPtr filename)
		{
			auto it = m_registry.find(filename);

			if (it != m_registry.end())
				return it->second;
			
			TSharedPtr<DynamicLibrary> dynamic_libary(new DynamicLibrary(filename));

			m_registry.insert({ filename, dynamic_libary });

			return dynamic_libary;
		}
		Void DynamicLibraryManager::UnloadDynamicLibrary(TWeakPtr<DynamicLibrary> dynamic_library)
		{
			if(dynamic_library.IsExpired())
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Dynamic library is null")

			if (!m_registry.count(dynamic_library.Lock()->GetLibraryName()))
				FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
					"Dynamic library has been unloaded")

			m_registry.erase(dynamic_library.Lock()->GetLibraryName());
		}

		Void DynamicLibraryManager::Clear(Void)
		{
			m_registry.clear();
		}
	}
}
