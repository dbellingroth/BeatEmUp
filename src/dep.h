#if (defined(__MACH__))

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#elif defined (__linux__)

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#elif defined (_WIN32)

#include "SDL.h"
#include "SDL_opengl.h"

#endif