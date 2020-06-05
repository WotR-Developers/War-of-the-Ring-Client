/* Contains the game update loop which is called on every game tick and fires the update of the rest of the game
 * e.g. the movement of soldiers */

#ifndef THE_FOURTH_AGE_GAME_H
#define THE_FOURTH_AGE_GAME_H

/* The coordinates of the player */
float playerPosX = 0.0f;        // The X coordinates
float playerPosY = 0.0f;        // The Y coordinates
float playerPosZ = 0.0f;        // The Z coordinates

/* To be called at the game start, sets everything up and adds game objects */
void GAM_gameStart          ();

/* The main game loop to be called every game tick */
void GAM_gameUpdate         ();

/* Gets called by the processInput of the game window, updates the player coordinates */
void GAM_movePlayer         (float x, float y, float z);

/* Calls the stop of everything in game/, frees variables and deletes all game objects */
void GAM_gameStop           ();

#endif //THE_FOURTH_AGE_GAME_H
