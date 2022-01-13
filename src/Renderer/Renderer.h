#ifndef S2D_RENDERER
#define S2D_RENDERER 1

#include "../Shapes/Quad.h"

#include <deque>
#define S2D_PUSH_STATIC 0
#define S2D_PUSH_DYNAMIC 1


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

		ShapeBuffer* InitVectorBuffer(Vector* vertices, int count);

		template<typename T>
		ShapeBuffer* ConvertShapeToBuffer(T& shape)
		{
			static_assert(false);
		}

		template<>
		ShapeBuffer* ConvertShapeToBuffer<Quad>(Quad& shape)
		{
			return InitVectorBuffer(shape.GetVertices(), 4); // 4 is number of vertices
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