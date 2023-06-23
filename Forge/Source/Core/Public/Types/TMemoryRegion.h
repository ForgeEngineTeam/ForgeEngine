#ifndef T_MEMORY_REGION_H
#define T_MEMORY_REGION_H

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Algorithm/Algorithm.h>

namespace Forge {
	namespace Common
	{
		/**
		 * @brief Representation of a contiguous region of arbitrary memory.
		 * 
		 * @author Karim Hisham
		 */
		template<typename InType>
		class TMemoryRegion
		{
		public:
			using Type         = InType;
			using TypePtr      = InType*;
			using TypeRef      = InType&;
			using TypeMoveRef  = InType&&;
			using ConstType    = const InType;
			using ConstTypeRef = const InType&;
			using ConstTypePtr = const InType*;

		public:
			using SelfType         = TMemoryRegion<InType>;
			using SelfTypePtr      = TMemoryRegion<InType>*;
			using SelfTypeRef      = TMemoryRegion<InType>&;
			using SelfTypeMoveRef  = TMemoryRegion<InType>&&;
			using ConstSelfType    = const TMemoryRegion<InType>;
			using ConstSelfTypeRef = const TMemoryRegion<InType>&;
			using ConstSelfTypePtr = const TMemoryRegion<InType>*;

		private:
			TypePtr m_data;		/* The starting address of the memory region. */

		private:
			Size m_capacity;		/* The capacity of the memory region. */
			Size m_capacity_bytes;	/* The capacity of the memory region in bytes. */

		public:
			/**
			 * @brief Default constructor.
			 */
			TMemoryRegion(Void)
				: m_data(nullptr), m_capacity_bytes(0), m_capacity(0) {}
			
			/**
			 * @brief Initialization constructor.
			 *
			 * @param data The starting address of the data.
			 * @param capacity The capacity of the memory region.
			 */
			TMemoryRegion(TypePtr data, Size capacity)
				: m_data(data), m_capacity(capacity), m_capacity_bytes(capacity * sizeof(Type))
			{
				if (this->m_data == nullptr || this->m_capacity == 0)
				{
					this->m_data = nullptr;

					this->m_capacity = 0;
					this->m_capacity_bytes = 0;
				}
			}
			
		public:
			/**
			 * @brief Move constructor.
			 */
			TMemoryRegion(SelfTypeMoveRef other)
			{
				*this = Algorithm::Move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TMemoryRegion(ConstSelfTypeRef other)
			{
				*this = other;
			}

		public:
			/**
			 * @brief Move assignment operator.
			 *
			 * @return SelfTypeRef storing the modified memory.
			 */
			FORGE_FORCE_INLINE SelfTypeRef operator =(SelfTypeMoveRef other)
			{
				this->m_data = other.m_data;
				this->m_capacity = other.m_capacity;
				this->m_capacity_bytes = other.m_capacity_bytes;

				other.Clear();

				return *this;
			}

			/**
			 * @brief Copy assignment operator.
			 *
			 * @return SelfTypeRef storing the modified memory.
			 */
			FORGE_FORCE_INLINE SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				this->m_data = other.m_data;
				this->m_capacity = other.m_capacity;
				this->m_capacity_bytes = other.m_capacity_bytes;

				return *this;
			}

		public:
			/**
			 * @brief Subscript operator.
			 *
			 * @param index The index of the data.
			 *
			 * @return TypeRef storing the data at the specified index.
			 *
			 * @throws IndexOutOfRangeException if the index is out of range.
			 */
			FORGE_FORCE_INLINE TypeRef operator[](Size index)
			{
				if (index < 0 || index >= m_capacity)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				return this->m_data[index];
			}

			/**
			 * @brief Subscript operator.
			 *
			 * @param index The index of the data.
			 *
			 * @return ConstTypeRef storing the data at the specified index.
			 *
			 * @throws IndexOutOfRangeException if the index is out of range.
			 */
			FORGE_FORCE_INLINE ConstTypeRef operator[](Size index) const
			{
				if (index < 0 || index >= m_capacity)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				return this->m_data[index];
			}

		public:
			/**
			 * @brief Checks if the memory region is empty.
			 * 
			 * @return True if the memory region is empty, false otherwise.
			 */
			FORGE_FORCE_INLINE Bool IsEmpty(Void) const
			{
				return this->m_capacity == 0;
			}

			/**
			 * @brief Checks if the memory region is valid.
			 * 
			 * @return True if the memory region is valid, false otherwise.
			 */
			FORGE_FORCE_INLINE Bool IsValid(Void) const
			{
				return this->m_data != nullptr;
			}

			/**
			 * @brief Checks if the memory region is invalid.
			 * 
			 * @return True if the memory region is invalid, false otherwise.
			 */
			FORGE_FORCE_INLINE Bool IsInvalid(Void) const
			{
				return this->m_data == nullptr;
			}

		public:
			/**
			 * @brief Gets the capacity of the memory region.
			 * 
			 * @return Size storing the capacity of the memory region.
			 */
			FORGE_FORCE_INLINE Size GetCapacity(Void) const
			{
				return this->m_capacity;
			}

			/**
			 * @brief Gets the capacity of the memory region in bytes.
			 * 
			 * @return Size storing the capacity of the memory region in bytes.
			 */
			FORGE_FORCE_INLINE Size GetCapacityBytes(Void) const
			{
				return this->m_capacity_bytes;
			}

			/**
			 * @brief Gets a pointer to the memory region.
			 * 
			 * @return TypePtr storing address to data stored by memory region.
			 */
			FORGE_FORCE_INLINE TypePtr GetPointer(Void)
			{
				return this->m_data;
			}

			/**
			 * @brief Gets a pointer to the end of the memory region.
			 *
			 * @return TypePtr storing address to data stored by memory region.
			 */
			FORGE_FORCE_INLINE TypePtr GetEndPointer(Void)
			{
				return this->m_data + (this->m_capacity - 1);
			}

			/**
			 * @brief Gets a const pointer to the memory region.
			 *
			 * @return ConstTypePtr storing address to data stored by memory
			 * region.
			 */
			FORGE_FORCE_INLINE ConstTypePtr GetConstPointer(Void) const
			{
				return this->m_data;
			}

			/**
			 * @brief Gets a constant pointer to the end of the memory region.
			 *
			 * @return ConstTypePtr storing address to data stored by memory
			 * region.
			 */
			FORGE_FORCE_INLINE ConstTypePtr GetConstEndPointer(Void) const
			{
				return this->m_data + (this->m_capacity - 1);
			}

		public:
			/**
			 * @brief Gets a sub-memory region of the specified offset and length.
			 * 
			 * @param offset The offset of the sub-memory region.
			 * @param length The length of the sub-memory region.
			 * 
			 * @return SelfType storing a new memory region representing the
			 * sub-memory region.
			 */
			FORGE_FORCE_INLINE SelfType GetSubMemory(Size offset, Size length)
			{
				return TMemoryRegion<Type>(this->m_data + offset, length);
			}

			/**
			 * @brief Gets a constant sub-memory region of the specified offset
			 * and length.
			 *
			 * @param offset The offset of the sub-memory region.
			 * @param length The length of the sub-memory region.
			 *
			 * @return SelfType storing a new memory region representing the
			 * sub-memory region.
			 */
			FORGE_FORCE_INLINE ConstSelfType GetConstSubMemory(Size offset, Size length) const
			{
				return TMemoryRegion<Type>(this->m_data + offset, length);
			}

		public:
			/**
			 * @brief Casts the data stored in memory region to a different
			 * type.
			 * 
			 * @tparam InOtherType The type to cast to.
			 * 
			 * @return TMemoryRegion<InOtherType> storing the new memory region
			 * with the casted type.
			 * 
			 * @throw InvalidOperationException if the element sizes are not
			 * equivalent.
			 */
			template <typename InOtherType>
			FORGE_FORCE_INLINE TMemoryRegion<InOtherType> Cast(Void)
			{
				if(sizeof(InType) != sizeof(InOtherType))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"Can only cast with equivalent element size.")

				return TMemoryRegion<InOtherType>(reinterpret_cast<InOtherType*>(this->m_data), this->m_capacity);
			}

			/**
			 * @brief Casts the data stored in memory region to a different
			 * constant type.
			 *
			 * @tparam InOtherType The type to cast to.
			 *
			 * @return TMemoryRegion<const InOtherType> storing the new memory
			 * region with the casted type.
			 *
			 * @throw InvalidOperationException if the element sizes are not
			 * equivalent.
			 */
			template <typename InOtherType>
			FORGE_FORCE_INLINE TMemoryRegion<const InOtherType> ConstCast(Void) const
			{
				if (sizeof(InType) != sizeof(InOtherType))
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION,
						"Can only cast with equivalent element size.")

				return TMemoryRegion<InOtherType>(reinterpret_cast<const InOtherType*>(this->m_data), this->m_capacity);
			}

		public:
			/**
			 * @brief Converts the memory region to a byte array.
			 * 
			 * @return TMemoryRegion<Byte> storing the new memory region with
			 * the type set to Byte.
			 */
			FORGE_FORCE_INLINE TMemoryRegion<Byte> ConvertToByteArray(Void)
			{
				return TMemoryRegion<Byte>(reinterpret_cast<BytePtr>(this->m_data), this->m_capacity_bytes);
			}

			/**
			 * @brief Converts the memory region to a constant byte array.
			 *
			 * @return const TMemoryRegion<Byte> storing the new memory region
			 * with the type set to Byte.
			 */
			FORGE_FORCE_INLINE const TMemoryRegion<Byte> ConvertToConstByteArray(Void) const
			{
				return TMemoryRegion<Byte>(reinterpret_cast<BytePtr>(this->m_data), this->m_capacity_bytes);
			}

		public:
			/**
			 * @brief Clears the memory region.
			 */
			FORGE_FORCE_INLINE Void Clear(Void)
			{
				this->m_data = nullptr;

				this->m_capacity = 0;
				this->m_capacity_bytes = 0;
			}

			/**
			 * @brief Resets the memory region.
			 */
			FORGE_FORCE_INLINE Void Reset(Void)
			{
				FORGE_SAFE_DELETE_BLOCK(this->m_data)

				this->m_capacity = 0;
				this->m_capacity_bytes = 0;
			}
		};

		FORGE_TYPEDEF_TEMPLATE_DECL(TMemoryRegion)
	}
}

#endif
