#ifndef S2D_VERTEX_ARRAY_H

#define S2D_VERTEX_ARRAY_H

#include "vertexBuffer.h"
#include "VertexBufferLayout.h"


namespace Strider2D
{
	namespace Renderer
	{
		class VertexArray
		{
		private:
			unsigned int m_RendererID;
		public:
			VertexArray();
			~VertexArray();

			void Bind() const;
			void Unbind() const;

			void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
		};
	}
}

#endif // !S2D_VERTEX_ARRAY_H

