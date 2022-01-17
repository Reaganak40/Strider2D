#include "pch.h"
#include "Tests.h"

int TestTriangleRotation(void)
{
	int TestTriangleRotation(void);	Strider2D::Window window("TestTriangleRotation", 960, 580);

	Strider2D::Triangle triangle(50, 70, 175, 200);

	Strider2D::Quad white_line(960, 10, 0, 200);
	white_line.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	triangle.SetColor(0.1f, 0.3f, 0.8f, 1.0f);
	//triangle.MakeIsosceles();
	float dr = -1.0f;


	while (window.isOpen())
	{
		window.clearWindow();

		window.DrawQuad(white_line);
		window.DrawTriangle(triangle);
		triangle.Rotate(dr);
		triangle.Translate(1);

		window.endFrame();
	}


	return 0;
}