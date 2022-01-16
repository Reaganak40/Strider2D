#include "Quad.h"

namespace Strider2D
{
	Quad::Quad(float width, float height, float x, float y)
	{
		m_rotation_rule = S2D_VERTEX_ROTATION; //rotate on vertex 0
		m_current_rotation = 0.0f;

		m_width = width;
		m_height = height;

		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + width;
		m_vertices[2].Position[0] = x + width;
		m_vertices[3].Position[0] = x;
		
		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y;
		m_vertices[2].Position[1] = y + height;
		m_vertices[3].Position[1] = y + height;

		SetColor(0.0f, 0.0f, 0.0f, 1.0f); // Pre-set all new quads to black

		SetTexture("NoTexture"); // No default texture (textureID = 0)
		SetTextureCoordinates();
	}

	void Quad::SetWidth(float width)
	{
		if (width < 0.01f)
			width = 0.01f;

		m_width = width;
		
		// this wizardry will reset the vertices with the height
		if(m_rotation_rule = S2D_VERTEX_ROTATION)
			Rotate(0);
		else
		{
			int i = 0;
			int g = 1;

			REASSIGN_POSITIONS:
			{
				float dy = m_vertices[g].Position[1] - m_vertices[i].Position[1];
				float dx = m_vertices[g].Position[0] - m_vertices[i].Position[0];

				float hyp = (float)sqrt(pow(dx, 2) + pow(dy, 2));
				float midpoint = hyp / 2;
				float theta = atan(abs(dy) / abs(dx));

				//std::cout << theta << std::endl;

				float midx = midpoint * cos(theta);
				float midy = midpoint * sin(theta);
			
				float f = m_width / 2;
				float xx = f * cos(theta);
				float yy = f * sin(theta);


				m_vertices[i].Position[0] = m_vertices[i].Position[0] + midx - xx;
				m_vertices[i].Position[1] = m_vertices[i].Position[1] + midy - yy;

				m_vertices[g].Position[0] = m_vertices[g].Position[0] - midx + xx;
				m_vertices[g].Position[1] = m_vertices[g].Position[1] - midy + yy;

				if (i == 0)
				{
					i = 3;
					g = 2;
					goto REASSIGN_POSITIONS;
				}
			}

		}

	}

	void Quad::SetHeight(float height)
	{
		if (height < 0.01f)
			height = 0.01f;

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
		if ((rotation_rule == S2D_VERTEX_ROTATION) || (rotation_rule == S2D_MIDPOINT_ROTATION))
			m_rotation_rule = rotation_rule;
		else
			ASSERT(false);
	}

	void Quad::Rotate(float d_degrees)
	{

		
		float new_rotation = m_current_rotation + d_degrees;
		new_rotation = (float)fmod((double)new_rotation, 360); //keep rotation relative
		double rad_rotation = new_rotation * (S2D_PI / 180);
		m_current_rotation = new_rotation;
		
		if (m_rotation_rule == S2D_VERTEX_ROTATION)
		{


			double vec2_dr = atan(m_height / m_width);
			double vec3_dr = 90 * (S2D_PI / 180);

			m_vertices[1].Position[0] = m_vertices[0].Position[0] + (float)(cos(rad_rotation) * m_width);
			m_vertices[1].Position[1] = m_vertices[0].Position[1] + (float)(sin(rad_rotation) * m_width);

			double hyp = sqrt(pow(m_width, 2) + pow(m_height, 2));
			m_vertices[2].Position[0] = m_vertices[0].Position[0] + (float)(cos(rad_rotation + vec2_dr) * hyp);
			m_vertices[2].Position[1] = m_vertices[0].Position[1] + (float)(sin(rad_rotation + vec2_dr) * hyp);

			m_vertices[3].Position[0] = m_vertices[0].Position[0] + (float)(cos(rad_rotation + vec3_dr) * m_height);
			m_vertices[3].Position[1] = m_vertices[0].Position[1] + (float)(sin(rad_rotation + vec3_dr) * m_height);

		}
		else if (m_rotation_rule == S2D_MIDPOINT_ROTATION)
		{

			double rel_rotation = d_degrees * (S2D_PI / 180);
			
			// 1. Find the midpoint
			// find smallest x-value
			float smallest_x = m_vertices[0].Position[0];
			for (int i = 1; i < 4; i++)
				if (m_vertices[i].Position[0] < smallest_x)
					smallest_x = m_vertices[i].Position[0];
			// find smallest y-value
			float smallest_y = m_vertices[0].Position[1];
			for (int i = 1; i < 4; i++)
				if (m_vertices[i].Position[1] < smallest_y)
					smallest_y = m_vertices[i].Position[1];

			// find largest x-value
			float largest_x = m_vertices[0].Position[0];
			for (int i = 1; i < 4; i++)
				if (m_vertices[i].Position[0] > largest_x)
					largest_x = m_vertices[i].Position[0];

			// find largest y-value
			float largest_y = m_vertices[0].Position[1];
			for (int i = 1; i < 4; i++)
				if (m_vertices[i].Position[1] > largest_y)
					largest_y = m_vertices[i].Position[1];

			float midpoint_x = (smallest_x + largest_x) / 2;
			float midpoint_y = (smallest_y + largest_y) / 2;


			for (int i = 0; i < 4; i++)
			{
				float last_x = m_vertices[i].Position[0] - midpoint_x;
				float last_y = m_vertices[i].Position[1] - midpoint_y;

				m_vertices[i].Position[0] = (last_x * (float)cos(rel_rotation)) - (last_y * (float)sin(rel_rotation)) + midpoint_x;
				m_vertices[i].Position[1] = (last_y * (float)cos(rel_rotation)) + (last_x * (float)sin(rel_rotation)) + midpoint_y;
			}

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
