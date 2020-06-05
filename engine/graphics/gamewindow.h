/* This file sets up the game window proceeds input and forwards it to the camera */

#ifndef THE_FOURTH_AGE_GAMEWINDOW_H
#define THE_FOURTH_AGE_GAMEWINDOW_H

/* Include the GL Window library to be able to work with a game window */
#include <GLFW/glfw3.h>

/* A variable which changes to 1 if the window should be closed */
int gameWindowShouldClose = 0;

/* The game window represented by a GLFWwindow. */
GLFWwindow *gameWindow;

/* Creates the game window and sets it up. */
void createGameWindow           ();

/* Updates the game window. */
void updateGameWindow           ();

/* Processes the input and forwards it to the game or camera or itself. */
void processInput               ();

/* The scroll callback. Forwards to the camera. */
void scroll_callback            (GLFWwindow *window, double xoffset, double yoffset);

/* The mouse callback. Forwards to the camera. */
void processMouse               (GLFWwindow* placeholder, double xpos, double ypos);

/* Updates GLFW attributes to 3D. */
void setWindow3D                ();

/* Updates GLFW attributes to 2D. */
void setWindow2D                ();

#endif //THE_FOURTH_AGE_GAMEWINDOW_H
