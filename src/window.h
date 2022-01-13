#ifndef S2D_WINDOW_H
#define S2D_WINDOW_H 1

#include <core.h>

#include "Shapes/Quad.h"

namespace Strider2D
{
	class Window : public Core::Application
	{
	public:
		// Call Core::Application Constructor
		Window(const std::string app_name = "Application", int window_width = 960, int window_height = 540)
			: Core::Application(app_name, window_width, window_height) {}

		// Runs a OpenGL draw call for a Quad object
		void DrawQuad(Quad quad);
	};
}

#endif