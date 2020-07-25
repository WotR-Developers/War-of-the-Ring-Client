/* The EventManager of the game, responsible for:
 * ending and starting the game
 * processing input
 * calling the right functions for the different stages
 * Updating with the game and render loop. */

#ifndef FOURTH_AGE_CLIENT_EVENTMANAGER
#define FOURTH_AGE_CLIENT_EVENTMANAGER

#include "../graphics/gamewindow.h"
#include "../graphics/camera3d.h"
#include "../graphics/object.h"
#include "../libs/resourcemanager.h"
#include "../graphics/projection.h"
#include "../graphics/camera2d.h"

/* Buttons for input system. */
int     buttonEsc;
int     buttonW;
int     buttonS;
int     buttonA;
int     buttonD;

/* 0 = battle phase, 1 = turn phase */
int     phase;

/* The screen aspect ratio. */
float   aspectRatio;

/* Calls the functions to start the game:
 * Loads the Resoources
 * Initializes the cameras
 * Initializes the Projections
 * Initializes the game window. */
void    EMG_startGame   (char   gameDirectory[], int    windowWidth, int    windowHeight);

/* Proceeds game tick tasks. */
void    EMG_doGameTick  ();

/* Proceeds render tick tasks:
 * Updates the camera
 * Draws the objects
 * Processes the inputs. */
void    EMG_doRenderTick    (float  deltaTime);

/* Processes the input, calls the appropriate functions. */
void    EMG_processInput    ();

/* Switch to 3D-battle mode. */
void    EMG_startBattlePhase    ();

/* Switch to 2D-Campaign mode. */
void    EMG_startTurnPhase      ();

/* Processes ending tasks for the game. */
void    EMG_endGame     ();

#endif
