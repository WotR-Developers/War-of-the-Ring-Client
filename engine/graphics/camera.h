/* Contains the movement/strafe and functions of the camera */

#ifndef THE_FOURTH_AGE_CAMERA_H
#define THE_FOURTH_AGE_CAMERA_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include <maths.h>

/* The matrices to be calculated and returned */
mat4 viewMatrix;

/* The camera vectors for the view matrix calculation */
vec3 worldUp;
vec3 cameraPosition;
vec3 cameraFront;
vec3 cameraUp;
vec3 cameraRight;

/* The camera variables to be adjusted */
float yaw;
float pitch;
float movementSpeed;
float mouseSensitivity;
float xOffSet;
float yOffSet;

/* Initializes variables and matrices to default; to be called at start of program */
void CAM_initCamera             ();

/* Moves the camera forwards */
void CAM_moveForward            ();

/* Moves the camera backwards. */
void CAM_moveBackward           ();

/* Moves the camera leftwards. */
void CAM_strafeLeft             ();

/* Moves the camera rightwards. */
void CAM_strafeRight            ();

/* Rotates the camera to the left. Only called in 2D mode. */
void CAM_rotateLeft             ();

/* Rotates the camera to the right. Only called in 2D mode. */
void CAM_rotateRight            ();

/* Resets the matrices and variables to default. Usually called if changed to 2D or 3D mode. */
void CAM_resetCamera            ();

/* Calculates and returns the view matrix */
mat4 CAM_getViewMatrix          ();

#endif //THE_FOURTH_AGE_CAMERA_H
