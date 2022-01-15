#include "window.h"

namespace Strider2D
{
	void Window::DrawQuad(Quad quad)
	{
		glm::mat4 proj = glm::ortho(0.0f, (float)getWindowWidth(), 0.0f, (float)getWindowHeight(), -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		glm::vec3 translation(0, 0, 0);

		// Create a Vertex Array
		Renderer::VertexArray vao;
		
		// Create a Vertex Buffer
		Renderer::ShapeBuffer* sb;
		sb = Renderer::ConvertShapeToBuffer<Quad>(quad);
		Renderer::VertexBuffer vb(sb->b_attributes, sb->b_num_attributes * sizeof(float));

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

			//shader.SetUniform1iv("u_Textures", m_samplers, m_num_objects + 1);
			shader.SetUniformMat4f("u_MVP", mvp);

			renderer.draw(vao, ib, shader);
		}


	}
}

