#include "Quad.h"

namespace Strider2D
{
	Quad::Quad(float width, float height, float x, float y)
	{
		m_width = width;
		m_height = height;

		SetX(x);
		SetY(y);

		SetColor(0.0f, 0.0f, 0.0f, 1.0f); // Pre-set all new quads to black

		SetTexture("NoTexture"); // No default texture (textureID = 0)
		SetTextureCoordinates();
	}
	
	// Return X position of Quad, starting at bottom left corner
	void Quad::SetX(float x)
	{
		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + m_width;
		m_vertices[2].Position[0] = x + m_width;
		m_vertices[3].Position[0] = x;

	}

	// Return Y position of Quad, starting at bottom left corner
	void Quad::SetY(float y)
	{
		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y;
		m_vertices[2].Position[1] = y + m_height;
		m_vertices[3].Position[1] = y + m_height;
	}

	// Set RGBA values for quad
	void Quad::SetColor(float red, float green, float blue, float alpha)
	{
		for (int i = 0; i < 4; i++)
		{
			m_vertices[i].Color[0] = red;
			m_vertices[i].Color[1] = green;
			m_vertices[i].Color[2] = blue;
			m_vertices[i].Color[3] = alpha;
		}
	}

	// Give the quad a texture with a texture file location (relative)
	void Quad::SetTexture(std::string texture_loc)
	{
		int id = GetTextureFromMap(texture_loc); // reads ID from the TextureMap.txt file
		
		for (int i = 0; i < 4; i++)
			m_vertices[i].TextureID = (float)id;
	}

	std::string Quad::c_str()
	{
		std::string info = "";

		info.append("<Quad Object: Vertices \n\t{\n");

		for (int i = 0; i < 4; i++)
		{
			info.append("\t\t");
			// Position values
			for (int g = 0; g < 2; g++) {
				info.append("m_vertices[");
				info.append(std::to_string(i));
				info.append("].Position[");
				info.append(std::to_string(g));
				info.append("] 	= ");
				float val = m_vertices[i].Position[g];
				info.append(std::to_string(val));
				info.append("\n\t\t");
			}

			// Color values
			for (int g = 0; g < 4; g++) {
				info.append("m_vertices[");
				info.append(std::to_string(i));
				info.append("].Color[");
				info.append(std::to_string(g));
				info.append("]		= ");
				float val = m_vertices[i].Color[g];
				info.append(std::to_string(val));
				info.append("\n\t\t");
			}

			// TextureCoords
			for (int g = 0; g < 2; g++) {
				info.append("m_vertices[");
				info.append(std::to_string(i));
				info.append("].TextureCoords[");
				info.append(std::to_string(g));
				info.append("]  = ");
				float val = m_vertices[i].TextureCoords[g];
				info.append(std::to_string(val));
				info.append("\n\t\t");
			}

			info.append("m_vertices[");
			info.append(std::to_string(i));
			info.append("].TextureID 	= ");
			float val = m_vertices[i].TextureID;
			info.append(std::to_string(val));
			info.append("\n\n");
		}
		info.append("\t}\n");

		float val = GetX();
		info.append("GetX() = ");
		info.append(std::to_string(val));
		info.append(", ");

		val = GetY();
		info.append("GetY() = ");
		info.append(std::to_string(val));
		info.append(", ");

		val = GetWidth();
		info.append("GetWidth() = ");
		info.append(std::to_string(val));
		info.append(", ");

		val = GetHeight();
		info.append("GetHeight() = ");
		info.append(std::to_string(val));
		info.append(" >\n");

		return info;
	}

	// Private function: Initialize mapping for texture (calls regardless of textureID)
	void Quad::SetTextureCoordinates()
	{
		m_vertices[0].TextureCoords[0] = 0.0f;
		m_vertices[0].TextureCoords[1] = 0.0f;

		m_vertices[1].TextureCoords[0] = 1.0f;
		m_vertices[1].TextureCoords[1] = 0.0f;

		m_vertices[2].TextureCoords[0] = 1.0f;
		m_vertices[2].TextureCoords[1] = 1.0f;

		m_vertices[3].TextureCoords[0] = 0.0f;
		m_vertices[3].TextureCoords[1] = 1.0f;
	}

}
