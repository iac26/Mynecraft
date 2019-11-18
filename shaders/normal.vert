
#version 410 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 tex;

out vec2 texCoord;
out vec3 normal;


uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
    normal = mat3(transpose(inverse(model))) * norm;
	texCoord = tex;
    gl_Position = projection * view * model * vec4(pos, 1.0);


}