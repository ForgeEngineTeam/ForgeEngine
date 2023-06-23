#ifndef VERTEX_ELEMENT_H
#define VERTEX_ELEMENT_H

#include <Core/Public/Common/Common.h>

#include <GraphicsDevice/Public/GraphicsTypes.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Represents the description of a single vertex attribute
		 * contained in a vertex buffer.
		 * 
		 * @author Karim Hisham.
		 */
		class VertexElement final
		{
		private:
			U16 m_index;
			U16 m_source;

		private:
			Size m_offset;

		private:
			Bool m_is_normalized;
			
		private:
			VertexElementTypeMask m_type;
			VertexElementSemanticMask m_semantic;

		public:
			/**
			 * @brief Gets the size of the vertex element type in bytes.
			 * 
			 * @param type[in] The type of the vertex element.
			 * 
			 * @returns Size storing the size of the vertex element in bytes.
			 */
			static Size GetTypeSize(VertexElementTypeMask type);

			/**
			 * @brief Gets the number of components of the vertex element type.
			 *
			 * @param type[in] The type of the vertex element.
			 *
			 * @returns Size storing the number of components of the vertex
			 * element.
			 */
			static Size GetTypeCount(VertexElementTypeMask type);

		public:
			/**
			 * @brief Default constructor.
			 */
			VertexElement(Void) = default;

			/**
			 * @brief Initializer constructor.
			 */
			VertexElement(U16 index, U16 source, Size offset,
				Bool is_nomralized, VertexElementTypeMask type, VertexElementSemanticMask semantic);
		
		public:
			/**
			 * @brief Default destructor.
			 */
			~VertexElement(Void) = default;

		public:
			/**
			 * @brief Equality operator.
			 */
			Bool operator ==(const VertexElement& other) const;

			/**
			 * @brief Inequality operator.
			 */
			Bool operator !=(const VertexElement& other) const;

		public:
			/**
			 * @brief Checks wether the vertex element value is normalized or not.
			 *
			 * @returns True if the vertex element value is normalized, otherwise
			 * false.
			 */
			Bool IsNormalized(Void) const;

		public:
			/**
			 * @brief Gets the index of the vertex element that is specified in
			 * the vertex shader.
			 * 
			 * @returns U16 storing the index of the vertex element.
			 */
			U16 GetIndex(Void) const;

			/**
			 * @brief Gets the source vertex buffer where the vertex element is
			 * read from.
			 * 
			 * @returns U16 storing the source vertex buffer.
			 */
			U16 GetSource(Void) const;

		public:
			/**
			 * Gets the size of the vertex element in bytes.
			 * 
			 * @returns Size storing the size of the vertex element in bytes.
			 */
			Size GetSize(Void) const;

			/**
			 * @brief Gets the offset where the vertex element starts.
			 * 
			 * @returns Size storing the offset where the vertex element starts.
			 */
			Size GetOffset(Void) const;
			
		public:
			/**
			 * @brief Gets the data format of the vertex element.
			 * 
			 * @returns VertexElementTypeMask storing the data format of the vertex
			 * element.
			 */
			VertexElementTypeMask GetType(Void) const;
			
			/**
			 * @brief Gets the meaning of the vertex element.
			 * 
			 * @returns VertexElementSemantic storing the meaning of the vertex
			 * element.
			 */
			VertexElementSemanticMask GetSemantic(Void) const;
		};

		FORGE_TYPEDEF_DECL(VertexElement)

		FORGE_FORCE_INLINE VertexElement::VertexElement(U16 index, U16 source, Size offset, 
			Bool is_nomralized, VertexElementTypeMask type, VertexElementSemanticMask semantic) 
			: m_index(index), m_source(source), m_offset(offset), m_is_normalized(is_nomralized), m_type(type), m_semantic(semantic) {}

		FORGE_FORCE_INLINE Size VertexElement::GetTypeSize(VertexElementTypeMask type)
		{
			switch (type)
			{
			case VertexElementTypeMask::FORGE_BYTE1:
			case VertexElementTypeMask::FORGE_UBYTE1:
				return sizeof(char);
			case VertexElementTypeMask::FORGE_BYTE2:
			case VertexElementTypeMask::FORGE_UBYTE2:
				return sizeof(char) * 2;
			case VertexElementTypeMask::FORGE_BYTE3:
			case VertexElementTypeMask::FORGE_UBYTE3:
				return sizeof(char) * 3;
			case VertexElementTypeMask::FORGE_BYTE4:
			case VertexElementTypeMask::FORGE_UBYTE4:
				return sizeof(char) * 4;
			case VertexElementTypeMask::FORGE_SHORT1:
			case VertexElementTypeMask::FORGE_USHORT1:
				return sizeof(short);
			case VertexElementTypeMask::FORGE_SHORT2:
			case VertexElementTypeMask::FORGE_USHORT2:
				return sizeof(short) * 2;
			case VertexElementTypeMask::FORGE_SHORT3:
			case VertexElementTypeMask::FORGE_USHORT3:
				return sizeof(short) * 3;
			case VertexElementTypeMask::FORGE_SHORT4:
			case VertexElementTypeMask::FORGE_USHORT4:
				return sizeof(short) * 4;
			case VertexElementTypeMask::FORGE_INT1:
			case VertexElementTypeMask::FORGE_UINT1:
				return sizeof(int);
			case VertexElementTypeMask::FORGE_INT2:
			case VertexElementTypeMask::FORGE_UINT2:
				return sizeof(int) * 2;
			case VertexElementTypeMask::FORGE_INT3:
			case VertexElementTypeMask::FORGE_UINT3:
				return sizeof(int) * 3;
			case VertexElementTypeMask::FORGE_INT4:
			case VertexElementTypeMask::FORGE_UINT4:
				return sizeof(int) * 4;
			case VertexElementTypeMask::FORGE_FLOAT1:
				return sizeof(float);
			case VertexElementTypeMask::FORGE_FLOAT2:
				return sizeof(float) * 2;
			case VertexElementTypeMask::FORGE_FLOAT3:
				return sizeof(float) * 3;
			case VertexElementTypeMask::FORGE_FLOAT4:
				return sizeof(float) * 4;
			case VertexElementTypeMask::FORGE_DOUBLE1:
				return sizeof(double);
			case VertexElementTypeMask::FORGE_DOUBLE2:
				return sizeof(double) * 2;
			case VertexElementTypeMask::FORGE_DOUBLE3:
				return sizeof(double) * 3;
			case VertexElementTypeMask::FORGE_DOUBLE4:
				return sizeof(double) * 4;
			}

			return 0;
		}
		FORGE_FORCE_INLINE Size VertexElement::GetTypeCount(VertexElementTypeMask type)
		{
			switch (type)
			{
			case VertexElementTypeMask::FORGE_BYTE1:
			case VertexElementTypeMask::FORGE_UBYTE1:
			case VertexElementTypeMask::FORGE_SHORT1:
			case VertexElementTypeMask::FORGE_USHORT1:
			case VertexElementTypeMask::FORGE_INT1:
			case VertexElementTypeMask::FORGE_UINT1:
			case VertexElementTypeMask::FORGE_FLOAT1:
			case VertexElementTypeMask::FORGE_DOUBLE1:
				return 1;
			case VertexElementTypeMask::FORGE_BYTE2:
			case VertexElementTypeMask::FORGE_UBYTE2:
			case VertexElementTypeMask::FORGE_SHORT2:
			case VertexElementTypeMask::FORGE_USHORT2:
			case VertexElementTypeMask::FORGE_INT2:
			case VertexElementTypeMask::FORGE_UINT2:
			case VertexElementTypeMask::FORGE_FLOAT2:
			case VertexElementTypeMask::FORGE_DOUBLE2:
				return 2;
			case VertexElementTypeMask::FORGE_BYTE3:
			case VertexElementTypeMask::FORGE_UBYTE3:
			case VertexElementTypeMask::FORGE_SHORT3:
			case VertexElementTypeMask::FORGE_USHORT3:
			case VertexElementTypeMask::FORGE_INT3:
			case VertexElementTypeMask::FORGE_UINT3:
			case VertexElementTypeMask::FORGE_FLOAT3:
			case VertexElementTypeMask::FORGE_DOUBLE3:
				return 3;
			case VertexElementTypeMask::FORGE_BYTE4:
			case VertexElementTypeMask::FORGE_UBYTE4:
			case VertexElementTypeMask::FORGE_SHORT4:
			case VertexElementTypeMask::FORGE_USHORT4:
			case VertexElementTypeMask::FORGE_INT4:
			case VertexElementTypeMask::FORGE_UINT4:
			case VertexElementTypeMask::FORGE_FLOAT4:
			case VertexElementTypeMask::FORGE_DOUBLE4:
				return 4;
			}

			return 0;
		}

		FORGE_FORCE_INLINE Bool VertexElement::operator ==(const VertexElement& other) const
		{
			if (m_index    != other.m_index  ||
				m_source   != other.m_source ||
				m_offset   != other.m_offset ||
				m_type     != other.m_type   ||
				m_semantic != other.m_semantic)
				return false;
			else
				return true;
		}
		FORGE_FORCE_INLINE Bool VertexElement::operator !=(const VertexElement& other) const
		{
			if (m_index    != other.m_index  ||
				m_source   != other.m_source ||
				m_offset   != other.m_offset ||
				m_type     != other.m_type   ||
				m_semantic != other.m_semantic)
				return true;
			else
				return false;
		}

		FORGE_FORCE_INLINE Bool VertexElement::IsNormalized(Void) const
		{
			return m_is_normalized;
		}

		FORGE_FORCE_INLINE U16 VertexElement::GetIndex(Void) const 
		{ 
			return m_index; 
		}
		FORGE_FORCE_INLINE U16 VertexElement::GetSource(Void) const 
		{ 
			return m_source; 
		}

		FORGE_FORCE_INLINE Size VertexElement::GetSize(Void) const 
		{ 
			return GetTypeSize(m_type); 
		}
		FORGE_FORCE_INLINE Size VertexElement::GetOffset(Void) const 
		{ 
			return m_offset; 
		}

		FORGE_FORCE_INLINE VertexElementTypeMask VertexElement::GetType(Void) const
		{ 
			return m_type; 
		}
		FORGE_FORCE_INLINE VertexElementSemanticMask VertexElement::GetSemantic(Void) const
		{ 
			return m_semantic; 
		}
	}
}

#endif // VERTEX_ELEMENT_H
