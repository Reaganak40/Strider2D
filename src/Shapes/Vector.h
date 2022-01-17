#ifndef S2D_VECTOR_H
#define S2D_VECTOR_H 1

#define S2D_VECTOR_FLOAT_COUNT 9 //number of float values in a Vector struct
#define S2D_PI 3.14159265
#define S2D_VERTEX_ROTATION 0	  //rotate on vertex 0
#define S2D_MIDPOINT_ROTATION 1   // rotate on the center point of shape

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

}

#endif // !S2D_VECTOR_H