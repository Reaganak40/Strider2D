#ifndef S2D_VERTEXBUFFER
#define S2D_VERTEXBUFFER 1

namespace Strider2D
{
	namespace Renderer //VertexBuffer is a dependency for renderer
	{
		class VertexBuffer
		{
		private:
			unsigned int m_RendererID;
		public:
			// Constructor: Adds data to a OpenGL buffer data object
			VertexBuffer(const void* data, unsigned int size);
			~VertexBuffer();

			// Updates the buffer data with the given data
			void Update(const void* data, unsigned int size);

			// Assigns buffer to next draw call 
			void Bind() const;

			// Remove buffer to next draw call 
			void Unbind() const;
		};
	}
}
#endif