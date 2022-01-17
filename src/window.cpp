#include "pch.h"
#include "window.h"

namespace Strider2D
{
	void Window::DrawQuad(Quad quad)
	{
		
		m_renderer.DrawQuad(quad);

	}
	void Window::DrawTriangle(Triangle triangle)
	{
		m_renderer.DrawTriangle(triangle);
	}
}

