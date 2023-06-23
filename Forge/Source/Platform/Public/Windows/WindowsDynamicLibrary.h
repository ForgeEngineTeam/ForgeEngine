#ifndef WINDOWS_DYNAMIC_LIBRARY_H
#define WINDOWS_DYNAMIC_LIBRARY_H

#include <Windows.h>

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Algorithm/Algorithm.h>

#include <Platform/Public/Base/AbstractDynamicLibrary.h>

using namespace Forge::Debug;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Platform
	{
		/**
		 * @brief Windows dynamic library holder implementation.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API WindowsDynamicLibrary final : public AbstractDynamicLibrary
		{
		private:
			HMODULE m_handle;

		public:
			/**
			 * @brief Default constructor.
			 */
			WindowsDynamicLibrary(ConstCharPtr filename);

		public:
			/**
			 * @brief Default destructor.
			 */
			~WindowsDynamicLibrary(Void);

		public:
			/**
			 * @brief Gets the address of the specified dynamic library symbol.
			 *
			 * @param symbol[in] The dynamic library symbol to retrieve.
			 *
			 * @returns ConstVoidPtr storing the address of the dynamic library
			 * symbol.
			 *
			 * @throws InvalidIOException if failed to load dynamic
			 * library symbol.
			 */
			ConstVoidPtr GetLibrarySymbol(ConstCharPtr symbol) override;
		};

		using DynamicLibrary = WindowsDynamicLibrary;
		FORGE_TYPEDEF_DECL(DynamicLibrary)
	}
}

#endif
