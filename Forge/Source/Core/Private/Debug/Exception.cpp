#include <sstream>

#include <Core/Public/Memory/MemoryUtilities.h>
#include <Core/Public/Debug/Exception/Exception.h>

namespace Forge {
	namespace Debug
	{
		Exception::Exception(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr desc)
			: m_line(line), m_file(file), m_function(function), m_additional_info(nullptr)
		{
			std::stringstream ss;
			ss << "type_name" << ": " << desc << " in '" << m_function << "' at '" << m_file << "' (line " << m_line << ").";
			
			Memory::MemoryCopy(m_description, const_cast<CharPtr>(ss.str().c_str()), ss.str().size());
		}
		Exception::Exception(ConstCharPtr line, ConstCharPtr file, ConstCharPtr function, ConstCharPtr desc, ConstCharPtr info)
			: m_line(line), m_file(file), m_function(function), m_additional_info(info)
		{
			std::stringstream ss;
			ss << "type_name" << ": " << desc << " in '" << m_function << "' at '" << m_file << "' (line " << m_line << "). " << m_additional_info << ".";

			Memory::MemoryCopy(m_description, const_cast<CharPtr>(ss.str().c_str()), ss.str().size());
		}
	}
}