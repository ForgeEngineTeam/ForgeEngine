#include "Core/Public/RTTI/Object.h"

namespace Forge {
	namespace RTTI
	{
		ConstTypeInfoPtr Object::GetTypeInfo(void)
		{
			static TypeInfo static_type_info("Object", sizeof(Object), nullptr);
			return &static_type_info;
		}

		Bool Object::IsInstanceOf(ConstStringHash type_id) const
		{
			return GetTypeInfo()->IsDerivedFrom(type_id);
		}
		Bool Object::IsInstanceOf(ConstTypeInfoPtr type_info) const
		{
			return GetTypeInfo()->IsDerivedFrom(type_info);
		}
	}
}
