#ifndef BINARY_FUNCTIONS_H
#define BINARY_FUNCTIONS_H

#include <Core/Public/Common/TypeDefinitions.h>

namespace Forge {
	namespace Algorithm
	{
		template<typename InArgumentOne, typename InArgumentTwo, typename OutOperationResult>
		struct BinaryFunction
		{
			using FirstArgumentType   = InArgumentOne;
			using SecondArgumentType  = InArgumentTwo;
			using OperationResultType = OutOperationResult;

			virtual OperationResultType operator ()(FirstArgumentType& a1, SecondArgumentType& a2) = 0;
		};

		/**
		 * @brief Binary function object implementing addition.
		 */
		template<typename InType>
		struct Plus : public BinaryFunction<InType, InType, InType>
		{
			InType operator ()(InType& a1, InType& a2) override { return a1 + a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(Plus)

		/**
		 * @brief Binary function object implementing subtraction.
		 */
		template<typename InType>
		struct Minus : public BinaryFunction<InType, InType, InType>
		{
			InType operator ()(InType& a1, InType& a2) override { return a1 - a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(Minus)

		/**
		 * @brief Binary function object implementing multiplication.
		 */
		template<typename InType>
		struct Multiply : public BinaryFunction<InType, InType, InType>
		{
			InType operator ()(InType& a1, InType& a2) override { return a1 * a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(Multiply)

		/**
		 * @brief Binary function object implementing division.
		 */
		template<typename InType>
		struct Divide : public BinaryFunction<InType, InType, InType>
		{
			InType operator ()(InType& a1, InType& a2) override { return a1 / a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(Divide)

		/**
		 * @brief Binary function object implementing modulus.
		 */
		template<typename InType>
		struct Modulus : public BinaryFunction<InType, InType, InType>
		{
			InType operator ()(InType& a1, InType& a2) override { return a1 % a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(Modulus)
		
		/**
		 * @brief Binary function object implementing equality.
		 */
		template<typename InType>
		struct EqualTo : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 == a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(EqualTo)

		/**
		 * @brief Binary function object implementing non-equality.
		 */
		template<typename InType>
		struct NotEqualTo : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 != a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(NotEqualTo)

		/**
		 * @brief Binary function object implementing greater than.
		 */
		template<typename InType>
		struct GreaterThan : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 > a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(GreaterThan)

		/**
		 * @brief Binary function object implementing less than.
		 */
		template<typename InType>
		struct LessThan : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 < a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(LessThan)

		/**
		 * @brief Binary function object implementing greatert than or equal.
		 */
		template<typename InType>
		struct GreaterThanOrEqual : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 >= a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(GreaterThanOrEqual)

		/**
		 * @brief Binary function object implementing less than or equal.
		 */
		template<typename InType>
		struct LessThanOrEqual : public BinaryFunction<InType, InType, Bool>
		{
			Bool operator ()(InType& a1, InType& a2) override { return a1 <= a2; }
		};

		FORGE_BINARY_FUNCTION_DECL(LessThanOrEqual)
	}
}

#endif // BINARY_FUNCTIONS_H
