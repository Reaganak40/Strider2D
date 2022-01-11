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

#include "debugGL.h"
#include <iostream>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] {" << error << "} " << function <<
            " " << file << ": " << line << std::endl;
        return false;
    }
    return true;
}

void CoreError(const char* error)
{
    std::cout << "[Core Error]: " << error << std::endl;
}