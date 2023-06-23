#ifndef T_DYNAMIC_ARRAY_H
#define T_DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <initializer_list>

#include <Core/Public/Containers/AbstractList.h>

namespace Forge {
	namespace Containers
	{
		/**
		 * @brief A list container representing arrays that can change in size.
		 * 
		 * TDynamicArray uses contiguous storage locations for its elements, which
		 * means that the elements can be accessed using offsets on regular
		 * pointers to its elements. However, unlike arrays, its size can change
		 * dynamically, with the storage being handled automatically by the
		 * container.
		 * 
		 * @author Karim Hisham.
		 */
		template<typename InElementType>
		class TDynamicArray final : public AbstractList<InElementType>
		{
		public:
			using ElementType         = InElementType;
			using ElementTypePtr      = InElementType*;
			using ElementTypeRef      = InElementType&;
			using ElementTypeMoveRef  = InElementType&&;
			using ConstElementType    = const InElementType;
			using ConstElementTypePtr = const InElementType*;
			using ConstElementTypeRef = const InElementType&;

		private:
			using SelfType         = TDynamicArray<ElementType>;
			using SelfTypePtr      = TDynamicArray<ElementType>*;
			using SelfTypeRef      = TDynamicArray<ElementType>&;
			using SelfTypeMoveRef  = TDynamicArray<ElementType>&&;
			using ConstSelfType    = const TDynamicArray<ElementType>;
			using ConstSelfTypePtr = const TDynamicArray<ElementType>*;
			using ConstSelfTypeRef = const TDynamicArray<ElementType>&;

		private:
			enum { CAPACITY_ALIGNMENT = 2 };

		private:
			ElementTypePtr m_mem_block;

		private:
			Size m_version;
			Size m_capacity;

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
				Iterator operator +(Size inc)
				{
					return Iterator(this->m_ptr + inc);
				}
				Iterator operator -(Size inc)
				{
					return Iterator(this->m_ptr - inc);
				}

			public:
				Iterator operator --(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr--;

					return temp;
				}
				Iterator operator --(Void)
				{
					this->m_ptr--;

					return *this;
				}

			public:
				Iterator operator ++(I32)
				{
					Iterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				Iterator operator ++(Void)
				{
					this->m_ptr++;

					return *this;
				}

			public:
				Size operator -(const Iterator& other)
				{
					return ((reinterpret_cast<U64>(this->m_ptr) - reinterpret_cast<U64>(other.m_ptr)) / sizeof(ElementType)) + 1;
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
					*this = Move(other);
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
					Memory::MemoryCopy(this, &other, sizeof(Iterator));

					other.m_ptr = nullptr;

					return *this;
				}
				ConstIterator& operator =(const ConstIterator& other)
				{
					Memory::MemoryCopy(this, const_cast<Iterator*>(&other), sizeof(Iterator));

					return *this;
				}

			public:
				ConstIterator operator +(Size inc)
				{
					return ConstIterator(this->m_ptr + inc);
				}
				ConstIterator operator -(Size inc)
				{
					return ConstIterator(this->m_ptr - inc);
				}

			public:
				ConstIterator operator --(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr--;

					return temp;
				}
				ConstIterator operator --(Void)
				{
					this->m_ptr--;

					return *this;
				}

			public:
				ConstIterator operator ++(I32)
				{
					ConstIterator temp(this->m_ptr);

					this->m_ptr++;

					return temp;
				}
				ConstIterator operator ++(Void)
				{
					this->m_ptr++;

					return *this;
				}

			public:
				Size operator -(const ConstIterator& other)
				{
					return ((reinterpret_cast<Size>(this->m_ptr) - reinterpret_cast<Size>(other.m_ptr)) / sizeof(ElementType)) + 1;
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
			 * Constructs an empty dynamic array.
			 */
			TDynamicArray(Void) 
				: m_mem_block(nullptr), m_version(0), m_capacity(0), AbstractList<ElementType>(0, ~((Size)0)) {}

			/**
			 * @brief Move element constructor.
			 *
			 * Constructs a dynamic array with a copy of an element.
			 */
			TDynamicArray(ElementTypeMoveRef element, Size count)
				: m_mem_block(nullptr), m_version(0), m_capacity(count), AbstractList<ElementType>(count, ~((Size)0))
			{
				this->m_mem_block = (ElementTypePtr)malloc(this->m_count * sizeof(ElementType));

				Memory::MoveConstruct(this->m_mem_block, Move(element), this->m_count);
			}

			/**
			 * @brief Copy element constructor.
			 *
			 * Constructs a dynamic array with a copy of an element.
			 */
			TDynamicArray(ConstElementTypeRef element, Size count)
				: m_mem_block(nullptr), m_version(0), m_capacity(count), AbstractList<ElementType>(count, ~((Size)0))
			{
				this->m_mem_block = (ElementTypePtr)malloc(this->m_count * sizeof(ElementType));

				Memory::CopyConstruct(this->m_mem_block, element, this->m_count);
			}

			/**
			 * @brief Initializer list constructor.
			 *
			 * Constructs a static array with an initializer list.
			 */
			TDynamicArray(std::initializer_list<ElementType> init_list)
				: m_mem_block(nullptr), m_version(0), m_capacity(init_list.size()), AbstractList<ElementType>(init_list.size(), ~((Size)0))
			{
				this->m_mem_block = (ElementTypePtr)malloc(this->m_count * sizeof(ElementType));

				Memory::CopyConstructArray(this->m_mem_block, const_cast<ElementTypePtr>(init_list.begin()), this->m_count);
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			TDynamicArray(SelfTypeMoveRef other)
				: m_mem_block(nullptr), m_version(0), m_capacity(0), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = Move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TDynamicArray(ConstSelfTypeRef other)
				: m_mem_block(nullptr), m_version(0), m_capacity(0), AbstractList<ElementType>(0, ~((Size)0))
			{
				*this = other;
			}

		public:	
			/**
			 * @brief Default constructor.
			 */
			~TDynamicArray(Void)
			{
				this->Clear();

				if(this->m_mem_block)
					free(this->m_mem_block);
			}

		public:
			/**
			 * @brief Move assignment.
			 */
			SelfTypeRef operator =(SelfTypeMoveRef other)
			{
				this->Clear();
				
				Memory::MemoryCopy(this, &other, sizeof(SelfType));

				other.m_mem_block = nullptr;
				other.m_capacity = other.m_count = other.m_version = 0;

				return *this;
			}

			/**
			 * @brief Copy assignment.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				ConstSize old_count = this->m_count;
				ConstSize new_count = other.m_count;

				this->Clear();

				if (new_count > old_count)
				{
					this->ReserveCapacity(new_count);

					Memory::CopyArray(this->m_mem_block, other.m_mem_block, old_count);
					Memory::CopyConstructArray(this->m_mem_block + old_count, other.m_mem_block + old_count, new_count - old_count);
				}
				else
					Memory::CopyArray(this->m_mem_block, other.m_mem_block, new_count);


				this->m_count = other.m_count;
				this->m_version = other.m_version;
				this->m_capacity = other.m_capacity;
				this->m_max_capacity = other.m_max_capacity;

				return *this;
			}
		
		public:
			/**
			 * @brief Element Accessor.
			 */
			ElementTypeRef operator [](Size index)
			{
				FORGE_ASSERT(index >= 0 && index < this->m_count, "Index is out of range.")

				return *(this->m_mem_block + index);
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
				return Iterator(const_cast<ElementTypePtr>(this->m_mem_block));
			}

			/**
			 * @brief Returns an iterator pointing to the past-end element in this
			 * collection.
			 *
			 * @return Iterator pointing to the past-end element element.
			 */
			Iterator GetEndItr(Void)
			{
				return Iterator(const_cast<ElementTypePtr>(this->m_mem_block + this->m_count));
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in this
			 * collection.
			 *
			 * @return ConstIterator pointing to the first element.
			 */
			ConstIterator GetStartConstItr(Void) const
			{
				return ConstIterator(const_cast<ElementTypePtr>(this->m_mem_block));
			}

			/**
			 * @brief Returns a const iterator pointing to the past-end element in
			 * this collection.
			 *
			 * @return ConstIterator pointing to the past-end element element.
			 */
			ConstIterator GetEndConstItr(Void) const
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
				if (index >= 0 && index < this->m_count)
				{
					// Throw Exception
				}

				return *(this->m_mem_block + index);
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
			Void ForEach(TDelegate<Void(ElementTypeRef)> function) override
			{
				for (U32 i = 0; i < this->m_count; i++)
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
			 *
			 * @throws InvalidOperationException if collection is empty.
			 */
			Void ForEach(TDelegate<Void(ConstElementTypeRef)> function) const override
			{
				for (U32 i = 0; i < this->m_count; i++)
					function.Invoke(*(this->m_mem_block + i));
			}

		public:
			/**
			 * @brief Requests that this collection capacity is large enough
			 * to contain the specified number of elements.
			 * 
			 * @param[in] capacity The minimum capacity of the dynamic array.
			 */
			Void ReserveCapacity(Size capacity)
			{
				if (capacity <= this->m_capacity)
					return;

				Size new_capacity;

				ElementTypePtr old_elements, new_elements;

				new_capacity = this->m_capacity + (this->m_capacity / 2);
				new_capacity = new_capacity > capacity ? new_capacity : capacity;
				new_capacity = new_capacity < this->m_max_capacity ? new_capacity : this->m_max_capacity;
				new_capacity = (new_capacity + (CAPACITY_ALIGNMENT - 1)) & ~(CAPACITY_ALIGNMENT - 1);
			
				old_elements = this->m_mem_block;
				new_elements = (ElementTypePtr)malloc(new_capacity * sizeof(ElementType));

				Memory::MoveConstructArray(new_elements, old_elements, this->m_count);

				free(old_elements);

				this->m_mem_block = new_elements;
				this->m_capacity = new_capacity;
				this->m_version++;
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
			I64 FirstIndexOf(ConstElementTypeRef value) const override
			{
				if (this->m_count)
				{
					ConstElementTypePtr start = this->m_mem_block;
					ConstElementTypePtr end = start + this->m_count;

					for (ConstElementTypePtr ptr = start; ptr != end; ptr++)
					{
						if (Memory::MemoryCompare(ptr, &value, sizeof(ElementType)))
							return reinterpret_cast<I64>(Memory::SubAddress(ptr, start)) / sizeof(ElementType);
					}
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
			I64 LastIndexOf(ConstElementTypeRef value) const override
			{
				if (this->m_count > 0)
				{
					ConstElementTypePtr start = this->m_mem_block - 1;
					ConstElementTypePtr end = start + this->m_count;

					for (ConstElementTypePtr ptr = end; ptr != start; ptr--)
					{
						if (Memory::MemoryCompare(ptr, &value, sizeof(ElementType)))
							return reinterpret_cast<I64>(Memory::SubAddress(ptr, start + 1)) / sizeof(ElementType);
					}
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
			 * @throw IndexOutOfRangeException if index to insert element is out
			 * of range.
			 *
			 * @throw MemoryOutOfBoundsException if this collection's max capacity
			 * has been reached.
			 */
			Void InsertAt(Size index, ElementTypeMoveRef element) override
			{
				if (index < 0 || index >= this->m_count)
					FORGE_EXCEPT(ExceptionType::FORGE_INDEX_OUT_RANGE)

				if (this->m_count >= this->m_max_capacity)
					FORGE_EXCEPT(ExceptionType::FORGE_MEMORY_OUT_OF_BOUNDS)

				this->ReserveCapacity(this->m_count + 1);

				ElementType next, prev;

				ElementTypePtr ptr = this->m_mem_block + index;

				prev = *ptr;

				for (I32 i = 0;  i < this->m_count - index; i++)
				{
					next = *(++ptr);
					*ptr = prev;
					prev = next;
				}

				Memory::Move(this->m_mem_block + index, Move(element), 1);

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

				if (this->m_count >= this->m_max_capacity)
					return;

				this->ReserveCapacity(this->m_count + 1);
				
				ElementType next, prev;

				ElementTypePtr ptr = this->m_mem_block + index;
				
				prev = *ptr;
				
				for (I32 i = 0;  i < this->m_count - index; i++)
				{
					next = *(++ptr);
					*ptr = prev;
					prev = next;
				}

				Memory::Copy(this->m_mem_block + index, element, 1);

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

				ElementTypePtr slow_ptr = this->m_mem_block + index;
				ElementTypePtr fast_ptr = this->m_mem_block + index + 1;

				Memory::Destruct(this->m_mem_block + index, 1);

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

				Memory::Destruct(this->m_mem_block, this->m_count);

				this->m_count = this->m_version = 0;
			}
		};

		FORGE_TYPEDEF_TEMPLATE_DECL(TDynamicArray)
	}
}

#endif // T_DYNAMIC_ARRAY_H

