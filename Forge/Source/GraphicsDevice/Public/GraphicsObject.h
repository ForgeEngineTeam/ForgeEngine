#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include <Core/Public/Common/Common.h>

namespace Forge {
	namespace Graphics
	{
		class GraphicsObject
		{
		public:
			union Handle
			{
			public:
				U32 m_id_num;
				VoidPtr m_id_ptr;

			public:
				Handle(Void)
					: m_id_num(0) {}
				Handle(U32 id_num)
					: m_id_num(id_num) {}
				Handle(VoidPtr id_ptr)
					: m_id_ptr(id_ptr) {}

			public:
				~Handle(Void)
				{
					m_id_num = 0;
				}
			
			public:
				operator Bool(Void)
				{
					return m_id_num != 0 ||
						   m_id_ptr != nullptr;
				}
				Bool operator !(Void)
				{
					return m_id_num == 0 || 
						   m_id_ptr == nullptr;
				}

			public:
				Bool operator ==(const Handle& other) const
				{
					return m_id_num == other.m_id_num || 
						   m_id_ptr == other.m_id_ptr;
				}
				Bool operator !=(const Handle& other) const
				{
					return m_id_num != other.m_id_num ||
						   m_id_ptr != other.m_id_ptr;
				}
			};

		protected:
			Handle m_handle;

		public:
			/**
			 * @brief Default constructor.
			 */
			GraphicsObject(Void) = default;

		public:
			/**
			 * @brief Default destructor.
			 */
			virtual ~GraphicsObject(Void) = default;

		public:
			/**
			 * @brief Equality operator.
			 */
			Bool operator ==(const GraphicsObject& other) const;

			/**
			 * @brief Inequality operator.
			 */
			Bool operator !=(const GraphicsObject& other) const;

		public:
			/**
			 * @brief Gets the native handle of the graphics object.
			 *
			 * @returns Handle storing the native handle of the hardware buffer.
			 */
			Handle GetNativeHandle(Void);
		};

		FORGE_TYPEDEF_DECL(GraphicsObject)

		FORGE_FORCE_INLINE Bool GraphicsObject::operator ==(const GraphicsObject& other) const
		{
			return m_handle == other.m_handle;
		}
		FORGE_FORCE_INLINE Bool GraphicsObject::operator !=(const GraphicsObject& other) const
		{
			return m_handle != other.m_handle;
		}

		FORGE_FORCE_INLINE GraphicsObject::Handle GraphicsObject::GetNativeHandle(Void)
		{
			return m_handle;
		}
	}
}

#endif
