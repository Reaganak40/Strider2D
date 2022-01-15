#ifndef S2D_QUAD 
#define S2D_QUAD 1

#include "Vector.h"
#include "../Renderer/Texture.h"

#include <string>

namespace Strider2D
{
	class Quad
	{
	private:
		Vector m_vertices[4];
		float m_width;
		float m_height;

		void SetTextureCoordinates();

	public:
		Quad(float width = 50, float height = 50, float x = 0, float y = 0);
		
		// Change the x-length of the quad
		void SetWidth(float width);

		// Change the y-length of the quad
		void SetHeight(float height);

		// Set X position of Quad, starting at bottom left corner
		void SetX(float x);

		// Ser Y position of Quad, starting at bottom left corner
		void SetY(float y);

		// Set RGBA values for quad
		void SetColor(float red, float green, float blue, float alpha);
		
		// Give the quad a texture with a texture file location (relative)
		void SetTexture(std::string texture_loc);

		// Get length of bottom left vertex to bottom right vertex
		inline float GetWidth()	 { return m_width;  }
		
		// Get length of upper left vertex to bottom left vertex
		inline float GetHeight() { return m_height; }

		// Get X position of Quad, starting at bottom left corner
		inline float GetX()		 { return m_vertices[0].Position[0]; }

		// Get Y position of Quad, starting at bottom left corner
		inline float GetY()		 { return m_vertices[0].Position[1]; }

		// Returns the list of vectors for this Quad (will return 4 vectors)
		inline Vector* GetVertices() { return m_vertices; }

		// Print Object Current Attributes
		std::string c_str();
	};
}

#endif