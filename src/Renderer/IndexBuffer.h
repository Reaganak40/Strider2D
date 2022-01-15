#ifndef S2D_INDEX_BUFFER_H
#define S2D_INDEX_BUFFER_H 1

#include <core.h>

namespace Strider2D
{
	namespace Renderer
	{
		class IndexBuffer
		{
		private:
			unsigned int m_RendererID;
			unsigned int m_Count;
		public:
			IndexBuffer(const unsigned int* data, unsigned int count);
			~IndexBuffer();

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetCount() const { return m_Count; }
		};
	}
}

#endif
