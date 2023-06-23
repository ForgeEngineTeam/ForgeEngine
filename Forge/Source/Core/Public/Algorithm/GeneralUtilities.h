#ifndef GENERAL_UTILITIES_H
#define GENERAL_UTILITIES_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Containers
	{
		template<typename InTypeOne, typename InTypeTwo>
		struct TPair;
	}
}

namespace Forge {
	namespace Algorithm
	{
		namespace Internal
		{
			template<typename InType,
				Bool IsFloatingPoint = Common::TIsFloatingPoint<InType>::Value,
				Bool IsDoublePrecision = Common::TIsDoublePrecision<InType>::Value>
			struct EndiannessImpl {};

			template<typename InType>
			struct EndiannessImpl<InType, false, false>
			{
				static Void SwapEndian(InType data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						*buffer = (data & (0xFF << (sizeof(data) - 1) * 8)) >> ((sizeof(data) - 1) * 8);
						return;
					}

					EndiannessImpl<InType, false, false>::SwapEndian(data, buffer + 1, size - 1);

					data = data << 8;
					*buffer = (data & (0xFF << (sizeof(data) - 1) * 8)) >> ((sizeof(data) - 1) * 8);
				}

				static Void RegisterEndian(InType& data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						data |= (InType)(*buffer);
						return;
					}

					data |= (InType)(*buffer);
					data = data << 8;

					EndiannessImpl<InType, false, false>::RegisterEndian(data, buffer + 1, size - 1);
				}
			};

			template<typename InType>
			struct EndiannessImpl<InType, true, false>
			{
				union U32F32
				{
					U32 i;
					F32 f;
				} static union_helper;

				static Void SwapEndian(InType data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						*buffer = (union_helper.i & 0xFF000000) >> 24;
						return;
					}

					EndiannessImpl<InType, true, false>::SwapEndian(data, buffer + 1, size - 1);

					union_helper.i = union_helper.i << 8;
					*buffer = (union_helper.i & 0xFF000000) >> 24;
				}

				static Void RegisterEndian(InType& data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						union_helper.i |= (U32)(*buffer);
						data = union_helper.f;
						return;
					}

					union_helper.i |= (U32)(*buffer);
					union_helper.i = union_helper.i << 8;

					EndiannessImpl<InType, true, false>::RegisterEndian(data, buffer + 1, size - 1);
				}
			};

			template<typename InType>
			struct EndiannessImpl<InType, true, true>
			{
				union U64F64
				{
					U64 i;
					F64 f;
				} static union_helper;

				static Void SwapEndian(InType data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						*buffer = (union_helper.i & 0xFF00000000) >> 32;
						return;
					}

					EndiannessImpl<InType, true, true>::SwapEndian(data, buffer + 1, size - 1);

					union_helper.i = union_helper.i << 8;
					*buffer = (union_helper.i & 0xFF00000000) >> 32;
				}

				static Void RegisterEndian(InType& data, BytePtr buffer, Size size)
				{
					if (size == 1)
					{
						union_helper.i |= (U64)(*buffer);
						data = union_helper.f;
						return;
					}

					union_helper.i |= (U64)(*buffer);
					union_helper.i = union_helper.i << 8;

					EndiannessImpl<InType, true, true>::RegisterEndian(data, buffer + 1, size - 1);
				}
			};
		}

		/**
		 * @brief Swaps a given data's endian format and stores the conversion.
		 *
		 * @param[in]  data The data to convert its endian format.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto SwapEndian(InType& data)
			-> Void
		{
			mutable Byte buffer[sizeof(data)];

			if (Common::TIsFloatingPoint<InType>::Value)
				Internal::EndiannessImpl<InType>::union_helper.f = data;

			Internal::EndiannessImpl<InType>::SwapEndian(data, buffer, sizeof(data));

			if (Common::TIsFloatingPoint<InType>::Value)
				Internal::EndiannessImpl<InType>::union_helper.i = 0;

			Internal::EndiannessImpl<InType>::RegisterEndian(data, buffer, sizeof(data));
		}

		/**
		 * @brief Converts an argument to an r-value reference indicating that this
		 * object may be moved, allowing efficient transfer of resources to another
		 * object.
		 *
		 * @param arg The object to be moved.
		 *
		 * @return InType&& storing an r-value reference to the object.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto Move(InType&& arg)
			-> typename Common::TRemoveRefernce<InType>::Type&&
		{
			return static_cast<typename Common::TRemoveRefernce<InType>::Type&&>(arg);
		}

		/**
		 * @brief Swaps the content of two varibales.
		 *
		 * @param lhs The left-hand side variable to swap.
		 * @param rhs The right-hand side variable to swap.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto Swap(InType& lhs, InType& rhs)
			-> Void
		{
			InType tmp = Move(lhs); lhs = Move(rhs); rhs = Move(tmp);
		}

		/**
		 * @brief Replaces the value of the passed object with a new value and
		 * returns the old value.
		 *
		 * @param obj The object whose value to replace.
		 * @param val The new value to assign to the object.
		 *
		 * @returns InDataType storing the old value of the object.
		 */
		template<typename InObjectType, typename InDataType = InObjectType>
		FORGE_FORCE_INLINE auto Exchange(InObjectType& obj, InDataType&& val)
			-> InDataType
		{
			InObjectType tmp = Move(obj); obj = Move(val); return tmp;
		}

		/**
		 * @brief Returns the smallest between two values.
		 * 
		 * @param lhs The left-hand side value to compare.
		 * @param rhs The right-hand side value to compare.
		 * 
		 * @return ConstInTypeRef storing the smallest value.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto Min(const InType& lhs, const InType& rhs)
			-> const InType&
		{
			return lhs < rhs ? lhs : rhs;
		}

		/**
		 * @brief Returns the largest between two values.
		 * 
		 * @param lhs The left-hand side value to compare.
		 * @param rhs The right-hand side value to compare.
		 * 
		 * @return ConstInTypeRef storing the largest value.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto Max(const InType& lhs, const InType& rhs)
			-> const InType&
		{
			return lhs > rhs ? lhs : rhs;
		}

		/**
		 * @brief Returns a pair storing the smallest and largest passed values.
		 *
		 * @param lhs  The left-hand side value to compare.
		 * @param rhs  The right-hand side value to compare.
		 *
		 * @return TPair storing the smallest value in the first item and the
		 * largest value in the second item.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto MinMax(const InType& lhs, const InType& rhs)
			-> Containers::TPair<const InType&, const InType&>
		{
			return lhs < rhs ? Containers::TPair<const InType&, const InType&>(lhs, rhs)
							 : Containers::TPair<const InType&, const InType&>(rhs, lhs);
		}
		
		/**
		 * @brief Clamps the value passed between two boundries, low and high.
		 *
		 * If the value is less than the low boundry return the low boundry value
		 * and if the value is larger than the high boundry return the high boundry.
		 *
		 * @param val The value to clamp.
		 * @param low  The low boundry to clamp to.
		 * @param high The high boundry to clamp to.
		 *
		 * @return ConstInTypeRef storing the clampped value.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto Clamp(const InType& val, const InType& low, const InType& high)
			-> const InType&
		{
			return val < low ? low : val > high ? high : val;
		}

		/**
		 * @brief Returns the smallest between two values.
		 *
		 * @param lhs  The left-hand side value to compare.
		 * @param rhs  The right-hand side value to compare.
		 * @param comp Comparison binary function object which returns true if lhs
		 * is smaller than rhs.
		 * 
		 * @return ConstInTypeRef storing the smallest value.
		 */
		template<typename InType, typename InComparer>
		FORGE_FORCE_INLINE auto Min(const InType& lhs, const InType& rhs, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, const InType&>::Value
		{
			return comp(lhs, rhs) ? lhs : rhs;
		}

		/**
		 * @brief Returns the largest between two values.
		 *
		 * @param lhs  The left-hand side value to compare.
		 * @param rhs  The right-hand side value to compare.
		 * @param comp Comparison binary function object which returns true if lhs
		 * is larger than rhs.
		 *
		 * @return ConstInTypeRef storing the smallest value.
		 */
		template<typename InType, typename InComparer>
		FORGE_FORCE_INLINE auto Max(const InType& lhs, const InType& rhs, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, const InType&>::Value
		{
			return comp(lhs, rhs) ? lhs : rhs;
		}

		/**
		 * @brief Returns a pair storing the smallest and largest passed values.
		 *
		 * @param lhs  The left-hand side value to compare.
		 * @param rhs  The right-hand side value to compare.
		 * @param comp Comparison binary function object which returns true if lhs
		 * is smaller than rhs.
		 *
		 * @return TPair storing the smallest value in the first item and the
		 * largest value in the second item.
		 */
		template<typename InType, typename Comprarer>
		FORGE_FORCE_INLINE auto MinMax(const InType& lhs, const InType& rhs, Comprarer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<Comprarer>::Value, Containers::TPair<const InType&, const InType&>>::Value
		{
			return comp(lhs, rhs) ? Containers::TPair<const InType&, const InType&>(lhs, rhs)
				                  : Containers::TPair<const InType&, const InType&>(rhs, lhs);
		}

		/**
		 * @brief Clamps the value passed between two boundries, low and high.
		 *
		 * If the value is less than the low boundry return the low boundry value
		 * and if the value is larger than the high boundry return the high boundry.
		 *
		 * @param val The value to clamp.
		 * @param low  The low boundry to clamp to.
		 * @param high The high boundry to clamp to.
		 * @param comp Comparison binary function object which returns true if lhs
		 * is smaller than rhs.
		 *
		 * @return ConstInTypeRef storing the clampped value.
		 */
		template<typename InType, typename InComparer>
		FORGE_FORCE_INLINE auto Clamp(const InType& val, const InType& low, const InType& high, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, const InType&>::Value
		{
			return comp(val, low) ? low : comp(high, val) ? high : val;
		}

		/**
		 * @brief Checks wether the value passed is between two boundries, low and
		 * high.
		 *
		 * This operation considers the high boundry part of the set of values
		 * between the two boundries passed.
		 *
		 * @param val  The value to check if within bounds.
		 * @param low  The low boundry to check against.
		 * @param high The high boundry to check against.
		 *
		 * @return True if the passed value is between the two boundries passed.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto IsWithinValueBoundsInclusive(const InType& val, const InType& low, const InType& high)
			-> Bool
		{
			return val >= low && val <= high;
		}

		/**
		 * @brief Checks wether the value passed is between two boundries, low and
		 * high.
		 *
		 * This operation considers the high boundry not part of the set of values
		 * between the two boundries passed.
		 *
		 * @param val  The value to check if within bounds.
		 * @param low  The low boundry to check against.
		 * @param high The high boundry to check against.
		 *
		 * @return True if the passed value is between the two boundries passed.
		 */
		template<typename InType>
		FORGE_FORCE_INLINE auto IsWithinValueBoundsExclusive(const InType& val, const InType& low, const InType& high)
			-> Bool
		{
			return val >= low && val < high;
		}
	}
}

#endif // GENERAL_UTILITIES_H
