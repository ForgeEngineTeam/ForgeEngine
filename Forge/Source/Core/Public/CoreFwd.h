#ifndef CORE_FWD_H
#define CORE_FWD_H

namespace Forge {
	namespace Containers
	{

	}
}

namespace Forge {
	namespace Memory
	{
		class AbstractAllocator;
	}
}

namespace Forge {
	namespace RTTI
	{
		class Object;
		class AbstractObjectFactory;

		class TypeInfo;
		class RefCounted;

		template<typename T>
		class TSharedPtr;

		template<typename T>
		class TWeakPtr;
	}
}

#endif // CORE_FWD_H
