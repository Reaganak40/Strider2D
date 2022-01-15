#ifndef S2D_VERTEX_BUFFER_LAYOUT_H
#define S2D_VERTEX_BUFFER_LAYOUT_H 1

#include <core.h>
#include <vector>

namespace Strider2D
{
	namespace Renderer
	{
		struct VertexBufferElement
		{
			unsigned int type;
			unsigned int count;
			unsigned char normalized;

			static unsigned int GetSizeOfType(unsigned int type);
		};


		class VertexBufferLayout
		{
		private:
			std::vector<VertexBufferElement> m_Elements;
			unsigned int m_Stride;

		public:
			VertexBufferLayout()
				: m_Stride(0) {}


			template<typename T>
			void Push(unsigned int count)
			{
				static_assert(false);
			}

			template<>
			inline void Push<float>(unsigned int count)
			{
				m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
				m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;

			}

			template<>
			inline void Push<unsigned int>(unsigned int count)
			{
				m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
				m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;


			}

			template<>
			inline void Push<unsigned char>(unsigned int count)
			{
				m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
				m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;


			}

			inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
			inline unsigned int GetStride() const { return m_Stride; }
		};
	} 
}

#endif
