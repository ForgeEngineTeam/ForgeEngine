#ifndef T_LINKED_LIST_H
#define T_LINKED_LIST_H

#include <utility>
#include <stdlib.h>
#include <initializer_list>

#include "AbstractList.h"

#include "Core/Public/Common/TypeDefinitions.h"
#include "Core/Public/Common/PreprocessorUtilities.h"

#include "Core/Public/Memory/MemoryUtilities.h"

namespace Forge {
	namespace Containers
	{
		template<typename InElementType>
		class TLinkedList : public AbstractList<InElementType>
		{
		private:
			using ElementType         = InElementType;
			using ElementTypeRef      = InElementType&;
			using ElementTypePtr      = InElementType*;
			using ConstElementType    = const InElementType;
			using ConstElementTypeRef = const InElementType&;
			using ConstElementTypePtr = const InElementType*;

		private:
			using SelfType         = TLinkedList<ElementType>;
			using SelfTypeRef      = TLinkedList<ElementType>&;
			using SelfTypePtr      = TLinkedList<ElementType>*;
			using ConstSelfType    = const TLinkedList<ElementType>;
			using ConstSelfTypeRef = const TLinkedList<ElementType>&;
			using ConstSelfTypePtr = const TLinkedList<ElementType>*;

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
					: m_data(std::move(data)), m_prev(nullptr), m_next(nullptr) {}
				EntryNode(ConstElementTypeRef data)
					: m_data(data), m_prev(nullptr), m_next(nullptr) {}
			};
		
		public:
			struct Iterator
			{
			private:
				EntryNode* m_ptr;

			public:
				Iterator(void)
					: m_ptr(nullptr) {}

				Iterator(EntryNode* ptr)
					: m_ptr(ptr) {}

			public:
				Iterator(Iterator&& other)
				{
					*this = std::move(other);
				}
				Iterator(const Iterator& other)
				{
					*this = other;
				}

			public:
				~Iterator() = default;

			public:
				Iterator& operator =(Iterator&& other)
				{
					Memory::MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				Iterator& operator =(const Iterator& other)
				{
					Memory::MemoryCopy(this, const_cast<Iterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				Iterator operator --(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr = this->m_ptr->m_prev;

					return temp;
				}
				Iterator operator --(void)
				{
					this->m_ptr = this->m_ptr->m_prev;

					return *this;
				}

			public:
				Iterator operator ++(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr = this->m_ptr->m_next;

					return temp;
				}
				Iterator operator ++(void)
				{
					this->m_ptr = this->m_ptr->m_next;

					return *this;
				}

			public:
				Bool operator ==(const Iterator& other)
				{
					return this->m_ptr == other.m_ptr;
				}
				Bool operator !=(const Iterator& other)
				{
					return this->m_ptr != other.m_ptr;
				}

			public:
				ElementTypeRef operator *()
				{
					return this->m_ptr->m_data;
				}

			public:
				ElementTypePtr operator ->()
				{
					return this->m_ptr;
				}
			};
			struct ConstIterator
			{
			private:
				EntryNode* m_ptr;

			public:
				ConstIterator(void)
					: m_ptr(nullptr) {}

				ConstIterator(EntryNode* ptr)
					: m_ptr(ptr) {}

			public:
				ConstIterator(ConstIterator&& other)
				{
					*this = std::move(other);
				}
				ConstIterator(const ConstIterator& other)
				{
					*this = other;
				}

			public:
				~ConstIterator() = default;

			public:
				ConstIterator& operator =(ConstIterator&& other)
				{
					Memory::MemoryCopy(this, &other, sizeof(ConstIterator));

					other.m_ptr = nullptr;

					return *this;
				}
				ConstIterator& operator =(const ConstIterator& other)
				{
					Memory::MemoryCopy(this, const_cast<ConstIterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				ConstIterator operator --(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr = this->m_ptr->m_prev;

					return temp;
				}
				ConstIterator operator --(void)
				{
					this->m_ptr = this->m_ptr->m_prev;

					return *this;
				}

			public:
				ConstIterator operator ++(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr = this->m_ptr->m_next;

					return temp;
				}
				ConstIterator operator ++(void)
				{
					this->m_ptr = this->m_ptr->m_next;

					return *this;
				}

			public:
				Bool operator ==(const ConstIterator& other)
				{
					return this->m_ptr == other.m_ptr;
				}
				Bool operator !=(const ConstIterator& other)
				{
					return this->m_ptr != other.m_ptr;
				}

			public:
				ConstElementTypeRef operator *()
				{
					return this->m_ptr->m_data;
				}

			public:
				ConstElementTypePtr operator ->()
				{
					return this->m_ptr;
				}
			};

		private:
			EntryNode* m_head;
			EntryNode* m_tail;

		public:
			/**
			 * @brief Default constructor.
			 *
			 * Constructs an empty linked list.
			 */
			TLinkedList(void)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0)) {}

			/**
			 * @brief Move element constructor.
			 *
			 * Constructs a linked list with a copy of an element.
			 */
			TLinkedList(ElementType&& element, Size count)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				while (count > this->m_count)
					this->PushBack(std::move(element));
			}

			/**
			 * @brief Copy element constructor.
			 *
			 * Constructs a linked list with a copy of an element.
			 */
			TLinkedList(ConstElementTypeRef element, Size count)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				while (count > this->m_count)
					this->PushBack(element);
			}

			/**
			 * @brief Initializer list constructor.
			 *
			 * Constructs a linked list with an initializer list.
			 */
			TLinkedList(std::initializer_list<ElementType> init_list)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				ConstElementTypePtr ptr = init_list.begin();

				while (init_list.size() > this->m_count)
					this->PushBack(*(ptr + this->m_count));
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			TLinkedList(SelfType&& other)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = std::move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TLinkedList(ConstSelfTypeRef other)
				: m_head(nullptr), m_tail(nullptr), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = other;
			}
		
		public:
			/**
			 * @brief Destructor
			 */
			~TLinkedList()
			{
				this->Clear();
			}

		public:
			/**
			 * @brief Move assignment operator.
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
			 * @brief Copy assignment operator.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				this->Clear();

				for (EntryNode* curr_node = other.m_head; curr_node; curr_node = curr_node->m_next)
					this->PushBack(curr_node->m_data);

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

		public:
			/**
			 * @brief Returns an iterator pointing to the first element in this
			 * collection.
			 *
			 * @return Iterator pointing to the first element.
			 */
			Iterator GetStartItr(void)
			{
				return Iterator(this->m_head);
			}

			/**
			 * @brief Returns an iterator pointing to the past-end element in this
			 * collection.
			 *
			 * @return Iterator pointing to the past-end element element.
			 */
			Iterator GetEndItr(void)
			{
				return Iterator(this->m_tail->m_next);
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in this
			 * collection.
			 *
			 * @return ConstIterator pointing to the first element.
			 */
			ConstIterator GetStartConstItr(void) const
			{
				return ConstIterator(this->m_head);
			}

			/**
			 * @brief Returns a const iterator pointing to the past-end element in
			 * this collection.
			 *
			 * @return ConstIterator pointing to the past-end element element.
			 */
			ConstIterator GetEndConstItr(void) const
			{
				return ConstIterator(this->m_tail->m_next);
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
			 * @brief Inserts the specified element in the specified index in this
			 * collection.
			 *
			 * This function will increase this collection's count size by one and
			 * shift all elements that preceed the newly inserted element.
			 *
			 * @param[in] index   The index to insert the element at.
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 */
			Void InsertAt(Size index, ElementType&& element) override
			{
				if (this->m_count >= this->m_max_capacity)
				{
					// Throw Exception
				}

				if (index < 0 || index > this->m_count)
				{
					// Throw Exception
				}

				EntryNode* elem_node = new EntryNode(std::move(element));

				if (!this->m_head || !this->m_tail)
				{
					this->m_head = this->m_tail = elem_node;
				}
				else if (index == 0)
				{
					elem_node->m_next = this->m_head;
					this->m_head->m_prev = elem_node;
					this->m_head = elem_node;
				}
				else if (index == this->m_count)
				{
					elem_node->m_prev = this->m_tail;
					this->m_tail->m_next = elem_node;
					this->m_tail = elem_node;
				}
				else
				{
					EntryNode* next_node = this->m_head;

					while (next_node->m_next && (index--) > 0)
						next_node = next_node->m_next;

					EntryNode* prev_node = next_node->m_prev;

					elem_node->m_next = next_node;
					elem_node->m_prev = prev_node;
					next_node->m_prev = elem_node;
					prev_node->m_next = elem_node;
				}

				this->m_count++;
			}

			/**
			 * @brief Inserts the specified element in the specified index in this
			 * collection.
			 *
			 * This function will increase this collection's count size by one and
			 * shift all elements that preceed the newly inserted element to the
			 * right.
			 *
			 * @param[in] index   The index to insert the element at.
			 * @param[in] element The element to insert in this collection.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 * 
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 */
			Void InsertAt(Size index, ConstElementTypeRef element) override
			{
				if (this->m_count >= this->m_max_capacity)
				{
					// Throw Exception
				}

				if (index < 0 || index > this->m_count)
				{
					// Throw Exception
				}

				EntryNode* elem_node = new EntryNode(std::move(element));

				if (!this->m_head || !this->m_tail)
				{
					this->m_head = this->m_tail = elem_node;
				}
				else if (index == 0)
				{
					elem_node->m_next = this->m_head;
					this->m_head->m_prev = elem_node;
					this->m_head = elem_node;
				}
				else if (index == this->m_count)
				{
					elem_node->m_prev = this->m_tail;
					this->m_tail->m_next = elem_node;
					this->m_tail = elem_node;
				}
				else
				{
					EntryNode* next_node = this->m_head;

					while (next_node->m_next && (index--) > 0)
						next_node = next_node->m_next;

					EntryNode* prev_node = next_node->m_prev;

					elem_node->m_next = next_node;
					elem_node->m_prev = prev_node;
					next_node->m_prev = elem_node;
					prev_node->m_next = elem_node;
				}

				this->m_count++;
			}

			/**
			 * @brief Removes the specified element after the element in the
			 * specified index in this collection.
			 *
			 * This function will decreases this collection's count by one and shift
			 * all elements that preceed the removed element to the left.
			 *
			 * This function explicitly calls the destructor of the element
			 * but does not deallocate the memory it was stored at.
			 *
			 * @param[in] index The numerical index to remove the element at.
			 *
			 * @throws InvalidOperationException if this collection is empty.
			 * 
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 */
			Void RemoveAt(Size index) override
			{
				if (this->IsEmpty())
				{
					// Throw Exception
				}

				if (index < 0 || index >= this->m_count)
				{
					// Throw Exception
				}

				EntryNode* curr_node = this->m_head;

				while (curr_node->m_next && (index--) > 0)
					curr_node = curr_node->m_next;

				EntryNode* next_node = curr_node->m_next;
				EntryNode* prev_node = curr_node->m_prev;

				if (!next_node && !prev_node)
				{
					this->m_head = this->m_tail = nullptr;
				}
				else if (!next_node)
				{
					this->m_tail = prev_node;
					this->m_tail->m_next = nullptr;
				}
				else if (!prev_node)
				{
					this->m_head = next_node;
					this->m_head->m_prev = nullptr;
				}
				else
				{
					prev_node->m_next = next_node;
					next_node->m_prev = prev_node;
				}

				free(curr_node);

				this->m_count--;
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
					this->PopBack();
			}
		};
	}
}

#endif // T_LINKED_LIST_H
