#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <glad.h>

#include "texture.h"
#include "shader.h"

class ResourceManager
{
public:
    //resource storage
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;
    // loads and generates a shader program file loading vertex fragment and geometry shaders sources code
    static Shader   loadShader(const char *vShaderFile, const char *fShaderFile, const char * gShaderFile, std::string name);
    // retrieves a strored shader
    static Shader   getShader(std::string name);
    //loads and generates a texture from file
    static Texture2D loadTexture(const char *file, bool alpha, std::string name);
    //retrieves a stored texture
    static Texture2D getTexture(std::string name);
    static void Clear();
private:
    //private constructor
    ResourceManager() {  }
    //loads and generates a shader from file
    static Shader   loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    //load a single texture form file
    static Texture2D loadTextureFromFile(const char *file, bool alpha);
};

#endif