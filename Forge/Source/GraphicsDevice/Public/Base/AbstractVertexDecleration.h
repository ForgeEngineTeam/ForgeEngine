#ifndef ABSTRACT_VERTEX_DECLERATION_H
#define ABSTRACT_VERTEX_DECLERATION_H

#include <Core/Public/Types/Types.h>
#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Common/Common.h>
#include <Core/Public/Containers/Containers.h>

#include <GraphicsDevice/Public/GraphicsObject.h>
#include <GraphicsDevice/Public/VertexElement.h>
#include <GraphicsDevice/Public/Base/AbstractHardwareBuffer.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Abstract class defining the layout of a hardware vertex buffer.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API AbstractVertexDecleration : public GraphicsObject
		{
		protected:
			Containers::TDynamicArray<VertexElement> m_vertex_element_list;
			
		protected:
			Containers::TDynamicArray<TWeakPtr<AbstractHardwareBuffer>> m_vertex_binding_list;

		protected:
			Containers::TDynamicArray<Common::TPair<U32, TWeakPtr<AbstractHardwareBuffer>>> m_vertex_attribute_list;
			
		public:
			/**
			 * @brief Default constructor.
			 */
			AbstractVertexDecleration(Void) = default;

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~AbstractVertexDecleration(Void) = default;
	
		public:
			/**
			 * @brief Gets the size of the vertex defined by the vertex
			 * decleration in bytes.
			 * 
			 * @param source[in] The source of the vertex element.
			 * 
			 * @returns Size storing the size of the vertex defined by the vertex
			 * decleration in bytes.
			 */
			Size GetVertexSize(U16 source) const;

		public:
			/**
			 * @brief Gets the number of elements in the vertex decleration.
			 * 
			 * @returns Size storing the number of elements in the vertex
			 * decleration.
			 */
			Size GetVertexElementCount(Void) const;

		public:
			/**
			 * @brief Gets the number of vertex bindings in the vertex
			 * decleration.
			 *
			 * @returns Size storing the number of vertex bindings in the vertex
			 * decleration.
			 */
			Size GetVertexBindingCount(Void) const;

		public:
			/**
			 * @brief Gets the vertex elements in the vertex decleration.
			 * 
			 * This function provides read-only access to the returned elements.
			 * 
			 * @returns const TDynamicArray storing the vertex elements.
			 */
			Containers::ConstTDynamicArray<VertexElement> GetVertexElements(Void) const;

			/**
			 * @brief Gets the vertex elements in the vertex decleration using
			 * the specified source.
			 *
			 * This function provides read-only access to the returned elements.
			 *
			 * @param source[in] The source of the vertex element.
			 * 
			 * @returns const TDynamicArray storing the vertex elements.
			 */
			Containers::ConstTDynamicArray<VertexElement> GetVertexElements(U16 source) const;

		public:
			/**
			 * @brief Gets the vertex bindings in the vertex decleration.
			 *
			 * This function provides read-only access to the returned vertex
			 * bindings.
			 *
			 * @returns const TDynamicArray storing the vertex bindings.
			 */
			Containers::ConstTDynamicArray<TWeakPtr<AbstractHardwareBuffer>> GetVertexBindings(Void) const;

		public:
			/**
			 * @brief Adds a vertex element to the vertex decleration.
			 * 
			 * @param vertex_element[in] The vertex element to add.
			 */
			Void AddVertexElement(VertexElement vertex_element);

		public:
			/**
			 * @brief Adds a vertex binding to the vertex decleration.
			 *
			 * @param vertex_binding[in] The vertex binding to add.
			 */
			Void AddVertexBinding(TWeakPtr<AbstractHardwareBuffer> vertex_binding);

		public:
			/**
			 * @brief Removes a vertex element from the vertex decleration using
			 * the specified source.
			 *
			 * @param source[in] The source of the vertex element.
			 */
			Void RemoveVertexElement(U16 source);

			/**
		     * @brief Removes a vertex element from the vertex decleration using
		     * the specified semantic.
		     *
		     * @param semantic[in] The semantic of the vertex element.
		     */
			Void RemoveVertexElement(VertexElementSemanticMask semantic);

		public:
			/**
			 * @brief Removes a vertex element from the vertex decleration using
			 * the specified source.
			 *
			 * @param source[in] The source of the vertex element.
			 */
			Void RemoveVertexBinding(U16 source);

		public:
			/**
			 * @brief Modifies a vertex element stored inside the vertex decleration.
			 * 
			 * @param index[in]          The index of the vertex element inside the list.
			 * @param vertex_element[in] The new vertex element data.
			 */
			Void ModifyVertexElement(U16 index, VertexElement vertex_element);

		public:
			/**
			 * @brief Registers the vertex attributes using the associated vertex
			 * elements and bindings.
			 * 
			 * This function should be called after setting the vertex elements
			 * and binding of the vertex decleration
			 */
			Void RegisterVertexAttributes(Void);

		public:
			/**
			 * @brief Removes all vertex elements from the vertex decleration.
			 */
			Void Clear(Void);
		};

		FORGE_TYPEDEF_DECL(AbstractVertexDecleration)
	}
}
#endif // ABSTRACT_VERTEX_DECLERATION_H
