#ifndef GL_UTILITIES_H
#define GL_UTILITIES_H

#include <Core/Public/Common/Common.h>

#include <GraphicsDevice/Public/OpenGL/GL/gl.h>
#include <GraphicsDevice/Public/GraphicsTypes.h>

namespace Forge {
	namespace Graphics
	{
#if defined(FORGE_GL_ERROR_CHECK)
	#define FORGE_GL_CHECK_ERROR(__FUNC__)                                                                  \
	{                                                                                                       \
	    __FUNC__;                                                                                           \
	    GLenum error = glGetError();                                                                        \
	    if (error != 0)                                                                                     \
	    {                                                                                                   \
	        ConstCharPtr string = "";                                                                       \
	        switch(error)                                                                                   \
	        {                                                                                               \
	            case GL_INVALID_ENUM:                   string = "GL_INVALID_ENUM";                  break; \
	            case GL_INVALID_VALUE:                  string = "GL_INVALID_VALUE";                 break; \
	            case GL_OUT_OF_MEMORY:                  string = "GL_OUT_OF_MEMORY";                 break; \
	            case GL_INVALID_OPERATION:              string = "GL_INVALID_OPERATION";             break; \
	            case GL_INVALID_FRAMEBUFFER_OPERATION:  string = "GL_INVALID_FRAMEBUFFER_OPERATION"; break; \
	            default:                                                                             break; \
	        }                                                                                               \
	        String func_name = #__FUNC__;                                                                   \
	        func_name = func_name.Cut(0, func_name.FindFirstOf('('));                                       \
	        LogManager::getSingleton().logError(StringUtil::format("%s failed with %s in %s at %s(%d)",     \
	                                                                func_name.ConvertToCString(), string,   \
		                                                            __FUNCTION__, __FILE__, __LINE__));     \
	    }                                                                                                   \
	}
#else
	#define FORGE_GL_CHECK_ERROR(__FUNC__) { __FUNC__; }
#endif
		/**
		 * @brief Converts Engine API value type to Opengl value type.
		 *
		 * @param function The engine API value type to convert.
		 *
		 * @returns GLenum storing Opengl value type.
		 */
		FORGE_FORCE_INLINE GLenum ConvertToGLValueType(ValueTypeMask value_type)
		{
			GLenum gl_value_type;

			switch (value_type)
			{
			case ValueTypeMask::FORGE_BYTE:       gl_value_type = GL_BYTE;           break;
			case ValueTypeMask::FORGE_UBYTE:      gl_value_type = GL_UNSIGNED_BYTE;  break;
			case ValueTypeMask::FORGE_SHORT:      gl_value_type = GL_SHORT;          break;
			case ValueTypeMask::FORGE_USHORT:     gl_value_type = GL_UNSIGNED_SHORT; break;
			case ValueTypeMask::FORGE_INT:		  gl_value_type = GL_INT;            break;
			case ValueTypeMask::FORGE_UINT:		  gl_value_type = GL_UNSIGNED_INT;   break;
			case ValueTypeMask::FORGE_HALF_FLOAT: gl_value_type = GL_HALF_FLOAT;     break;
			case ValueTypeMask::FORGE_FLOAT:	  gl_value_type = GL_FLOAT;          break;
			case ValueTypeMask::FORGE_DOUBLE:	  gl_value_type = GL_DOUBLE;         break;
			}

			return gl_value_type;
		}

		/**
		 * @brief Converts Engine API usage mode to Opengl usage mode.
		 *
		 * @param function The engine API usage mode to convert.
		 *
		 * @returns GLenum storing Opengl usage mode.
		 */
		FORGE_FORCE_INLINE GLenum ConvertToGLBufferUsage(UsageModeMask usage_mode)
		{
			GLenum gl_usage_mode;

			switch (usage_mode)
			{
			case UsageModeMask::FORGE_GPU_TO_CPU:              gl_usage_mode = GL_STATIC_READ;  break;
			case UsageModeMask::FORGE_CPU_TO_GPU:              gl_usage_mode = GL_DYNAMIC_READ; break;
			case UsageModeMask::FORGE_GPU_ONLY:                gl_usage_mode = GL_STATIC_DRAW;  break;
			case UsageModeMask::FORGE_CPU_TO_GPU_WRITE_ONLY:   gl_usage_mode = GL_DYNAMIC_DRAW; break;
			}

			return gl_usage_mode;
		}

		/**
		 * @brief Converts Engine API value type to Opengl value type.
		 *
		 * @param function The engine API value type to convert.
		 *
		 * @returns GLenum storing Opengl value type.
		 */
		FORGE_FORCE_INLINE GLenum ConvertToGLBufferType(BufferTypeMask buffer_type)
		{
			GLenum gl_buffer_type;

			switch (buffer_type)
			{
			case BufferTypeMask::FORGE_VERTEX_BUFFER:     gl_buffer_type = GL_ARRAY_BUFFER;         break;
			case BufferTypeMask::FORGE_INDEX_BUFFER:      gl_buffer_type = GL_ELEMENT_ARRAY_BUFFER; break;
			case BufferTypeMask::FORGE_COPY_READ_BUFFER:  gl_buffer_type = GL_COPY_READ_BUFFER;     break;
			case BufferTypeMask::FORGE_COPY_WRITE_BUFFER: gl_buffer_type = GL_COPY_WRITE_BUFFER;    break;
			}

			return gl_buffer_type;
		}

		/**
		 * @brief Converts Engine API blend function to Opengl blending function.
		 * 
		 * @param function The engine API blend function to convert.
		 *
		 * @returns GLenum storing Opengl blend function.
		 */
		FORGE_FORCE_INLINE GLenum ConvertToGLBlendFunction(BlendFuncMask blend_function)
		{
			GLenum gl_function;

			switch (blend_function)
			{
			case BlendFuncMask::FORGE_ZERO:                     gl_function = GL_ZERO;                     break;
			case BlendFuncMask::FORGE_ONE:                      gl_function = GL_ONE;                      break;
			case BlendFuncMask::FORGE_SRC_COLOR:                gl_function = GL_SRC_COLOR;                break;
			case BlendFuncMask::FORGE_ONE_MINUS_SRC_COLOR:      gl_function = GL_ONE_MINUS_SRC_COLOR;      break;
			case BlendFuncMask::FORGE_DST_COLOR:                gl_function = GL_DST_COLOR;                break;
			case BlendFuncMask::FORGE_ONE_MINUS_DST_COLOR:      gl_function = GL_ONE_MINUS_DST_COLOR;      break;
			case BlendFuncMask::FORGE_SRC_ALPHA:                gl_function = GL_SRC_ALPHA;                break;
			case BlendFuncMask::FORGE_ONE_MINUS_SRC_ALPHA:      gl_function = GL_ONE_MINUS_SRC_ALPHA;      break;
			case BlendFuncMask::FORGE_DST_ALPHA:               	gl_function = GL_DST_ALPHA;                break;
			case BlendFuncMask::FORGE_ONE_MINUS_DST_ALPHA:		gl_function = GL_ONE_MINUS_DST_ALPHA;      break;
			case BlendFuncMask::FORGE_CONSTANT_COLOR:			gl_function = GL_CONSTANT_COLOR;           break;
			case BlendFuncMask::FORGE_ONE_MINUS_CONSTANT_COLOR:	gl_function = GL_ONE_MINUS_CONSTANT_COLOR; break;
			case BlendFuncMask::FORGE_CONSTANT_ALPHA:			gl_function = GL_CONSTANT_ALPHA;           break;
			case BlendFuncMask::FORGE_ONE_MINUS_CONSTANT_ALPHA:	gl_function = GL_ONE_MINUS_CONSTANT_ALPHA; break;
			}

			return gl_function;
		}

		/**
		 * @brief Converts Engine API compare function to Opengl compare function.
		 *
		 * @param function The engine API compare function to convert.
		 *
		 * @returns GLenum storing Opengl compare function.
		 */
		FORGE_FORCE_INLINE GLenum ConvertToGLCompareFunction(ComparisonFuncMask comparison_function)
		{
			GLenum gl_function;

			switch (comparison_function)
			{
			case ComparisonFuncMask::FORGE_LESS:     gl_function = GL_LESS;     break;
			case ComparisonFuncMask::FORGE_NEVER:    gl_function = GL_NEVER;    break;
			case ComparisonFuncMask::FORGE_EQUAL:    gl_function = GL_EQUAL;    break;
			case ComparisonFuncMask::FORGE_LEQUAL:   gl_function = GL_LEQUAL;   break;
			case ComparisonFuncMask::FORGE_GEQUAL:   gl_function = GL_GEQUAL;   break;
			case ComparisonFuncMask::FORGE_ALWAYS:   gl_function = GL_ALWAYS;   break;
			case ComparisonFuncMask::FORGE_GREATER:  gl_function = GL_GREATER;  break;
			case ComparisonFuncMask::FORGE_NOTEQUAL: gl_function = GL_NOTEQUAL; break;
			}

			return gl_function;
		}
	}
}

#endif
