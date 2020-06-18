/* Contains the movement/strafe and functions of the camera */

#ifndef THE_FOURTH_AGE_CAMERA_H
#define THE_FOURTH_AGE_CAMERA_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include "../../libs/maths/quasar/matrix/mat4.h"
#include "../../libs/maths/quasar/vector/vec3.h"
#include "../../libs/maths/quasar/math/toradians.h"
#include <math.h>

/* The matrices to be calculated and returned */
QsrMat4f    viewMatrix;

/* The camera vectors for the view matrix calculation */
QsrVec3f    worldUp;
QsrVec3f    cameraPosition;
QsrVec3f    cameraFront;
QsrVec3f    cameraUp;
QsrVec3f    cameraRight;

/* The camera variables to be adjusted */
float   yaw;
float   pitch;
float   movementSpeed;
float   mouseSensitivity;
float   xOffSet;
float   yOffSet;
float   lastX;
float   lastY;

/* Initializes variables and matrices to default; to be called at start of program */
void    CA3_initCamera      ();

/* Moves the camera forwards */
void    CA3_moveForward     ();

/* Moves the camera backwards. */
void    CA3_moveBackward    ();

/* Moves the camera leftwards. */
void    CA3_strafeLeft      ();

/* Moves the camera rightwards. */
void    CA3_strafeRight     ();

/* Rotates the camera to the left. Only called in 2D mode. */
void    CA3_rotateLeft      ();

/* Rotates the camera to the right. Only called in 2D mode. */
void    CA3_rotateRight     ();

/* Resets the matrices and variables to default. Usually called if changed to 2D or 3D mode. */
void    CA3_resetCamera     ();

/* Calculates camera for mouse movement. */
void    CA3_processMouse    (double     xpos, double    ypos);

/* Calculates and returns the view matrix */
QsrMat4f    CA3_getViewMatrix   ();

#endif //THE_FOURTH_AGE_CAMERA_H
