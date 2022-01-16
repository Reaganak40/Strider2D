#include "Tests.h"

int TestQuadRotationTranslation(void)
{
    Strider2D::Window window("TestQuadRotationTranslation", 960, 580);

    Strider2D::Quad square(100, 100, 300, 200);
    square.SetColor(0.9f, 0.0f, 0.5f, 1.0f);
    float dr = -5.0f;
    float ds = 0.5f;
   /* square.Rotate(45);
    square.SetX(100);*/

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);

        square.Rotate(dr);
        square.SetX(square.GetX() + 2);

        square.SetWidth(square.GetWidth() + ds);
        square.SetHeight(square.GetHeight() + ds);


        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}