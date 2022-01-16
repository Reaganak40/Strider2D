#include "Quad.h"

namespace Strider2D
{
	Quad::Quad(float width, float height, float x, float y)
	{
		m_rotation_rule = S2D_POINT_ROTATION; //rotate on vertex 0
		m_current_rotation = 0.0f;

		m_width = width;
		m_height = height;

		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + width;
		m_vertices[2].Position[0] = x + width;
		m_vertices[3].Position[0] = x;
		
		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y + height;
		m_vertices[2].Position[1] = y + height;
		m_vertices[3].Position[1] = y;

		SetColor(0.0f, 0.0f, 0.0f, 1.0f); // Pre-set all new quads to black

		SetTexture("NoTexture"); // No default texture (textureID = 0)
		SetTextureCoordinates();
	}

	void Quad::SetWidth(float width)
	{
		m_width = width;
		
		// this wizardry will reset the vertices with the height
		Rotate(0);

	}

	void Quad::SetHeight(float height)
	{
		m_height = height;
		
		// this wizardry will reset the vertices with the height
		Rotate(0);

	}
	
	// Set X position of Quad, starting at bottom left corner
	void Quad::SetX(float x)
	{
		// we must calculate each individually due to rotations
		float dx1 = m_vertices[1].Position[0] - m_vertices[0].Position[0];
		float dx2 = m_vertices[2].Position[0] - m_vertices[0].Position[0];
		float dx3 = m_vertices[3].Position[0] - m_vertices[0].Position[0];


		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + dx1;
		m_vertices[2].Position[0] = x + dx2;
		m_vertices[3].Position[0] = x + dx3;

	}

	// Set Y position of Quad, starting at bottom left corner
	void Quad::SetY(float y)
	{
		// we must calculate each individually due to rotations
		float dy1 = m_vertices[1].Position[1] - m_vertices[0].Position[1];
		float dy2 = m_vertices[2].Position[1] - m_vertices[0].Position[1];
		float dy3 = m_vertices[3].Position[1] - m_vertices[0].Position[1];

		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y + dy1;
		m_vertices[2].Position[1] = y + dy2;
		m_vertices[3].Position[1] = y + dy3;
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

	void Quad::SetRotationRule(int rotation_rule)
	{
		if ((rotation_rule == S2D_ORIGIN_ROTATION) || (rotation_rule == S2D_POINT_ROTATION))
			m_rotation_rule = rotation_rule;
		else
			ASSERT(false);
	}

	void Quad::Rotate(float d_degrees)
	{
		if (m_rotation_rule == S2D_POINT_ROTATION)
		{
			float new_rotation = m_current_rotation + d_degrees;
			new_rotation = fmod(new_rotation, 360); //keep rotation relative

			double rad_rotation = new_rotation * (S2D_PI / 180);
			double vec2_dr = 45 * (S2D_PI / 180);
			double vec3_dr = 90 * (S2D_PI / 180);

			m_vertices[1].Position[0] = m_vertices[0].Position[0] + (cos(rad_rotation) * m_width);
			m_vertices[1].Position[1] = m_vertices[0].Position[1] + (sin(rad_rotation) * m_height);

			float hyp = sqrt(pow(m_width, 2) + pow(m_height, 2));
			m_vertices[2].Position[0] = m_vertices[0].Position[0] + (cos(rad_rotation + vec2_dr) * hyp);
			m_vertices[2].Position[1] = m_vertices[0].Position[1] + (sin(rad_rotation + vec2_dr) * hyp);

			m_vertices[3].Position[0] = m_vertices[0].Position[0] + (cos(rad_rotation + vec3_dr) * m_width);
			m_vertices[3].Position[1] = m_vertices[0].Position[1] + (sin(rad_rotation + vec3_dr) * m_height);

			m_current_rotation = new_rotation;
		}
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
