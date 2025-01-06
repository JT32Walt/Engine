#include "shaderManager.h"

void shaderManager::AddShader(const std::string& name, GLuint shaderID)
{
    shaders[name] = shaderID;
}

GLuint shaderManager::GetShader(const std::string& name)
{
    if (shaders.find(name) != shaders.end())
    {
        return shaders[name];
    }
    else 
    {
        std::cout << "Shader: " << name << " not found" << std::endl;
    }
}

void shaderManager::DeleteAllShaders()
{
    for (auto& pair : shaders)
    {
        glDeleteShader(pair.second);
    }
    shaders.clear();
}

std::string shaderManager::LoadShaderAsString(const std::string& filename)
{
    std::string result = "";
    std::string line = "";

    std::ifstream myFile(filename.c_str());

    if (myFile.is_open())
    {
        while(std::getline(myFile, line))
        {
            result += line + '\n';
        }
        myFile.close();
    }
    return result;
}


GLuint shaderManager::CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource)
{
    GLuint programObject = glCreateProgram();

    GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vertexshadersource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentshadersource);

    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);
    glLinkProgram(programObject);

    //Validate Program
    glValidateProgram(programObject);
    // glDetachShader, glDeleteShader

    return programObject;
}

GLuint shaderManager::CompileShader(GLuint type, const std::string& shadersource)
{
    GLuint shaderObject;
    if (type == GL_VERTEX_SHADER)
    {
        shaderObject = glCreateShader(GL_VERTEX_SHADER);

    }
    else if (type == GL_FRAGMENT_SHADER)
    {
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const char * src = shadersource.c_str();    
    glShaderSource(shaderObject, 1, &src, nullptr);
    glCompileShader(shaderObject);

    return shaderObject;
}