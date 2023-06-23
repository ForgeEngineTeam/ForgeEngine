#ifndef RANGE_UTILITIES_H
#define RANGE_UTILITIES_H

#include "GeneralUtilities.h"

#include "Core/Public/Common/Compiler.h"
#include "Core/Public/Common/TypeTraits.h"
#include "Core/Public/Common/TypeDefinitions.h"

#include "Core/Public/Types/TPair.h"
#include "Core/Public/Types/TDelegate.h"

#include "Core/Public/Memory/MemoryUtilities.h"

namespace Forge {
	namespace Algorithm
	{
		/**
		 * @brief Returns an iterator pointing to the element with the smallest
		 * value in a given range.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 *
		 * @return Iterator storing the smallest value in the range.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto MinRange(InIterator first, InIterator last)
			-> InIterator
		{
			if (first == last)
				return first;

			InIterator min_element_itr = first++;

			for (; first != last; first++)
				min_element_itr = *min_element_itr < *first ? min_element_itr : first;

			return min_element_itr;
		}

		/**
		 * @brief Returns an iterator pointing to the element with the largest
		 * value in a given range.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 *
		 * @return Iterator storing the largest value in the range.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto MaxRange(InIterator first, InIterator last)
			-> InIterator
		{
			if (first == last)
				return first;

			InIterator max_element_itr = first++;

			for (; first != last; first++)
				max_element_itr = *max_element_itr > *first ? max_element_itr : first;

			return max_element_itr;
		}

		/**
		 * @brief Returns a pair with an iterator pointing to the element with the
		 * smallest and largest value in a given range.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 *
		 * @return TPair storing a pair with an iterator pointing to the element
		 * with the smallest and largest value in the range.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto MinMaxRange(InIterator first, InIterator last)
			->InIterator
		{
			Containers::TPair<InIterator, InIterator> result(first, first);

			if (first == last)
				return result;

			for (first++; first != last; first++)
			{
				result.m_first = *(result.m_first) < *first ? result.m_first : first;
				result.m_second = *(result.m_second) > *first ? result.m_second : first;
			}

			return result;
		}

		/**
		 * @brief Returns an iterator pointing to the element with the smallest
		 * value in a given range.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param comp  The comparison binary function that returns true if lhs
		 * is smaller than rhs.
		 * 
		 * @return Iterator storing the smallest value in the range.
		 */
		template<typename InIterator, typename InComparer>
		FORGE_FORCE_INLINE auto MinRange(InIterator first, InIterator last, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, InIterator>::Value
		{
			if (first == last)
				return first;

			InIterator min_element_itr = first++;

			for (; first != last; first++)
				min_element_itr = comp(*min_element_itr, *first) ? min_element_itr : first;

			return min_element_itr;
		}

		/**
		 * @brief Returns an iterator pointing to the element with the largest
		 * value in a given range.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param comp The comparison binary function that returns true if lhs
		 * is larger than rhs.
		 *
		 * @return Iterator storing the largest value in the range.
		 */
		template<typename InIterator, typename InComparer>
		FORGE_FORCE_INLINE auto MaxRange(InIterator first, InIterator last, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, InIterator>::Value
		{
			if (first == last)
				return first;

			InIterator max_element_itr = first++;

			for (; first != last; first++)
				max_element_itr = comp(*max_element_itr, *first) ? max_element_itr : first;

			return max_element_itr;
		}

		/**
		 * @brief Returns a pair with an iterator pointing to the element with the
		 * smallest and largest value in a given range.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param comp  The comparison binary function that returns true if lhs
		 * is smaller than rhs.
		 * 
		 * @return TPair storing a pair with an iterator pointing to the element
		 * with the smallest and largest value in the range.
		 */
		template<typename InIterator, typename InComparer>
		FORGE_FORCE_INLINE auto MinMaxRange(InIterator first, InIterator last, InComparer comp)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InComparer>::Value, Containers::TPair<InIterator, InIterator>>::Value
		{
			Containers::TPair<InIterator, InIterator> result(first, first);

			if (first == last)
				return result;

			for (first++; first != last; first++)
			{
				result.m_first = comp(*(result.m_first), *first) ? result.m_first : first;
				result.m_second = comp(*first, *(result.m_second)) ? result.m_second : first;
			}

			return result;
		}
		
		/**
		 * @brief Removes all but the first element from every consecutive group of
		 * equivalent elements in a given range.
		 * 
		 * This function does not alter the properties of the object containing the
		 * range of elements, like its size or capacity. The removal is done by
		 * replacing the duplicate elements by the next element that is not a
		 * duplicate.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * 
		 * @return Iterator storing the element that follows the last element not
		 * removed.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto UniqueRange(InIterator first, InIterator last)
			-> InIterator
		{
			InIterator res = first++;

			while (first != last)
			{
				if (!(*res == *first))
					*(++res) = *first;

				first++;
			}

			return ++res;
		}

		/**
		 * @brief Reverses the order of the elements in a given range.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * 
		 * @return Iterator storing the element that was originially at the start
		 * of the range.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto ReverseRange(InIterator first, InIterator last)
			-> InIterator
		{
			while (first != last)
			{
				Swap(*first, *last); first++; last--;
			}

			return first;
		}

		/**
		 * @brief Rotates the order of the elements in a given range, in such a way
		 * that the element pointed by a given pivot becomes the new first element.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param pivot The iterator pointing to the pivot element in the range.
		 * 
		 * @return Iterator storing the element that was originially at the start
		 * of the range.
		 */
		template<typename InIterator>
		FORGE_FORCE_INLINE auto RotateRange(InIterator first, InIterator last, InIterator pivot)
			-> InIterator
		{
			InIterator next = pivot;

			while (first != last)
			{
				Swap(*(first++), *(next++));

				if (first == pivot)
					pivot = next;
			}

			return pivot;
		}

		/**
		 * @brief Assigns a value returned by successive calls to a given
		 * generator to the elements in a given range.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param gen   The generator that returns a value that can be assigned to
		 * the value pointed by the iterator.
		 */
		template<typename InIterator, typename InGenerator>
		FORGE_FORCE_INLINE auto GenerateRange(InIterator first, InIterator last, InGenerator gen)
			-> Void
		{
			while (first != last)
				*(first++) = gen();
		}

		/**
		 * @brief Assigns a given element to all the elements in a given range.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param elem  The element to assign to all elements in the range.
		 */
		template<typename InIterator, typename InElementType>
		FORGE_FORCE_INLINE auto FillRange(InIterator first, InIterator last, const InElementType& elem)
			-> Void
		{
			while (first != last)
				*(first++) = elem;
		}

		/**
		 * @brief Returns the number of elements in a given range that compare
		 * equal to a given element.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param elem  The element to check for occurances in the range.
		 * 
		 * @return Size The number of elements in the range that compare equal to
		 * the given element.
		 */
		template<typename InIterator, typename InElementType>
		FORGE_FORCE_INLINE auto CountRange(InIterator first, InIterator last, const InElementType& elem)
			-> Size
		{
			Size count = 0;

			while (first != last)
				if (*(first++) == elem)
					count++;

			return count;
		}

		/**
	     * @brief Computes the total result of the elements in a given range using
	     * a given operation.
	     *
	     * @param first The iterator pointing to the first element in the range.
	     * @param last  The iterator pointing to the last element in the range.
	     * @param init  The	initial value of the resultant operation.
	     * @param op    The operation binary function that will be applied to
	     * elements in the range.
	     *
	     * @return OutReturnType storting the result of computing the given
	     * operation on all elements in the given range.
	     */
		template<typename InIterator, typename OutReturnType, typename InOperation>
		FORGE_FORCE_INLINE auto AccumulateRange(InIterator first, InIterator last, OutReturnType init, InOperation op)
			-> typename Common::TEnableIf<Common::TIsBinaryFunction<InOperation>::Value, OutReturnType>::Value
		{
			if (first == last)
				return init;

			while (first != last)
				init = op(init, *(first++));

			return init;
		}

		/**
		 * @brief Returns true if the given predicate returns true for all the
		 * elements in a given range and false otherwise.
		 * 
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param pred  The function to test for a specific condition on elements
		 * in the range.
		 * 
		 * @return True if the predicate returns true for all the elements in the
		 * range and false otherwise.
		 */
		template<typename InIterator, typename InElementType>
		FORGE_FORCE_INLINE auto AllOfRange(InIterator first, InIterator last, Common::TDelegate<Bool(const InElementType&)> pred)
			-> Bool
		{
			if (first == last)
				return false;

			while (first != last)
				if (!pred.Invoke(*(first++)))
					return false;

			return true;
		}

		/**
		 * @brief Returns true if the given predicate returns true for any of the
		 * elements in a given range and false otherwise.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param pred  The function to test for a specific condition on elements
		 * in the range.
		 *
		 * @return True if the predicate returns true for any of the elements in
		 * the range and false otherwise.
		 */
		template<typename InIterator, typename InElementType>
		FORGE_FORCE_INLINE auto AnyOfRange(InIterator first, InIterator last, Common::TDelegate<Bool(const InElementType&)> pred)
			-> Bool
		{
			if (first == last)
				return false;

			while (first != last)
				if (pred.Invoke(*(first++)))
					return true;

			return false;
		}

		/**
		 * @brief Returns true if the given predicate returns false for all the
		 * elements in a given range and false otherwise.
		 *
		 * @param first The iterator pointing to the first element in the range.
		 * @param last  The iterator pointing to the last element in the range.
		 * @param pred  The function to test for a specific condition on elements
		 * in the range.
		 *
		 * @return True if the predicate returns false for all the elements in
		 * the range and false otherwise.
		 */
		template<typename InIterator, typename InElementType>
		FORGE_FORCE_INLINE auto NoneOfRange(InIterator first, InIterator last, Common::TDelegate<Bool(const InElementType&)> pred)
			-> Bool
		{
			if (first == last)
				return false;

			while (first != last)
				if (pred.Invoke(*(first++)))
					return false;

			return true;
		}

		/**
		 * @brief Compares the elements in a given range with those in another
		 * given range and returns the first element of both ranges that does
		 * not match.
		 * 
		 * @param first_one The iterator pointing to the first element in the first range.
		 * @param last_one  The iterator pointing to the last element in the first range.
		 * @param first_two The iterator pointing to the first element in the second range.
		 * @param last_two  The iterator pointing to the last element in the second range.
		 * 
		 * @return TPair storing two iterators pointing to the first element in
		 * both sequences that did not compare equal to each other.
		 */
		template<typename InIteratorOne, typename InIteratorTwo>
		FORGE_FORCE_INLINE auto MismatchRange(InIteratorOne first_one, InIteratorOne last_one, InIteratorTwo first_two, InIteratorTwo last_two)
			-> Containers::TPair<InIteratorOne, InIteratorTwo>
		{
			if (last_one - first_one != last_two - first_two)
				return Containers::TPair<InIteratorOne, InIteratorTwo>(first_one, first_one);

			while (first_one != last_one && *first_one == *first_two)
			{
				first_one++; first_two++;
			}

			return Containers::TPair<InIteratorOne, InIteratorTwo>(first_one, first_two);
		}

		/**
		 * @brief Compares the elements in a given range with those in another
		 * given range and returns true if all of the elements in both ranges match
		 * even in a different order.
		 * 
		 * @param first_one The iterator pointing to the first element in the first range.
		 * @param last_one  The iterator pointing to the last element in the first range.
		 * @param first_two The iterator pointing to the first element in the second range.
		 * @param last_two  The iterator pointing to the last element in the second range.
		 * 
		 * @return True if all the elements in the range compare equal to those of
		 * the other range in any order, and false otherwise.
		 */
		template<typename InIteratorOne, typename InIteratorTwo>
		FORGE_FORCE_INLINE auto EqualPermuationlRange(InIteratorOne first_one, InIteratorOne last_one, InIteratorTwo first_two, InIteratorTwo last_two)
			-> Bool
		{
			Size range_size = last_one - first_one;

			if (range_size != last_two - first_two)
				return false;

			I32 map[range_size];

			Memory::Copy(const_cast<I32*>(map), 0, range_size);

			while (first_one != last_one)
				map[*((first_one++)) % range_size]++;

			while (first_two != last_two)
			{
				if (map[(*first_two) % range_size] == 0)
					return false;

				map[(*(first_two++)) % range_size]--;
			}
				

			return true;
		}
	}
}

#endif // RANGE_UTILITIES_H
