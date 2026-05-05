#version 330 core
out vec4 FragColor;
in vec3 Color;
uniform mat4 translate;

void main()
{
    FragColor = translate * vec4(Color, 1.0f);
}