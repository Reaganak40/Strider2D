#include "pch.h"
#include "Tests.h"

int TestBatchRenderer(void)
{
    Strider2D::Window window("TestBatchRenderer", 600, 500);

    Strider2D::Quad square(50, 50, 100, 100);
    square.SetColor(0.8f, 1.0f, 0.0f, 1.0f);
    square.SetWidth(200);
    square.SetHeight(200);

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        
        window.DrawQuad(square);

        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}