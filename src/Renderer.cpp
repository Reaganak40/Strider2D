#include "Renderer.h"

namespace Strider2D
{
	void RunDrawQueue(Application& app, Renderer2D renderer)
	{
		
	}
	void Renderer2D::appendQueue(Vector* element_vertices, int count)
	{
		DrawQueueElement* dq_element = new DrawQueueElement;

		if (m_allocate_type == S2D_PUSH_DYNAMIC)
		{
			dq_element->e_vertices = element_vertices;
		}
		else if (m_allocate_type == S2D_PUSH_STATIC)
		{
			dq_element->e_vertices = new Vector[count];

			for (int i = 0; i < count; i++)
				CopyVector(element_vertices[i], dq_element->e_vertices[i]);
		}

		dq_element->e_num_vertices = count;
		m_drawQueue.push(dq_element);
	}
	void Renderer2D::SetAllocationType(int type_val)
	{
		if ((type_val == S2D_PUSH_DYNAMIC) || (type_val == S2D_PUSH_STATIC))
			m_allocate_type = type_val;
		else
			ASSERT(false);
	}
}