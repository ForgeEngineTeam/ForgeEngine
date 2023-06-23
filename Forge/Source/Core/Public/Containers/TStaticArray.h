#ifndef T_STATIC_ARRAY_H
#define T_STATIC_ARRAY_H

#include <utility>
#include <initializer_list>

#include <Core/Public/Containers/AbstractList.h>

namespace Forge {
	namespace Containers
	{
		/**
		 * @brief A fixed-size linear container that holds a specific number of
		 * elements in a contigous memory block.
		 * 
		 * The static array has a fixed-size and does not manage the allocation of
		 * its elements through memory allocators, instead the memory block is
		 * constructed at compile time in the stack. Therefore, it cannot be expanded
		 * dynamiclly at run-time.
		 * 
		 * @author Karim Hisham
		 */
		template<typename InElementType, Size InMaxSize>
		class TStaticArray final : public AbstractList<InElementType>
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
			using SelfType         = TStaticArray<ElementType, InMaxSize>;
			using SelfTypePtr      = TStaticArray<ElementType, InMaxSize>*;
			using SelfTypeRef      = TStaticArray<ElementType, InMaxSize>&;
			using SelfTypeMoveRef  = TStaticArray<ElementType, InMaxSize>&&;
			using ConstSelfType    = const TStaticArray<ElementType, InMaxSize>;
			using ConstSelfTypePtr = const TStaticArray<ElementType, InMaxSize>*;
			using ConstSelfTypeRef = const TStaticArray<ElementType, InMaxSize>&;

		public:
			struct Iterator
			{
			public:
				using ElementType = InElementType;

			private:
				ElementTypePtr m_ptr;

			public:
				Iterator(Void)
					: m_ptr(nullptr) {}

				Iterator(ElementTypePtr ptr)
					: m_ptr(ptr) {}

			public:
				Iterator(Iterator&& other)
				{
					*this = Move(other);
				}
				Iterator(const Iterator& other)
				{
					*this = other;
				}

			public:
				~Iterator(Void) = default;

			public:
				Iterator& operator =(Iterator&& other)
				{
					MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				Iterator& operator =(const Iterator& other)
				{
					MemoryCopy(this, const_cast<Iterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				Iterator operator +(Size inc)
				{
					return Iterator(m_ptr + inc);
				}
				Iterator operator -(Size inc)
				{
					return Iterator(m_ptr - inc);
				}

			public:
				Iterator operator --(I32)
				{
					Iterator temp(m_ptr);

					m_ptr--;

					return temp;
				}
				Iterator operator --(Void)
				{
					m_ptr--;

					return *this;
				}

			public:
				Iterator operator ++(I32)
				{
					Iterator temp(m_ptr);

					m_ptr++;

					return temp;
				}
				Iterator operator ++(Void)
				{
					m_ptr++;

					return *this;
				}
			
			public:
				Size operator -(const Iterator& other)
				{
					return ((reinterpret_cast<Size>(m_ptr) - reinterpret_cast<Size>(other.m_ptr)) / sizeof(ElementType)) + 1;
				}

			public:
				Bool operator ==(const Iterator& other)
				{
					return m_ptr == other.m_ptr;
				}
				Bool operator !=(const Iterator& other)
				{
					return m_ptr != other.m_ptr;
				}

			public:
				ElementTypeRef operator *()
				{
					return *(m_ptr);
				}

			public:
				ElementTypePtr operator ->()
				{
					return m_ptr;
				}
			};
			struct ConstIterator
			{
			public:
				using ElementType = InElementType;

			private:
				ElementTypePtr m_ptr;

			public:
				ConstIterator(Void)
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
				ConstIterator& operator =(ConstIterator&& other)
				{
					MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				ConstIterator& operator =(const ConstIterator& other)
				{
					MemoryCopy(this, const_cast<Iterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				ConstIterator operator +(Size inc)
				{
					return ConstIterator(m_ptr + inc);
				}
				ConstIterator operator -(Size inc)
				{
					return ConstIterator(m_ptr - inc);
				}

			public:
				ConstIterator operator --(I32)
				{
					ConstIterator temp(m_ptr);

					m_ptr--;

					return temp;
				}
				ConstIterator operator --(Void)
				{
					m_ptr--;

					return *this;
				}

			public:
				ConstIterator operator ++(I32)
				{
					ConstIterator temp(m_ptr);

					m_ptr++;

					return temp;
				}
				ConstIterator operator ++(Void)
				{
					m_ptr++;

					return *this;
				}

			public:
				Size operator -(const ConstIterator& other)
				{
					return ((reinterpret_cast<Size>(m_ptr) - reinterpret_cast<Size>(other.m_ptr)) / sizeof(ElementType)) + 1;
				}

			public:
				Bool operator ==(const ConstIterator& other)
				{
					return m_ptr == other.m_ptr;
				}
				Bool operator !=(const ConstIterator& other)
				{
					return m_ptr != other.m_ptr;
				}

			public:
				ConstElementTypeRef operator *()
				{
					return *(m_ptr);
				}

			public:
				ConstElementTypePtr operator ->()
				{
					return m_ptr;
				}
			};

		private:
			ElementType m_mem_block[InMaxSize];
		
		public:
			/**
			 * @brief Default constructor.
			 * 
			 * Constructs an empty static array.
			 */
			TStaticArray(Void) 
				: AbstractList<ElementType>(0, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count <= this->m_max_capacity, "Array size is not large enough to store the data.")

				Construct(m_mem_block, this->m_count);
			}

			/**
			 * @brief Move element constructor.
			 * 
			 * Constructs a static array with a copy of an element.
			 */
			TStaticArray(ElementTypeMoveRef element, Size count)
				: AbstractList<ElementType>(count, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count <= this->m_max_capacity, "Array size is not large enough to store the data.")

				MoveConstruct(m_mem_block, Move(element), this->m_count);
			}

			/**
			 * @brief Copy element constructor.
			 *
			 * Constructs a static array with a copy of an element.
			 */
			TStaticArray(ConstElementTypeRef element, Size count)
				: AbstractList<ElementType>(count, InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count <= this->m_max_capacity, "Array size is not large enough to store the data.")

				CopyConstruct(m_mem_block, element, this->m_count);
			}

			/**
			 * @brief Initializer list constructor.
			 * 
			 * Constructs a static array with an initializer list.
			 */
			TStaticArray(std::initializer_list<ElementType> init_list)
				: AbstractList<ElementType>(init_list.size(), InMaxSize)
			{
				FORGE_ASSERT(this->m_max_capacity != 0 && this->m_count <= this->m_max_capacity, "Array size is not large enough to store the data.")

				MoveConstructArray(m_mem_block, const_cast<ElementTypePtr>(init_list.begin()), this->m_count);
			}
			
		public:
			/**
			 * @brief Move constructor.
			 */
			TStaticArray(SelfTypeMoveRef other) 
				: AbstractList<ElementType>(0, InMaxSize)
			{
				*this = Move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TStaticArray(ConstSelfTypeRef other)
				: AbstractList<ElementType>(0, InMaxSize)
			{
				*this = other;
			}

		public:
			/**
			 * @brief Default destructor.
			 */
			~TStaticArray(Void)
			{
				Clear();
			}

		public:
			/**
			 * @brief Move assignment.
			 */
			SelfTypeRef operator =(SelfTypeMoveRef other)
			{
				Clear();

				MemoryCopy(this, &other, sizeof(SelfType));

				other.m_count = 0;

				return *this;
			}
			
			/**
			 * @brief Copy assignment.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				Clear();

				MemoryCopy(this, const_cast<SelfTypePtr>(&other), sizeof(SelfType));

				return *this;
			}

		public:
			/**
			 * @brief Subscript operator.
			 */
			ElementTypeRef operator [](Size index)
			{
				FORGE_ASSERT(index >= 0 && index < this->m_count, "Index is out of range.")

				return *(m_mem_block + index);
			}

		public:
			/**
			 * @brief Returns an iterator pointing to the first element in this
			 * collection.
			 *
			 * @return Iterator pointing to the first element.
			 */
			Iterator GetStartItr(Void)
			{
				return Iterator(const_cast<ElementTypePtr>(m_mem_block));
			}

			/**
			 * @brief Returns an iterator pointing to the past-end element in this
			 * collection.
			 *
			 * @return Iterator pointing to the past-end element element.
			 */
			Iterator GetEndItr(Void)
			{
				return Iterator(const_cast<ElementTypePtr>(m_mem_block + this->m_count - 1));
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in this
			 * collection.
			 *
			 * @return ConstIterator pointing to the first element.
			 */
			ConstIterator GetStartConstItr(Void) const
			{
				return ConstIterator(const_cast<ElementTypePtr>(m_mem_block));
			}

			/**
			 * @brief Returns a const iterator pointing to the past-end element in
			 * this collection.
			 *
			 * @return ConstIterator pointing to the past-end element element.
			 */
			ConstIterator GetEndConstItr(Void) const
			{
				return ConstIterator(const_cast<ElementTypePtr>(m_mem_block + this->m_count - 1));
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
				return m_mem_block;
			}

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
				FORGE_ASSERT(index >= 0 && index < this->m_count, "Index is out of range.")

				return *(m_mem_block + index);
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
			ElementTypePtr ToArray(Void) const override
			{
				if (!this->m_count)
					return nullptr;

				ElementTypePtr array_ptr = new ElementType[this->m_count * sizeof(ElementType)];

				CopyConstructArray(array_ptr, const_cast<ElementTypePtr>(m_mem_block), this->m_count);

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

				CopyConstructArray(array_ptr, const_cast<ElementTypePtr>(m_mem_block), this->m_count);

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
			Void ForEach(TDelegate<Void(ElementTypeRef)> function) override
			{
				for (U32 i = 0; i < this->m_count; i++)
					function.Invoke(*(m_mem_block + i));
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
			Void ForEach(TDelegate<Void(ConstElementTypeRef)> function) const override
			{
				for (U32 i = 0; i < this->m_count; i++)
					function.Invoke(*(m_mem_block + i));
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
				
				ConstElementTypePtr start = m_mem_block;
				ConstElementTypePtr end = start + this->m_count;

				for (ConstElementTypePtr ptr = start; ptr != end; ptr++)
					if (*ptr == element)
						return reinterpret_cast<I64>(SubAddress(ptr, start)) / sizeof(ElementType);
				
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
				
				ConstElementTypePtr start = m_mem_block - 1;
				ConstElementTypePtr end = start + this->m_count;

				for (ConstElementTypePtr ptr = end; ptr != start; ptr--)
					if (*ptr == element)
						return reinterpret_cast<I64>(SubAddress(ptr, start + 1)) / sizeof(ElementType);
				
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
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 * 
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void InsertAt(Size index, ElementType&& element) override
			{
				if (index < 0 || index >= this->m_count)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				if (this->m_count >= this->m_max_capacity)
					FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)
					
				ElementType next, prev;

				ElementTypePtr ptr = m_mem_block + index;

				prev = *ptr;

				for (U32 i = 0; i < this->m_count - index; i++)
				{
					next = *(++ptr);
					*ptr = prev;
					prev = next;
				}

				Move(m_mem_block + index, Move(element), 1);

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
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void InsertAt(Size index, ConstElementTypeRef element) override
			{
				if (index < 0 || index >= this->m_count)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				if (this->m_count >= this->m_max_capacity)
					FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

				ElementType next, prev;

				ElementTypePtr ptr = m_mem_block + index;

				prev = *ptr;

				for (I32 i = 0; i < this->m_count - index; i++)
				{
					next = *(++ptr);
					*ptr = prev;
					prev = next;
				}

				Copy(m_mem_block + index, element, 1);

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
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 * 
			 * @Throws InvalidOperationException if this collection is empty.
			 */
			Void RemoveAt(Size index) override
			{
				if (index < 0 || index >= this->m_count)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				if (!this->m_count)
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

				ElementTypePtr slow_ptr = m_mem_block + index;
				ElementTypePtr fast_ptr = m_mem_block + index + 1;
				
				Destruct(m_mem_block + index, 1);

				for (I32 i = 0; i < this->m_count - index; i++)
					*(slow_ptr++) = *(fast_ptr++);

				this->m_count--;
			}

		public:
			/**
			 * @brief Removes all the elements from this collection.
			 */
			Void Clear(Void) override
			{
				if (!this->m_count)
					return;

				Destruct(m_mem_block, this->m_count);

				this->m_count = 0;
			}
		};
	}
}

#endif // T_STATIC_ARRAY_H
