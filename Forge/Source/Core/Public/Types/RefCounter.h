#ifndef REF_COUNTER_H
#define REF_COUNTER_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Common
	{
		/**
		 * @brief Manages reference-counting.
		 * 
		 * @author Karim Hisham
		 */
		class RefCounter final
		{
		FORGE_CLASS_NONCOPYABLE(RefCounter)

		private:
			Size m_ref;
			Size m_weak_ref;

		public:
			/**
			 * @brief Default constructor.
			 */
			RefCounter(Void);

		public:
			/**
			 * @brief Default destructor.
			 */
			~RefCounter(Void) = default;

		public:
			/**
			 * @brief Checks if the object is referenced.
			 * 
			 * @return True if the object is referenced, otherwise false.
			 */
			Bool IsReferenced(Void) const;

		public:
			/**
			 * @brief Gets number of object references.
			 * 
			 * @return ConstSize storing number of references. 
			 */
			ConstSize GetRefCount(Void) const;

			/**
			 * @brief Gets number of object weak references.
			 *
			 * @return ConstSize storing number of weak references. 
			 */
			ConstSize GetWeakRefCount(Void) const;

		public:
			/**
			 * @brief Increments number of object references.
			 */
			Void IncrementRef(Void);

			/**
			 * @brief Decrements number of object references.
			 */
			Void DecrementRef(Void);

			/**
			 * @brief Increments number of object weak references.
			 */
			Void IncrementWeakRef(Void);

			/**
			 * @brief Decrements number of object weak references.
			 */
			Void DecrementWeakRef(Void);
		};

		FORGE_TYPEDEF_DECL(RefCounter)

		FORGE_FORCE_INLINE RefCounter::RefCounter(Void)
			: m_ref(0), m_weak_ref(0) {}

		FORGE_FORCE_INLINE Bool RefCounter::IsReferenced(Void) const
		{
			return this->GetRefCount() >= 1;
		}

		FORGE_FORCE_INLINE ConstSize RefCounter::GetRefCount(Void) const
		{
			return this->m_ref;
		}
		FORGE_FORCE_INLINE ConstSize RefCounter::GetWeakRefCount(Void) const
		{
			return this->m_weak_ref;
		}

		FORGE_FORCE_INLINE Void RefCounter::IncrementRef(Void)
		{
			FORGE_ASSERT(m_ref >= 0, "Reference number must be a positive integer")
				
			this->m_ref++;
		}
		FORGE_FORCE_INLINE Void RefCounter::DecrementRef(Void)
		{
			FORGE_ASSERT(m_ref >= 0, "Reference number must be a positive integer")
			
			this->m_ref--;
		}

		FORGE_FORCE_INLINE Void RefCounter::IncrementWeakRef(Void)
		{
			FORGE_ASSERT(m_weak_ref >= 0, "Weak reference number must be a positive integer")
			
			this->m_weak_ref++;
		}
		FORGE_FORCE_INLINE Void RefCounter::DecrementWeakRef(Void)
		{
			FORGE_ASSERT(m_weak_ref >= 0, "Weak reference number must be a positive integer")
			
			this->m_weak_ref--;
		}
	}
}

#endif // REF_COUNTER_H
