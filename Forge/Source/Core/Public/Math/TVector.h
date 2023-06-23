#ifndef T_VECTOR_H
#define T_VECTOR_H

#include "Core/Public/Common/Common.h"

namespace Forge {
	namespace Math
	{
		/**
		 * @brief Generic vector template supporting vectors of any type and any
		 * dimension.
		 * 
		 * @author Karim Hisham.
		 */
		template<typename InType, Size InDim, 
				 typename = typename Common::TEnableIf<Common::TIsArithmetic<InType>::Value, InType>>
		class TVector
		{
		public:
			InType m_data[InDim];

		public:
			TVector(Void)
			{
				for (U32 i = 0; i < InDim; i++)
					m_data[i] = static_cast<InType>(0);
			}
			TVector(const InType& value)
			{
				for (U32 i = 0; i < InDim; i++)
					m_data[i] = value;
			}
			TVector(const InType* array)
			{
				//TODO: Use Platform::AssertionCheck

				for (U32 i = 0; i < InDim; i++)
					m_data[i] = array[i];
			}

		public:
			InType& operator [](Size index)
			{
				//TODO: Use Platform::AssertionCheck

				FORGE_ASSERT(index >= 0 && index < InDim, "Index out of bounds.")
				return m_data[index];
			}
		};

		template<typename InType>
		class TVector<InType, 2>
		{
		public:
			union
			{
				InType m_data[2];

				struct { InType x, y; };

				struct { InType u, v; };
			};

		public:
			TVector(Void)
			{
				for (U32 i = 0; i < 2; i++)
					m_data[i] = static_cast<InType>(0);
			}
			TVector(const InType& value)
			{
				for (U32 i = 0; i < 2; i++)
					m_data[i] = value;
			}
			TVector(const InType* array)
			{
				//TODO: Use Platform::AssertionCheck

				for (U32 i = 0; i < 2; i++)
					m_data[i] = array[i];
			}
			TVector(const InType& x, const InType& y)
			{
				m_data[0] = x;
				m_data[1] = y;
			}

		public:
			InType& operator [](Size index)
			{
				//TODO: Use Platform::AssertionCheck

				FORGE_ASSERT(index >= 0 && index < 2, "Index out of bounds.")						
					return m_data[index];
			}
		};

		template<typename InType>
		class TVector<InType, 3>
		{
		public:
			union
			{
				InType m_data[3];

				struct { InType x, y, z; };

				struct { InType r, g, b; };

				struct { InType u, v, t; };
			};

		public:
			TVector(Void)
			{
				for (U32 i = 0; i < 3; i++)
					m_data[i] = static_cast<InType>(0);
			}
			TVector(const InType& value)
			{
				for (U32 i = 0; i < 3; i++)
					m_data[i] = value;
			}
			TVector(const InType* array)
			{
				//TODO: Use Platform::AssertionCheck

				for (U32 i = 0; i < 3; i++)
					m_data[i] = array[i];
			}
			TVector(const InType& x, const InType& y, const InType& z)
			{
				m_data[0] = x;
				m_data[1] = y;
				m_data[2] = z;
			}

		public:
			InType& operator [](Size index)
			{
				//TODO: Use Platform::AssertionCheck

				FORGE_ASSERT(index >= 0 && index < 3, "Index out of bounds.")
					return m_data[index];
			}
		};

		typedef TVector<F32, 2> Vector2;
		typedef TVector<F32, 3> Vector3;

		template<typename InType, Size InDim>
		TVector<InType, InDim> operator +(TVector<InType, InDim> lhs, TVector<InType, InDim> rhs)
		{
			TVector<InType, InDim> result;

			for (I32 i = 0; i < InDim; i++)
				result[i] = lhs[i] + rhs[i];

			return result;
		}

		template<typename InType, Size InDim>
		TVector<InType, InDim> operator -(TVector<InType, InDim> lhs, TVector<InType, InDim> rhs)
		{
			TVector<InType, InDim> result;

			for (I32 i = 0; i < InDim; i++)
				result[i] = lhs[i] - rhs[i];

			return result;
		}

		template<typename InType, Size InDim>
		TVector<InType, InDim> operator *(TVector<InType, InDim> lhs, InType scalar)
		{
			TVector<InType, InDim> result;

			for (I32 i = 0; i < InDim; i++)
				result[i] = lhs[i] * scalar;

			return result;
		}
	}
}

#endif
