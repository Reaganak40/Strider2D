#include <iostream>
#include <fstream>

#include "../src/Quad.h"
#include "../src/Renderer.h"

int main(void)
{
    Strider2D::Application app("Testing OpenGL Core", 600, 500);

    Strider2D::Quad shape;

    Strider2D::Renderer2D renderer;
    renderer.Push<Strider2D::Quad>(shape);

    /* Loop until the user closes the window */
    while (app.isOpen())
    {
        /* GLClear Call */
        app.clearWindow();

        /* Draw Code Goes Here */
        Strider2D::RunDrawQueue(app, renderer);

        /* GL Swap Buffers */
        app.endFrame();
    }

    Strider2D::ResetTextureMap();
    return 0;
}
