#include "globals.h"

int             gScreenHeight       =   480;
int             gScreenWidth        =   640;
SDL_Window*     gGraphicsWindow     =   nullptr;
SDL_GLContext   gOpenGLContext      =   nullptr;
bool            gQuit               =   false;
GLuint          gVertexArrayObject  =   0;
GLuint          gVertexBufferObject =   0;
GLuint          gGraphicsPipelineShaderProgram =   0;


std::string     gVertexShaderSource =
    "#version 410 core\n"
    "in vec4 position;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(position.x, position.y, position.z, position.w);\n"
    "}\n";

std::string     gFragmentShaderSource =
    "#version 410 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
    "}\n";