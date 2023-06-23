#ifndef PREPROCESSOR_UTILITIES_H
#define PREPROCESSOR_UTILITIES_H

#include <cstdio>

#include "Compiler.h"

#define FORGE_TRUE	1
#define FORGE_FALSE	0

#define FORGE_BIT(x) (1 << x)

#define FORGE_ARRAY_COUNT(array) ( sizeof(array) / sizeof( array[0] ) )

#define FORGE_SAFE_DELETE_UNIT(mem) if( mem != nullptr ) { delete mem; mem = nullptr; }
#define FORGE_SAFE_DELETE_BLOCK(mem) if( mem != nullptr ) { delete[] mem; mem = nullptr; }

#define IMPL_FORGE_STRINGIZE(s) #s
#define FORGE_STRINGIZE(s) IMPL_FORGE_STRINGIZE(s)

#define IMPL_FORGE_CONCATENATE(s1, s2) s1##s2
#define FORGE_CONCATENATE(s1, s2) IMPL_FORGE_CONCATENATE(s1, s2)

#define IMPL_FORGE_CONCATENATE_VARIADIC(s, ...) s ## __VA_ARGS__
#define FORGE_CONCATENATE_VARIADIC(s, ...) IMPL_FORGE_CONCATENATE_VARIADIC(s, ...)

#define IMPL_FORGE_CONCATENATE_COMMA_VARIADIC(s, ...) s, ## __VA_ARGS__
#define FORGE_CONCATENATE_COMMA_VARIADIC(s, ...) IMPL_FORGE_CONCATENATE_COMMA_VARIADIC(s, ...)

#define FORGE_FUNC_LITERAL __FUNCTION__
#define FORGE_LINE_LITERAL FORGE_STRINGIZE(__LINE__)
#define FORGE_FILE_LITERAL FORGE_STRINGIZE(__FILE__)

#define FORGE_NOT_IMPLEMENTED(...) do {} while(false);

#define FORGE_ENUM_DECL(__NAME__, __VALUE__) __NAME__ = __VALUE__,

#define FORGE_FLAG_DECL(__NAME__)									                 \
	inline Bool operator &(__NAME__ lhs, __NAME__ rhs)								 \
    {                                                                                \
		return static_cast<Bool>(static_cast<int>(lhs) & static_cast<int>(rhs));     \
	}                                                                                \
	inline __NAME__ operator |(__NAME__ lhs, __NAME__ rhs)                           \
	{                                                                                \
		return static_cast<__NAME__>(static_cast<int>(lhs) | static_cast<int>(rhs)); \
	}

#define FORGE_FRIEND_DECL(__NAME__) \
	friend class __NAME__;

#define FORGE_UNARY_FUNCTION_DECL(__NAME__) \
	template<typename InType> struct TIsUnaryFunction<__NAME__<InType>> { enum { Value = true }; };

#define FORGE_BINARY_FUNCTION_DECL(__NAME__) \
	template<typename InType> struct TIsBinaryFunction<__NAME__<InType>> { enum { Value = true }; };

#define FORGE_TYPEDEF_DECL(__NAME__)                 \
    using __NAME__##Ptr        = __NAME__*;          \
    using __NAME__##Ref        = __NAME__&;          \
    using __NAME__##MoveRef    = __NAME__&&;         \
    using Const##__NAME__      = const __NAME__;     \
    using Const##__NAME__##Ptr = const __NAME__*;    \
    using Const##__NAME__##Ref = const __NAME__&;    \

#define FORGE_TYPEDEF_TEMPLATE_DECL(__NAME__)                                          \
    template<typename InType> using __NAME__##Ptr        = __NAME__<InType>*;          \
	template<typename InType> using __NAME__##Ref        = __NAME__<InType>&;          \
	template<typename InType> using __NAME__##MoveRef    = __NAME__<InType>&&;         \
    template<typename InType> using Const##__NAME__      = const __NAME__<InType>;     \
    template<typename InType> using Const##__NAME__##Ptr = const __NAME__<InType>*;    \
	template<typename InType> using Const##__NAME__##Ref = const __NAME__<InType>&;

#define FORGE_CLASS_NONCOPYABLE(__NAME__)                  \
	public:                                                \
		__NAME__(__NAME__&& rhs) = delete;                 \
		__NAME__(const __NAME__& rhs) = delete;            \
		__NAME__& operator=(__NAME__&& rhs) = delete;      \
		__NAME__& operator=(const __NAME__& rhs) = delete; \

#if defined(FORGE_BUILD_DEBUG)
	#define FORGE_ASSERT(__EXPR__, __MSG__)                                                                      \
		if(__EXPR__) {}                                                                                          \
		else                                                                                                     \
		{                                                                                                        \
			fprintf(stderr, "%s:%s: assertion failed: %s\n", FORGE_FILE_LITERAL, FORGE_LINE_LITERAL, #__EXPR__); \
			fprintf(stderr, "assertion message: %s", #__MSG__);                                                  \
			FORGE_DEBUG_BREAK																					 \
		}											                                                             \

#define FORGE_STATIC_ASSERT(__EXPR__)            \
	enum                                         \
	{                                            \
		FORGE_CONCATENATE(assert_fail, __LINE__) \
			= 1 / (int) (!!(__EXPR__))           \
	};
#else
	#define FORGE_ASSERT(__EXPR__)
	#define FORGE_STATIC_ASSERT(__EXPR__)
#endif

#endif // PREPROCESSOR_UTILITIES_H