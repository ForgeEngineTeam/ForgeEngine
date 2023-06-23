#ifndef SINGLETON_H
#define SINGELTON_H

#include "../Common/Compiler.h"

namespace Forge
{
	template<typename InDerivedType>
	class TSingleton
	{
	FORGE_CLASS_NONCOPYABLE(TSingleton)

	protected:
		TSingleton() = default;
		~TSingleton() = default;

	public:
		static InDerivedType& GetInstance()
		{
			static InDerivedType instance;
			return instance;
		}
	};

	#define FORGE_CLASS_SINGLETON(Typename) \
		private:							\
			Typename() = default;			\
		friend TSingleton<Typename>;        \

}

#endif // SINGLETON_H
