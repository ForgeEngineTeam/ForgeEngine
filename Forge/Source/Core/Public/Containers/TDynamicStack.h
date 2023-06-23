#ifndef T_DYNAMIC_STACK_H
#define T_DYNAMIC_STACK_H

#include <utility>
#include <stdlib.h>
#include <initializer_list>

#include "AbstractList.h"

#include "Core/Public/Common/TypeDefinitions.h"
#include "Core/Public/Common/PreprocessorUtilities.h"

#include "Core/Public/Memory/PoolAllocator.h"
#include "Core/Public/Memory/MemoryUtilities.h"

namespace Forge {
	namespace Containers
	{
		template<typename InElementType>
		class TDynamicStack : public AbstractList<InElementType>
		{
		private:
			using ElementType         = InElementType;
			using ElementTypeRef      = InElementType&;
			using ElementTypePtr      = InElementType*;
			using ConstElementType    = const InElementType;
			using ConstElementTypeRef = const InElementType&;
			using ConstElementTypePtr = const InElementType*;

		private:
			using SelfType         = TDynamicStack<ElementType>;
			using SelfTypeRef      = TDynamicStack<ElementType>&;
			using SelfTypePtr      = TDynamicStack<ElementType>*;
			using ConstSelfType    = const TDynamicStack<ElementType>;
			using ConstSelfTypeRef = const TDynamicStack<ElementType>&;
			using ConstSelfTypePtr = const TDynamicStack<ElementType>*;

		private:
			struct EntryNode
			{
			public:
				ElementType m_data;

			public:
				EntryNode* m_prev;
				EntryNode* m_next;

			public:
				EntryNode(ElementType&& data)
					: m_data(std::move(data)), m_next(nullptr), m_prev(nullptr) {}
				EntryNode(ConstElementTypeRef data)
					: m_data(data), m_next(nullptr), m_prev(nullptr) {}
			};

		private:
			EntryNode* m_head;
			EntryNode* m_tail;

		public:
			/**
			 * @brief Default constructor.
			 *
			 * Constructs an empty dynamic stack.
			 */
			TDynamicStack(void)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0)) {}

			/**
			 * @brief Move element constructor.
			 *
			 * Constructs a dynamic stack with a copy of an element.
			 */
			TDynamicStack(ElementType&& element, Size count)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				while (count > this->m_count)
					this->Push(std::move(element));
			}

			/**
			 * @brief Copy element constructor.
			 *
			 * Constructs a dynamic stack with a copy of an element.
			 */
			TDynamicStack(ConstElementTypeRef element, Size count)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				while (count > this->m_count)
					this->Push(element);
			}

			/**
			 * @brief Initializer list constructor.
			 *
			 * Constructs a dynamic stack with an initializer list.
			 */
			TDynamicStack(std::initializer_list<ElementType> init_list)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				ConstElementTypePtr ptr = init_list.begin();

				while (init_list.size() > this->m_count)
					this->Push(*(ptr + this->m_count));
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			TDynamicStack(SelfType&& other)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = std::move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TDynamicStack(ConstSelfTypeRef other)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = other;
			}

		public:
			/**
			 * @brief Destructor.
			 */
			~TDynamicStack()
			{
				this->Clear();
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			SelfTypeRef operator =(SelfType&& other)
			{
				this->Clear();

				Memory::MemoryCopy(this, &other, sizeof(SelfType));

				other.m_head = other.m_tail = nullptr;
				other.m_count = 0;

				return *this;
			}

			/**
			 * @brief Copy constructor.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				this->Clear();

				for (EntryNode* curr_node = other.m_head; curr_node; curr_node = curr_node->m_next)
					this->Push(curr_node->m_data);

				return *this;
			}

		private:
			/**
			 * @brief This function is not supported by this collection.
			 *
			 * @throws InvalidOperationException if attempted to retrieve
			 * this collection's raw pointer.
			 */
			ConstElementTypePtr GetRawData(void) const override
			{
				// Throw Exception

				return nullptr;
			}

		private:
			/**
			 * @brief This collection only allows retrieval of the front element.
			 *
			 * @throws InvalidOperationException if attempted to retrieve the front
			 * element in this collection.
			 */
			ConstElementTypeRef PeekBack(void) const override
			{
				// Throw Exception

				return ElementType();
			}

			/**
			 * @brief Retreives the front element in this collection.
			 *
			 * @return ConstElementTypeRef storing the front element in this
			 * collection.
			 *
			 * @throws InvalidOperationException if this collection is empty.
			 */
			ConstElementTypeRef PeekFront(void) const override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				return this->m_head->m_data;
			}

		private:
			/**
			 * @brief This collection only allows insertion of elements at the front.
			 *
			 * @throws InvalidOperationException if attempted to insert at the back
			 * of this collection.
			 */
			Void PushBack(ElementType&& element) override
			{
				// Throw Exception
			}

			/**
			 * @brief Inserts a new element at the front of this collection. before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void PushFront(ElementType&& element) override
			{
				if (this->m_count >= this->m_max_capacity)
				{
					// Throw Exception
				}

				EntryNode* elem_node = new EntryNode(std::move(element));

				if (!this->m_head || !this->m_tail)
					this->m_head = this->m_tail = elem_node;
				else
				{
					elem_node->m_next = this->m_head;
					this->m_head->m_prev = elem_node;
					this->m_head = elem_node;
				}

				this->m_count++;
			}

			/**
			 * @brief This collection only allows insertion of elements at the front.
			 *
			 * @throws InvalidOperationException if attempted to insert at the back
			 * of this collection.
			 */
			Void PushBack(ConstElementTypeRef element) override
			{
				// Throw Exception
			}

			/**
			 * @brief Inserts a new element at the front of this collection. before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void PushFront(ConstElementTypeRef element) override
			{
				if (this->m_count >= this->m_max_capacity)
				{
					// Throw Exception
				}

				EntryNode* elem_node = new EntryNode(element);

				if (!this->m_head || !this->m_tail)
					this->m_head = this->m_tail = elem_node;
				else
				{
					elem_node->m_next = this->m_head;
					this->m_head->m_prev = elem_node;
					this->m_head = elem_node;
				}

				this->m_count++;
			}

			/**
			 * @brief This collection only allows retreival of elements at the front.
			 *
			 * @throws InvalidOperationException if attempted to retreive at the back
			 * of this collection.
			 */
			Void PopBack(void) override
			{
				// Throw Exception
			}

			/**
			 * @brief Removes the element at the front of this collection, effectivly
			 * reducing the collection count by one.
			 *
			 * @Throws InvalidOperationException if this collection is empty.
			 */
			Void PopFront(void) override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				EntryNode* curr_node = this->m_head;

				if (this->m_head == this->m_tail)
					this->m_head = this->m_tail = nullptr;
				else
				{
					this->m_head = this->m_head->m_next;
					this->m_head->m_prev = nullptr;
				}

				free(curr_node);

				this->m_count--;
			}

		private:
			/**
			 * @brief This collection does not support removal of elements at
			 * specified positions.
			 *
			 * @throws InvalidOperationException if attempted to remove element at
			 * a specified position.
			 */
			Bool Remove(ConstElementTypeRef element) override
			{
				// Throw Exception

				return false;
			}

		private:
			/**
			 * @brief This collection does not support insertion of elements at
			 * specified indices.
			 *
			 * @throws InvalidOperationException if attempted to insert element at
			 * a specified index.
			 */
			Void InsertAt(Size index, ElementType&& element) override
			{
				// Throw Exception
			}

			/**
			 * @brief This collection does not support insertion of elements at
			 * specified indices.
			 *
			 * @throws InvalidOperationException if attempted to insert element at
			 * a specified index.
			 */
			Void InsertAt(Size index, ConstElementTypeRef element) override
			{
				// Throw Exception
			}

			/**
			 * @brief This collection does not support removal of elements at
			 * specified indices.
			 *
			 * @throws InvalidOperationException if attempted to remove element at
			 * a specified index.
			 */
			Void RemoveAt(Size index) override
			{
				// Throw Exception
			}

		private:
			/**
			 * @brief This collection does not support removal of elements at
			 * specified positions.
			 *
			 * @throws InvalidOperationException if attempted to remove element at
			 * a specified position.
			 */
			Bool RemoveAll(AbstractCollection<ElementType>& collection) override
			{
				// Throw Exception

				return false;
			}

		public:
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
			ConstElementTypeRef GetByIndex(Size index) const override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				if (index < 0 || index > this->m_count)
				{
					// Throw Exception
				}

				EntryNode* curr_node = this->m_head;

				while (curr_node->m_next && (index--) > 0)
					curr_node = curr_node->m_next;

				return curr_node->m_data;
			}

		public:
			/**
			 * @brief Returns an array containing all the elements returned by this
			 * collection's iterator.
			 *
			 * The length of the array is equal to the number of elements returned
			 * by the iterator. If this collection makes any guarantees as to what
			 * order its elements are returned by its iterator, this method must
			 * return the elements in the same order. The returned array contains
			 * deep copies of the elements.
			 *
			 * @return ElementTypePtr storing the address of the array or
			 * nullptr if collection is empty.
			 */
			ElementTypePtr ToArray(void) const override
			{
				if (this->IsEmpty())
					return nullptr;

				ElementTypePtr array_ptr = (ElementTypePtr)malloc(this->m_count * sizeof(ElementType));

				I32 index = 0;

				for (EntryNode* curr_node = this->m_head; curr_node; curr_node = curr_node->m_next, index++)
					Memory::CopyConstruct(array_ptr + index, curr_node->m_data, 1);

				return array_ptr;
			}

			/**
			 * @brief Returns an array containing all the elements returned by this
			 * collection's iterator.
			 *
			 * The length of the array is equal to the number of elements returned
			 * by the iterator. If this collection makes any guarantees as to what
			 * order its elements are returned by its iterator, this method must
			 * return the elements in the same order. The returned array contains
			 * deep copies of the elements.
			 *
			 * @param[out] array_ptr The array to store this collection's elements.
			 *
			 * @return ElementTypePtr storing the address of the array or
			 * nullptr if collection is empty.
			 */
			ElementTypePtr ToArray(ElementTypePtr array_ptr) const override
			{
				if (this->IsEmpty())
					return nullptr;

				I32 index = 0;

				for (EntryNode* curr_node = this->m_head; curr_node; curr_node = curr_node->m_next, index++)
					Memory::CopyConstruct(array_ptr + index, curr_node->m_data, 1);

				return array_ptr;
			}

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
			Void ForEach(Common::TDelegate<Void(ElementTypeRef)> function) override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				for (EntryNode* curr_node = this->m_head; curr_node; curr_node = curr_node->m_next)
					function.Invoke(curr_node->m_data);
			}

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
			Void ForEach(Common::TDelegate<Void(ConstElementTypeRef)> function) const override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				for (EntryNode* curr_node = this->m_head; curr_node; curr_node = curr_node->m_next)
					function.Invoke(curr_node->m_data);
			}

		public:
			/**
			 * @brief Returns the index of the first occurence of the specified
			 * element in this collection, or -1 if it does not contain the
			 * element or it is empty.
			 *
			 * @param[in] element The element to search for the first occurence.
			 *
			 * @return Size storing the index of the first occurrence of the
			 * specified element, or -1 if this collection does not contain the
			 * element or it is empty.
			 * 
			 * @throws InvalidOperationException if collection is empty.
			 */
			I64 FirstIndexOf(ConstElementTypeRef element) const override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				EntryNode* curr_node = this->m_head;

				for (I32 index = 0; curr_node; index++)
				{
					if (Memory::MemoryCompare(&curr_node->m_data, &element, sizeof(ElementType)))
						return index;

					curr_node = curr_node->m_next;
				}

				return -1;
			}

			/**
			 * @brief Returns the index of the last occurence of the specified
			 * element in this collection, or -1 if it does not contain the
			 * element or it is empty.
			 *
			 * @param[in] element The element to search for the last occurence.
			 *
			 * @return Size storing the index of the last occurrence of the
			 * specified element, or -1 if this collection does not contain the
			 * element or it is empty.
			 * 
			 * @throws InvalidOperationException if collection is empty.
			 */
			I64 LastIndexOf(ConstElementTypeRef element) const override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				EntryNode* curr_node = this->m_tail;

				for (I32 index = this->m_count - 1; curr_node; index--)
				{
					if (Memory::MemoryCompare(&curr_node->m_data, &element, sizeof(ElementType)))
						return index;

					curr_node = curr_node->m_prev;
				}

				return -1;
			}

		public:
			/**
			 * @brief Retreives the front element in this collection.
			 *
			 * @return ConstElementTypeRef storing the front element in this
			 * collection.
			 *
			 * @throws InvalidOperationException if this collection is empty.
			 */
			ConstElementTypeRef Peek(void)
			{
				return this->PeekFront();
			}

		public:
			/**
			 * @brief Inserts a new element at the front of this collection. before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void Push(ElementType&& element)
			{
				this->PushFront(std::move(element));
			}
			
			/**
			 * @brief Inserts a new element at the front of this collection. before
			 * its current first element.
			 *
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void Push(ConstElementTypeRef element)
			{
				this->PushFront(element);
			}

			/**
			 * @brief Removes the element at the front of this collection, effectivly
			 * reducing the collection count by one.
			 *
			 * @Throws InvalidOperationException if this collection is empty.
			 */
			Void Pop(void)
			{
				this->PopFront();
			}

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
			Bool InsertAll(AbstractCollection<ElementType>& collection) override
			{
				if (collection.IsEmpty())
					return false;

				if (this->m_max_capacity - collection.GetMaxCapacity() < 0)
					return false;

				collection.ForEach([this](ElementTypeRef element) -> Void
					{
						this->Push(element);
					}
				);

				return true;
			}

		public:
			/**
			 * @brief Removes all the elements from this collection.
			 */
			Void Clear(void) override
			{
				if (this->IsEmpty())
					return;

				while (this->m_count > 0)
					this->Pop();
			}
		};
	}
}

#endif // T_DYNAMIC_STACK_H
