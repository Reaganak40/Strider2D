// ==================================================================================================
//		OpenGL-Core
//		Create by Reagan Kelley
//		Version 1.0.0 
//		
//		Last Revised: 1/7/2022
//
//		OpenGL-Core is a bare bones implementation of OpenGL providing ease of use
//		to start new openGL applications quickly without any direct OpenGL initialization.
// 
//		Core::Application
//			- A class that can be run in main to initialize a new OpenGL context
//			- Use the loop setup in core.cpp to change window output by frame
// 
//		Other Core utilities:
//			- ASSERT - function for error handling
//			- GLCall - function wrapper for easy OpenGL debugging
//			- ApplicationBreak - Ends application adbruptly if error occurs within Core::Application
//  
// ==================================================================================================

#include "core.h"

// EXAMPLE OF A CORE::APPLICATION 

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