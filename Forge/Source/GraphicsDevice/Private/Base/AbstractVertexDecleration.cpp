#include <GraphicsDevice/Public/Base/AbstractVertexDecleration.h>

namespace Forge {
	namespace Graphics
	{
		Size AbstractVertexDecleration::GetVertexSize(U16 source) const
		{
			Size result = 0;

			m_vertex_element_list.ForEach([&result, source](ConstVertexElementRef element) -> Void
				{
					if (element.GetSource() == source)
						result += element.GetSize();
				}
			);

			return result;
		}

		Size AbstractVertexDecleration::GetVertexElementCount(Void) const
		{
			return m_vertex_element_list.GetCount();
		}

		Size AbstractVertexDecleration::GetVertexBindingCount(Void) const
		{
			return m_vertex_binding_list.GetCount();
		}

		Containers::ConstTDynamicArray<VertexElement> AbstractVertexDecleration::GetVertexElements(Void) const
		{
			return m_vertex_element_list;
		}
		Containers::ConstTDynamicArray<VertexElement> AbstractVertexDecleration::GetVertexElements(U16 source) const
		{
			Containers::TDynamicArray<VertexElement> result;

			m_vertex_element_list.ForEach([&result, source](ConstVertexElementRef element) -> Void
				{
					if (element.GetSource() == source)
						result.PushBack(element);
				}
			);

			return result;
		}

		Containers::ConstTDynamicArray<TWeakPtr<AbstractHardwareBuffer>> AbstractVertexDecleration::GetVertexBindings(Void) const
		{
			return m_vertex_binding_list;
		}

		Void AbstractVertexDecleration::AddVertexElement(VertexElement vertex_element)
		{
			m_vertex_element_list.PushBack(vertex_element);
		}

		Void AbstractVertexDecleration::AddVertexBinding(TWeakPtr<AbstractHardwareBuffer> vertex_binding)
		{
			m_vertex_binding_list.PushBack(vertex_binding);
		}

		Void AbstractVertexDecleration::RemoveVertexElement(U16 source)
		{
			m_vertex_element_list.ForEach([this, source](VertexElementRef element) -> Void
				{
					if (element.GetSource() == source)
						m_vertex_element_list.Remove(element);
				}
			);
		}
		Void AbstractVertexDecleration::RemoveVertexElement(VertexElementSemanticMask semantic)
		{
			m_vertex_element_list.ForEach([this, semantic](VertexElementRef element) -> Void
				{
					if (element.GetSemantic() == semantic)
						m_vertex_element_list.Remove(element);
				}
			);
		}

		Void AbstractVertexDecleration::RemoveVertexBinding(U16 source)
		{
			m_vertex_binding_list.ForEach([this, source](TWeakPtrRef<AbstractHardwareBuffer> element) -> Void
				{
					if (!element.IsExpired() && element.Lock()->GetNativeHandle().m_id_num == source)
						m_vertex_binding_list.Remove(element);
				}
			);
		}

		Void AbstractVertexDecleration::ModifyVertexElement(U16 index, VertexElement vertex_element)
		{
			m_vertex_element_list[index] = vertex_element;
		}

		Void AbstractVertexDecleration::RegisterVertexAttributes(Void)
		{
			m_vertex_attribute_list.Clear();

			m_vertex_element_list.ForEach([this](VertexElementRef element) -> Void
				{
					TWeakPtr<AbstractHardwareBuffer> vertex_buffer;

					auto start_itr = m_vertex_binding_list.GetStartItr();
					auto end_itr = m_vertex_binding_list.GetEndItr();

					for (; start_itr != end_itr; start_itr++)
					{
						if (start_itr->Lock()->GetNativeHandle().m_id_num == element.GetSource())
						{
							vertex_buffer = *start_itr;
							break;
						}
					}

					m_vertex_attribute_list.PushBack({ element.GetIndex(), vertex_buffer });
				}
			);
		}

		Void AbstractVertexDecleration::Clear(Void)
		{
			m_vertex_element_list.Clear();
				
			m_vertex_binding_list.Clear();

			m_vertex_attribute_list.Clear();
		}
	}
}
