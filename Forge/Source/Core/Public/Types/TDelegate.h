#ifndef T_DELEGATE_HPP
#define T_DELEGATE_HPP

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Common/Common.h>

#include <Core/Public/Memory/MemoryUtilities.h>

#include <Core/Public/Algorithm/GeneralUtilities.h>

using namespace Forge::Debug;
using namespace Forge::Memory;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Common
	{
		template<typename Type>
		class TDelegate {};

		/**
		 * @brief A delegate is a type that represents references to callable
		 * objects with a particular parameter list and return type.
		 * 
		 * When an instance of a delegate is created, the instance can be associated
		 * with any function with a compatible signature and return type. The method
		 * can be invoked (or called) through the delegate instance.
		 * 
		 * Delegates are used to pass functions as arguments to other functions.
		 * This ability to refer to a function as a parameter makes delegates ideal
		 * for defining callback functions.
		 * 
		 * @author Karim Hisham
		 */
		template<typename InReturnType, typename... InParams>
		class TDelegate<InReturnType(InParams...)>
		{
		private:
			using SelfType         = TDelegate<InReturnType(InParams...)>;
			using SelfTypePtr      = TDelegate<InReturnType(InParams...)>*;
			using SelfTypeRef      = TDelegate<InReturnType(InParams...)>&;
			using SelfTypeMoveRef  = TDelegate<InReturnType(InParams...)>&&;
			using ConstSelfType    = const TDelegate<InReturnType(InParams...)>;
			using ConstSelfTypeRef = const TDelegate<InReturnType(InParams...)>&;
			using ConstSelfTypePtr = const TDelegate<InReturnType(InParams...)>*;

		private:
			using SignatureFunc = InReturnType(*)(InParams...);
			using InvokableFunc = InReturnType(*)(ConstSelfTypeRef, InParams...);

		private:
			template<typename InLambdaFunctor>
			struct LambdaStorage 
			{ 
				InLambdaFunctor m_lambda; 
				LambdaStorage(InLambdaFunctor lambda) : m_lambda(lambda) {}
			};

		private:
			union
			{
				VoidPtr m_instance_ptr;
				ConstVoidPtr m_const_instance_ptr;
			};

		private:
			InvokableFunc m_invokable_function;

		private:
			 Size m_function_size;
			 mutable BytePtr m_function_address;

		private:
			/**
			 * @brief Invokes the lambda functor currently bound inplace in the
			 * delegate object.
			 *
			 * This function is used internally by the delegate object to call a
			 * function pointer with the appropriate parameter semantics it was
			 * passed.
			 *
			 * @param[in] self_type The calling delegate object to this function.
			 * @param[in] InParams    The parameters to pass to the bound function.
			 *
			 * @return InReturnType storing the return value of the bound function.
			 */
			template<typename InFunction>
			static InReturnType InvokeLambda(ConstSelfTypeRef self_type, InParams... params)
			{
				return reinterpret_cast<LambdaStorage<InFunction>*>(self_type.m_function_address)->m_lambda(params...);
			}

			/**
			 * @brief Invokes the global function currently bound inplace in the
			 * delegate object.
			 *
			 * This function is used internally by the delegate object to call a
			 * function pointer with the appropriate parameter semantics it was
			 * passed.
			 *
			 * @param[in] self_type The calling delegate object to this function.
			 * @param[in] InParams    The parameters to pass to the bound function.
			 *
			 * @return InReturnType storing the return value of the bound function.
			 */
			template<typename InFunction>
			static InReturnType InvokeFunction(ConstSelfTypeRef self_type, InParams... params)
			{
				return (*(reinterpret_cast<InFunction*>(self_type.m_function_address)))(params...);
			}

			/**
			 * @brief Invokes the member function currently bound inplace in the
			 * delegate object.
			 *
			 * This function is used internally by the delegate object to call a
			 * function pointer with the appropriate parameter semantics it was
			 * passed.
			 *
			 * @param[in] self_type The calling delegate object to this function.
			 * @param[in] InParams    The parameters to pass to the bound function.
			 *
			 * @return InReturnType storing the return value of the bound function.
			 */
			template<typename InFunction, typename InClass>
			static InReturnType InvokeClassFunction(ConstSelfTypeRef self_type, InParams... params)
			{
				InFunction function = *(reinterpret_cast<InFunction*>(self_type.m_function_address));

				return (static_cast<InClass*>(self_type.m_instance_ptr)->*function)(params...);
			}

			/**
			 * @brief Invokes the const member function currently bound inplace in
			 * the delegate object.
			 *
			 * This function is used internally by the delegate object to call a
			 * function pointer with the appropriate parameter semantics it was
			 * passed.
			 *
			 * @param[in] self_type The calling delegate object to this function.
			 * @param[in] InParams    The parameters to pass to the bound function.
			 *
			 * @return InReturnType storing the return value of the bound function.
			 */
			template<typename InFunction, typename InClass>
			static InReturnType InvokeClassConstFunction(ConstSelfTypeRef self_type, InParams... params)
			{
				InFunction function = *(reinterpret_cast<InFunction*>(self_type.m_function_address));

				return (static_cast<const InClass*>(self_type.m_const_instance_ptr)->*function)(params...);
			}

		public:
			/**
			 * @brief Default constructor.
			 * 
			 * Constructs an empty delegate object with the invokable to null.
			 */
			TDelegate(Void)
				: m_function_size(0), m_function_address(nullptr), m_invokable_function(nullptr) {}

			/**
			 * @brief Global invokable constructor.
			 * 
			 * Constructs a delegate object with the passed invokable bound to the
			 * delegate object.
			 */
			template<typename InFunction>
			TDelegate(InFunction function)
			{
				if (TIsAssignable<SignatureFunc&, InFunction>::Value)
				{
					ConstSize size = sizeof(InFunction);

					m_function_address = new Byte[size];
					
					if (size > 1 && size <= sizeof(SignatureFunc))
						MemoryCopy(m_function_address, &function, size);
					else
						MemorySet(m_function_address, 0, size);

					m_instance_ptr = nullptr;

					m_function_size = size;
					m_invokable_function = reinterpret_cast<InvokableFunc>(&InvokeFunction<InFunction>);
				}
				else
				{
					ConstSize size = sizeof(LambdaStorage<InFunction>);

					m_function_address = new Byte[size];
						
					new (m_function_address) LambdaStorage<InFunction>(function);
				
					m_instance_ptr = nullptr;

					m_function_size = size;
					m_invokable_function = reinterpret_cast<InvokableFunc>(&InvokeLambda<InFunction>);
				}
			}
			
			/**
			 * @brief Member function constructor.
			 * 
			 * Constructs a delegate object with the passed member function bound
			 * to the delegate object.
			 */
			template<typename InFunction, typename InClass>
			TDelegate(InFunction function, InClass* instance)
			{
				ConstSize size = sizeof(InFunction);

				m_function_address = new Byte[size];

				MemoryCopy(m_function_address, &function, size);

				m_instance_ptr = instance;

				m_function_size = size;
				m_invokable_function = &InvokeClassFunction<InFunction, InClass>;
			}
			
			/**
			 * @brief Bind const member function constructor.
			 *
			 * Constructs a delegate object with the passed const member function
			 * bound to the delegate object.
			 */
			template<typename InFunction, typename InClass>
			TDelegate(InFunction function, const InClass* instance)
			{
				ConstSize size = sizeof(InFunction);

				m_function_address = new Byte[size];

				MemoryCopy(m_function_address, &function, size);

				m_const_instance_ptr = instance;

				m_function_size = size;
				m_invokable_function = &InvokeClassFunction<InFunction, InClass>;
			}

		public:
			/**
			 * @brief Move constructor.
			 */
			TDelegate(SelfTypeMoveRef other)
				: m_function_size(0), m_function_address(nullptr), m_invokable_function(nullptr)
			{
				*this = Move(other);
			}

			/**
			 * @brief Copy constructor.
			 */
			TDelegate(ConstSelfTypeRef other)
				: m_function_size(0), m_function_address(nullptr), m_invokable_function(nullptr)
			{
				*this = other;
			}

		public:
			/**
			 * @brief Default destructor
			 */
			~TDelegate(Void)
			{
				Invalidate();
			}

		public:
			/**
			 * @brief Move assignment.
			 */
			SelfTypeRef operator =(SelfTypeMoveRef other)
			{
				Invalidate();

				MemoryCopy(this, &other, sizeof(SelfType));
			
				other.m_function_size = 0;
				other.m_instance_ptr = nullptr;
				other.m_function_address = nullptr;
				other.m_invokable_function = nullptr;

				return *this;
			}

			/**
			 * @brief Copy assignment.
			 */
			SelfTypeRef operator =(ConstSelfTypeRef other)
			{
				Invalidate();

				m_function_address = new Byte[other.m_function_size];

				MemoryCopy(m_function_address, other.m_function_address, other.m_function_size);

				m_instance_ptr = other.m_instance_ptr;

				m_function_size = other.m_function_size;
				m_invokable_function = other.m_invokable_function;

				return *this;
			}

		public:
			/** 
			 * @brief Checks wether the delegate object has a currently bound
			 * invokable. 
			 * 
			 * The function pointer must be valid and non-nullptr.
			 * 
			 * @return True if the delegate object has a bound function.
			 */
			Bool IsValid(Void)
			{
				return m_invokable_function != nullptr;
			}
			
			/**
			 * @brief Checks wether two delegate objects are bound to the same
			 * invokables, including the same instance.
			 * 
			 * @param[in] other The other delegate object to check for equality.
			 * 
			 * @return True if both delegate objects are equal.
			 */
			Bool IsEqual(ConstSelfTypeRef other)
			{
				return m_instance_ptr == other.m_instance_ptr &&
					   m_invokable_function == other.m_invokable_function &&
					   MemoryCompare(m_function_address, other.m_function_address, sizeof(InReturnType(*)(InParams...)));
			}

		public:
			/**
			 * @brief Releases the currently bound invokable.
			 * 
			 * This function invalidates the delegate object by resseting its
			 * inplace memory storage for function address.
			 */
			Void Invalidate(Void)
			{
				if (m_function_address)
				{
					MemorySet(m_function_address, 0, m_function_size);
					delete m_function_address;
				}

				m_function_size = 0;
				m_instance_ptr = nullptr;
				m_function_address = nullptr;
				m_invokable_function = nullptr;
			}

			/**
			 * @brief Invokes the currently bound invokable.
			 *
			 * @param[in] InParams The parameters to pass to the bound invokable.
			 *
			 * @return InReturnType storing the return value of the bound invokable.
			 * 
			 * @throws InvalidOperationException if the delegate object is invalid.
			 */
			InReturnType Invoke(InParams... params)
			{
				if (!IsValid())
					FORGE_EXCEPT(ExceptionType::FORGE_INVALID_OPERATION)

				return (m_invokable_function)(*this, params...);
			}
		};
	}
}

#endif // T_DELEGATE_HPP
