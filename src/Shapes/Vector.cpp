#include "Vector.h"

// Copies the contents of a Vector src to the new Vector dst
void Strider2D::CopyVector(const Vector src, Vector& dst)
{
    dst.Position[0] = src.Position[0];
    dst.Position[1] = src.Position[1];

    dst.Color[0] = src.Color[0];
    dst.Color[1] = src.Color[1];
    dst.Color[2] = src.Color[2];
    dst.Color[3] = src.Color[3];

    dst.TextureCoords[0] = src.TextureCoords[0];
    dst.TextureCoords[1] = src.TextureCoords[1];

    dst.TextureID = src.TextureID;

}