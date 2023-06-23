#ifndef ABSTRACT_STRING_H
#define ABSTRACT_STRING_H

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Memory/Memory.h>
#include <Core/Public/Algorithm/Algorithm.h>
#include <Core/Public/Containers/Containers.h>

namespace Forge {
	namespace Common
	{
		/**
		 * @brief String search case specifing wether the search case is
		 * sensitive or not.
		 */
		enum class StringSearchCase
		{
			/**
			 * @brief Upper/Lower characters must match for strings to be considered equaL.
			 */
			FORGE_ENUM_DECL(CASE_SENSETIVE,   0)

			/**
			 * @brief Upper/Lower characters does not matter when making a comparison.
			 */
			FORGE_ENUM_DECL(CASE_INSENSITIVE, 1)

			MAX
		};

		template<typename InDerived>
		class AbstractString
		{
		private:
			using DerivedType         = InDerived;
			using DerivedTypePtr      = InDerived*;
			using DerivedTypeRef      = InDerived&;
			using DerivedTypeMoveRef  = InDerived&&;
			using ConstDerivedType    = const InDerived;
			using ConstDerivedTypeRef = const InDerived&;
			using ConstDerivedTypePtr = const InDerived*;

		private:
			using SelfType         = AbstractString;
			using SelfTypePtr      = AbstractString*;
			using SelfTypeRef      = AbstractString&;
			using SelfTypeMoveRef  = AbstractString&&;
			using ConstSelfType    = const AbstractString;
			using ConstSelfTypeRef = const AbstractString&;
			using ConstSelfTypePtr = const AbstractString*;

		protected:
			Size m_count;			/* The count of characters in the string. */
			Size m_max_capacity;	/* The maximum capacity of the string. */
		
		public:
			/**
			 * @brief Default constructor.
			 * 
			 * @param count The count of characters in the string.
			 * @param max_capacity The maximum capacity of the string.
			 */
			AbstractString(Size count, Size max_capacity)
				: m_count(count), m_max_capacity(max_capacity) {}

		public:
			/**
			 * @brief Default constructor.
			 * 
			 */
			virtual ~AbstractString(Void) = default;

		public:
			/**
			 * @brief Subscript operator.
			 *
			 * @param index The index of the character.
			 * 
			 * @return ConstChar& storing the character at the specified index.
			 * 
			 * @throws IndexOutOfRangeException if the index is out of range.
			 */
			ConstChar& operator [](Size index)
			{
				FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				return this->GetRawData()[index];
			}

		public:
			/**
			 * @brief Checks if the string is full.
			 * 
			 * @return True if the string is full, false otherwise.
			 */
			virtual Bool IsFull(Void) const
			{
				return this->m_count == this->m_max_capacity;
			}

			/**
			 * @brief Checks if the string is empty.
			 *
			 * @return True if the string is empty, false otherwise.
			 */
			virtual Bool IsEmpty(Void) const
			{
				return this->m_count == 0;
			}

		public:
			/**
			 * @brief Gets the count of characters in the string.
			 *
			 * @return Size storing the count of characters.
			 */
			virtual Size GetCount(Void) const
			{
				return this->m_count;
			}

			/**
			 * @brief Gets the maximum capacity of the string.
			 *
			 * @return Size storing the maximum capacity.
			 */
			virtual Size GetMaxCapacity(Void) const
			{
				return this->m_max_capacity;
			}

			/**
			 * @brief Gets the raw data of the string.
			 *
			 * @return ConstCharPtr storing the raw data.
			 */
			virtual ConstCharPtr GetRawData(Void) const = 0;

		public:
			/**
			 * @brief Gets a substring of the current string starting at the
			 * specified offset.
			 *
			 * @param offset The starting offset of the substring.
			 * 
			 * @return DerivedType storing the substring starting at the
			 * specified offset.
			 */
			virtual DerivedType GetSubString(ConstSize offset) const
			{
				FORGE_NOT_IMPLEMENTED()

				return DerivedType();
			}

			/**
			 * @brief Gets a substring of the current string starting at the
			 * specified offset and with the specified length.
			 *
			 * @param offset The starting offset of the substring.
			 * @param length The length of the substring.
			 * 
			 * @return DerivedType storing the substring starting at the
			 * specified offset and with the specified length.
			 */
			virtual DerivedType GetSubString(ConstSize offset, ConstSize length) const
			{
				FORGE_NOT_IMPLEMENTED()

				return DerivedType();
			}

		public:
			/**
			 * @brief Finds the index of the first occurrence of a character
			 * within the current string.
			 *
			 * @param ch The character to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return I32 storing the index of the first occurrence of the
			 * character, or -1 if not found.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range.
			 */
			virtual I32 FindFirstOf(ConstChar ch, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than or equal string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindStringFirstOf(this->GetRawData(), ch, pos);

				return Algorithm::FindStringFirstOfNoCase(this->GetRawData(), ch, pos);
			}

			/**
			 * @brief Finds the index of the last occurrence of a character
			 * within the current string.
			 *
			 * @param ch The character to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return I32 storing the index of the last occurrence of the
			 * character, or -1 if not found.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range.
			 */
			virtual I32 FindLastOf(ConstChar ch, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than or equal string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindStringLastOf(this->GetRawData(), ch, pos);

				return Algorithm::FindStringLastOfNoCase(this->GetRawData(), ch, pos);
			}

			/**
			 * @brief Finds the index of the first occurrence of a character 
			 * not matching the specified character within the current string.
			 *
			 * @param ch The character to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return I32 storing the index of the first occurrence of the
			 * character not matching the specified character, or -1 if not
			 * found.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range.
			 */
			virtual I32 FindFirstNotOf(ConstChar ch, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than or equal string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindStringFirstNotOf(this->GetRawData(), ch, pos);

				return Algorithm::FindStringFirstNotOfNoCase(this->GetRawData(), ch, pos);
			}
			
			/**
			 * @brief Finds the index of the last occurrence of a character
			 * not matching the specified character within the current string.
			 *
			 * @param ch The character to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return I32 storing the index of the last occurrence of the
			 * character not matching the specified character, or -1 if not
			 * found.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range.
			 */
			virtual I32 FindLastNotOf(ConstChar ch, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than or equal string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindStringLastNotOf(this->GetRawData(), ch, pos);

				return Algorithm::FindStringLastNotOfNoCase(this->GetRawData(), ch, pos);
			}
			
			/**
			 * @brief Finds the index of the first occurrence of any character
			 * from the specified character sequence within the current string.
			 *
			 * @param str The character sequence to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return I32 storing index of the first occurrence of any
			 * character from the specified character sequence, or -1 if not
			 * found.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range
			 * or the character sequence is empty.
			 */
			virtual I32 FindFirstOf(ConstCharPtr str, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				Size character_sequence_length = Algorithm::GetStringLength(str);

				if (search_case == StringSearchCase::CASE_SENSETIVE)
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringFirstOf(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}
				else
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringFirstOfNoCase(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}

				return -1;
			}
			
			/**
			 * @brief Finds the index of the last occurrence of any character
			 * from the specified character sequence within the current string.
			 *
			 * @param str The character sequence to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return I32 storing the index of the last occurrence of any
			 * character from the specified character sequence, or -1 if not
			 * found.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range
			 * or the character sequence is empty.
			 */
			virtual I32 FindLastOf(ConstCharPtr str, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				Size character_sequence_length = Algorithm::GetStringLength(str);

				if (search_case == StringSearchCase::CASE_SENSETIVE)
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringLastOf(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}
				else
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringLastOfNoCase(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}

				return -1;
			}

			/**
			 * @brief Finds the index of the first occurrence of any character
			 * not matching the specified character sequence within the current
			 * string.
			 *
			 * @param str The character sequence to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return I32 storing the index of the first occurrence of any
			 * character not matching the specified character sequence, or -1
			 * if not found.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range
			 * or the character sequence is empty.
			 */
			virtual I32 FindFirstNotOf(ConstCharPtr str, 
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				Size character_sequence_length = Algorithm::GetStringLength(str);

				if (search_case == StringSearchCase::CASE_SENSETIVE)
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringFirstNotOf(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}
				else
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringFirstNotOfNoCase(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}

				return -1;
			}

			/**
			 * @brief Finds the index of the last occurrence of any character
			 * not matching the specified character sequence within the current
			 * string.
			 *
			 * @param str The character sequence to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return I32 storing the index of the last occurrence of any
			 * character not matching the specified character sequence, or -1
			 * if not found.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the position is out of range
			 * or the character sequence is empty.
			 */
			virtual I32 FindLastNotOf(ConstCharPtr str,
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (Algorithm::IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				Size character_sequence_length = Algorithm::GetStringLength(str);

				if (search_case == StringSearchCase::CASE_SENSETIVE)
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringLastNotOf(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}
				else
				{
					for (I32 i = 0; i < character_sequence_length; i++)
						if (Algorithm::FindStringLastNotOfNoCase(this->GetRawData(), *(str + i), 0) >= 0)
							return i;
				}

				return -1;
			}

		public:
			/**
			 * @brief Finds the index of the first occurrence of a substring
			 * within the current string.
			 *
			 * @param substr The substring to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return I32 storing the index of the first occurrence of the
			 * substring, or -1 if not found.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty or
			 * the position is out of range.
			 */
			virtual I32 FindSubString(ConstCharPtr substr,
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (IsStringNullOrEmpty(substr))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (IsWithinValueBoundsExclusive(pos, (ConstSize)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindSubString(this->GetRawData(), substr, pos);

				return Algorithm::FindSubStringNoCase(this->GetRawData(), substr, pos);
			}

			/**
			 * @brief Finds the index of the first occurrence of a substring
			 * within the current string.
			 *
			 * @param substr The substring to search for.
			 * @param pos The position to start the search from. Default is 0.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return I32 storing the index of the first occurrence of the
			 * substring, or -1 if not found.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty or
			 * the position is out of range.
			 */
			virtual I32 FindSubString(ConstDerivedTypeRef substr,
				ConstSize pos = 0, StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (substr.IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (IsWithinValueBoundsExclusive(pos, (Size)0, this->GetCount()))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"Position is less than zero or greater than string length");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::FindSubString(this->GetRawData(), substr.GetRawData(), pos);

				return Algorithm::FindSubStringNoCase(this->GetRawData(), substr.GetRawData(), pos);
			}

		public:
			/**
			 * @brief Checks if the string starts with the specified substring.
			 *
			 * @param substr The substring to check for.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 * 
			 * @return True if the string starts with the substring, false
			 * otherwise.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty.
			 */
			virtual Bool StartsWith(ConstCharPtr substr, 
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				return this->FindSubString(substr, 0, search_case) == 0;
			}

			/**
			 * @brief Checks if the string starts with the specified substring.
			 *
			 * @param substr The substring to check for.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return True if the string starts with the substring, false
			 * otherwise.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty.
			 */
			virtual Bool StartsWith(ConstDerivedTypeRef substr,
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				return this->FindSubString(substr, 0, search_case) == 0;
			}

			/**
			 * @brief Checks if the string ends with the specified substring.
			 *
			 * @param substr The substring to check for.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return True if the string ends with the substring, false
			 * otherwise.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty.
			 */
			virtual Bool EndsWith(ConstCharPtr substr,
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				ConstSize index = this->FindSubString(substr, 0 , search_case);
				
				if (index < 0)
					return FORGE_FALSE;

				ConstSize substr_size = GetStringLength(this->GetRawData() + index);

				return (this->GetCount() - index) == substr_size;
			}

			/**
			 * @brief Checks if the string ends with the specified substring.
			 *
			 * @param substr The substring to check for.
			 * @param search_case The case sensitivity of the search. Default is CASE_SENSETIVE.
			 *
			 * @return True if the string ends with the substring, false
			 * otherwise.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the substring is empty.
			 */
			virtual Bool EndsWith(ConstDerivedTypeRef substr,
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				ConstSize index = this->FindSubString(substr, 0, search_case);

				if (index < 0)
					return false;

				ConstSize substr_size = GetStringLength(this->GetRawData() + index);

				return (this->GetCount() - index) == substr_size;
			}

		public:
			///**
			// * @brief Splits the string into substrings after the occurance of
			// * the specified delimiter.
			// * 
			// * @param ch[in] The delimiter to split the string after.
			// * 
			// * @return TDynamicArray<DerivedType> storing the splitted strings.
			// */
			//virtual TDynamicArray<DerivedType> Split(ConstChar ch) const
			//{
			//	FORGE_NOT_IMPLEMENTED()

			//	return TDynamicArray<DerivedType>();
			//}

			///**
			// * @brief Splits the string into substrings after the occurance of
			// * the a delimiter in the array of characters.
			// *
			// * @param str[in] The character array storing delimiters to split
			// * the string after.
			// *
			// * @return TDynamicArray<DerivedType> storing the splitted strings.
			// */
			//virtual TDynamicArray<DerivedType> Split(ConstCharPtr str) const
			//{
			//	FORGE_NOT_IMPLEMENTED()

			//	return TDynamicArray<DerivedType>();
			//}

		public:
			/**
			 * @brief Compare the string with another string.
			 *
			 * @param str The other string to compare.
			 * @param search_case The case sensitivity of the comparison. Default is CASE_SENSETIVE.
			 * 
			 * @return Zero if equal, negative number if less than, positive
			 * number if greater than.
		     * 
		     * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the other string is empty.
			 */
			virtual I32 Compare(ConstCharPtr str, 
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::CompareString(this->GetRawData(), str);

				return Algorithm::CompareStringNoCase(this->GetRawData(), str);
			}

			/**
			 * @brief Compare the string with another string.
			 *
			 * @param str The other string to compare.
			 * @param search_case The case sensitivity of the comparison. Default is CASE_SENSETIVE.
			 *
			 * @return Zero if equal, negative number if less than, positive
			 * number if greater than.
			 *
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the other string is empty.
			 */
			virtual I32 Compare(ConstDerivedTypeRef str, 
				StringSearchCase search_case = StringSearchCase::CASE_SENSETIVE) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (str.IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (search_case == StringSearchCase::CASE_SENSETIVE)
					return Algorithm::CompareString(this->GetRawData(), str.GetRawData());

				return Algorithm::CompareStringNoCase(this->GetRawData(), str.GetRawData());
			}

		public:
			/**
			 * @brief Compare lexicographicaly the string with another string.
			 *
			 * @param str The other string to compare.
			 * 
			 * @return True if the string is lexicographically less than the
			 * given string, false otherwise.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the other string is empty.
			 */
			virtual Bool LexicographicalCompare(ConstCharPtr str) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (Algorithm::IsStringNullOrEmpty(str))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				ConstCharPtr data = this->GetRawData();

				for (I32 i = 0; i < Algorithm::Min(this->GetCount(), GetStringLength(str)); i++)
					if (*(data + i) < *(str + i))
						return FORGE_TRUE;
					else
						return FORGE_FALSE;
			}

			/**
			 * @brief Compare lexicographicaly the string with another string.
			 *
			 * @param str The other string to compare.
			 *
			 * @return True if the string is lexicographically less than the
			 * given string, false otherwise.
			 * 
			 * @throws InvalidOperationException if the string is empty.
			 * @throws InvalidArgumentException if the other string is empty.
			 */
			virtual Bool LexicographicalCompare(ConstDerivedTypeRef str) const
			{
				if (this->IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"String is empty");

				if (str.IsEmpty())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_ARGUMENT,
						"String is empty");

				ConstCharPtr data = this->GetRawData();
				ConstCharPtr str_data = str.GetRawData();

				for (I32 i = 0; i < Algorithm::Min(this->GetCount(), str.GetCount()); i++)
					if (*(data + i) < *(str_data + i))
						return FORGE_TRUE;
					else
						return FORGE_FALSE;
			}
		};
	}
}

#endif // ABSTRACT_STRING_H
