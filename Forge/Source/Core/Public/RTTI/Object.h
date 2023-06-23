#ifndef OBJECT_H
#define OBJECT_H

#include "TypeInfo.h"

#include "Core/Public/CoreFwd.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

using namespace Forge::Memory;

namespace Forge {
	namespace RTTI
	{
		using ObjectRef		 = Object&;
		using ObjectPtr      = Object*;
		using ConstObject    = const Object;
		using ConstObjectRef = const Object&;
		using ConstObjectPtr = const Object*;

		/**
		 * @brief Base class for classes with run-time type information. This
		 * class is reference-counted and is non-copyable.
		 * 
		 * @author Karim Hisham
		 */
		class FORGE_API Object
		{
		public:
			Object() = default;
		   ~Object() = default;
		
		public:
			/**
			 * @brief Gets the run-time type info of this class.
			 * 
			 * @return Const raw pointer to the class type info.
			 */
			static ConstTypeInfoPtr GetTypeInfo(void);

		public:
			/**
			 * @brief Performs a deep-copy of the object and returns the new
			 * instance.
			 * 
			 * @return TSharedPtr object to the cloned object. 
			 */
			virtual TSharedPtr<Object> Clone(void) = 0;

			/**
			 * @brief Performs a deep-copy of the object and returns the new
			 * instance using an allocator.
			 *
			 * @param[in] allocator The allocator used to construct the new object.
			 * 
			 * @return TSharedPtr object to the cloned object.
			 */
			virtual TSharedPtr<Object> Clone(AbstractAllocator* allocator) = 0;

		public:
			/**
			 * @brief Check whether the current type is of the specified type ID.
			 * 
			 * @param[in] type_id The type ID to check if the object is instance of.
			 * 
			 * @return True if the object is an instace of the type ID.
			 */
			Bool IsInstanceOf(ConstStringHash type_id) const;

			/**
			 * @brief Check whether the current type is of the specified type info.
			 *
			 * @param[in] type_info The type info to check if the object is 
			 * instance of.
			 *
			 * @return True if the object is an instace of the type info.
			 */
			Bool IsInstanceOf(ConstTypeInfoPtr type_info) const;

		public:
			/**
			 * @brief Casts the object to the class specified staticly.
			 * 
			 * @return TSharedPtr object to the class specified.
			 */
			template<typename T> 
			TSharedPtr<T> StaticCast(void)
			{
				return TSharedPtr((T*)this);
			}

			/**
			 * @brief Casts the object to the class specified dynamically.
			 *
			 * @return TSharedPtr to the class specified, or an empty one if not 
			 * derived from it.
			 */
			template<typename T> 
			TSharedPtr<T> DynamicCast(void)
			{
				if (this->IsInstanceOf(T::GetTypeInfo()))
					return TSharedPtr<T>((T*)this);
				
				return TSharedPtr<T>();
			}
		};

		#define FORGE_DECLARE_TYPEINFO(__TYPENAME__, __BASE_TYPENAME__)	\
			using ClassName     = __TYPENAME__;							\
			using BaseClassName = __BASE_TYPENAME__;					\
			static ConstTypeInfoPtr GetTypeInfo(void) { static TypeInfo static_type_info(#__TYPENAME__, sizeof(ClassName), BaseClassName::GetTypeInfo()); return &static_type_info; }
	}
}

#endif // OBJECT_H
