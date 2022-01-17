#include "pch.h"
#include "Tests.h"

int TestQuadRotationTranslation(void)
{
    Strider2D::Window window("TestQuadRotationTranslation", 960, 580);

    Strider2D::Quad square(100, 25, 100, 200);

    //square.SetRotationRule(S2D_MIDPOINT_ROTATION);
    square.SetColor(0.9f, 0.0f, 0.5f, 1.0f);

    float dr = -1.0f;

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);
        

        square.Rotate(dr);
        square.Translate(3, 0);

        /*square.ScaleW(2);
        square.ScaleH(2);*/

        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}