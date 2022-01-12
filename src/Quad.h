#define STDR_QUAD 1

#include "Strider2D.h"
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
		
		void SetX(float x);
		void SetY(float y);
		void SetColor(float red, float green, float blue, float alpha);
		void SetTexture(std::string texture_loc);

		inline float GetWidth()	 { return m_width;  }
		inline float GetHeight() { return m_height; }
		inline float GetX()		 { return m_vertices[0].Position[0]; }
		inline float GetY()		 { return m_vertices[0].Position[1]; }

		std::string c_str();
	};
}