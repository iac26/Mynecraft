#version 410 core

layout (location = 0) out vec4 FragColor;

in vec2 texCoord;
in vec3 normal;

uniform sampler2D Texture;

void main()
{
	vec3 sun = vec3(0.2, 1.0, 0.4);
	vec3 color = texture(Texture, texCoord).rgb;
	vec3 ambient = vec3(0.3, 0.3, 0.3);

	vec3 light = max(dot(normal, sun), 0.0)*vec3(0.8, 0.8, 0.8);

	FragColor = vec4(color * (light + ambient), 1.0);

} 