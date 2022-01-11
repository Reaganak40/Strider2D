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

// Use static libs
#define GLEW_STATIC 0

// Base C/C++ Libs
#include <iostream>
#include <string>

// OpenGL Libs
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// OpenGL-Core Files
#include "debugGL.h"

namespace Core
{
	class Application
	{
	public:
		Application(const std::string app_name = "Application", int window_width = 960, int window_height = 540)
		{
			m_application_name = app_name;
			m_window_width = window_width;
			m_window_height = window_height;

			init_application(app_name.c_str(), window_width, window_height);
		}
		~Application() { glfwTerminate(); }

		inline bool isOpen(void) { return (!glfwWindowShouldClose(m_window)); }
		inline void clearWindow(void) { GLCall(glClear(GL_COLOR_BUFFER_BIT)); }
		inline void endFrame(void)
		{
			/* Swap front and back buffers */
			glfwSwapBuffers(m_window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		inline std::string getApplicationName(void) { return m_application_name; }
		inline int getWindowWidth(void) { return m_window_width; }
		inline int getWindowHeight(void) { return m_window_height; }

	
	private:

		inline void init_application(const char* app_name, int window_length, int window_height)
		{
			/* Initialize the library */
			if (!glfwInit())
			{
				ApplicationBreak("glfw failed to init");
			}

			/* Create a windowed mode window and its OpenGL context */
			m_window = glfwCreateWindow(window_length, window_height, app_name, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				ApplicationBreak("failed to create window");

			}

			/* Make the window's context current */
			glfwMakeContextCurrent(m_window);
			glfwSwapInterval(1);

			if (glewInit() != GLEW_OK)
			{
				ApplicationBreak("glew failed to init");
			}

			/* Make the window's context current */
			glfwMakeContextCurrent(m_window);
		}

		// OpenGL Context Variables
		GLFWwindow* m_window;
		std::string m_application_name;
		int			m_window_width;
		int			m_window_height;

	};
}