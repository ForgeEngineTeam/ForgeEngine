#ifndef T_PAIR_H
#define T_PAIR_H

#include <Core/Public/Common/Common.h>

#include <Core/Public/Algorithm/GeneralUtilities.h>

using namespace Forge::Algorithm;

namespace Forge {
	namespace Common
	{
		/**
	     * @brief Class template that allows to store two heterogeneous objects as
	     * a single unit.
	     *
	     * @author Karim Hisham
	     */
		template<typename InTypeOne, typename InTypeTwo>
		struct TPair
		{
		public:
			using FirstType         = InTypeOne;
			using FirstTypePtr      = InTypeOne*;
			using FirstTypeRef      = InTypeOne&;
			using FirstTypeMoveRef  = InTypeOne&&;
			using ConstFirstType    = const InTypeOne;
			using ConstFirstTypePtr = const InTypeOne*;
			using ConstFirstTypeRef = const InTypeOne&;

		public:
			using SecondType         = InTypeTwo;
			using SecondTypePtr      = InTypeTwo*;
			using SecondTypeRef      = InTypeTwo&;
			using SecondTypeMoveRef  = InTypeTwo&&;
			using ConstSecondType    = const InTypeTwo;
			using ConstSecondTypePtr = const InTypeTwo*;
			using ConstSecondTypeRef = const InTypeTwo&;

		private:
			using SelfType          = TPair<FirstType, SecondType>;
			using SelfTypePtr       = TPair<FirstType, SecondType>*;
			using SelfTypeRef       = TPair<FirstType, SecondType>&;
			using SelfTypeMoveRef   = TPair<FirstType, SecondType>&&;
			using ConstSelfType     = const TPair<FirstType, SecondType>;
			using ConstSelfTypePtr  = const TPair<FirstType, SecondType>*;
			using ConstSelfTypeRef  = const TPair<FirstType, SecondType>&;

		public:
			FirstType m_first;
			SecondType m_second;

		public:
			/**
			 * @brief Default constructor.
			 */
			TPair(Void)
				: m_first(), m_second() {}

			/**
			 * @brief Move items constructor.
			 */
			TPair(FirstTypeMoveRef first, SecondTypeMoveRef second)
				: m_first(Move(first)), m_second(Move(second)) {}

			/**
			 * @brief Copy items constructor.
			 */
			TPair(ConstFirstTypeRef first, ConstSecondTypeRef second)
				: m_first(first), m_second(second) {}

		public:
			/**
			 * @brief Move constructor.
			 */
			TPair(SelfTypeMoveRef other)
			{
				*this = Move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TPair(ConstSelfTypeRef other)
			{
				*this = other;
			}

		public:
			/**
			 * @brief Move assignment.
			 */
			SelfTypeRef operator =(SelfTypeMoveRef other)
			{
				this->m_first = Move(other.m_first);
				this->m_second = Move(other.m_second);

				return *this;
			}

			/**
			 * @brief Copy assignment
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				this->m_first = other.m_first;
				this->m_second = other.m_second;

				return *this;
			}
		};
	}
}

#endif // T_PAIR_H
