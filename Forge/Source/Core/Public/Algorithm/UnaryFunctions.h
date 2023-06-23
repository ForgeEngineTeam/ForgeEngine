#ifndef UNARY_FUNCTIONS_H
#define UNARY_FUNCTIONS_H

#include <Core/Public/Common/Common.h>

using namespace Forge::Common;

namespace Forge {
	namespace Algorithm
	{
		template<typename InArgument, typename OutOperationResult>
		struct UnaryFunction
		{
			using ArgumentType        = InArgument;
			using OperationResultType = OutOperationResult;

			virtual OperationResultType operator ()(ArgumentType& a1) = 0;
		};

		/**
		 * @brief Unary function object implementing default unit deleter.
		 */
		template<typename InType>
		struct DefaultUnitDeleter : public UnaryFunction<InType, Void>
		{
			Void operator ()(InType& a1) override { FORGE_SAFE_DELETE_UNIT(a1) }
		};

		FORGE_UNARY_FUNCTION_DECL(DefaultUnitDeleter)
	}
}

#endif // UNARY_FUNCTIONS_H
