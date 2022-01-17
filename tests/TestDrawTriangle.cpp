#include "pch.h"
#include "Tests.h"

int TestDrawTriangle(void)
{

    Strider2D::Window window("TestDrawTriangle", 600, 500);

    Strider2D::Quad white_line(600, 10, 0, 350);
    white_line.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

    Strider2D::Triangle triangle(150, 150, 100, 50);
    triangle.SetColor(1.0f, 0.3f, 0.0f, 1.0f);

    triangle.SetX(200);
    triangle.SetY(200);

    float dw = 2;
    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        triangle.ScaleW(dw);
        triangle.ScaleH(dw);
        triangle.MakeIsosceles();
        
        window.DrawQuad(white_line);
        window.DrawTriangle(triangle);
       

        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}