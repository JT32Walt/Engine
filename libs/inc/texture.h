#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad.h>

class Texture2D
{
public:
    //Texture ID
    unsigned int ID;
    //Texture Diminsions
    unsigned int Width, Height;
    //Texture Format
    unsigned int Internal_Format;
    unsigned int Image_Format;
    //texture Configuration
    unsigned int Wrap_S;
    unsigned int Wrap_T;
    unsigned int Filter_Min;
    unsigned int Filter_Max;
    //Constructor
    Texture2D();
    //Generate texture from image data
    void Generate(unsigned int width, unsigned int height, unsigned char * data);
    //bind texture as gcurrect actuve GL_TEXTURE_2D texture object
    void Bind() const;

};

#endif