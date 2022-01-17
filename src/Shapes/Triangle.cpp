#include "pch.h"
#include "Triangle.h"

namespace Strider2D
{
	Triangle::Triangle(float width, float height, float x, float y)
	{
		m_rotation_rule = S2D_VERTEX_ROTATION; //rotate on vertex 0
		m_current_rotation = 0.0f;

		m_width = width;
		m_height = height;

		m_flipped_x = false;
		m_flipped_y = false;

		// Default is a right traingle
		m_vertex_angle = 90;
		m_vec2_hyp = sqrt(pow(m_width, 2) + pow(m_height, 2));
		m_vec2_dr = atan(m_height / m_width);

		// Position must be done manually because functions depend on initialized positions
		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + width;
		m_vertices[2].Position[0] = x + width;

		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y;
		m_vertices[2].Position[1] = y + height;

		SetColor(0.0f, 0.0f, 0.0f, 1.0f); // Pre-set all new traingles to black

		SetTexture("NoTexture"); // No default texture (textureID = 0)
		SetTextureCoordinates();
	}

	void Triangle::SetVertexAngle(float degrees)
	{
		// limit the min max degrees of the vertex angle
		if (degrees < 1)
			degrees = 1;
		else if (degrees > 179)
			degrees = 179;

		double rad_rotation;

		if(m_flipped_y && !m_flipped_x || (!m_flipped_y && m_flipped_x))
			rad_rotation = (degrees) * (S2D_PI / 180);
		else
			rad_rotation = ((-1) * degrees) * (S2D_PI / 180);

		float local_x = (float)cos(rad_rotation);

		float dx = 0;
		if(degrees != 90) //since tan(90) = undefined
			dx = m_height / (float)tan(rad_rotation);

		m_vertices[2].Position[0] = m_vertices[1].Position[0] + dx;
		m_vertices[2].Position[1] = m_vertices[0].Position[1] + m_height;

		m_vertex_angle = degrees;

		double vec2_dx = abs(m_vertices[2].Position[0] - m_vertices[0].Position[0]);

		if(vec2_dx == 0) // to avoid divide by 0
			m_vec2_dr = 90 * (float)(S2D_PI / 180);
		else
			m_vec2_dr  = (float)atan(m_height / vec2_dx);
		
		m_vec2_hyp = sqrt(pow(vec2_dx, 2) + pow(m_height, 2));


	}

	void Triangle::SetWidth(float width)
	{
		m_width = width;
		if (m_flipped_y)
		{
			m_width = -abs(m_width);
			if (m_width < 1 && m_width > -1)
				m_width = -1;
		}
		else
		{
			if (m_width < 1 && m_width > -1)
				m_width = 1;
		}

		float vec2_diff = 0;
		vec2_diff = m_vertices[1].Position[0] - m_vertices[0].Position[0];
		vec2_diff = m_width - vec2_diff;

		m_vertices[1].Position[0] += vec2_diff;
		m_vertices[2].Position[0] += vec2_diff;

	}

	void Triangle::SetHeight(float height)
	{
		m_height = height;
		
		if (m_flipped_x)
		{
			m_height = -abs(m_height);
			if (m_height < 1 && m_height > -1)
				m_height = -1;
		}
		else
		{
			if (m_height < 1 && m_height > -1)
				m_height = 1;
		}

		m_vertices[2].Position[1] = GetY() + m_height;
	}

	void Triangle::MakeRight(void)
	{
		SetVertexAngle(90);
	}

	void Triangle::MakeIsosceles(void)
	{
		float half_width = abs(m_width) / 2;
		float height = abs(m_height);

		float rad = atan(height / half_width);

		float degrees = rad * (float)(180 / S2D_PI);

		SetVertexAngle(degrees);
	}

	void Triangle::SetX(float x)
	{
		// we must calculate each individually due to rotations
		float dx1 = m_vertices[1].Position[0] - m_vertices[0].Position[0];
		float dx2 = m_vertices[2].Position[0] - m_vertices[0].Position[0];


		m_vertices[0].Position[0] = x;
		m_vertices[1].Position[0] = x + dx1;
		m_vertices[2].Position[0] = x + dx2;
	}

	void Triangle::SetY(float y)
	{
		// we must calculate each individually due to rotations
		float dy1 = m_vertices[1].Position[1] - m_vertices[0].Position[1];
		float dy2 = m_vertices[2].Position[1] - m_vertices[0].Position[1];

		m_vertices[0].Position[1] = y;
		m_vertices[1].Position[1] = y + dy1;
		m_vertices[2].Position[1] = y + dy2;
	}

	void Triangle::FlipAxisY(void)
	{
		if (m_flipped_y)
			m_flipped_y = false;
		else
			m_flipped_y = true;

		SetWidth(abs(m_width));
		Translate(0,0);
	}

	void Triangle::FlipAxisX(void)
	{
		if (m_flipped_x)
			m_flipped_x = false;
		else
			m_flipped_x = true;

		SetHeight(abs(m_height));
		Translate(0,0);
	}

	void Triangle::SetTextureCoordinates()
	{
		m_vertices[0].TextureCoords[0] = 0.0f;
		m_vertices[0].TextureCoords[1] = 0.0f;

		m_vertices[1].TextureCoords[0] = 1.0f;
		m_vertices[1].TextureCoords[1] = 0.0f;

		m_vertices[2].TextureCoords[0] = 1.0f;
		m_vertices[2].TextureCoords[1] = 1.0f;

	}
	void Triangle::SetColor(float red, float green, float blue, float alpha)
	{
		for (int i = 0; i < 3; i++)
		{
			m_vertices[i].Color[0] = red;
			m_vertices[i].Color[1] = green;
			m_vertices[i].Color[2] = blue;
			m_vertices[i].Color[3] = alpha;
		}
	}

	void Triangle::SetTexture(std::string texture_loc)
	{
		int id = GetTextureFromMap(texture_loc); // reads ID from the TextureMap.txt file

		for (int i = 0; i < 3; i++)
			m_vertices[i].TextureID = (float)id;
	}
	void Triangle::SetRotationRule(int rotation_rule)
	{
		if ((rotation_rule == S2D_VERTEX_ROTATION) || (rotation_rule == S2D_MIDPOINT_ROTATION))
			m_rotation_rule = rotation_rule;
		else
			ASSERT(false);
	}
	void Triangle::Rotate(float d_degrees)
	{
		float new_rotation = m_current_rotation + d_degrees;
		new_rotation = (float)fmod((double)new_rotation, 360); //keep rotation relative

		if (new_rotation < 0)
			new_rotation += 360;

		double rad_rotation = new_rotation * (S2D_PI / 180);
		m_current_rotation = new_rotation;

		if (m_rotation_rule == S2D_VERTEX_ROTATION)
		{

			double vec2_dx = abs(m_vertices[2].Position[0] - m_vertices[0].Position[0]);

			m_vertices[1].Position[0] = m_vertices[0].Position[0] + (float)(cos(rad_rotation) * m_width);
			m_vertices[1].Position[1] = m_vertices[0].Position[1] + (float)(sin(rad_rotation) * m_width);

			m_vertices[2].Position[0] = m_vertices[0].Position[0] + (float)(cos(rad_rotation + m_vec2_dr) * m_vec2_hyp);
			m_vertices[2].Position[1] = m_vertices[0].Position[1] + (float)(sin(rad_rotation + m_vec2_dr) * m_vec2_hyp);

		}
	}
	void Triangle::Translate(float dx, float dy)
	{
		if (dx)
			SetX(GetX() + dx);

		if (dy)
			SetY(GetY() + dy);
	}
	void Triangle::ScaleW(float dw)
	{
		SetWidth(abs(m_width) + dw);
	}
	void Triangle::ScaleH(float dw)
	{
		SetHeight(abs(m_height) + dw);
	}
}
