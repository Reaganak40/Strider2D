#include "pch.h"
#include "VertexBufferLayout.h"

namespace Strider2D
{
	namespace Renderer
	{
		unsigned int VertexBufferElement::GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
			}

			ASSERT(false);
			return 0;
		}

	}
}