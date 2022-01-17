#ifndef S2D_TRIANGLE 
#define S2D_TRIANGLE 1

#include "Vector.h"
#include "../Renderer/Texture.h"

namespace Strider2D
{
	class Triangle
	{
	private:
		Vector m_vertices[3];
		float m_width;
		float m_height;

		int m_rotation_rule;
		float m_vertex_angle;
		float m_current_rotation;

		float m_vec2_dr;
		float m_vec2_hyp;

		bool m_flipped_x;
		bool m_flipped_y;


		void SetTextureCoordinates();

	public:
		Triangle(float width = 50, float height = 50, float x = 0, float y = 0);

		// Moves the nose of the triangle so that it matches the given angle (in degrees)
		void SetVertexAngle(float degrees);

		// Change the x-length of the Triangle
		void SetWidth(float width);

		// Change the y-length of the Triangle
		void SetHeight(float height);

		// Make shape a RIGHT triangle
		void MakeRight(void);

		// Make shape an ISOSCELES triangle
		void MakeIsosceles(void);

		// Set X position of Triangle, starting at bottom left corner
		void SetX(float x);

		// Set Y position of Triangle, starting at bottom left corner
		void SetY(float y);

		// Flips the triangle on the y-axis
		void FlipAxisY(void);

		// Flips the triangle on the x-axis
		void FlipAxisX(void);

		// Set RGBA values for Triangle
		void SetColor(float red, float green, float blue, float alpha);

		// Give the triangle a texture with a texture file location (relative)
		void SetTexture(std::string texture_loc);

		// Determines the center point where the shape rotates
		void SetRotationRule(int rotation_rule);

		// Get the current rotation of the Triangle in degrees
		float GetRotation(void) { return m_current_rotation; }

		// Set the rotation of the Triangle to a degree
		void SetRotation(float rotation_degrees);

		// Rotate the Triangle by d_degrees
		void Rotate(float d_degrees);

		// Move the object from its current position by the specified difference
		void Translate(float dx = 0, float dy = 0);

		// Change the width of the Triangle by a number dw
		void ScaleW(float dw);

		// Change the height of the Triangle by a number dh
		void ScaleH(float dw);


		// Get length of bottom left vertex to bottom right vertex
		inline float GetWidth() { return m_width; }

		// Get length of upper left vertex to bottom left vertex
		inline float GetHeight() { return m_height; }

		// Get X position of Triangle, starting at bottom left corner
		inline float GetX() { return m_vertices[0].Position[0]; }

		// Get Y position of Triangle, starting at bottom left corner
		inline float GetY() { return m_vertices[0].Position[1]; }

		// Returns the list of vectors for this Triangle (will return 4 vectors)
		inline Vector* GetVertices() { return m_vertices; }

		// Print Object Current Attributes
		std::string c_str();
	};
}


#endif
