#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in float a_texIndex;

uniform mat4 u_MVP;

out vec2 v_TexCoord;
out vec4 v_Color;
out float v_TexIndex;

void main()
{
	gl_Position = u_MVP * position;
	v_TexCoord = texCoord;
	v_TexIndex = a_texIndex;
	v_Color = a_Color;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in float v_TexIndex;
in vec4 v_Color;

uniform vec4 u_Color;
uniform sampler2D u_Textures[32];

void main()
{

	//int index = int(v_TexIndex);

	//if (index == 0)
	//{
	//	color = v_Color; // shape is shaded by color
	//}
	//else {
	//	vec4 texColor = texture(u_Textures[index], v_TexCoord);
	//	color = texColor;  // shape is shaded by texture

	//}

	color = v_Color; // shape is shaded by color
	//color = vec4(1.0);
};