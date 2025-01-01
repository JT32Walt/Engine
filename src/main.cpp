#include "SDL.h"
#include "SDL_image.h"

#include "globals.h"
#include "glm.hpp"
#include "glad.h"

#include <iostream>

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
    }
}

void PreDraw()
{

}

void Draw()
{

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


int main()
{
    InitalizeProgram();

    MainLoop();

    clean();

    return 0;
}