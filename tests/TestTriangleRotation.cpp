#include "pch.h"
#include "Tests.h"

int TestTriangleRotation(void)
{
	int TestTriangleRotation(void);	Strider2D::Window window("TestTriangleRotation", 960, 580);

	Strider2D::Triangle triangle(70, 100, 300, 200);

	Strider2D::Quad white_line(960, 10, 0, 200);
	Strider2D::Quad RedBox(10, 10, 295, 195);
	white_line.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	RedBox.SetColor(1.0f, 0.0f, 0.0f, 1.0f);

	triangle.SetColor(0.1f, 0.3f, 0.8f, 1.0f);
	float dr = 2.0f;
	triangle.MakeRight();
	//triangle.Rotate(-90);
	
	triangle.FlipAxisX();
	//triangle.FlipAxisY();

	
	while (window.isOpen())
	{
		window.clearWindow();

		triangle.Rotate(dr);
		triangle.ScaleH(1);
		triangle.ScaleW(1);

		
		window.DrawQuad(white_line);
		window.DrawTriangle(triangle);
		window.DrawQuad(RedBox);

		
		//triangle.Translate(1);

		
		

		window.endFrame();
	}


	return 0;
}