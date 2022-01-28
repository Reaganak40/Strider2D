#ifndef S2D_RENDERER
#define S2D_RENDERER 1

#include "../Shapes/Quad.h"
#include "../Shapes/Triangle.h"

#include "VertexBuffer.h" // a dependency for OpenGL rendering
#include "VertexArray.h"  // a dependency for OpenGL rendering
#include "IndexBuffer.h"  // a dependency for OpenGL rendering
#include "Shader.h"		  // a dependency for OpenGL rendering

#define S2D_PUSH_STATIC 0
#define S2D_PUSH_DYNAMIC 1
#define S2D_BATCH_LIMIT 9 // This is how many batch rendering units are allowed for a single renderer object

namespace Strider2D
{
	namespace Renderer
	{
		// An intermediary struct that takes any shape and converts it to buffer data
		struct ShapeBuffer
		{
			float* b_attributes;
			int b_num_attributes;

		};

		class Renderer2D
		{
		private:

			struct DrawQueue // THIS IS A BATCH RENDERING UNIT
			{
				VertexBuffer* batch_vb;
			};

			int m_window_height;
			int m_window_width;

			DrawQueue m_queues[S2D_BATCH_LIMIT];

			// Calls OpenGL clear buffer bit
			void clear();

			// Takes the rendering utlities, combinining them to draw data to the screen
			void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		public:

			Renderer2D(int window_width = 960, int window_height = 540);
			
			// Runs a OpenGL draw call for a Quad object
			void DrawQuad(Quad quad);

			// Runs a OpenGL draw call for a Triangle object
			void DrawTriangle(Triangle triangle);

			// BATCH RENDERING IMPLEMENTATION ******************************
			// *************************************************************

			// Pushes a primitive shape object to a draw queue
			template<typename T>
			void Push(T& draw_element, int queue_index)
			{
				static_assert(false);
			}

			template<>
			void Push<Quad>(Quad& draw_element, int queue_index)
			{
				if (queue_index >= S2D_BATCH_LIMIT)
					ApplicationBreak("Renderer2D::Push<Quad>() Specified queue is out of range");

				// Break down quad into its vector parts
				// append those vectors to the specified draw queue
			}

			template<>
			void Push<Triangle>(Triangle& draw_element, int queue_index)
			{
				if (queue_index >= S2D_BATCH_LIMIT)
					ApplicationBreak("Renderer2D::Push<Quad>() Specified queue is out of range");
			}

		};

		ShapeBuffer* InitVectorBuffer(Vector* vertices, int count);

		template<typename T>
		inline ShapeBuffer* ConvertShapeToBuffer(T& shape)
		{
			static_assert(false);
		}

		template<>
		inline ShapeBuffer* ConvertShapeToBuffer<Quad>(Quad& shape)
		{
			return InitVectorBuffer(shape.GetVertices(), 4); // 4 is number of vertices
		}

		template<>
		inline ShapeBuffer* ConvertShapeToBuffer<Triangle>(Triangle& shape)
		{
			return InitVectorBuffer(shape.GetVertices(), 3); // 4 is number of vertices
		}
		

	}
	//class Renderer2D
	//{
	//private:

	//	struct DrawQueueElement
	//	{
	//		Vector* e_vertices;
	//		int e_num_vertices;
	//	};
	//	std::deque<DrawQueueElement*> m_drawQueue;

	//	int m_allocate_type;

	//		VertexBuffer*	m_vb;
	//	/*	VertexArray*	m_va;
	//		IndexBuffer*	m_ib;
	//		Shader*			m_shader;*/

	//	// Takes a list of Vectors gathered by push and given the count, creates a new DrawQueueElment
	//	void appendQueue(Vector* element_vertices, int count);

	//	// Adds a draw elements vertices to a buffer of floats and returns the new offset
	//	int addVectorData(float* buffer_data, DrawQueueElement* draw_element);

	//public:

	//	Renderer2D() : m_allocate_type(S2D_PUSH_STATIC) {}

	//	void SetAllocationType(int type_val);
	//	void SetPushDynamic() { m_allocate_type = S2D_PUSH_DYNAMIC; }
	//	void SetPushStatic() { m_allocate_type = S2D_PUSH_STATIC; }

	//	// Takes an Application which contains an OpenGL window context
	//	// and runs through all the pushed objects in a Renderer objects
	//	// queue, drawing them to the screen.

	//	template<typename T>
	//	void Push(T& draw_element)
	//	{
	//		static_assert(false);
	//	}

	//	template<>
	//	void Push<Quad>(Quad& draw_element)
	//	{
	//		appendQueue(draw_element.GetVertices(), 4);
	//	}

	//};
}

#endif