// ==================================================================================================
//		Strider2D
//		Create by Reagan Kelley
//		Version 0.0.0 
//		
//		Last Revised: 1/11/2022
//
//		Strider2D is a basic rendering API that draws 2D graphics in an OpenGL Context window.
//  
// ==================================================================================================
#ifndef S2D_H
#define S2D_H 1

#include <map>
#include <string>

// Project Specific Includes
#include <core.h> // Base OpenGL Library

#include "window.h"					// OpenGL window context class
#include "Shapes/Quad.h"			// Class that allows user to draw quads to the screen
#include "Renderer/Renderer.h"		// Takes shapes and converts to data that OpenGL can read


namespace Strider2D
{

	void ResetTextureMap(void);
	int GetTextureFromMap(std::string texture_loc);
	
}

#endif