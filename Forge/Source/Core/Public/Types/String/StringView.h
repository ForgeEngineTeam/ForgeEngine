#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <Core/Public/Types/String/AbstractString.h>

namespace Forge {
	namespace Common
	{
		class FORGE_API StringView final : public AbstractString<StringView>
		{

		};
	}
}

#endif // STRING_VIEW_H
