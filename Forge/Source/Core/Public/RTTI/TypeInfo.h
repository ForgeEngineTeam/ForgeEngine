#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include "Core/Public/CoreFwd.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeDefinitions.h"

class ConstStringHash
{

};

namespace Forge {
	namespace RTTI
	{
		using TypeInfoRef	   = TypeInfo&;
		using TypeInfoPtr      = TypeInfo*;
		using ConstTypeInfo    = const TypeInfo;
		using ConstTypeInfoRef = const TypeInfo&;
		using ConstTypeInfoPtr = const TypeInfo*;

		/**
		 * @brief Stores run-time meta-information about classes.
		 * 
		 * @author Karim Hisham
		 */
		class FORGE_API TypeInfo
		{
		private:
			ConstSize		  m_type_size;
			ConstCharPtr      m_type_name;
			ConstStringHash	  m_type_hash_id;
			ConstTypeInfoPtr  m_base_type_info;
		
		public:
			TypeInfo(ConstCharPtr type_name, ConstSize type_Size, ConstTypeInfoPtr base_type_info);

		public:
		   ~TypeInfo() = default;

		public:
			/**
			 * @brief Get the size of the type in bytes.
			 * 
			 * @return ConstSize  storing the size of the type in bytes.
			 */
			ConstSize GetTypeSize(void) const;

			/**
			 * @brief Get the name of the type.
			 *
			 * @return ConstCharPtr storing the name of the type.
			 */
			ConstCharPtr GetTypeName(void) const;

			/**
			 * @brief Get the ID of the type.
			 *
			 * @return ConstStringHash storing the ID of the type.
			 */
			ConstStringHash GetTypeId(void) const;
 
			/**
			 * @brief Get the base type of the type.
			 *
			 * @return ConstTypeInfoPtr storing the type info of the type, nullptr
			 * if it has no base class.
			 */
			ConstTypeInfoPtr GetBaseTypeInfo(void) const;

		public:
			/**
			 * @brief Checks wether the type is an abstract class.
			 *
			 * @return True if the type is an abstract class.
			 */
			Bool IsAbstract() const;

		public:
			/**
			 * @brief Checks whether the current type is same as a specified type ID.
			 * 
			 * @param[in] type_id The type ID to check whether its same as the
			 * object.
			 * 
			 * @return True if the object is same as the type ID.
			 */
			Bool IsSameAs(ConstStringHash& type_id) const;
	 
			/**
			 * @brief Checks wether the current type is derived from a specified 
			 * type ID.
			 *
			 * @param[in] type_id The type ID to check whether the object is
			 * derived from it.
			 * 
			 * @return True if the object is derived from the type ID.
			 */
			Bool IsDerivedFrom(ConstStringHash& type_id) const;
			
			/**
			 * @brief Checks whether the current type is same as a specified type 
			 * info.
			 *
			 * @param[in] type_info The type info to check whether its same as the
			 * object.
			 *
			 * @return True if the object is same as the type info.
			 */
			Bool IsSameAs(ConstTypeInfoPtr type_info) const;

			/**
			 * @brief Checks wether the current type is derived from a specified
			 * type info.
			 *
			 * @param[in] type_info The type info to check whether the object is
			 * derived from it.
			 *
			 * @return True if the object is derived from the type info.
			 */
			Bool IsDerivedFrom(ConstTypeInfoPtr type_info) const;
		};

		FORGE_FORCE_INLINE ConstSize TypeInfo::GetTypeSize(void) const            { return m_type_size; }
		FORGE_FORCE_INLINE ConstCharPtr TypeInfo::GetTypeName(void) const         { return m_type_name; }
		FORGE_FORCE_INLINE ConstStringHash TypeInfo::GetTypeId(void) const		  { return m_type_hash_id; }
		FORGE_FORCE_INLINE ConstTypeInfoPtr TypeInfo::GetBaseTypeInfo(void) const { return m_base_type_info; }
	}
}

#endif // TYPE_INFO_H
