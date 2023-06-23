#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H

#include <Core/Public/Algorithm/GeneralUtilities.h>
#include <Core/Public/Containers/AbstractCollection.h>

using namespace Forge::Memory;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Containers
	{
		template<typename InElementType>
		class AbstractList : public AbstractCollection<InElementType>
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
			using SelfType         = AbstractList<ElementType>;
			using SelfTypePtr      = AbstractList<ElementType>*;
			using SelfTypeRef      = AbstractList<ElementType>&;
			using SelfTypeMoveRef  = AbstractList<ElementType>&&;
			using ConstSelfType    = const AbstractList<ElementType>;
			using ConstSelfTypeRef = const AbstractList<ElementType>&;
			using ConstSelfTypePtr = const AbstractList<ElementType>*;

		public:
			/**
			 * @brief Default constructor.
			 */
			AbstractList(Size count, Size max_capacity)
				: AbstractCollection<ElementType>(count, max_capacity) {}

		public:
			/**
			 * @brief Default destructor.
			 * 
			 */
			virtual ~AbstractList(Void) = default;

		public:
			/**
			 * @brief Gets a direct pointer to the memory array managed by this
			 * list.
			 *
			 * Elements in the memory array are guranteed to be stored in contiguous
			 * memory locations. This allows the pointer to be offsetted to access
			 * different elements.
			 * 
			 * @return ConstElementTypePtr storing address of the memory array.
			 *
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual ConstElementTypePtr GetRawData(Void) const = 0;

			/**
			 * @brief Retreives a reference to the element stored in the collection
			 * at the specified index.
			 *
			 * @param[in] index The index to retreive the element stored at.
			 *
			 * @return ConstElementTypeRef storting the element stored at the
			 * specified index.
			 *
			 * @throws InvalidOperationException if collection is empty.
			 * 
			 * @throws IndexOutOfRangeExceotion if index is out of range.
			 */
			virtual ConstElementTypeRef GetByIndex(Size index) const = 0;

		public:
			/**
			 * @brief Checks whether this collection is equal to the specified
			 * collection.
			 *
			 * Equality between collections is governed by their size, the order
			 * of the elements in the collection and the eqaulity of the elements
			 * they store.
			 *
			 * @param[in] collection The collection to be compared with this
			 * collection.
			 *
			 * @return True if the specified collection is equal to this collection.
			 */
			virtual Bool IsEqual(AbstractCollection<ElementType>& collection) const
			{
				if (this->m_count != collection.GetCount())
					return FORGE_FALSE;

				I32 index = 0;

				Bool return_value = FORGE_TRUE;

				collection.ForEach([this, &index, &return_value](ElementTypeRef element) -> Void
					{
						ConstElementTypeRef other_element = this->GetByIndex(index++);

						if (!MemoryCompare(&other_element, &element, sizeof(ElementType)))
						{
							return_value = FORGE_FALSE;
							return;
						}
					}
				);

				return return_value;
			}

		public:
			/**
			 * @brief Returns the index of the first occurence of the specified
			 * element in this list, or -1 if it does not contain the element.
			 *
			 * @param[in] element The element to search for the first occurence.
			 *
			 * @return Size storing the index of the first occurrence of the
			 * specified element, or -1 if this list does not contain the element.
			 * 
			 * @throws InvalidOperationException if collection is empty.
			 */
			virtual I64 FirstIndexOf(ConstElementTypeRef element) const = 0;

			/**
			 * @brief Returns the index of the last occurence of the specified
			 * element in this list, or -1 if it does not contain the element.
			 *
			 * @param[in] element The element to search for the first occurence.
			 *
			 * @return Size storing the index of the last occurrence of the
			 * specified element, or -1 if this list does not contain the element.
			 * 
			 * @throws InvalidOperationException if collection is empty.
			 */
			virtual I64 LastIndexOf(ConstElementTypeRef element) const = 0;

		public:
			/**
			 * @brief Retreives the back element in this collection.
			 * 
			 * @return ConstElementTypeRef storing the last element in this
			 * collection.
			 * 
			 * @Throws InvalidOperationException if this collection is empty or not
			 * supported by this collection.
			 */
			virtual ConstElementTypeRef PeekBack(Void) const
			{
				return this->GetByIndex(this->m_count - 1);
			}

			/**
			 * @brief Retreives the front element in this collection.
			 *
			 * @return ConstElementTypeRef storing the front element in this
			 * collection.
			 *
			 * @Throws InvalidOperationException if this collection is empty or not
			 * supported by this collection.
			 */
			virtual ConstElementTypeRef PeekFront(Void) const
			{
				return this->GetByIndex(0);
			}

		public:
			/**
			 * @brief Inserts a new element at the end of this collection, after
			 * its current last element.
			 *
			 * @param[in] element The element to insert in this collection.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Void PushBack(ElementType&& element)
			{
				this->InsertAt(this->m_count, Move(element));
			}

			/**
			 * @brief Inserts a new element at the front of this collection before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Void PushFront(ElementType&& element)
			{
				this->InsertAt(0, Move(element));
			}

			/**
			 * @brief Inserts a new element at the end of this collection, after
			 * its current last element.
			 *
			 * @param[in] element The element to insert in this collection.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Void PushBack(ConstElementTypeRef element)
			{
				this->InsertAt(this->m_count, element);
			}

			/**
			 * @brief Inserts a new element at the start of this collection. before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Void PushFront(ConstElementTypeRef element)
			{
				this->InsertAt(0, element);
			}

			/**
			 * @brief Removes the element at the end of this collection, effectivly
			 * reducing the collection count by one.
			 *
			 * @Throws InvalidOperationException if this collection is empty or not
			 * supported by this collection.
			 */
			virtual Void PopBack(Void)
			{
				this->RemoveAt(this->m_count - 1);
			}

			/**
			 * @brief Removes the element at the front of this collection, effectivly
			 * reducing the collection count by one.
			 *
			 * @Throws InvalidOperationException if this collection is empty or not
			 * supported by this collection.
			 */
			virtual Void PopFront(Void)
			{
				this->RemoveAt(0);
			}
		
		public:
			/**
			 * @brief Removes the first occurance of the specified element from
			 * this collection.
			 *
			 * This function explicitly calls the destructor of the element
			 * but does not deallocate the memory it was stored at.
			 *
			 * @param[in] element ElementType to remove from this collection.
			 *
			 * @return True if removal was successful and the element was found.
			 * 
			 * @throws InvalidOperationException if operation not supported by
			 * this collection.
			 */
			virtual Bool Remove(ConstElementTypeRef element) override
			{
				Size index = this->FirstIndexOf(element);

				if (index != -1)
				{
					this->RemoveAt(index);
					return FORGE_TRUE;
				}

				return FORGE_FALSE;
			}

			/**
			 * @brief Searches this collection for the specified element.
			 *
			 * @param[in] element ElementType to search for in this collection.
			 *
			 * @return True if the specified element was found in this collection.
			 */
			virtual Bool Contains(ConstElementTypeRef element) const override
			{
				return this->FirstIndexOf(element) != -1;
			}

		public:
			/**
			 * @brief Inserts the specified element in the specified index.
			 *
			 * This function will increase count size by one and shift all elements
			 * that preceed the newly inserted element. If the number of elements
			 * overflow the capacity of the collection, a reallocation will occur
			 * to accomodate for the increased size if supported.
			 *
			 * @param[in] ui_index The numerical index to insert the element at.
			 * @param[in] element  The element to insert in the list.
			 *
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throw InvalidOperationException if operation not supported by
			 * this list.
			 */
			virtual Void InsertAt(Size index, ElementType&& element) = 0;

			/**
			 * @brief Inserts the specified element in the specified index.
			 * 
			 * This function will increase count size by one and shift all elements
			 * that preceed the newly inserted element. If the number of elements 
			 * overflow the capacity of the collection, a reallocation will occur
			 * to accomodate for the increased size if supported.
			 * 
			 * @param[in] ui_index The numerical index to insert the element at.
			 * @param[in] element  The element to insert in the list.
			 * 
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throw InvalidOperationException if operation not supported by
			 * this list.
			 */
			virtual Void InsertAt(Size index, ConstElementTypeRef element) = 0;

			/**
			* @brief Removes an element in the specified index.
			*
			* This function will decrease the count size by one and shift all
			* elements that preceed the removed element.
			*
			* @param[in] ui_index The numerical index to remove the element at.
			*
			* @throw IndexOutOfRangeException if index to remove element at is out
			* of range.
			*
			* @throw MemoryOutOfBoundsException if this collection's max capacity
			* has been reached.
			* 
			* @throw InvalidOperationException if operation not supported by
			* this list.
			*/
			virtual Void RemoveAt(Size index) = 0;

		public:
			/**
			 * @brief Inserts all the elements in the specified collection to this
			 * collection.
			 *
			 * The order in which the elements are inserted into this collection
			 * depends on how the specified collection is iterated on.
			 *
			 * @param[in] collection The collection containing elements to be added
			 * to this collection.
			 *
			 * @return True if insertion was succesfull and collection is not empty.
			 */
			virtual Bool InsertAll(AbstractCollection<ElementType>& collection) override
				{
					if (collection.IsEmpty())
						return FORGE_FALSE;

					if (this->m_max_capacity - collection.GetMaxCapacity() < 0)
						return FORGE_FALSE;

					collection.ForEach([this](ElementTypeRef element) -> Void
						{
							this->PushBack(element);
						}
					);

					return FORGE_TRUE;
				}

			/**
			 * @brief Removes all the elements in the specified collection from this
			 * collection.
			 *
			 * This function explicitly calls the destructor of the elements
			 * but does not deallocate the memory it was stored at.
			 *
			 * @param[in] collection The collection containing elements to be
			 * removed from this collection.
			 *
			 * @return True if removal was successful, the elements were found and
			 * the collection is not empty.
			 */
			virtual Bool RemoveAll(AbstractCollection<ElementType>& collection) override
			{
				if (!this->m_count || collection.IsEmpty())
					return FORGE_FALSE;

				I32 index = 0;

				while (index < this->m_count)
				{
					ConstElementTypeRef element = this->GetByIndex(index);

					if (collection.Contains(element))
						this->Remove(element);
					else
						index++;
				}

				return FORGE_TRUE;
			}

			/**
			 * @brief Searches for all the elements in the specified collection in
			 * this collection.
			 *
			 * @param[in] collection The collection containing elements to be
			 * search for in this collection.
			 *
			 * @return True if the specified elements were found and the collection
			 * is not empty.
			 */
			virtual Bool ContainsAll(AbstractCollection<ElementType>& collection) override
			{
				if (!this->m_count || collection.IsEmpty())
					return FORGE_FALSE;

				I32 index = 0;

				while (index < this->m_count)
				{
					ConstElementTypeRef element = this->GetByIndex(index);

					if (!collection.Contains(element))
						return FORGE_FALSE;
					else
						index++;
				}

				return FORGE_TRUE;
			}
		};
	}
}

#endif // ABSTRACT_LIST_H
