#ifndef GRAPHICS_TYPES_H
#define GRAPHICS_TYPES_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Buffer clear flags specifing the buffers to be cleared.
		 *
		 * [GL]: https://docs.gl/gl3/glClear
		 */
		enum class ClearFlags : Byte
		{
			/**
			 * @brief Indicates to clear the color buffer.
			 */
			FORGE_ENUM_DECL(FORGE_COLOR_BUFFER, FORGE_BIT(0))

			/**
			 * @brief Indicates to clear the depth buffer.
			 */
			FORGE_ENUM_DECL(FORGE_DEPTH_BUFFER, FORGE_BIT(1))

			/**
			 * @brief Indicates to clear the stencil buffer.
			 */
			FORGE_ENUM_DECL(FORGE_STENCIL_BUFFER, FORGE_BIT(2))

			MAX
		};

		/**
		 * @brief Value type masks specifing the base type of primitive data
		 * types.
		 *
		 * [GL]: https://www.khronos.org/opengl/wiki/OpenGL_Type
		 */
		enum class ValueTypeMask : Byte
		{
			FORGE_ENUM_DECL(FORGE_BYTE, 0)

			FORGE_ENUM_DECL(FORGE_UBYTE, 1)

			FORGE_ENUM_DECL(FORGE_SHORT, 2)

			FORGE_ENUM_DECL(FORGE_USHORT, 3)

			FORGE_ENUM_DECL(FORGE_INT, 4)

			FORGE_ENUM_DECL(FORGE_UINT, 5)

			FORGE_ENUM_DECL(FORGE_HALF_FLOAT, 6)

			FORGE_ENUM_DECL(FORGE_FLOAT, 7)

			FORGE_ENUM_DECL(FORGE_DOUBLE, 8)

			MAX
		};

		/**
		 * @brief Lock mode masks specifing access policy of the mapped buffer.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Buffer_Object#Mapping
		 */
		enum class LockModeFlags : Byte
		{
			FORGE_ENUM_DECL(FORGE_DISCARD,    FORGE_BIT(0))

			/**
			 * @brief Indicates that the buffer will be locked for reading
			 * only.
			 */
			FORGE_ENUM_DECL(FORGE_READ_ONLY,  FORGE_BIT(1))

			/**
			 * @brief Indicates that the buffer will be locked for writing
			 * only.
			 */
			FORGE_ENUM_DECL(FORGE_WRITE_ONLY, FORGE_BIT(2))

			MAX
		};

		/**
		 * @brief Usage mode masks specifing the expected usage pattern of the
		 * data store.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Buffer_Object#Buffer_Object_Usage
		 */
		enum class UsageModeMask : Byte
		{
			/**
			 * @brief Indicates that the buffer's data will be modified once,
			 * but might occasionally be read from.
			 */
			FORGE_ENUM_DECL(FORGE_GPU_TO_CPU,            0)

			/**
			 * @brief Indicates that the buffer's data will be modified
			 * repeatedly, and can be occasionally be read from.
			 */
			FORGE_ENUM_DECL(FORGE_CPU_TO_GPU,            1)

			/**
			 * @brief Indicates that the buffer's data will be modified once,
			 * and can not be read from. However, its data can be read from
			 * the shadow buffer if available.
			 */
			FORGE_ENUM_DECL(FORGE_GPU_ONLY,              2)

			/**
			 * @brief Indicates that the buffer's data will be modified 
			 * repeatedly, but can not be read from. However, its data can be
			 * read from the shadow buffer if available.
			 */
			FORGE_ENUM_DECL(FORGE_CPU_TO_GPU_WRITE_ONLY, 3)

			MAX
		};

		/**
		 * @brieff Buffer type masks specifing the type of buffer to bind or
		 * unbind.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Buffer_Object#General_use
		 */
		enum class BufferTypeMask : Byte
		{
			/**
			 * @brief Indicates that the buffer will be used a source of vertex
			 * data.
			 */
			FORGE_ENUM_DECL(FORGE_VERTEX_BUFFER,     0)

			/**
			 * @brief Indicates that the buffer will be used a source of index
			 * data.
			 */
			FORGE_ENUM_DECL(FORGE_INDEX_BUFFER,      1)

			/**
			 * @brief Indicates that the buffer will be used as a source buffer
			 * for copying.
			 */
			FORGE_ENUM_DECL(FORGE_COPY_READ_BUFFER,  2)

			/**
			 * @brief Indicates that the buffer will be used as a destination
			 * buffer for copying.
			 */
			FORGE_ENUM_DECL(FORGE_COPY_WRITE_BUFFER, 3)

			MAX
		};

		/**
		 * @brief Face culling masks specifing whether front or back facing faces
		 * are candidates for culling.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Face_Culling
		 */
		enum class FaceCullMask : Byte
		{
			/**
			 * @brief Indicates to cull front face.
			 */
			FORGE_ENUM_DECL(FORGE_FRONT,          0)

			/**
			 * @brief Indicates to cull back face.
			 */
			FORGE_ENUM_DECL(FORGE_BACK,           1)

			/**
			 * @brief Indicates to cull front and back face.
			 */
			FORGE_ENUM_DECL(FORGE_FRONT_AND_BACK, 2)

			MAX
		};

		/**
		 * @brief Front face masks specifing the orientation of front-facing
		 * polygons.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Face_Culling#Winding_order
		 */
		enum class FrontFaceMask
		{
			/**
			 * @brief Indicates that clockwise winding is front.
			 */
			FORGE_ENUM_DECL(FORGE_CW,  0)

			/**
			 * @brief Indicates that anti-clockwise winding is front.
			 */
			FORGE_ENUM_DECL(FORGE_CCW, 1)

			MAX
		};

		/**
		 * @brief Polygon fill masks specifing how polygons will be rasterized.
		 * 
		 * [GL]: https://docs.gl/gl3/glPolygonMode
		 */
		enum class PolygonFillMask : Byte
		{
			/**
			 * @brief Indicates that triangles will be rasterized using wireframe
			 * fill.
			 */
			FORGE_ENUM_DECL(FORGE_WIREFRAME, 1)

			/**
			 * @brief Indicates that triangles will be rasterized using solid
			 * fill.
			 */
			FORGE_ENUM_DECL(FORGE_SOLID,     2)

			MAX
		};

		/**
		 * @brief Blending functions masks specifing how the red, green, blue, and
		 * alpha source blending factors are computed.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Blending
		 */
		enum class BlendFuncMask : Byte
		{
			/**
			 * @brief Indicates to set blending factor to zero.
			 */
			FORGE_ENUM_DECL(FORGE_ZERO,                     0)

			/**
			 * @brief Indicates to set blending factor to one.
			 */
			FORGE_ENUM_DECL(FORGE_ONE,                      1)

			/**
			 * @brief Indicates to set blending factor to source color vector.
			 */
			FORGE_ENUM_DECL(FORGE_SRC_COLOR,                2)

			/**
			 * @brief Indicates to set blending factor to one minus source color
			 * vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_SRC_COLOR,      3)

			/**
			 * @brief Indicates to set blending factor to destination color
			 * vector.
			 */
			FORGE_ENUM_DECL(FORGE_DST_COLOR,                4)

			/**
			 * @brief Indicates to set blending factor to one minus destination
			 * color vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_DST_COLOR,      5)

			/**
			 * @brief Indicates to set blending factor to alpha component of the
			 * source color vector.
			 */
			FORGE_ENUM_DECL(FORGE_SRC_ALPHA,                6)

			/**
			 * @brief Indicates to set blending factor to one minus alpha
			 * component of the source color vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_SRC_ALPHA,      7)

			/**
			 * @brief Indicates to set blending factor to alpha alpha component of
			 * the destination color vector.
			 */
			FORGE_ENUM_DECL(FORGE_DST_ALPHA,                8)

			/**
			 * @brief Indicates to set blending factor to one minus alpha alpha
			 * component of the destination color vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_DST_ALPHA,      9)

			/**
			 * @brief Indicates to set blending factor to constant color vector.
			 */
			FORGE_ENUM_DECL(FORGE_CONSTANT_COLOR,           10)

			/**
			 * @brief Indicates to set blending factor to one minus constant color
			 * vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_CONSTANT_COLOR, 11)

			/**
			 * @brief Indicates to set blending factor to alpha component of
			 * constant color vector.
			 */
			FORGE_ENUM_DECL(FORGE_CONSTANT_ALPHA,           12)

			/**
			 * @brief Indicates to set blending factor to one minus alpha
			 * component of constant color vector.
			 */
			FORGE_ENUM_DECL(FORGE_ONE_MINUS_CONSTANT_ALPHA, 13)

			MAX
		};

		/**
		 * @brief Pixel storage masks specifing the packing of pixel data in
		 * memory.
		 * 
		 * [GL]: https://docs.gl/gl3/glPixelStore
		 */
		enum class PixelStorageMask : Byte
		{
			/**
			 * @brief Indicates the alignment requirements for the start of each
			 * pixel row in memory. 
			 * 
			 * The allowable values are 1, 2, 4, and 8.
			 */
			FORGE_ENUM_DECL(FORGE_PACK_ALIGNMENT, 0)

			MAX
		};

		/**
		 * @brief Comparison function masks specifing how to perform tests.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Depth_Test
		 *       https://www.khronos.org/opengl/wiki/Stencil_Test
		 */
		enum class ComparisonFuncMask : Byte
		{
			/**
			 * @brief Indicates to never pass the test.
			 */
			FORGE_ENUM_DECL(FORGE_NEVER,    0)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is less than the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_LESS,     1)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is equal to the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_EQUAL,    2)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is less than or equal to the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_LEQUAL,   3)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is greater than the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_GREATER,  4)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is not equal to the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_NOTEQUAL, 5)

			/**
			 * @brief Indicates to pass the test if the incoming value
			 * is greater than or equal to the stored value.
			 */
			FORGE_ENUM_DECL(FORGE_GEQUAL,   6)

			/**
			 * @brief Indicates to always pass the test.
			 */
			FORGE_ENUM_DECL(FORGE_ALWAYS,   7)

			MAX
		};
		
		/**
		 * @brief Primitive Topology masks specifing what kind of primitives to
		 * render.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/Primitive
		 */
		enum class PrimitiveTopologyMask : Byte
		{
			/**
			 * @brief Indicates to interpret each individual vertex as a point.
			 */
			FORGE_ENUM_DECL(FORGE_POINT,                    0)

			/**
			 * @brief Indicates to interpret each consecutive vertex pairs as a line.
			 */
			FORGE_ENUM_DECL(FORGE_LINE,                     1)

			/**
			 * @brief Indicates to interpret all adjacent vertices as a line,
			 * except that the first and last vertices are connected.
			 */
			FORGE_ENUM_DECL(FORGE_LINE_LOOP,                2)

			/**
			 * @brief Indicates to interpret all adjacent vertices as a line,
			 * except that the first and last vertices are not connected.
			 */
			FORGE_ENUM_DECL(FORGE_LINE_STRIP,               3)

			/**
			 * @brief Indicates to interpret each three consecutive vertices as a
			 * triangle.
			 */
			FORGE_ENUM_DECL(FORGE_TRIANGLE,                 4)

			/**
			 * @brief Indicates to fix the first vertex and interpret each two
			 * consecutive vertices with the first as a triangle.
			 */
			FORGE_ENUM_DECL(FORGE_TRIANGLE_FAN,             5)

			/**
			 * @brief Indicates to interpret each three consecutive vertices as
			 * triangle strips connected together.
			 */
			FORGE_ENUM_DECL(FORGE_TRIANGLE_STRIP,           6)
			
			/**
			 * @brief Indicates to interpret each consecutive vertex pairs as a line.
			 */
			FORGE_ENUM_DECL(FORGE_LINE_ADJACENCY,           7)
			
			/**
			 * @brief Indicates to interpret all adjacent vertices as a line,
			 * except that the first and last vertices are not connected.
			 */
			FORGE_ENUM_DECL(FORGE_LINE_STRIP_ADJACENCY,     8)

			/**
			 * @brief Indicates to interpret each three consecutive vertices as a
			 * triangle.
			 */
			FORGE_ENUM_DECL(FORGE_TRIANGLE_ADJACENCY,       9)

			/**
			 * @brief Indicates to interpret each three consecutive vertices as
			 * triangle strips connected together.
			 */
			FORGE_ENUM_DECL(FORGE_TRIANGLE_STRIP_ADJACENCY, 10)

			MAX
		};

		/**
		 * @brief Vertex element type masks specifing the base types of vertex buffer
		 * contents.
		 * 
		 * [GL]: https://www.khronos.org/opengl/wiki/OpenGL_Type
		 */
		enum VertexElementTypeMask : Byte
		{
			FORGE_ENUM_DECL(FORGE_BYTE1, 1)
			FORGE_ENUM_DECL(FORGE_BYTE2, 2)
			FORGE_ENUM_DECL(FORGE_BYTE3, 3)
			FORGE_ENUM_DECL(FORGE_BYTE4, 4)

			FORGE_ENUM_DECL(FORGE_UBYTE1, 5)
			FORGE_ENUM_DECL(FORGE_UBYTE2, 6)
			FORGE_ENUM_DECL(FORGE_UBYTE3, 7)
			FORGE_ENUM_DECL(FORGE_UBYTE4, 8)

			FORGE_ENUM_DECL(FORGE_SHORT1, 9)
			FORGE_ENUM_DECL(FORGE_SHORT2, 10)
			FORGE_ENUM_DECL(FORGE_SHORT3, 11)
			FORGE_ENUM_DECL(FORGE_SHORT4, 12)

			FORGE_ENUM_DECL(FORGE_USHORT1, 13)
			FORGE_ENUM_DECL(FORGE_USHORT2, 14)
			FORGE_ENUM_DECL(FORGE_USHORT3, 15)
			FORGE_ENUM_DECL(FORGE_USHORT4, 16)

			FORGE_ENUM_DECL(FORGE_INT1, 17)
			FORGE_ENUM_DECL(FORGE_INT2, 18)
			FORGE_ENUM_DECL(FORGE_INT3, 19)
			FORGE_ENUM_DECL(FORGE_INT4, 20)

			FORGE_ENUM_DECL(FORGE_UINT1, 21)
			FORGE_ENUM_DECL(FORGE_UINT2, 22)
			FORGE_ENUM_DECL(FORGE_UINT3, 23)
			FORGE_ENUM_DECL(FORGE_UINT4, 24)

			FORGE_ENUM_DECL(FORGE_FLOAT1, 25)
			FORGE_ENUM_DECL(FORGE_FLOAT2, 26)
			FORGE_ENUM_DECL(FORGE_FLOAT3, 27)
			FORGE_ENUM_DECL(FORGE_FLOAT4, 28)

			FORGE_ENUM_DECL(FORGE_DOUBLE1, 29)
			FORGE_ENUM_DECL(FORGE_DOUBLE2, 30)
			FORGE_ENUM_DECL(FORGE_DOUBLE3, 31)
			FORGE_ENUM_DECL(FORGE_DOUBLE4, 32)

			MAX
		};

		/**
		 * @brief Vertex element semantic masks specifing the meaning of vertex buffer
		 * contents.
		 */
		enum class VertexElementSemanticMask : Byte
		{
			/**
			 * @brief Indicates that the vertex is a position attribute, typically
			 * FORGE_FLOAT3.
			 */
			FORGE_ENUM_DECL(FORGE_POSITION,            0)

			/**
			 * @brief Indicates that the vertex is a blending weight attribute.
			 */
			FORGE_ENUM_DECL(FORGE_BLEND_WEIGHTS,       1)

			/**
			 * @brief Indicates that the vertex is a blending indices attribute.
			 */
			FORGE_ENUM_DECL(FORGE_BLEND_INDICES,       2)

			/**
			 * @brief Indicates that the vertex is a normal attribute, typically
			 * FORGE_FLOAT3.
			 */
			FORGE_ENUM_DECL(FORGE_NORMAL,              3)

			/**
			 * @brief Indicates that the vertex is a color attribute, typically
			 * FORGE_UBYTE4.
			 */
			FORGE_ENUM_DECL(FORGE_COLOR,               4)

			/**
			 * @brief Indicates that the vertex is a texture coordinate attribute,
			 * typically FORGE_FLOAT2.
			 */
			FORGE_ENUM_DECL(FORGE_TEXTURE_COORDINATES, 6)

			MAX
		};

		FORGE_FLAG_DECL(ClearFlags)

		FORGE_FLAG_DECL(LockModeFlags)
	}
}

#endif
