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

#pragma once
#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));

#define ApplicationBreak(x) CoreError(x);\
    ASSERT(false);

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
void CoreError(const char* error);