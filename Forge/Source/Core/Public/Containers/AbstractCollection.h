#ifndef ABSTRACT_COLLECTION_H
#define ABSTRACT_COLLECTION_H

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>

#include <Core/Public/Memory/MemoryUtilities.h>

#include <Core/Public/Algorithm/GeneralUtilities.h>

using namespace Forge::Debug;
using namespace Forge::Common;
using namespace Forge::Memory;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Containers
	{
		template<typename InElementType>
		class AbstractCollection
		{
		public:
			using ElementType         = InElementType;
			using ElementTypePtr      = InElementType*;
			using ElementTypeRef      = InElementType&;
			using ElementTypeMoveRef  = InElementType&&;
			using ConstElementType    = const InElementType;
			using ConstElementTypeRef = const InElementType&;
			using ConstElementTypePtr = const InElementType*;

		private:
			using SelfType         = AbstractCollection<ElementType>;
			using SelfTypePtr      = AbstractCollection<ElementType>*;
			using SelfTypeRef      = AbstractCollection<ElementType>&;
			using SelfTypeRef      = AbstractCollection<ElementType>&&;
			using ConstSelfType    = const AbstractCollection<ElementType>;
			using ConstSelfTypeRef = const AbstractCollection<ElementType>&;
			using ConstSelfTypePtr = const AbstractCollection<ElementType>*;

		protected:
			Size m_count;
			Size m_max_capacity;

		public:
			/**
			 * @brief Default constructor.
			 */
			AbstractCollection(Size count, Size max_capacity);

		public:
			/**
			 * @brief Default destructor.
			 * 
			 */
			virtual ~AbstractCollection() = default;

		public:
			/**
			 * @brief Checks whether this collection is full and is at maximum
			 * capacity.
			 *
			 * @return True if this collection is full, otherwise false.
			 */
			virtual Bool IsFull(Void) const;

			/**
			 * @brief Checks whether this collection is empty and not storing any
			 * elements.
			 *
			 * @return True if this collection is empty.
			 */
			virtual Bool IsEmpty(Void) const;

			/**
			 * @brief Checks whether this collection is equal to the specified
			 * collection.
			 *
			 * Equality between collections is governed by their size, the order
			 * of the elements in the collection and the eqaulity of the elements
			 * they store.
			 *
			 * @param[in] collection The collection to be compared with this collection.
			 *
			 * @return True if the specified collection is equal to this
			 * collection, otherwise false.
			 */
			virtual Bool IsEqual(AbstractCollection<ElementType>& collection) const = 0;

		public:
			/**
			 * @brief Gets the number of elements stored in this collection.
			 * 
			 * @return Size storing the number of elements.
			 */
			virtual Size GetCount(Void) const;

			/**
			 * @brief Gets the maximum number of elements that can be stored in
			 * this collection.
			 *
			 * @return Size storing the maximum number of elements.
			 */
			virtual Size GetMaxCapacity(Void) const;

		public:
			/**
			 * @brief Returns an array containing all the elements returned by this
			 * collection's forward iterator.
			 * 
			 * The length of the array is equal to the number of elements returned
			 * by the iterator. If this collection makes any guarantees as to what 
			 * order its elements are returned by its iterator, this method must 
			 * return the elements in the same order. The returned array contains 
			 * deep copies of the elements.
			 * 
			 * @return ElementTypePtr storing the address of the array.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual ElementTypePtr ToArray(Void) const = 0;

			/**
			 * @brief Returns an array containing all the elements returned by this
			 * collection's forward iterator.
			 *
			 * The length of the array is equal to the number of elements returned
			 * by the iterator. If this collection makes any guarantees as to what
			 * order its elements are returned by its iterator, this method must
			 * return the elements in the same order. The returned array contains
			 * deep copies of the elements.
			 *
			 * @param[out] array The array to store this collection's elements.
			 * 
			 * @return ElementTypePtr storing the address of the array.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual ElementTypePtr ToArray(ElementTypePtr array) const = 0;

		public:
			/**
			 * @brief Iterates through all the elements inside the collection and
			 * performs the operation provided on each element.
			 * 
			 * The operation is performed in the order of iteration, and is performed
			 * until all elements have been processed or the operation throws an
			 * exception.
			 * 
			 * @param[in] function The function to perform on each element.
			 * 
			 * @throws InvalidOperationException if collection is empty.
			 */
			virtual Void ForEach(TDelegate<Void(ElementTypeRef)> function) = 0;

			/**
			 * @brief Iterates through all the elements inside the collection and
			 * performs the operation provided on each element.
			 *
			 * The operation is performed in the order of iteration, and is performed
			 * until all elements have been processed or the operation throws an
			 * exception.
			 *
			 * @param[in] function The function to perform on each element.
			 *
			 * @throws InvalidOperationException if collection is empty.
			 */
			virtual Void ForEach(TDelegate<Void(ConstElementTypeRef)> function) const = 0;

		public:
			/**
			 * @brief Removes the specified element from this collection. This
			 * operation has different behaviours depending on the collection type.
			 *
			 * Collections that support this operation may place limitations on how
			 * elements are removed from the collection and in what order they are
			 * removed.
			 *
			 * @param[in] element ElementType to remove from this collection.
			 *
			 * @return True if removal was successful and the element was found.
			 *
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Bool Remove(ConstElementTypeRef element) = 0;

			/**
			 * @brief Searches this collection for the specified element. This
			 * operation has different behaviours depening on the collection type.
			 *
			 * @param[in] element ElementType to search for in this collection.
			 *
			 * @return True if the specified element was found in this collection.
			 */
			virtual Bool Contains(ConstElementTypeRef element) const = 0;

		public:
			/**
			 * @brief Inserts all the elements in the specified collection to this
			 * collection. This operation has different behaviours depending on the
			 * collection type.
			 * 
			 * @param[in] collection The collection containing elements to be added
			 * to this collection.
			 * 
			 * @return True if insertion was successful and no duplicates in
			 * this collection if supported.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Bool InsertAll(AbstractCollection<ElementType>& collection) = 0;

			/**
			 * @brief Removes all the elements in the specified collection from this
			 * collection. This operation has different behaviours depending on the
			 * collection type.
			 *
			 * @param[in] collection The collection containing elements to be 
			 * removed from this collection.
			 *
			 * @return True if removal was successful and the elements were found.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Bool RemoveAll(AbstractCollection<ElementType>& collection) = 0;

			/**
			 * @brief Searches for all the elements in the specified collection in 
			 * this collection. This operation has different behaviours depending
			 * on the collection type.
			 *
			 * @param[in] collection The collection containing elements to be
			 * search for in this collection.
			 * 
			 * @return True if the specified elements were found in this collection.
			 */
			virtual Bool ContainsAll(AbstractCollection<ElementType>& collection) = 0;

		public:
			/**
			 * @brief Removes all the elements from this collections.
			 */
			virtual Void Clear(Void) = 0;
		};

		template<typename T> FORGE_FORCE_INLINE AbstractCollection<T>::AbstractCollection(Size count, Size max_capacity)
			: m_count(count), m_max_capacity(max_capacity) {}

		template<typename T> FORGE_FORCE_INLINE Bool AbstractCollection<T>::IsFull(Void) const 
		{ 
			return m_count == m_max_capacity; 
		}
		template<typename T> FORGE_FORCE_INLINE Bool AbstractCollection<T>::IsEmpty(Void) const
		{ 
			return m_count == 0; 
		}
		template<typename T> FORGE_FORCE_INLINE Size AbstractCollection<T>::GetCount(Void) const
		{ 
			return m_count; 
		}
		template<typename T> FORGE_FORCE_INLINE Size AbstractCollection<T>::GetMaxCapacity(Void) const
		{ 
			return m_max_capacity; 
		}
	}
}

#endif // ABSTRACT_COLLECTION_H
