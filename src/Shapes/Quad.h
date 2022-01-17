#ifndef S2D_QUAD 
#define S2D_QUAD 1

#include "Vector.h"
#include "../Renderer/Texture.h"


namespace Strider2D
{
	class Quad
	{
	private:
		Vector m_vertices[4];
		float m_width;
		float m_height;

		int m_rotation_rule;
		float m_current_rotation;

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

		// Determines the center point where the shape rotates
		void SetRotationRule(int rotation_rule);

		// Get the current rotation of the quad in degrees
		float GetRotation(void) { return m_current_rotation; }

		// Set the rotation of the quad to a degree
		void SetRotation(float rotation_degrees);

		// Rotate the quad by d_degrees
		void Rotate(float d_degrees);

		// Move the object from its current position by the specified difference
		void Translate(float dx = 0, float dy = 0);

		// Change the width of the quad by a number dw
		void ScaleW(float dw);

		// Change the height of the quad by a number dh
		void ScaleH(float dw);


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