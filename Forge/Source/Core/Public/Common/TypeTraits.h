#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

#include <type_traits>

#include <Core/Public/Common/TypeDefinitions.h>

namespace Forge {
	namespace Common
	{
		template<I32 Value>
		struct TTraitInt
		{
			enum { Value = Value };
		};

		using TypeIsPod = TTraitInt<1>;
		using TypeIsClass = TTraitInt<0>;

		/**
		 * @brief Tests if a type is pod (plain old data).
		 */
		template<typename InType>
		struct TIsPod { enum { Value = __is_pod(InType) }; };
		
		/**
		 * @brief Tests if two types are assignable.
		 */
		template<typename InTypeOne, typename InTypeTwo> 
		struct TIsAssignable { enum { Value = std::is_assignable<InTypeOne, InTypeTwo>::value }; };

		/**
		 * @brief Tests if a type has a default constructor.
		 */
		template<typename InType>
		struct TIsTriviallyConstructible { enum { Value = __has_trivial_constructor(InType) }; };

		/**
		 * @brief Tests if a type has a default destructor.
		 */
		template<typename InType>
		struct TIsTriviallyDestructible { enum { Value = __has_trivial_destructor(InType) }; };

		/**
		 * @brief Tests if a type has a default copy constructor.
		 */
		template<typename InType>
		struct TIsTriviallyCopyConstructible { enum { Value = __has_trivial_copy(InType) }; };

		/**
		 * @brief Tests if a type has a default assignment operator.
		 */
		template<typename InType>
		struct TIsTriviallyCopyAssignable { enum { Value = __has_trivial_assign(InType) }; };

		/**
		 * @brief Tests whether two typenames are the same.
		 */
		template<typename InTypeOne, typename InTypeTwo>
		struct TAreSameType { enum { Value = false }; };

		template<typename InType>
		struct TAreSameType<InType, InType> { enum { Value = true }; };

		/**
		 * @brief Tests whether the predicate is true, if so returns the type.
		 */
		template<Bool Predicate, typename Result>
		struct TEnableIf { };

		template<typename Result>
		struct TEnableIf<true, Result> { using Type = Result; };

		/**
		 * @brief Tests whether class is derived from base.
		 */
		template<typename Derived, typename Base>
		struct IsBaseOf { static constexpr Bool value = __is_base_of(Base, Derived); };

		/**
		 * @brief Tests whether a type is const.
		 */
		template<typename InType>
		struct TIsConst { static constexpr Bool value = false; };

		template<typename InType>
		struct TIsConst<const InType> { static constexpr Bool value = true; };

		/**
		 * @brief Tests wether a type is pointer.
		 */
		template<typename InType>
		struct TIsPointer { enum { Value = false }; };

		template<typename InType>
		struct TIsPointer<InType*> { enum { Value = true }; };

		/**
		 * @brief Tests whether a type is l-value reference.
		 */
		template<typename InType>
		struct TIsLValueReference { enum { Value = false }; };

		template<typename InType>
		struct TIsLValueReference<InType&> { enum { Value = true }; };

		/**
		 * @brief Tests whether a type is r-value reference.
		 */
		template<typename InType>
		struct TIsRValueReference { enum { Value = false }; };

		template<typename InType>
		struct TIsRValueReference<InType&&> { enum { Value = true }; };
		
		/**
		 * @brief Tests whether a type is an unary functions.
		 */
		template<typename InType>
		struct TIsUnaryFunction { enum { Value = false }; };

		/**
		 * @brief Tests whether a type is a binary functions.
		 */
		template<typename InType>
		struct TIsBinaryFunction { enum { Value = false }; };

		/**
		 * @brief Test whether a type is arithmetic.
		 */
		template<typename InType>
		struct TIsArithmetic { enum { Value = false }; };

		template<> struct TIsArithmetic<Char> { enum { Value = true }; };

		template<> struct TIsArithmetic<U8>  { enum { Value = true }; };
		template<> struct TIsArithmetic<U16> { enum { Value = true }; };
		template<> struct TIsArithmetic<U32> { enum { Value = true }; };
		template<> struct TIsArithmetic<U64> { enum { Value = true }; };

		template<> struct TIsArithmetic<I8>  { enum { Value = true }; };
		template<> struct TIsArithmetic<I16> { enum { Value = true }; };
		template<> struct TIsArithmetic<I32> { enum { Value = true }; };
		template<> struct TIsArithmetic<I64> { enum { Value = true }; };

		template<> struct TIsArithmetic<F32> { enum { Value = true }; };
		template<> struct TIsArithmetic<F64> { enum { Value = true }; };

		template<typename InType>
		struct TIsArithmetic<const InType> { enum { Value = TIsArithmetic<InType>::Value }; };

		/**
		 * @brief Tests wether a type is signed.
		 */
		template<typename InType>
		struct TIsSigned { enum { Value = false }; };

		template<> struct TIsSigned<I8>  { enum { Value = true }; };
		template<> struct TIsSigned<I16> { enum { Value = true }; };
		template<> struct TIsSigned<I32> { enum { Value = true }; };
		template<> struct TIsSigned<I64> { enum { Value = true }; };

		template<> struct TIsSigned<F32> { enum { Value = true }; };
		template<> struct TIsSigned<F64> { enum { Value = true }; };

		template<typename InType>
		struct TIsSigned<const InType> { enum { Value = TIsSigned<InType>::Value }; };

		/**
		 * @brief Tests whether typename is floating point.
		 */
		template<typename InType>
		struct TIsFloatingPoint { enum { Value = false }; };

		template<> struct TIsFloatingPoint<F32> { enum { Value = true }; };
		template<> struct TIsFloatingPoint<F64> { enum { Value = true }; };

		template<typename InType>
		struct TIsFloatingPoint<const InType> { enum { Value = TIsFloatingPoint<InType>::Value }; };

		/**
		 * @brief Checks whether a type is double precision.
		 */
		template<typename InType>
		struct TIsDoublePrecision { enum { Value = false }; };

		template<> struct TIsDoublePrecision<F64> { enum { Value = true }; };

		template<typename InType>
		struct TIsDoublePrecision<const InType> { enum { Value = TIsDouble<InType>::Value }; };

		/**
		 * @brief Removes constant qualifiers from a type.
		 */
		template<typename InType>
		struct TRemoveConst { using Type = InType; };

		template<typename InType>
		struct TRemoveConst<const InType> { using Type = InType; };

		/**
		 * @brief Removes pointer qualifier from a type.
		 */
		template<typename InType>
		struct TRemovePointer { using Type = InType; };

		template<typename InType>
		struct TRemovePointer<InType*> { using Type = InType; };

		/**
		 * @brief Removes reference qualifiers from a type.
		 */
		template<typename InType>
		struct TRemoveRefernce { using Type = InType; };

		template<typename InType>
		struct TRemoveRefernce<InType&> { using Type = InType; };

		template<typename InType>
		struct TRemoveRefernce<InType&&> { using Type = InType; };
	}
}

#endif // TYPE_TRAITS_H
