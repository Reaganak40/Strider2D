#include "pch.h"
#include "Tests.h"

int TestTriangleRotation(void)
{
	int TestTriangleRotation(void);	Strider2D::Window window("TestTriangleRotation", 960, 580);

	Strider2D::Triangle triangle(70, 100, 100, 300);

	Strider2D::Quad white_line(960, 10, 0, 200);
	Strider2D::Quad RedBox(10, 10, 295, 195);
	white_line.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	RedBox.SetColor(1.0f, 0.0f, 0.0f, 1.0f);

	triangle.SetColor(0.1f, 0.3f, 0.8f, 1.0f);
	float dr = 2.0f;

	triangle.MakeIsosceles();
	triangle.Rotate(-90);

	float dx = 2;
	float dy = 5;
	
	while (window.isOpen())
	{
		window.clearWindow();

		triangle.Translate(dx, dy);
		
		triangle.Rotate(dy * 0.3);

		if (triangle.GetY() > 500 || triangle.GetY() < 120)
			dy = -dy;
		
		window.DrawQuad(white_line);
		window.DrawTriangle(triangle);
		window.DrawQuad(RedBox);

		
		//triangle.Translate(1);

		
		

		window.endFrame();
	}


	return 0;
}