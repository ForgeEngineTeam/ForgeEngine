#ifndef T_STATIC_QUEUE_H
#define T_STATIC_QUEUE_H

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
		template<typename InElementType, Size InMaxSize>
		class TStaticQueue : public AbstractList<InElementType>
		{
		private:
			using ElementType         = InElementType;
			using ElementTypeRef      = InElementType&;
			using ElementTypePtr      = InElementType*;
			using ConstElementType    = const InElementType;
			using ConstElementTypeRef = const InElementType&;
			using ConstElementTypePtr = const InElementType*;
		
		private:
			using SelfType         = TStaticQueue<ElementType, InMaxSize>;
			using SelfTypeRef      = TStaticQueue<ElementType, InMaxSize>&;
			using SelfTypePtr      = TStaticQueue<ElementType, InMaxSize>*;
			using ConstSelfType    = const TStaticQueue<ElementType, InMaxSize>;
			using ConstSelfTypeRef = const TStaticQueue<ElementType, InMaxSize>&;
			using ConstSelfTypePtr = const TStaticQueue<ElementType, InMaxSize>*;

		private:
			ElementType m_mem_block[InMaxSize];

		public:
			struct Iterator
			{
			private:
				ElementTypePtr m_ptr;

			public:
				Iterator(void)
					: m_ptr(nullptr) {}

				Iterator(ElementTypePtr ptr)
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
				Iterator operator =(Iterator&& other)
				{
					Memory::MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				Iterator operator =(const Iterator& other)
				{
					Memory::MemoryCopy(this, const_cast<Iterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				Iterator operator --(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				Iterator operator --(void)
				{
					this->m_ptr++;

					return *this;
				}

			public:
				Iterator operator ++(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				Iterator operator ++(void)
				{
					this->m_ptr++;

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
					return *(this->m_ptr);
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
				ElementTypePtr m_ptr;

			public:
				ConstIterator(void)
					: m_ptr(nullptr) {}

				ConstIterator(ElementTypePtr ptr)
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
				ConstIterator operator =(ConstIterator&& other)
				{
					Memory::MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				ConstIterator operator =(const ConstIterator& other)
				{
					Memory::MemoryCopy(this, const_cast<ConstIterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				ConstIterator operator --(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				ConstIterator operator --(void)
				{
					this->m_ptr++;

					return *this;
				}

			public:
				ConstIterator operator ++(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				ConstIterator operator ++(void)
				{
					this->m_ptr++;

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
					return *(this->m_ptr);
				}

			public:
				ConstElementTypePtr operator ->()
				{
					return this->m_ptr;
				}
			};

		public:
			/**
			 * @brief Default constructor.
			 *
			 * Constructs an empty static queue.
			 */
			TStaticQueue(void)
				: AbstractList<ElementType>(0, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count < this->m_max_capacity, "Array size is not large enough to store the data.")
			}

			/**
			 * @brief Move element constructor.
			 *
			 * Constructs a static queue with a copy of an element.
			 */
			TStaticQueue(ElementType&& element, Size count)
				: AbstractList<ElementType>(count, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count < this->m_max_capacity, "Array size is not large enough to store the data.")

				Memory::MoveConstruct(m_mem_block, std::move(element), this->m_count);
			}

			/**
			 * @brief Copy element constructor.
			 *
			 * Constructs a static queue with a copy of an element.
			 */
			TStaticQueue(ConstElementTypeRef element, Size count)
				: AbstractList<ElementType>(count, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count < this->m_max_capacity, "Array size is not large enough to store the data.")

				Memory::CopyConstruct(m_mem_block, element, this->m_count);
			}

			/**
			 * @brief Initializer list constructor.
			 *
			 * Constructs a static queue with an initializer list.
			 */
			TStaticQueue(std::initializer_list<ElementType> init_list)
				: AbstractList<ElementType>(init_list.size(), InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count < this->m_max_capacity, "Array size is not large enough to store the data.")

				Memory::MoveConstructArray(this->m_mem_block, const_cast<ElementTypePtr>(init_list.begin()), this->m_count);
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			TStaticQueue(SelfType&& other)
			{
				*this = std::move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TStaticQueue(ConstSelfTypeRef other)
			{
				*this = other;
			}

		public:
			~TStaticQueue()
			{
				this->Clear();
			}

		public:
			/**
			 * @brief Move assignment.
			 */
			SelfTypeRef operator =(SelfType&& other)
			{
				this->Clear();

				Memory::MemoryCopy(this, &other, sizeof(SelfType));

				other.m_mem_block = nullptr;
				other.m_count = 0;

				return *this;
			}

			/**
			 * @brief Copy assignment.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				this->Clear();

				Memory::CopyArray(this->m_mem_block, other.m_mem_block, other.m_count);

				this->m_count = other.m_count;

				return *this;
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
				return Iterator(const_cast<ElementTypePtr>(this->m_mem_block));
			}

			/**
			 * @brief Returns an iterator pointing to the past-end element in this
			 * collection.
			 *
			 * @return Iterator pointing to the past-end element element.
			 */
			Iterator GetEndItr(void)
			{
				return Iterator(const_cast<ElementTypePtr>(this->m_mem_block + this->m_count));
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in this
			 * collection.
			 *
			 * @return ConstIterator pointing to the first element.
			 */
			ConstIterator GetStartConstItr(void) const
			{
				return ConstIterator(const_cast<ElementTypePtr>(this->m_mem_block));
			}

			/**
			 * @brief Returns a const iterator pointing to the past-end element in
			 * this collection.
			 *
			 * @return ConstIterator pointing to the past-end element element.
			 */
			ConstIterator GetEndConstItr(void) const
			{
				return ConstIterator(const_cast<ElementTypePtr>(this->m_mem_block + this->m_count));
			}

		public:
			/**
			 * @brief Gets a direct pointer to the memory array managed by this
			 * collection.
			 *
			 * Elements in the memory array are guranteed to be stored in contiguous
			 * memory locations. This allows the pointer to be offsetted to access
			 * different elements.
			 *
			 * @return ConstElementTypePtr storing address of the memory array.
			 */
			ConstElementTypePtr GetRawData() const override
			{
				return this->m_mem_block;
			}

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
			Bool IsEqual(AbstractCollection<ElementType>& collection) const override
			{
				if (collection.IsEmpty())
					return false;

				if (this->m_count != collection.GetCount())
					return false;

				Bool return_value;

				ConstIterator start_itr = this->GetStartConstItr();
				ConstIterator end_itr = this->GetEndConstItr();

				collection.ForEach([&return_value, &start_itr, end_itr](ElementTypeRef element) -> Void
					{
						if ((start_itr++) == end_itr)
						{
							return_value = true;
							return;
						}

						if (!Memory::MemoryCompare(&(*start_itr), &element, sizeof(ElementType)))
						{
							return_value = false;
							return;
						}
					}
				);

				return return_value;
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
				if (!this->m_count)
					return nullptr;

				ElementTypePtr array_ptr = (ElementTypePtr)malloc(this->m_count * sizeof(ElementType));

				Memory::CopyConstructArray(array_ptr, const_cast<ElementTypePtr>(this->m_mem_block), this->m_count);

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
				if (!this->m_count)
					return nullptr;

				Memory::CopyConstructArray(array_ptr, const_cast<ElementTypePtr>(this->m_mem_block), this->m_count);

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
			 */
			Void ForEach(Common::TDelegate<Void(ElementTypeRef)> function) override
			{
				for (I32 i = 0; i < this->m_count; i++)
					function.Invoke(*(this->m_mem_block + i));
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
			 */
			Void ForEach(Common::TDelegate<Void(ConstElementTypeRef)> function) const override
			{
				for (I32 i = 0; i < this->m_count; i++)
					function.Invoke(*(this->m_mem_block + i));
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
			 */
			I64 FirstIndexOf(ConstElementTypeRef element) const override
			{
				if (!this->m_count)
					return -1;
				
				ConstElementTypePtr start = this->m_mem_block;
				ConstElementTypePtr end = start + this->m_count;

				for (ConstElementTypePtr ptr = start; ptr != end; ptr++)
				{
					if (Memory::MemoryCompare(ptr, &element, sizeof(ElementType)))
						return reinterpret_cast<I64>(Memory::SubAddress(ptr, start)) / sizeof(ElementType);
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
			 */
			I64 LastIndexOf(ConstElementTypeRef element) const override
			{
				if (!this->m_count)
					return -1;
				
				ConstElementTypePtr start = this->m_mem_block - 1;
				ConstElementTypePtr end = start + this->m_count;

				for (ConstElementTypePtr ptr = end; ptr != end; ptr--)
				{
					if (Memory::MemoryCompare(ptr, &element, sizeof(ElementType)))
						return reinterpret_cast<I64>(Memory::SubAddress(ptr, start + 1)) / sizeof(ElementType);
				}
				
				return -1;
			}

		public:
			/**
			 * @brief This collection only allows retrieval of the front most element.
			 *
			 * @throws InvalidOperationException if attempted to retrieve the last
			 * element in this collection.
			 */
			ConstElementTypeRef PeekBack() const override
			{
				// Throw Exception

				return ElementType();
			}

			/**
			 * @brief Retreives the first element in this collection.
			 *
			 * @return ConstElementTypeRef storing the first element in this
			 * collection.
			 *
			 * @Throws InvalidOperationException if this collection is empty.
			 */
			ConstElementTypeRef PeekFront() const override
			{
				if (!this->m_count)
				{
					// Throw Exception
				}

				return *(this->m_mem_block);
			}

		public:
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
			 * @brief Inserts a new element at the front of this collection, before
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

				Memory::Move(this->m_mem_block + this->m_count, std::move(element), 1);

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
			 * @brief Inserts a new element at the front of this collection, before
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

				Memory::Copy(this->m_mem_block + this->m_count, element, 1);

				this->m_count++;
			}

			/**
			 * @brief This collection only allows removal of elements at the front.
			 *
			 * @throws InvalidOperationException if attempted to remove at the back
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
			 * This function has the same functionality as Pop
			 *
			 * @Throws InvalidOperationException if this collection is empty.
			 */
			Void PopFront(void) override
			{
				if (!this->m_count)
				{
					// Throw Exception
				}

				ElementTypePtr slow_ptr = this->m_mem_block;
				ElementTypePtr fast_ptr = this->m_mem_block + 1;

				Memory::Destruct(this->m_mem_block, 1);

				for (I32 i = 0; i < this->m_count; i++)
					*(slow_ptr++) = *(fast_ptr++);

				this->m_count--;
			}

		public:
			/**
			 * @brief Inserts a new element at the front of this collection.
			 *
			 * This function has the same functionality as PushBack.
			 *
			 * @param[in] element The element to insert at the front.
			 */
			Void Push(ElementType&& element)
			{
				this->PushFront(element);
			}

			/**
			 * @brief Inserts a new element at the front of this collection.
			 *
			 * This function has the same functionality as PushBack.
			 *
			 * @param[in] element The element to insert at the front.
			 */
			Void Push(ConstElementTypeRef element)
			{
				this->PushFront(element);
			}

			/**
			 * @brief Removes the element at the front of this collection.
			 *
			 * This operation has the same functionality as PopBack.
			 */
			Void Pop(void)
			{
				this->PopFront();
			}

		public:
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
			 * @brief This does not support removal of elements at specified indices.
			 *
			 * @throws InvalidOperationException if attempted to remove element at
			 * a specified index.
			 */
			Void RemoveAt(Size index) override
			{
				// Throw Exception
			}

		public:
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

			/**
			 * @brief Searches this collection for the specified element.
			 *
			 * @param[in] element ElementType to search for in this collection.
			 *
			 * @return True if the specified element was found in this collection.
			 */
			Bool Contains(ConstElementTypeRef element) const override
			{
				return this->FirstIndexOf(element) != -1;
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
			Bool ContainsAll(AbstractCollection<ElementType>& collection) override
			{
				if (!this->m_count || collection.IsEmpty())
					return false;

				Bool return_value;

				collection.ForEach([this, &return_value](ElementTypeRef element) -> Void
					{
						return_value = this->Contains(element);

						if (!return_value)
							return;
					}
				);

				return return_value;
			}

		public:
			/**
			 * @brief Removes all the elements from this collection.
			 */
			Void Clear(void) override
			{
				if (!this->m_count)
					return;

				Memory::Destruct(this->m_mem_block, this->m_count);

				this->m_count = 0;
			}
		};
	}
}
#endif // T_STATIC_QUEUE_H
