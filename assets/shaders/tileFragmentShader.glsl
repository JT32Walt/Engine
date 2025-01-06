#version 410 core

in vec4 screenUV;

out vec4 color;

uniform vec4 quadrangColors[4];

void main
{
    if (screenUV.x < 0.5f && screenUV.y < 0.5f)
    {
        color = quadrangColors[0];
    }
    if (screenUV.x >= 0.5f && screenUV.y < 0.5f)
    {
        color = quadrangColors[1];
    }
    if (screenUV.x < 0.5f && screenUV.y >= 0.5f)
    {
        color = quadrangColors[2];
    }
    else
    {
        color = quadrangColors[3];
    }
}