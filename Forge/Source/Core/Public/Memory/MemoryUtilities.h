#ifndef MEMORY_UTILITIES_H
#define MEMORY_UTILITIES_H

#include <iostream>

#include <Core/Public/Common/Common.h>
#include <Core/Public/Algorithm/GeneralUtilities.h>

using namespace Forge::Common;

namespace Forge {
	namespace Memory
	{
		/**
		 * @brief Copies data from source memory buffer to destination memory buffer.
		 *
		 * @param[out] dst   The destination memory buffer where data will be copied to.
		 * @param[in]  src   The source memory buffer where data is stored.
		 * @param[in]  bytes The number of bytes to copy to the destination memory buffer.
		 */
		FORGE_FORCE_INLINE Void MemoryCopy(VoidPtr dst, VoidPtr src, Size bytes)
		{
			BytePtr temp_dst = reinterpret_cast<BytePtr>(dst);
			BytePtr temp_src = reinterpret_cast<BytePtr>(src);

			for (int i = 0; i < bytes; i++)
				*(temp_dst + i) = *(temp_src + i);
		}

		/**
		 * @brief Sets the destination memory buffer to the value specified.
		 *
		 * @param[out] dst   The destination memory buffer where data will be set.
		 * @param[in]  value The value the memory buffer will be set to.
		 * @param[in]  bytes The number of bytes to copy to the destination memory buffer.
		 */
		FORGE_FORCE_INLINE Void MemorySet(VoidPtr dst, Byte value, Size bytes)
		{
			BytePtr temp_dst = reinterpret_cast<BytePtr>(dst);

			for (int i = 0; i < bytes; i++)
				*(temp_dst + i) = value;
		}

		/**
		 * @brief Compares the data stored in two memory buffers.
		 *
		 * @param[in] lh_address The left-hand side memory buffer to compare.
		 * @param[in] rh_address The right-hand side memory buffer to comapre.
		 * @param[in] bytes      The number of bytes in the memory buffers.
		 *
		 * @returns True if the data stored in the memory buffers are equal.
		 */
		FORGE_FORCE_INLINE Bool MemoryCompare(VoidPtr lh_address, VoidPtr rh_address, Size bytes)
		{
			if (lh_address == rh_address)
				return FORGE_TRUE;

			BytePtr temp_lh = reinterpret_cast<BytePtr>(lh_address);
			BytePtr temp_rh = reinterpret_cast<BytePtr>(rh_address);

			for (U32 i = 0; i < bytes; i++)
				if (*(temp_lh + i) != *(temp_rh + i))
					return FORGE_FALSE;

			return FORGE_TRUE;
		}

		/**
		 * @brief Compares the data stored in two memory buffers.
		 *
		 * @param[in] lh_address The left-hand side memory buffer to compare.
		 * @param[in] rh_address The right-hand side memory buffer to comapre.
		 * @param[in] bytes      The number of bytes in the memory buffers.
		 *
		 * @returns True if the data stored in the memory buffers are equal.
		 */
		FORGE_FORCE_INLINE Bool MemoryCompare(ConstVoidPtr lh_address, ConstVoidPtr rh_address, Size bytes)
		{
			if (lh_address == rh_address)
				return FORGE_TRUE;

			ConstBytePtr temp_lh = reinterpret_cast<ConstBytePtr>(lh_address);
			ConstBytePtr temp_rh = reinterpret_cast<ConstBytePtr>(rh_address);

			for (U32 i = 0; i < bytes; i++)
				if (*(temp_lh + i) != *(temp_rh + i))
					return FORGE_FALSE;

			return FORGE_TRUE;
		}

		namespace
		{
			template<typename InType>
			FORGE_FORCE_INLINE Void ConstructImpl(InType* dst, Size count, TypeIsPod)
			{
				FORGE_NOT_IMPLEMENTED()
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void ConstructImpl(InType* dst, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					new (dst + i) InType();
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void DestructImpl(InType* dst, Size count, TypeIsPod)
			{
				FORGE_NOT_IMPLEMENTED()
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void DestructImpl(InType* dst, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					(dst + i)->~InType();
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void MoveImpl(InType* dst, InType&& temp, Size count, TypeIsPod)
			{
				for (U32 i = 0; i < count; i++)
					MemoryCopy(dst + i, &temp, sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void MoveImpl(InType* dst, InType&& temp, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					*(dst + i) = Algorithm::Move(temp);
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void CopyImpl(InType* dst, const InType& copy, Size count, TypeIsPod)
			{
				for (U32 i = 0; i < count; i++)
					MemoryCopy(dst + i, const_cast<InType*>(&copy), sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void CopyImpl(InType* dst, const InType& copy, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					*(dst + i) = copy;
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void MoveConstructImpl(InType* dst, InType&& temp, Size count, TypeIsPod)
			{
				for (U32 i = 0; i < count; i++)
					MemoryCopy(dst + i, &temp, sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void MoveConstructImpl(InType* dst, InType&& temp, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					new (dst + i) InType(Algorithm::Move(temp));
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void CopyConstructImpl(InType* dst, const InType& copy, Size count, TypeIsPod)
			{
				for (U32 i = 0; i < count; i++)
					MemoryCopy(dst + i, const_cast<InType*>(&copy), sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void CopyConstructImpl(InType* dst, const InType& copy, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					new (dst + i) InType(copy);
			}

			template<typename InType>
			FORGE_FORCE_INLINE Bool CompareArrayImpl(const InType* lh_array, const InType* rh_array, Size count, TypeIsPod)
			{
				return MemoryCompare(lh_array, rh_array, count * sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Bool CompareArrayImpl(const InType* lh_array, const InType* rh_array, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					if (*(lh_array + i) != *(rh_array + i))
						return FORGE_FALSE;

				return FORGE_TRUE;
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void CopyArrayImpl(InType* dst, InType* src, Size count, TypeIsPod)
			{
				MemoryCopy(dst, src, count * sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void CopyArrayImpl(InType* dst, InType* src, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					*(dst + i) = *(src + i);
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void MoveConstructArrayImpl(InType* dst, InType* src, Size count, TypeIsPod)
			{
				MemoryCopy(dst, src, count * sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void MoveConstructArrayImpl(InType* dst, InType* src, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					new (dst + i) InType(Algorithm::Move(*(src + i)));
			}

			template<typename InType>
			FORGE_FORCE_INLINE Void CopyConstructArrayImpl(InType* dst, InType* src, Size count, TypeIsPod)
			{
				MemoryCopy(dst, src, count * sizeof(InType));
			}
			template<typename InType>
			FORGE_FORCE_INLINE Void CopyConstructArrayImpl(InType* dst, InType* src, Size count, TypeIsClass)
			{
				for (U32 i = 0; i < count; i++)
					new (dst + i) InType(*(src + i));
			}
		}

		/**
		 * @brief Constructs object type a number of types in an array
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array where type will be constructed.
		 * @param[in]  count The number of element to construct in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void Construct(InType* dst, Size count)
		{
			ConstructImpl(dst, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Destructs object type a number of times in an array
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst The destination array where type will be destructed.
		 * @param[in]  count The number of element to construct in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void Destruct(InType* dst, Size count)
		{
			DestructImpl(dst, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Moves an object a number of times in an array.
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array where the copies will be stored.
		 * @param[in]  copy  The copy of the object to store in the array.
		 * @param[in]  count The number of element copies to store in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void Move(InType* dst, InType&& temp, Size count)
		{
			MoveImpl(dst, Algorithm::Move(temp), count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Copies an object a number of times in an array.
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array where the copies will be stored.
		 * @param[in]  copy  The copy of the object to store in the array.
		 * @param[in]  count The number of element copies to store in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void Copy(InType* dst, const InType& copy, Size count)
		{
			CopyImpl(dst, copy, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Copy constructs an object a number of times in an array.
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array where the copies will be stored.
		 * @param[in]  copy  The copy of the object to store in the array.
		 * @param[in]  count The number of element copies to store in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void CopyConstruct(InType* dst, const InType& copy, Size count)
		{
			CopyConstructImpl(dst, copy, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Move constructs an object a number of times in an array.
		 *
		 * The destination array should have enough allocated space to
		 * store the wanted number of copies. If the count is larger than the
		 * allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array where the copies will be stored.
		 * @param[in]  temp  The copy of the object to store in the array.
		 * @param[in]  count The number of element copies to store in the array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void MoveConstruct(InType* dst, InType&& temp, Size count)
		{
			MoveConstructImpl(dst, Algorithm::Move(temp), count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Compares the data stored in two arrays.
		 *
		 * @param[in] lh_array The left-hand side array to comapre.
		 * @param[in] rh_array The right-hand side array to compare.
		 * @param[in] count    The number of elements in the arrays.
		 *
		 * @returns True if the data stored in the arrays are equal.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Bool CompareArray(const InType* lh_array, const InType* rh_array, Size count)
		{
			return CompareArrayImpl(lh_array, rh_array, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Copies the elements stored in source array to destination array
		 *
		 * The number of bytes should be equal to the allocated space of both the
		 * destination and source arrays. If the number of bytes is larger than
		 * the allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array to copy elements to.
		 * @param[in]  src   The source array where elementa will be copied from.
		 * @param[in]  count The number of elements to copy to the destination array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void CopyArray(InType* dst, InType* src, Size count)
		{
			CopyArrayImpl(dst, src, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Move constructs the elements stored in source array to
		 * destiniation array.
		 *
		 * The number of bytes should be equal to the allocated space of both the
		 * destination and source arrays. If the number of bytes is larger than
		 * the allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array to copy elements to.
		 * @param[in]  src   The source array where elementa will be moved from.
		 * @param[in]  count The number of elements to move to the destination array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void MoveConstructArray(InType* dst, InType* src, Size count)
		{
			MoveConstructArrayImpl(dst, src, count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Copy constructs the elements stored in source array to
		 * destiniation array.
		 *
		 * The number of bytes should be equal to the allocated space of both the
		 * destination and source arrays. If the number of bytes is larger than
		 * the allocated space undefined behaviour might occur.
		 *
		 * @param[out] dst   The destination array to copy elements to.
		 * @param[in]  src   The source array where elementa will be copied from.
		 * @param[in]  count The number of elements to copy to the destination array.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE Void CopyConstructArray(InType* dst, InType* src, Size ui_count)
		{
			CopyConstructArrayImpl(dst, src, ui_count, TTraitInt<TIsPod<InType>::Value>());
		}

		/**
		 * @brief Aligns address to an alignment boundry and retrieves the first aligned
		 * address after the address passed.
		 *
		 * @param[in] address   The address to align.
		 * @param[in] alignment The alignment requirment of the memory, must be power of two.
		 *
		 * @returns VoidPtr storing the aligned address.
		 */
		FORGE_FORCE_INLINE VoidPtr AlignAddressUpward(VoidPtr address, Byte alignment)
		{
			return reinterpret_cast<VoidPtr>(((reinterpret_cast<U64>(address) + (alignment - 1)) & ~(alignment - 1)));
		}

		/**
		 * @brief Aligns address to an alignment boundry and retrieves the first aligned
		 * address before the address passed.
		 *
		 * @param[in] address   The address to align.
		 * @param[in] alignment The alignment requirment of the memory, must be power of two.
		 *
		 * @returns VoidPtr storing the aligned address.
		 */
		FORGE_FORCE_INLINE VoidPtr AlignAddressBackward(VoidPtr address, Byte alignment)
		{
			return reinterpret_cast<VoidPtr>((reinterpret_cast<U64>(address) & ~(alignment - 1)));
		}

		/**
		 * @brief Calculates how many bytes are need to align the address upwards.
		 *
		 * @param[in] address   The address to align.
		 * @param[in] alignment The Alignment requirment of the memory, must be power of two.
		 *
		 * @returns Size storing the number of bytes needed to align the address.
		 */
		FORGE_FORCE_INLINE Size AlignAddressUpwardAdjustment(VoidPtr address, Byte alignment)
		{
			Size adjustment = alignment - (reinterpret_cast<U64>(address) & (alignment - 1));
			return adjustment != alignment ? adjustment : 0;
		}

		/**
		 * @brief Calculates how many bytes are need to align the address backwards.
		 *
		 * @param[in] address   The address to align.
		 * @param[in] alignment The alignment requirment of the memory, must be power of two.
		 *
		 * @returns Size storing the number of bytes needed to align the address.
		 */
		FORGE_FORCE_INLINE Size AlignAddressBackwardAdjustment(VoidPtr address, Byte alignment)
		{
			Size adjustment = (reinterpret_cast<U64>(address) & (alignment - 1));
			return adjustment != alignment ? adjustment : 0;
		}

		/**
		 *@brief Checks whether address is aligned to a specific alignment boundry.
		 *
		 *@param[in] address   The address to check for alignment.
		 *@param[in] alignment The alignment requirment of the memory, must be power of two.
		 *
		 * @returns True if the address is aligned.
		 */
		FORGE_FORCE_INLINE Bool IsAddressAligned(VoidPtr address, Byte alignment)
		{
			return AlignAddressUpwardAdjustment(address, alignment) == 0;
		}

		/**
		 * @brief Performs addition on a raw memory address.
		 *
		 * @param[in] address The address to perform addition on.
		 * @param[in] bytes   The number of bytes to add to the address.
		 *
		 * @returns VoidPtr storing the resultant address.
		 */
		FORGE_FORCE_INLINE VoidPtr AddAddress(VoidPtr address, Size bytes)
		{
			return reinterpret_cast<VoidPtr>((reinterpret_cast<U64>(address) + bytes));
		}

		/**
		 * @brief Performs addition on two raw memory addresses.
		 *
		 * @param[in] lh_address The left-hand side address.
		 * @param[in] rh_address the right-hand side address.
		 *
		 * @returns VoidPtr storing the resultant address.
		 */
		FORGE_FORCE_INLINE VoidPtr AddAddress(VoidPtr lh_address, VoidPtr rh_address)
		{
			return reinterpret_cast<VoidPtr>((reinterpret_cast<U64>(lh_address) + reinterpret_cast<U64>(rh_address)));
		}

		/**
		 * @brief Performs subtraction on a raw memory address.
		 *
		 * @param[in] address The address to perform subtraction on.
		 * @param[in] bytes   The number of bytes to subtract from the address.
		 *
		 * @returns VoidPtr storing the resultant address.
		 */
		FORGE_FORCE_INLINE VoidPtr SubAddress(VoidPtr address, Size bytes)
		{
			return reinterpret_cast<VoidPtr>((reinterpret_cast<U64>(address) - bytes));
		}

		/**
		 * @brief Performs subtraction on two raw memory addresses.
		 *
		 * @param[in] lh_address The left-hand side address.
		 * @param[in] rh_address the right-hand side address.
		 *
		 * @returns VoidPtr storing the resultant address.
		 */
		FORGE_FORCE_INLINE VoidPtr SubAddress(VoidPtr lh_address, VoidPtr rh_address)
		{
			return reinterpret_cast<VoidPtr>((reinterpret_cast<U64>(lh_address) - reinterpret_cast<U64>(rh_address)));
		}

		/**
		 * @brief Performs subtraction on two const raw memory addresses.
		 *
		 * @param[in] lh_address The left-hand side address.
		 * @param[in] rh_address the right-hand side address.
		 *
		 * @returns VoidPtr storing the resultant address.
		 */
		FORGE_FORCE_INLINE ConstVoidPtr SubAddress(ConstVoidPtr lh_address, ConstVoidPtr rh_address)
		{
			return reinterpret_cast<ConstVoidPtr>((reinterpret_cast<U64>(lh_address) - reinterpret_cast<U64>(rh_address)));
		}

		/**
		 * @brief Checks whether the address is within bounds of the allocated memory.
		 *
		 * @param[in] start_address  The starting address of the memory pool.
		 * @param[in] address        The address to bound check.
		 * @param[in] total_Size     The total Size of the memory pool.
		 *
		 * @return True if the address within the passed bounds.
		 */
		FORGE_FORCE_INLINE Bool WithinAddressBounds(VoidPtr start_address, VoidPtr address, Size total_size)
		{
			return reinterpret_cast<U64>(address) >= reinterpret_cast<U64>(start_address) &&
				reinterpret_cast<U64>(address) < reinterpret_cast<U64>(start_address) + total_size;
		}
	}
}

#endif // MEMORY_UTILITIES_H
