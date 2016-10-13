#version 410

out vec4 FragColor;
uniform vec4 Colour = (1.0f,0.0f,0.0f,0.0f);

void main()
{
	FragColor = Colour;
}