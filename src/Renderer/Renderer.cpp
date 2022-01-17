#include "pch.h"
#include "Renderer.h"

namespace Strider2D 
{
	namespace Renderer
	{
		ShapeBuffer* InitVectorBuffer(Vector* vertices, int count)
		{
			int buffer_size = count * S2D_VECTOR_FLOAT_COUNT;
			float* attributes = new float[buffer_size];
			
			// Add the vector data to the buffer
			for (int current_vector = 0; current_vector < count; current_vector++)
				for (int current_attribute = 0; current_attribute < S2D_VECTOR_FLOAT_COUNT; current_attribute++)
					attributes[(current_vector * S2D_VECTOR_FLOAT_COUNT) + current_attribute] = *(((float*)(&vertices[current_vector])) + current_attribute);
			ShapeBuffer* n_sb = new ShapeBuffer;

			n_sb->b_attributes = attributes;
			n_sb->b_num_attributes = buffer_size;

			return n_sb;
		}

		void Renderer2D::clear()
		{
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}
		void Renderer2D::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
		{
			shader.Bind();
			va.Bind();
			ib.Bind();
			GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
		}

		Renderer2D::Renderer2D(int window_width, int window_height)
		{
			m_window_width = window_width;
			m_window_height = window_height;
			
		}

		void Renderer2D::DrawQuad(Quad quad)
		{

			glm::mat4 proj = glm::ortho(0.0f, (float)m_window_width, 0.0f, (float)m_window_height, -1.0f, 1.0f);
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
			glm::vec3 translation(0, 0, 0);

			int* samplers = nullptr;
			int sampler_size = 0;
			std::string texture_loc;
			Renderer::Texture* texture = nullptr;

			// Create a Vertex Array
			Renderer::VertexArray vao;

			// Create a Vertex Buffer
			Renderer::ShapeBuffer* sb;
			sb = Renderer::ConvertShapeToBuffer<Quad>(quad);
			Renderer::VertexBuffer vb(sb->b_attributes, sb->b_num_attributes * sizeof(float));

			// Check for textures
			samplers = GetSamplers(&sampler_size);
			if (sb->b_attributes[8] != 0) //8th index is a TextureID
			{
				texture_loc = GetTextureFromMap((int)sb->b_attributes[8]);


			}
			else
			{
				texture_loc = "NoTexture";
			}

			// Create a Vertex Buffer Layout
			Renderer::VertexBufferLayout layout;
			layout.Push<float>(2); // x,y coordinates
			layout.Push<float>(4); // color values (rgba)
			layout.Push<float>(2); // texture (coordinate)
			layout.Push<float>(1); // texture (index)

			vao.AddBuffer(vb, layout); // Add buffer and layout to Vertex Array

			// Create an Index Buffer
			unsigned int indices[]
			{
				0, 1, 2,	// Triangle 1
				2, 3, 0		// Triangle 2
			};
			Renderer::IndexBuffer ib(indices, 6);

			// Create and bind a Shader
			Renderer::Shader shader("res/shaders/basic.shader");
			shader.Bind();

			Renderer::Renderer2D renderer;

			// draw data to screen
			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
				glm::mat4 mvp = proj * view * model;
				shader.Bind();

				shader.SetUniform1iv("u_Textures", samplers, sampler_size);
				shader.SetUniformMat4f("u_MVP", mvp);

				if (texture_loc != "NoTexture")
				{
					texture = new Renderer::Texture(texture_loc);
					GLCall(glBindTextureUnit((int)sb->b_attributes[8], texture->GetRendererID()));
				}
				renderer.draw(vao, ib, shader);
				delete texture;
			}
		}
	}
}

namespace Strider2D
{
	//void RunDrawQueue(Application& app, Renderer2D renderer)
	//{
	//	int attribute_count = 0;
	//	// Create a new vertex buffer
	//	// 
	//	// 1. Get size of buffer (get the TOTAL number of attributes)
	//	for (unsigned int i = 0; i < renderer.m_drawQueue.size(); i++)
	//		attribute_count += (renderer.m_drawQueue[i]->e_num_vertices * S2D_VECTOR_FLOAT_COUNT); //add the number of vertices to the vector total

	//	// 2. Create an array to hold all vector data
	//	float* buffer_data = new float[attribute_count];

	//	// 3. Add all vertices to buffer
	//	unsigned int current_offset = 0;
	//	unsigned int current_element = 0;

	//	while (current_element < renderer.m_drawQueue.size())
	//		current_offset += renderer.addVectorData(buffer_data + current_offset, renderer.m_drawQueue[current_element++]);

	//	for (unsigned int i = 0; i < attribute_count; i++);
	//		//std::cout << buffer_data[i] << std::endl;
	//}
	//void Renderer2D::appendQueue(Vector* element_vertices, int count)
	//{
	//	DrawQueueElement* dq_element = new DrawQueueElement;

	//	if (m_allocate_type == S2D_PUSH_DYNAMIC) //In dynamic pushing the queue maintains the same pointers that the object has
	//	{
	//		dq_element->e_vertices = element_vertices;
	//	}
	//	else if (m_allocate_type == S2D_PUSH_STATIC) // In static pushing the queue initiates its own pointers creating a copy of the object
	//	{
	//		dq_element->e_vertices = new Vector[count];

	//		for (int i = 0; i < count; i++)
	//			CopyVector(element_vertices[i], dq_element->e_vertices[i]);
	//	}

	//	dq_element->e_num_vertices = count;
	//	m_drawQueue.push_back(dq_element);
	//}
	//int Renderer2D::addVectorData(float* buffer_data, DrawQueueElement* draw_element)
	//{
	//	int n = 0;
	//	for (int vector = 0; vector < draw_element->e_num_vertices; vector++)
	//		for (int attribute = 0; attribute < S2D_VECTOR_FLOAT_COUNT; attribute++)
	//		{
	//			buffer_data[(vector * S2D_VECTOR_FLOAT_COUNT) + attribute] = *(float*)(&(draw_element->e_vertices[vector]) + attribute);

	//			std::cout << buffer_data[(vector * S2D_VECTOR_FLOAT_COUNT) + attribute] << std::endl;
	//		}
	//	return ((draw_element->e_num_vertices) * S2D_VECTOR_FLOAT_COUNT);
	//}
	//void Renderer2D::SetAllocationType(int type_val)
	//{
	//	if ((type_val == S2D_PUSH_DYNAMIC) || (type_val == S2D_PUSH_STATIC))
	//		m_allocate_type = type_val;
	//	else
	//		ASSERT(false);
	//}

	
}

