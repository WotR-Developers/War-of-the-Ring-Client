/* Contains the movement/strafe and functions of the camera */

#ifndef THE_FOURTH_AGE_CAMERA2D_H
#define THE_FOURTH_AGE_CAMERA2D_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include "../../libs/maths/quasar/matrix/mat4.h"
#include "../../libs/maths/quasar/vector/vec3.h"
#include "../../libs/maths/quasar/math/toradians.h"
#include <math.h>

/* The matrices to be calculated and returned */
QsrMat4f    viewMatrix2d;

/* The camera vectors for the view matrix calculation */
QsrVec3f    worldUp2d;
QsrVec3f    cameraPosition2d;
QsrVec3f    cameraFront2d;
QsrVec3f    cameraUp2d;
QsrVec3f    cameraRight2d;

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

/* Resets the matrices and variables to default. Usually called if changed to 2D or 3D mode. */
void    CA2_resetCamera     ();

/* Calculates and returns the view matrix */
QsrMat4f    CA2_getViewMatrix   ();

#endif //THE_FOURTH_AGE_CAMERA2D_H
