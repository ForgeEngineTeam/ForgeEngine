#ifndef GL_LOADER_H
#define GL_LOADER_H

#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Memory/Memory.h>

#include <GraphicsDevice/Public/OpenGL/GL/gl.h>

#include <Platform/Public/Platform.h>
#include <Platform/Public/DynamicLibrary.h>

using namespace Forge::Memory;
using namespace Forge::Platform;

namespace Forge {
	namespace Graphics
	{	
		/**
		 * @brief OpenGL profile mask specifing the type of profile to use.
		 */
		enum class GLContextProfileMask
		{
			/**
			 * @brief The OpenGL embedded system profile.
			 */
			FORGE_ENUM_DECL(FORGE_ES,     0)

			/**
			 * @brief The OpenGL core profile.
			 */
			FORGE_ENUM_DECL(FORGE_CORE,   1)

			/**
			 * @brief The OpenGL compatibility profile.
			 */
			FORGE_ENUM_DECL(FORGE_COMPAT, 2)

			MAX
		};

		/**
		 * @brief OpenGL context flags specifing extended features.
		 */
		enum class GLContextFlags
		{
			FORGE_ENUM_DECL(FORGE_NONE,           FORGE_BIT(1))

			/**
			 * @brief Specifies that the OpenGL context is in debug mode.
			 */
			FORGE_ENUM_DECL(FORGE_DEBUG,          FORGE_BIT(2))

			/**
			 * @brief Specifies that the OpenGL context will not generate errors.
			 */
			FORGE_ENUM_DECL(FORGE_NO_ERROR,       FORGE_BIT(3))

			/**
			 * @brief Specifies that the OpenGL context supports robust buffer
			 * access.
			 */
			FORGE_ENUM_DECL(FORGE_ROBUSTNESS,     FORGE_BIT(4))

			/**
			 * @brief Specifies the OpenGL context release behaviour.
			 */
			FORGE_ENUM_DECL(FORGE_RELEASE_FLUSH,  FORGE_BIT(5))

			/**
			 * @brief Specifies that the OpenGL context support forward
			 * compatibility.
			 */
			FORGE_ENUM_DECL(FORGE_FORWARD_COMPAT, FORGE_BIT(6))

			MAX
		};

		FORGE_FLAG_DECL(GLContextFlags)

		/**
		 * @brief Abstract base class for loading and initializing OpenGL
		 * function pointers.
		 * 
		 * @author Karim Hisham.
		 */
		class GLLoader
		{
		protected:
			I32 m_major_version;
			I32 m_minor_version;

		protected:
			Bool m_extension_hints[163];

		protected:
			TWeakPtr<DynamicLibrary> m_dynamic_library;

		public:
			/**
			 * @brief Default constructor.
			 */
			GLLoader(Void) = default;

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~GLLoader(Void) = default;
	
		public:
			/**
			 * @brief Gets an extension hint.
			 *
			 * @param hint[in] The context hint to get.
			 * 
			 * @returns Bool storing the value of the specified hint.
			 */
			virtual Bool GetExtensionHint(I32 hint);

			/**
			 * @brief Gets major version of the context.
			 *
			 * @returns ConstCharPtr storing the major version of the context.
			 */
			virtual I32 GetContextMajorVersion(Void);

			/**
			 * @brief Gets minor version of the context.
			 *
			 * @returns ConstCharPtr storing the minor version of the context.
			 */
			virtual I32 GetContextMinorVersion(Void);

		public:
			/**
			 * @brief Sets an extension hint for the next call to the graphics
			 * context initialization function.
			 *
			 * This function should be called before initialization of the
			 * graphics context. If changes are desired, a new context must
			 * be created.
			 *
			 * @param hint[in] The context hint to set.
			 * @param value[in] The value of the context hint.
			 */
			virtual Void SetExtensionHint(I32 hint, Bool value);

			/**
			 * @brief Sets a context version for the next call to the graphics
			 * context initialization function.
			 *
			 * This function should be called before initialization of the
			 * graphics context. If changes are desired, a new context must
			 * be created.
			 *
			 * @param major[in] The major version of the context to set.
			 * @param minor[in] The minor version of the context to set.
			 */
			virtual Void SetContextVersion(I32 major, I32 minor);

		public:
			/**
			 * @brief Pre-initializes the OpenGL platform backend function
			 * pointers.
			 *
			 * This function loads the OpenGL dynamic library and performs
			 * function queries to the platform-dependant backend OpenGL
			 * functions.
			 * 
			 * @throw InvalidIOException if failed to load dynamic library or
			 * failed to load dynamic library symbol.
			 */
			virtual Void PreInitialize(Void) = 0;

			/**
			 * @brief Initializes the OpenGL function pointers.
			 * 
			 * This function performs function queries to the OpenGL functions
			 * with respect to the major and minor version of the context.
			 * 
			 * @throw InvalidIOException if failed to load dynamic library
			 * symbol.
			 */
			virtual Void Initialize(Void) = 0;
			
			/**
			 * @brief Terminates the OpenGL function pointers.
			 * 
			 * This function releases the OpenGL dynamic library and 
			 * perfoms nullification to the initialized OpenGL functions.
			 * 
			 * @throw InvalidOperationException if the dynamic library is null
			 * or not present in the registry.
			 */
			virtual Void Terminate(Void) = 0;

		public:
			/**
			 * @brief Loads the specified OpenGL function symbol from the
			 * loaded OpenGL dynamic library.
			 *
			 * @param symbol[in] The OpenGL function symbol to load.
			 *
			 * @returns ConstVoidPtr storing the address of the specified
			 * OpenGL function symbol.
			 *
			 * @throw InvalidIOException if failed to load dynamic library
			 * symbol
			 *
			 * @throw InvalidOperationException if the dynamic library is null
			 * or not present in the registry.
			 */
			virtual ConstVoidPtr LoadFunction(ConstCharPtr symbol) = 0;
		};

		FORGE_TYPEDEF_DECL(GLLoader)

		FORGE_FORCE_INLINE Bool GLLoader::GetExtensionHint(I32 hint)
		{
			return m_extension_hints[hint];
		}
		FORGE_FORCE_INLINE I32  GLLoader::GetContextMajorVersion(Void)
		{
			return m_major_version;
		}
		FORGE_FORCE_INLINE I32  GLLoader::GetContextMinorVersion(Void)
		{
			return m_minor_version;
		}

		FORGE_FORCE_INLINE Void GLLoader::SetExtensionHint(I32 hint, Bool value)
		{
			m_extension_hints[hint] = value;
		}
		FORGE_FORCE_INLINE Void GLLoader::SetContextVersion(I32 major, I32 minor)
		{
			m_major_version = major;
			m_minor_version = minor;
		}
	}
}

#endif
