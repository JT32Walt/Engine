#ifndef CAMERA_H
#define  CAMERA_H

#include <glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

using namespace glm;

class Camera2D
{
    public:
        vec2 focusPosition;
        float zoom;

        Camera2D(vec2 focusPosition, float zoom);
        mat4 getProjectionMatrix(); 
};

#endif