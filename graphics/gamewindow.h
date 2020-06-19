#ifndef FOURTH_AGE_CLIENT_GAMEWINDOW
#define FOURTH_AGE_CLIENT_GAMEWINDOW

/* This file contains:
 * - Game window creation.
 * - SDL context creation.
 * - Input handling. 
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

/* Include cameras to call movement. */
#include "camera2d.h"
#include "camera3d.h"

/* The game window pointer. */
SDL_Window*     window;

/* 0 = 2D, 1 = 3D. */
int             mode;

/* Booleans if keys are pressed. */
int     buttonW;
int     buttonS;
int     buttonA;
int     buttonD;
int     buttonQ;
int     buttonE;

/* - Creates Game Window.
 * - Creates window context.
 * - Initializes SDL.
 * - Returns success.
 * - Initializes cameras.*/
int     GWD_createWindow    (char  *title, int   resX, int   resY);

/* - Swaps the buffers. */
void    GWD_updateWindow    ();

/* - Processes input and calls appropriate functions
 * - Returns -1 if game should close. */
int     GWD_processInput    ();

/* - Updates SDL2 to 2D
 * - Calls 2D movement functions */
void    GWD_set2d           ();

/* - Updates SDL2 to 3D
 * - Calls 2D movement functions */
void    GWD_set3d           ();

/* Closes the game window. */
void    GWD_closeWindow     ();

#endif
