#include "SDL.h"

#include "globals.h"
#include "glm.hpp"
#include "glad.h"

#include <iostream>
#include <vector>
#include <string>

#undef main

void GetVersionInfo()
{
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void InitalizeProgram()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL2 could not initalize video" << std::endl;
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_DisplayMode dm;
    SDL_GetDesktopDisplayMode(0, &dm);
    gScreenWidth = dm.w;
    gScreenHeight = dm.h;

    gGraphicsWindow = SDL_CreateWindow("Test", 0, 0, gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (gGraphicsWindow == nullptr)
    {
        std::cout << "SDL Window Failed" << std::endl;
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsWindow);

    if (gOpenGLContext == nullptr)
    {
        std::cout << "OpenGL Context Failed" << std::endl;
        exit(1);
    }

    if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        std::cout << "Glad not initalized" << std::endl;
        exit(1);
    }
    
    GetVersionInfo();
}

void Input()
{
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            gQuit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                gQuit = true;
            }
        }
    }
}

void PreDraw()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glViewport(0,0, gScreenWidth, gScreenHeight);
    glClearColor(1.f, 1.f, 0.f, 1.f);

    glUseProgram(gGraphicsPipelineShaderProgram);
}

void Draw()
{
    glBindVertexArray(gVertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glDrawArrays(GL_TRIANGLES,0, 3);
}

void MainLoop()
{
    while(!gQuit)
    {
        Input();

        PreDraw();

        Draw();

        SDL_GL_SwapWindow(gGraphicsWindow);
    }
}

void clean()
{
    SDL_DestroyWindow(gGraphicsWindow);
    SDL_Quit();
}

void VertexSpecification()
{
    const std::vector<GLfloat> vertexPosition{
        //x     y     z
        -0.8f, -0.8f, 0.0f, //vertex 1
        0.8f, -0.8f, 0.0f,  //vertex 2
        0.0f, 0.8f, 0.0f    //vertex 3
    };
    //VAO
    glGenVertexArrays(1,&gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);
    //VBO
    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, vertexPosition.size() * sizeof(GLfloat), vertexPosition.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
}


GLuint CompileShader(GLuint type, const std::string& shadersource)
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

GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource)
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

void CreateGraphicsPipeline()
{
    gGraphicsPipelineShaderProgram = CreateShaderProgram(gVertexShaderSource, gFragmentShaderSource); 
}

int main()
{
    InitalizeProgram();

    VertexSpecification();

    CreateGraphicsPipeline();

    MainLoop();

    clean();

    return 0;
}