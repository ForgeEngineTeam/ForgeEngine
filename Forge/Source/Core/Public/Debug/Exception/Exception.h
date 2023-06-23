#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Debug
	{
		enum class ExceptionType
		{
			/**
			 * @brief Indicates that a timeout has occured.
			 */
			FORGE_ENUM_DECL(FORGE_TIMEOUT,			    0)

			/**
			 * @brief Indicates that an invalid I/O operation has occured.
			 */
			FORGE_ENUM_DECL(FORGE_INVALID_IO,           1)

			/**
			 * @brief Indicates that an invalid arugment has been passed to a
			 * function.
			 */
			FORGE_ENUM_DECL(FORGE_INVALID_ARGUMENT,	    2)

			/**
			 * @brief Indicates that a null pointer argument has been passed to a
			 * function.
			 */
			FORGE_ENUM_DECL(FORGE_ARGUMENT_NULL,        3)

			/**
			 * @brief Indicates that a divide by zero operation has occured.
			 */
			FORGE_ENUM_DECL(FORGE_DIVIDE_BY_ZERO,		4)

			/**
			 * @brief Indicates that a file search operation has failed.
			 */
			FORGE_ENUM_DECL(FORGE_FILE_NOT_FOUND,		5)

			/**
			 * @brief Indicates that a memory allocation operation has failed.
			 */
			FORGE_ENUM_DECL(FORGE_BAD_ALLOCATION,		6)

			/**
			 * @brief Indicates that an out of range array access has occured.
			 */
			FORGE_ENUM_DECL(FORGE_INDEX_OUT_RANGE,	    7)

			/**
			 * @brief Indicates that an invalid operation has occured.
			 */
			FORGE_ENUM_DECL(FORGE_INVALID_OPERATION,	8)

			/**
			 * @brief Indicates that an out of bounds memory access has occured.
			 */
			FORGE_ENUM_DECL(FORGE_MEMORY_OUT_OF_BOUNDS, 9)

			MAX
		};

		/**
		 * @brief Provides information about errors that occured in the engine.
		 * 
		 * Forge throws exceptions whenever an error occures, this is the object
		 * that stores the source of the problem and information regarding why the
		 * problem has occured.
		 * 
		 * The user application is advised to always wrap Forge functions within 
		 * try {} catch(Exception& e) {} blocks in order to gracefully handle these
		 * errors.
		 * 
		 * @author Karim Hisham
         */		
		class FORGE_API Exception
		{
		protected:
			ConstCharPtr m_line;
			ConstCharPtr m_file;
			ConstCharPtr m_function;
			ConstCharPtr m_additional_info;

		protected:
			Char m_description[256] = { 0 };

		public:
			Exception(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr desc);

			Exception(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr desc, ConstCharPtr info);

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~Exception(Void) = default;

		public:
			/**
			 * @brief Gets the number of the source line where the exception was
			 * thrown.
			 * 
			 * @return ConstCharPtr storing the number of the source line.
			 */
			ConstCharPtr GetLine(Void);

			/**
			 * @brief Gets the name of the source file where the exception was 
			 * thrown.
			 * 
			 * @return ConstCharPtr storing the name of the source file.
			 */
			ConstCharPtr GetFile(Void);

			/**
			 * @brief Gets the name of the source function where the exception was 
			 * thrown.
			 * 
			 * @return ConstCharPtr storing the name of the source function.
			 */
			ConstCharPtr GetFunction(Void);

			/**
			 * @brief Gets additional information about the exception if provided.
			 * 
			 * @return ConstCharPtr storing additional information about the 
			 * exception, or null if no additional information provided. 
			 */
			ConstCharPtr GetAdditionalInfo(Void);

		public:
			/**
			 * @brief Gets the full description of the exception.
			 * 
			 * The description contains the cause, the line number, file name, what
			 * function threw the error and additional information if provided.
			 */
			ConstCharPtr GetDescripton(Void);
		};

		FORGE_FORCE_INLINE ConstCharPtr Exception::GetLine(Void)
		{ 
			return m_line; 
		}
		FORGE_FORCE_INLINE ConstCharPtr Exception::GetFile(Void)
		{ 
			return m_file; 
		}
		FORGE_FORCE_INLINE ConstCharPtr Exception::GetFunction(Void)
		{
			return m_function;
		}
		FORGE_FORCE_INLINE ConstCharPtr Exception::GetAdditionalInfo(Void)
		{ 
			if (m_additional_info) 
				return m_additional_info; 
			
			return nullptr; 
		}

		FORGE_FORCE_INLINE ConstCharPtr Exception::GetDescripton(Void)
		{ 
			return m_description; 
		}
	}
}

#endif // EXCEPTION_H
