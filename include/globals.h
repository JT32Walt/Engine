#ifndef GLOBALS_H
#define GLOBALS_H
#include "glad.h"
#include "SDL.h"

#include <string>

extern int             gScreenHeight;
extern int             gScreenWidth;
extern SDL_Window*     gGraphicsWindow;
extern SDL_GLContext   gOpenGLContext;
extern bool            gQuit;
extern GLuint          gVertexArrayObject;
extern GLuint          gVertexBufferObject;
extern GLuint          gGraphicsPipelineShaderProgram;

extern std::string     gVertexShaderSource;
extern std::string     gFragmentShaderSource;
#endif