#version 410 core

layout(location=0) in vec3 position

out vec2 screenUV

void main()
{
    screenUV = (position.xy + vec2(1.0f)) * 0.5f;
    gl_position = vec4(position.x, position.y, position.z, 1.0f)
}