#include "Strider2D.h"
#include "Quad.h"

#include <queue>
#define S2D_PUSH_STATIC 0
#define S2D_PUSH_DYNAMIC 1


namespace Strider2D
{
	class Renderer2D;

	class Application : public Core::Application
	{
	public:
		// Call Core::Application Constructor
		Application(const std::string app_name = "Application", int window_width = 960, int window_height = 540)
			: Core::Application(app_name, window_width, window_height) {}

		friend void RunDrawQueue(Application&, Renderer2D);
	};

	class Renderer2D
	{
	private:

		struct DrawQueueElement
		{
			Vector* e_vertices;
			int e_num_vertices;
		};
		std::queue<DrawQueueElement*> m_drawQueue;

		int m_allocate_type;

		/*	VertexArray*	m_va;
			VertexBuffer*	m_vb;
			IndexBuffer*	m_ib;
			Shader*			m_shader;*/

		// Takes a list of Vectors gathered by push and given the count, creates a new DrawQueueElment
		void appendQueue(Vector* element_vertices, int count);

	public:

		Renderer2D() : m_allocate_type(S2D_PUSH_STATIC) {}

		void SetAllocationType(int type_val);
		void setPushDynamic() { m_allocate_type = S2D_PUSH_DYNAMIC; }
		void setPushStatic() { m_allocate_type = S2D_PUSH_DYNAMIC; }

		friend void RunDrawQueue(Application&, Renderer2D);

		template<typename T>
		void Push(T& draw_element)
		{
			static_assert(false);
		}

		template<>
		void Push<Quad>(Quad& draw_element)
		{
			appendQueue(draw_element.GetVertices(), 4);
		}

	};
}