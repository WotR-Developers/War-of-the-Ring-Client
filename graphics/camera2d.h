/* Contains the movement/strafe and functions of the camera */

#ifndef THE_FOURTH_AGE_CAMERA2D_H
#define THE_FOURTH_AGE_CAMERA2D_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include "../libs/maths.h"

/* The matrices to be calculated and returned */
mat4    viewMatrix2d;

/* The camera vectors for the view matrix calculation */
vec3    worldUp2d;
vec3    cameraPosition2d;
vec3    cameraFront2d;
vec3    cameraUp2d;
vec3    cameraRight2d;

/* The camera variables to be adjusted */
float   yaw2d;
float   pitch2d;
float   movementSpeed2d;
float   mouseSensitivity2d;
float   xOffSet2d;
float   yOffSet2d;

/* Initializes variables and matrices to default; to be called at start of program */
void    CA2_initCamera      ();

/* Moves the camera forwards */
void    CA2_moveForward     ();

/* Moves the camera backwards. */
void    CA2_moveBackward    ();

/* Moves the camera leftwards. */
void    CA2_strafeLeft      ();

/* Moves the camera rightwards. */
void    CA2_strafeRight     ();

/* Rotates the camera to the left. Only called in 2D mode. */
void    CA2_rotateLeft      ();

/* Rotates the camera to the right. Only called in 2D mode. */
void    CA2_rotateRight     ();

void    CA2_updateCamera    ();

/* Resets the matrices and variables to default. Usually called if changed to 2D or 3D mode. */
void    CA2_resetCamera     ();

/* Calculates and returns the view matrix */
void    CA2_getViewMatrix   (mat4   viewMatrix);

#endif //THE_FOURTH_AGE_CAMERA2D_H
