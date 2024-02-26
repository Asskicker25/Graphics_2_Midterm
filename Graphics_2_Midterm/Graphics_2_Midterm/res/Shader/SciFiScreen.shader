#vertex

#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoord;
layout(location = 3) in vec4 vertexColor;

out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out vec4 VertexColor;

uniform vec3 textureTiling;  //x, y

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 inverseModel;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1);
	TexCoord = vec2(texCoord.x * textureTiling.x, 1.0 - texCoord.y * textureTiling.y);

	vec4 worlNormal = inverseModel * vec4(normal, 1.0f);
	Normal = normalize(worlNormal.xyz);
	//Normal = normal;
	
	FragPos = vec3(model * vec4(position, 1.0f));
	VertexColor = vertexColor;
};


#fragment

#version 330 core


out vec4 color;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec4 VertexColor;

uniform sampler2D texture_diffuse;

uniform float flickerValue;

void main()
{
	vec2 uv = TexCoord;
	uv.y -= flickerValue;

	vec4 texColor = texture(texture_diffuse, uv);

	color = vec4(texColor.rgb, 1.0);
	
}
