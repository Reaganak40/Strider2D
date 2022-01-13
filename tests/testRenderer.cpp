#include <iostream>
#include <fstream>

#include "../src/Strider2D.h"

int main(void)
{

    Strider2D::Window window("Testing OpenGL Core", 600, 500);

    Strider2D::Quad square(50, 50, 100, 100);

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        /* GLClear Call */
        window.clearWindow();

        /* Draw Code Goes Here */
        window.DrawQuad(square);

        /* GL Swap Buffers */
        window.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}
