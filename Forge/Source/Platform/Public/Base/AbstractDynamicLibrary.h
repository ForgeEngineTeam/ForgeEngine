#ifndef ABSTRACT_DYNAMIC_LIBRARY_H
#define ABSTRACT_DYNAMIC_LIBRARY_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Platform
	{
		class AbstractDynamicLibrary
		{
		protected:
			ConstCharPtr m_name;

		public:
			/**
			 * @brief Default constructor.
			 */
			AbstractDynamicLibrary(ConstCharPtr filename)
				: m_name(filename) {}

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~AbstractDynamicLibrary(Void) = default;

		public:
			/**
			 * @brief Gets the name of the dynamic library.
			 * 
			 * @returns ConstCharPtr storing the name of the dynamic library.
			 */
			virtual ConstCharPtr GetLibraryName(Void);

			/**
			 * @brief Gets the address of the specified dynamic library symbol.
			 * 
			 * @param symbol[in] The dynamic library symbol to retrieve.
			 * 
			 * @returns ConstVoidPtr storing the address of the dynamic library
			 * symbol.
			 * 
			 * @throws InvalidOperationException if failed to load dynamic
			 * library symbol.
			 */
			virtual ConstVoidPtr GetLibrarySymbol(ConstCharPtr symbol) = 0;
		};

		FORGE_FORCE_INLINE ConstCharPtr AbstractDynamicLibrary::GetLibraryName(Void)
		{
			return m_name;
		}
	}
}

#endif
