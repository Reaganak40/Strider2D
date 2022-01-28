#ifndef S2D_WINDOW_H
#define S2D_WINDOW_H 1

#include <core.h>

#include "Renderer/Renderer.h"
#include "Shapes/Quad.h"

namespace Strider2D
{
	class Window : public Core::Application
	{

	private:
		Renderer::Renderer2D m_renderer;
	public:

		// Call Core::Application Constructor
		Window(const std::string app_name = "Application", int window_width = 960, int window_height = 540)
			: Core::Application(app_name, window_width, window_height),
			m_renderer(window_width, window_height) 
		{ GLCall(glClearColor(0.1f, 0.1f, 0.1f, 1.0f)); /* Make Background Dark gray*/ }

		// Runs a OpenGL draw call for a Quad object
		void DrawQuad(Quad quad);

		// Runs a OpenGL draw call for a Triangle object
		void DrawTriangle(Triangle triangle);

		template<typename T>
		void PushToDrawQueue(T& draw_element, int queue_index = 0)
		{
			static_assert(false);
		}

		template<>
		void PushToDrawQueue<Quad>(Quad& draw_element, int queue_index)
		{
			m_renderer.Push<Quad>(draw_element, queue_index);
		}

		template<>
		void PushToDrawQueue<Triangle>(Triangle& draw_element, int queue_index)
		{
			m_renderer.Push<Triangle>(draw_element, queue_index);
		}


	};
}

#endif