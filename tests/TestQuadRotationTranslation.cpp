#include "Tests.h"

int TestQuadRotationTranslation(void)
{
    Strider2D::Window window("TestQuadRotationTranslation", 960, 580);

    Strider2D::Quad square(100, 100, 0, 200);

    square.SetRotationRule(S2D_MIDPOINT_ROTATION);
    square.SetColor(0.9f, 0.0f, 0.5f, 1.0f);

    square.SetTexture("tests/testTextures/Football photo.png");

    
    float dr = -5.0f;
    float ds = 2.0f;
    //square.Rotate(40);
    //square.SetX(100);
    std::cout << square.c_str() << std::endl;

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);

       // square.Rotate(dr);
        
        square.Translate(8, 0);

        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}