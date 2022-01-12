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

static int* global_int = new int;

namespace Strider2D
{
	struct Vector
	{
		float Position[2];
		float Color[4];
		float TextureCoords[2];
		float TextureID;
	};

	void CopyVector(const Vector src, Vector& dst);
	void ResetTextureMap(void);
	int GetTextureFromMap(std::string texture_loc);

}

#endif