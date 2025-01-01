#include "SDL.h"
#include "globals.h"

int             gScreenHeight       =   2560;
int             gScreenWidth        =   1440;
SDL_Window*     gGraphicsWindow     =   nullptr;
SDL_GLContext   gOpenGLContext      =   nullptr;
bool            gQuit                =   false;