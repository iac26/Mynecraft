#version 410 core

layout (location = 0) out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D Texture;

void main()
{

	vec3 color = texture(Texture, texCoord).rgb;

	if(color.r < 0.1) {
		discard;
	}
	

	FragColor = vec4(color, 1.0);

} 