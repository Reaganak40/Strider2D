#include "Tests.h"

int TestDrawQuad(void) 
{

    Strider2D::Window window("TestDrawQuad", 600, 500);

    Strider2D::Quad square(50, 50, 100, 100);
    square.SetColor(0.5f, 0.9f, 0.9f, 1.0f);
    square.SetWidth(150);
    square.SetHeight(150);
    square.SetX(window.getWindowWidth() / (float)2 - square.GetWidth()/2);
    square.SetY(window.getWindowHeight() / (float)2 - square.GetHeight() / 2);

    Strider2D::Quad square2(50, 50, 10, 10);
    square2.SetColor(0.4f, 0.1f, 0.0f, 1.0f);

    /*float gb_val = 0.9f;
    float d_val = 0.02f;

    float r_val = 0.5f;
    float dr_val = 0.01f;*/

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);
        window.DrawQuad(square2);

        /*
        // Change color values
        gb_val += d_val;
        if (gb_val >= 1)
            d_val = -d_val;
        if (gb_val <= 0.5)
            d_val = -d_val;

        r_val += dr_val;
        if (r_val >= 1)
            dr_val = -dr_val;
        if (r_val <= 0.5)
            dr_val = -dr_val;

        square.SetColor(r_val, gb_val, gb_val, 1.0f);*/


        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}
