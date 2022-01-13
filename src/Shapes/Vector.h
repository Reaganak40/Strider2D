#ifndef S2D_VECTOR_H
#define S2D_VECTOR_H 1

#define S2D_VECTOR_FLOAT_COUNT 9 //number of float values in a Vector struct

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