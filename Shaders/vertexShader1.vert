#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 Color;
uniform mat4 translate;

void main()
{
    gl_Position = translate * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    Color = vec3(aColor.x, aColor.y, aColor.z);
}
