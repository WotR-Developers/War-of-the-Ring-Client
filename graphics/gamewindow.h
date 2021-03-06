#ifndef FOURTH_AGE_CLIENT_GAMEWINDOW
#define FOURTH_AGE_CLIENT_GAMEWINDOW

/* This file contains:
 * - Game window creation.
 * - SDL context creation. 
 * - Buffer swapping.*/

/* For return status of success. */
#include <stdlib.h>

/* Include SDL for window and context creation. */
#define SDL_MAIN_HANDLED
#ifdef _WIN32
#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#else
#include <SDL2/SDL.h>
#endif

/* The game window pointer. */
SDL_Window*     window;
SDL_GLContext   glContext;

float   screenSizeX;
float   screenSizeY;

/* - Creates Game Window.
 * - Creates window context.
 * - Initializes SDL.
 * - Returns success. */
int     GWD_create          (char  *title, int   *resX, int   *resY);

/* - Swaps the buffers. */
void    GWD_update          (float  deltaTime);

/* - Updates SDL2 to 2D. */
void    GWD_set2d           ();

/* - Updates SDL2 to 3D. */
void    GWD_set3d           ();

/* Returns the width of the screen as suggested by SDL2. */
float   GWD_getScreenSizeX  ();

/* Returns the height of the screen as suggested by SDL2. */
float   GWD_getScreenSizeY  ();

/* Closes the game window. */
void    GWD_close           ();

#endif
