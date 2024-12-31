#include "camera.h"
#include "window.h"

Camera2D::Camera2D(vec2 _focusPosition, float _zoom)
    : focusPosition(_focusPosition), zoom(_zoom)
{

}

mat4 Camera2D::getProjectionMatrix()
{
    float left = focusPosition.x - 2560.0f / 2;
    float right = focusPosition.x + 2560.0f / 2;
    float top = focusPosition.y - 1440.0f / 2;
    float bottom = focusPosition.y + 1440.0f / 2;

    mat4 projectionMatrix = ortho(left, right, bottom, top, 0.01f, 100.0f);
    projectionMatrix = scale(projectionMatrix, vec3(zoom, zoom, zoom));

    return projectionMatrix;    
}
