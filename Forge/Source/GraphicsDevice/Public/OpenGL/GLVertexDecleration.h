#ifndef GL_VERTEX_DECLERATION_H
#define GL_VERTEX_DECLERATION_H

#include <GraphicsDevice/Public/OpenGL/GL/gl.h>
#include <GraphicsDevice/Public/Base/AbstractVertexDecleration.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief Vertex decleration implementation for OpenGL.
		 *
		 * @author Karim Hisham.
		 */
		class FORGE_API GLVertexDecleration final : public AbstractVertexDecleration
		{
		public:
			/**
			 * @brief Defaul constructor.
			 */
			GLVertexDecleration(Void);

		public:
			/**
			 * @brief Defaul destructor.
			 */
			~GLVertexDecleration(Void) = default;
		};

		FORGE_TYPEDEF_DECL(GLVertexDecleration)

		FORGE_FORCE_INLINE GLVertexDecleration::GLVertexDecleration(Void)
		{
			glGenVertexArrays(1, &m_handle.m_id_num);
		}
	}
}

#endif
