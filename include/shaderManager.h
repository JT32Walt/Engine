#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "glad.h"
#include "SDL.h"

#include <string>
#include <map>
#include <iostream>
#include <fstream>

class shaderManager
{
private:
    /* data */
    static std::map<std::string, GLuint> shaders;
public:
    shaderManager(/* args */);
    ~shaderManager() { DeleteAllShaders();};

    //Managment Functions
    void AddShader(const std::string& name, GLuint shaderID);
    static GLuint GetShader(const std::string& name);
    void DeleteAllShaders();
    //File Reading
    std::string LoadShaderAsString(const std::string& filename);
    //Compilation Functions
    GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource);
    GLuint CompileShader(GLuint type, const std::string& shadersource);


};

#endif 