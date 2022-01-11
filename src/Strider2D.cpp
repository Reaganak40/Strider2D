#include <iostream>
#include <core.h>

int main(void)
{

    Core::Application app("Testing OpenGL Core", 600, 500);

    std::cout << "Application Name: " << app.getApplicationName() << std::endl;
    std::cout << "Window width:     " << app.getWindowWidth() << std::endl;
    std::cout << "Window height:    " << app.getWindowHeight() << std::endl;


    /* Loop until the user closes the window */
    while (app.isOpen())
    {
        /* GLClear Call */
        app.clearWindow();

        /* Draw Code Goes Here */


        /* GL Swap Buffers */
        app.endFrame();
    }

    return 0;
}