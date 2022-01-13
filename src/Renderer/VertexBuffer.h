#ifndef S2D_VERTEXBUFFER
#define S2D_VERTEXBUFFER 1

#include <core.h>

class VertexBuffer
{
private:
	unsigned int m_RendererID;
public:
	// Constructor: Adds data to a OpenGL buffer data object
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	// Assigns buffer to next draw call 
	void Bind() const;

	// Remove buffer to next draw call 
	void Unbind() const;
};

#endif