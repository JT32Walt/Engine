#include "tile.h"
#include "globals.h"
#include "shaderManager.h"

void tile::setupBuffers()
{
    //Set up the VAO for the object
    glGenVertexArrays(1, &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);
    //Set up the Vertex VBO
    glGenBuffers(1, &VertexPositionBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, VertexPositionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(GLfloat), vertexPositions.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindVertexArray(0);
     
    //Set up the IBO
    glGenBuffers(1, &VetexIndexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VertexPositionBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(GLuint), indexBufferData.data(), GL_STATIC_DRAW);

}


void tile::PreDraw()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glViewport(0,0, gScreenWidth, gScreenHeight);
    glClearColor(1.f, 1.f, 0.f, 1.f);

    glUseProgram(shaderManager::GetShader("tileShader"));
}


void tile::Draw()
{
    glBindVertexArray(VertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, VertexPositionBufferObject);

    glDrawElements(GL_TRIANGLES, 2, GL_UNSIGNED_INT, 0);

    glUseProgram(0);
}