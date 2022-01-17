#include "pch.h"
#include "Tests.h"

int TestQuadTexture(void)
{
	Strider2D::Window window("TestQuadTexture", 960, 580);

	Strider2D::Quad shape(200, 200, 200, 300);
	shape.SetColor(0.6f, 0.1f, 0.0f, 1.0f);
	shape.SetTexture("tests/testTextures/Football photo.png");

	Strider2D::Quad shape2(300, 200, 500, 300);
	shape2.SetColor(0.1f, 0.6f, 0.0f, 1.0f);
	shape2.SetTexture("tests/testTextures/khajiit.png");

	Strider2D::Quad shape3(200, 200, 400, 50);
	shape3.SetColor(0.1f, 0.0f, 0.6f, 1.0f);


	while (window.isOpen())
	{
		window.clearWindow();

		window.DrawQuad(shape);
		window.DrawQuad(shape2);
		window.DrawQuad(shape3);

		window.endFrame();
	}
	Strider2D::ResetTextureMap();

	return 0;
}