#ifndef STRING_H
#define STRING_H

#include <Core/Public/Types/String/AbstractString.h>

namespace Forge {
	namespace Common
	{
		class FORGE_API String final : public AbstractString<String>
		{
		private:
			using SelfType         = String;
			using SelfTypePtr      = String*;
			using SelfTypeRef      = String&;
			using SelfTypeMoveRef  = String&&;
			using ConstSelfType    = const String;
			using ConstSelfTypeRef = const String&;
			using ConstSelfTypePtr = const String*;

		private:
			TMemoryRegion<Char> m_data;		/* The memory region to store the string data. */

		public:
			/**
			 *  @brief Default constructor.
			 */
			String(Void);

			/**
			 * @brief Character fill constructor.
			 * 
			 * @param ch The character to fill.
			 * @param count The number of character occurances to fill.
			 */
			String(Char ch, Size count);

			/**
			 * @brief String literal constructor.
			 * 
			 * @param string The string literal to assign.
			 * @param count The number of characters to assign.
			 */
			String(ConstCharPtr string, Size count);

			/**
			 * @brief Substring constructor.
			 * 
			 * @param string The string to assign.
			 * @param start The starting index of the substring.
			 * @param end The ending index of the substring.
			 */
			String(ConstSelfTypeRef string, Size start, Size end);

		public:
			/**
			 * @brief Move constructor.
			 */
			String(SelfTypeMoveRef other);

			/**
			 * @brief Copy constructor.
			 */
			String(ConstSelfTypeRef other);

		public:
			/**
			 * @brief Default destructor.
			 */
			~String(Void);

		public:
			/**
			 * @brief Character assignment operator.
			 * 
			 * @param ch The character to assign.
			 * 
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator =(ConstChar ch);

			/**
			 * @brief String literal assignment operator.
			 *
			 * @param string The character to assign.
			 *
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator =(ConstCharPtr string);

			/**
			 * @brief Move assignment operator.
			 * 
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator =(SelfTypeMoveRef other);

			/**
			 * @brief Copy assignment operator.
			 * 
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other);

		public:
			/**
			 * @brief Character concatenation addition operator.
			 * 
			 * @param ch The character to concatenate.
			 * 
			 * @return SelfType storing the modified string.
			 */
			SelfType operator +(ConstChar ch);

			/**
			 * @brief String literal concatenation addition operator.
			 * 
			 * @param string The string literal to concatenate.
			 * 
			 * @return SelfType storing the modified string.
			 */
			SelfType operator +(ConstCharPtr string);

			/**
			 * @brief String concatenation addition operator.
			 *
			 * @param string The string to concatenate.
			 *
			 * @return SelfType storing the modified string.
			 */
			SelfType operator +(ConstSelfTypeRef string);

		public:
			/**
			 * @brief Character concatenation addition assignment operator.
			 *
			 * @param ch The character to concatenate.
			 *
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator +=(ConstChar character);

			/**
			 * @brief String literal concatenation addition assignment operator.
			 *
			 * @param string The string literal to concatenate.
			 *
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator +=(ConstCharPtr string);

			/**
			 * @brief String concatenation addition assignment operator.
			 *
			 * @param string The string to concatenate.
			 *
			 * @return SelfTypeRef storing the modified string.
			 */
			SelfTypeRef operator +=(ConstSelfTypeRef string);

		public:
			/**
			 * @brief Gets the raw data of the string.
			 *
			 * @return ConstCharPtr storing the raw data.
			 */
			ConstCharPtr GetRawData(Void) const override;

		public:
			/**
			 * @brief Reserves capacity for the string.
			 * 
			 * This function causes the container to increase its capacity to n
			 * characters or greater, If the specified capacity is greater than
			 * the current string capacity, otherwise the capacity remains
			 * unchanged.
			 * 
			 * @param capacity The new capacity of the string.
			 */
			Void ReserveCapacity(Size capacity);

		public:
			/**
			 * @brief Assigns a single character to the string, replacing its
			 * current contents.
			 * 
			 * @param ch The character to assign.
			 * @param count The number of character occurances to assign.
			 */
			Void Assign(ConstChar ch, Size count);

			/**
			 * @brief Assigns a string literal to the string, replacing its
			 * current contents.
			 * 
			 * @param string The string literal to assign.
			 * @param count The number of characters to assign.
			 */
			Void Assign(ConstCharPtr string, Size count);

			/**
			 * @brief Assigns a string to the string, replacing its current
			 * contents.
			 *
			 * @param string The string to assign.
			 * @param count The number of characters to assign.
			 */
			Void Assign(ConstSelfTypeRef other, Size count);

		public:
			/**
			 * @brief Appends a character to the string, extending the string at
			 * the end of its current value.
			 * 
			 * @param ch The character to append.
			 * @param count The number of character occurances to append.
			 */
			Void Append(ConstChar ch, Size count);

			/**
			 * @brief Appends a string literal to the string, extending the
			 * string at the end of its current value.
			 * 
			 * @param string The string literal to append.
			 * @param count The number of characters to append.
			 */
			Void Append(ConstCharPtr string, Size count);

			/**
			 * @brief Appends a string to the string, extending the string at
			 * the end of its current value.
			 * 
			 * @param string The string to append.
			 * @param count The number of characters to append.
			 */
			Void Append(ConstSelfTypeRef string, Size count);

		public:
			/**
			 * @brief Inserts a character at the specified offset.
			 * 
			 * @param offset The index at which to insert.
			 * @param ch The character to insert.
			 * @param count The number of character occurances to insert.
			 */
			Void Insert(Size offset, ConstChar character, Size count);

			/**
			 * @brief Inserts a string literal at the specified offset.
			 * 
			 * @param offset The index at which to insert.
			 * @param string The string literal to insert.
			 * @param count The number of characters to insert.
			 */
			Void Insert(Size offset, ConstCharPtr string, Size count);

			/**
			 * @brief Inserts a string at the specified offset.
			 *
			 * @param offset The index at which to insert.
			 * @param string The string to insert.
			 * @param count The number of characters to insert.
			 */
			Void Insert(Size offset, ConstSelfTypeRef other, Size count);

		public:
			/**
			* @brief Removes a character at the specified offset.
			* 
			* @param offset The index at which to remove.
			*/
			Void Remove(Size offset);

			/**
			* @brief Removes characters in the specified range.
			* 
			* @param offset The index at which to remove.
			* @param count The number of characters to remove.
			*/
			Void Remove(Size offset, Size count);

		public:
			/**
			* @brief Clears the content of the string.
			*/
			Void Clear(Void);
		};
	}
}
#endif // STRING_H
