#ifndef DYNAMIC_LIBRARY_MANAGER_H
#define DYNAMIC_LIBRARY_MANAGER_H

#include <unordered_map>

#include <Core/Public/Common/Common.h>

#include <Core/Public/Algorithm/Algorithm.h>

#include <Core/Public/Types/SmartPointer.h>

#include <Platform/Public/DynamicLibrary.h>

using namespace Forge::Common;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Platform
	{
		/**
		 * @brief Manages dynamic libraries.
		 * 
		 * This class is responsible for loading and unloading required dynamic
		 * libraries. It also maintains a registry of all loaded dynamic
		 * libraries as well as providing functionality to clear the manager
		 * by unloading all loaded libraries.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API DynamicLibraryManager final
		{
		private:
			using DynamicLibraryRegistry = std::unordered_map<ConstCharPtr, TSharedPtr<DynamicLibrary>>;

		private:
			DynamicLibraryRegistry m_registry;

		public:
			/**
			 * @brief Default constructor.
			 */
			DynamicLibraryManager(Void) = default;

		public:
			/**
			 * @brief Default destructor.
			 */
			~DynamicLibraryManager(Void) = default;

		public:
			/**
			 * @brief Loads a dynamic library and stores the loaded library in
			 * the registry.
			 * 
			 * @param filename[in] The filename of the dynamic library to
			 * load.
			 * 
			 * @returns TWeakPtr<AbstractDynamicLibrary> storing the loaded
			 * dynamic library.
			 * 
			 * @throw InvalidIOException if failed to load dynamic library.
			 */
			TWeakPtr<DynamicLibrary> LoadDynamicLibrary(ConstCharPtr filename);

			/**
			 * @brief Unloads a dynamic library and removes the loaded library
			 * from the registry.
			 * 
			 * @param dynamic_library[in] The handle of the dynamic library to
			 * unload.
			 * 
			 * @throw InvalidOperationException if the dynamic library is null or not
			 * present in the registry.
			 */
			Void UnloadDynamicLibrary(TWeakPtr<DynamicLibrary> dynamic_library);

		public:
			/**
			 * @brief Clears the manager by unloading all loaded dynamic
			 * libraries and removes them from the registry.
			 */
			Void Clear(Void);
		};
	}
}

#endif
