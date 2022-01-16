#include "Tests.h"

int TestQuadRotationTranslation(void)
{
    Strider2D::Window window("TestQuadRotationTranslation", 960, 580);

    Strider2D::Quad square(50, 50, 300, 200);

    square.SetRotationRule(S2D_MIDPOINT_ROTATION);
    square.SetColor(0.9f, 0.0f, 0.5f, 1.0f);
    float dr = -5.0f;
    float ds = 2.0f;
    //square.Rotate(45);
    //square.SetX(100);

    std::cout << square.c_str() << std::endl;

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);

        square.Rotate(dr);
        
        //square.SetX(square.GetX() + 2);
        square.SetWidth(square.GetWidth() + ds);
        //square.SetHeight(square.GetHeight() + ds);


        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}