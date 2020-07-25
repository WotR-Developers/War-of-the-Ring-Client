/* Contains Camera movement
 * constructs and returns a view matrix. */

#ifndef FOURTH_AGE_CAMERA3D_H
#define FOURTH_AGE_CAMERA3D_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include "../libs/maths.h"

/* The matrices to be calculated and returned */
mat4    viewMatrix;

/* The camera vectors for the view matrix calculation */
vec3    worldUp;
vec3    cameraPosition;
vec3    cameraFront;
vec3    cameraUp;
vec3    cameraRight;

/* The camera variables to be adjusted */
float   yaw;
float   pitch;
float   movementSpeed;
float   mouseSensitivity;

/* Initializes variables and matrices to default; to be called at start of program */
void    CA3_init            ();

/* Moves the camera forwards */
void    CA3_moveForward     ();

/* Moves the camera backwards. */
void    CA3_moveBackward    ();

/* Moves the camera leftwards. */
void    CA3_strafeLeft      ();

/* Moves the camera rightwards. */
void    CA3_strafeRight     ();

/* Calculates camera for mouse movement. */
void    CA3_processMouse    (double     xpos, double    ypos);

/* Updated vectors. */
void    CA3_update          (float  deltaTime);

/* Calculates and returns the view matrix */
void    CA3_getViewMatrix   (mat4 matrix);

#endif
