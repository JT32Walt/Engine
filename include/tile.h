#ifndef TILE_H
#define TILE_H

#include "glad.h"
#include "SDL.h"
#include "glm.hpp"

#include <vector>

class tile
{
private:
    int GridX;
    int GridY;

    GLuint VertexArrayObject = 0;
    GLuint VertexPositionBufferObject = 0;
    GLuint VetexIndexBufferObject = 0;

    const std::vector<GLfloat> vertexPositions {
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    const std::vector<GLuint> indexBufferData {
        2, 0, 1, 3, 2, 1
    };

    glm::vec4 colors[4] =  {
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), //bottom left
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), //bottom right
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), //top left
        glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)  //top right
    };


public:
    tile(/* args */);
    ~tile();

    //Initalization Functions
    void setupBuffers();
    //Math functions

    //Draw functions
    void PreDraw();
    void Draw();
};
#endif