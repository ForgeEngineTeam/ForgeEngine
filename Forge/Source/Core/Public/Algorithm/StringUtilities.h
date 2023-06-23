#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Algorithm
	{
		/**
		 * @brief Convert a character to lowercase.
		 *
		 * @param ch The character to convert.
		 * 
		 * @return Char storing the lowercase version of the character.
		 */
		FORGE_FORCE_INLINE Char ToCharacterLower(Char ch)
		{
			return ch | 32;
		}

		/**
		 * @brief Convert a character to uppercase.
		 *
		 * @param ch The character to convert.
		 *
		 * @return Char storing the uppercase version of the character.
		 */
		FORGE_FORCE_INLINE Char ToCharacterUpper(Char ch)
		{
			return ch ^ 32;
		}

		/**
		 * @brief Check if a string is null or empty.
		 *
		 * @param str The string to check.
		 * 
		 * @return True if the string is null or empty, false otherwise.
		 */
		FORGE_FORCE_INLINE Bool IsStringNullOrEmpty(ConstCharPtr str)
		{
			return str == nullptr || *str == '\0';
		}

		/**
		 * @brief Get the length of a  string.
		 *
		 * @param str The string to get the length of.
		 * 
		 * @return Size storing the length of the string.
		 */
		FORGE_FORCE_INLINE Size GetStringLength(ConstCharPtr str)
		{
			Size count = 0;

			while (*(str++) != '\0') count++;
			return count;
		}

		/**
		 * @brief Compare a string with another string.
		 *
		 * @param str_1 The string to compare.
		 * @param str_2 The other string to compare.
		 *
		 * @return Zero if equal, negative number if less than, positive
		 * number if greater than.
		 */
		FORGE_FORCE_INLINE I32 CompareString(ConstCharPtr str_1, ConstCharPtr str_2)
		{
			while (*str_1 && *str_2 &&
				  (*str_1 == *str_2))
			{
				str_1++;
				str_2++;
			}

			return *(I32*)str_1 - *(I32*)str_2;
		}

		/**
		 * @brief Compare a string with another string, without case
		 * sensitivity.
		 *
		 * @param str_1 The string to compare.
		 * @param str_2 The other string to compare.
		 *
		 * @return Zero if equal, negative number if less than, positive
		 * number if greater than.
		 */
		FORGE_FORCE_INLINE I32 CompareStringNoCase(ConstCharPtr str_1, ConstCharPtr str_2)
		{
			while (*str_1 && *str_2 &&
				  (ToCharacterLower(*str_1) == ToCharacterLower(*str_2)))
			{
				str_1++;
				str_2++;
			}

			return *(I32*)str_1 - *(I32*)str_2;
		}

		/**
		 * @brief Finds the index of the first occurrence of a character within
		 * a string.
		 * 
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The position to start the search from.
		 * 
		 * @return I32 storing the index of the first occurrence of the
		 * character, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindStringFirstOf(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = pos; i < str_length; i++)
				if (*(str + i) == ch)
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the first occurrence of a character within
		 * a string, without case sensitivity.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The position to start the search from.
		 *
		 * @return I32 storing the index of the first occurrence of the
		 * character, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindStringFirstOfNoCase(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = pos; i < str_length; i++)
				if (ToCharacterLower(*(str + i)) == ToCharacterLower(ch))
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the last occurrence of a character within
		 * a string.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The position to start the search from.
		 *
		 * @return I32 storing the index of the last occurrence of the
		 * character, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindStringLastOf(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = (str_length - 1) - pos; i >= 0; i--)
				if (*(str + i) == ch)
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the last occurrence of a character within
		 * a string, without case sensitivity.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The position to start the search from.
		 *
		 * @return I32 storing the index of the last occurrence of the
		 * character, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindStringLastOfNoCase(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = (str_length - 1) - pos; i >= 0; i--)
				if (ToCharacterLower(*(str + i)) == ToCharacterLower(ch))
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the first occurrence of a character not
		 * matching the specified character within a string.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The starting position for the search.
		 * 
		 * @return I32 storing the index of the first occurrence of the
		 * character not matching the specified character, or -1 if not
		 * found.
		 */
		FORGE_FORCE_INLINE I32 FindStringFirstNotOf(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = pos; i < str_length; i++)
				if (*(str + i) != ch)
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the first occurrence of a character not
		 * matching the specified character within a string, without case
		 * sensitivity.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The starting position for the search.
		 *
		 * @return I32 storing the index of the first occurrence of the
		 * character not matching the specified character, or -1 if not
		 * found.
		 */
		FORGE_FORCE_INLINE I32 FindStringFirstNotOfNoCase(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = pos; i < str_length; i++)
				if (ToCharacterLower(*(str + i)) != ToCharacterLower(ch))
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the last occurrence of a character not
		 * matching the specified character within a string.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The starting position for the search.
		 *
		 * @return I32 storing the index of the last occurrence of the
		 * character not matching the specified character, or -1 if not
		 * found.
		 */
		FORGE_FORCE_INLINE I32 FindStringLastNotOf(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = (str_length - 1) - pos; i >= 0; i--)
				if (*(str + i) != ch)
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the last occurrence of a character not
		 * matching the specified character within a string, without case
		 * sensitivity.
		 *
		 * @param str The string to search.
		 * @param ch The character to search for.
		 * @param pos The starting position for the search.
		 *
		 * @return I32 storing the index of the last occurrence of the
		 * character not matching the specified character, or -1 if not
		 * found.
		 */
		FORGE_FORCE_INLINE I32 FindStringLastNotOfNoCase(ConstCharPtr str, ConstChar ch, ConstSize pos)
		{
			ConstSize str_length = GetStringLength(str);

			for (I32 i = (str_length - 1) - pos; i >= 0; i--)
				if (ToCharacterLower(*(str + i)) != ToCharacterLower(ch))
					return i;

			return -1;
		}

		/**
		 * @brief Finds the index of the first occurrence of a substring
		 * within a string.
		 *
		 * @param str The string to search.
		 * @param substr The substring to search for.
		 * @param pos The position to start the search from.
		 *
		 * @return I32 storing the index of the first occurrence of the
		 * substring, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindSubString(ConstCharPtr str, ConstCharPtr substr, ConstSize pos)
		{
			/**
			 * TODO: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
			 * 
			 * Implemented approach is naive with O(n^2) time complexity.
			 * 
			 * Above link explains a more computaionaly faster algorithm known
			 * as the KMP algorithm.
			 */

			ConstSize str_length = GetStringLength(str);
			ConstSize substr_length = GetStringLength(substr);

			for (I32 i = pos; i < str_length - substr_length; i++)
				for (I32 j = 0; j < substr_length; j++)
				{
					if (*(str + (i + j)) != *(substr + j))
						break;

					return i;
				}

			return -1;
		}

		/**
		 * @brief Finds the index of the first occurrence of a substring
		 * within a string, without case sensitivity.
		 *
		 * @param str The string to search.
		 * @param substr The substring to search for.
		 * @param pos The position to start the search from.
		 *
		 * @return I32 storing the index of the first occurrence of the
		 * substring, or -1 if not found.
		 */
		FORGE_FORCE_INLINE I32 FindSubStringNoCase(ConstCharPtr str, ConstCharPtr substr, ConstSize pos)
		{
			/**
			 * TODO: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
			 *
			 * Implemented approach is naive with O(n^2) time complexity.
			 *
			 * Above link explains a more computaionaly faster algorithm known
			 * as the KMP algorithm.
			 */

			ConstSize str_length = GetStringLength(str);
			ConstSize substr_length = GetStringLength(substr);

			for (I32 i = pos; i <= str_length - substr_length; i++)
				for (I32 j = 0; j < substr_length; j++)
				{
					if (ToCharacterLower(*(str + (i + j))) != ToCharacterLower(*(substr + j)))
						break;

					return i;
				}

			return -1;
		}
	}
}

#endif // STRING_UTILITIES_H 
