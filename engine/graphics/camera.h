/* Contains the movement/strafe/rotate and zoom functions of the camera
 * Calculates the view and projection matrix and returns them */

#ifndef THE_FOURTH_AGE_CAMERA_H
#define THE_FOURTH_AGE_CAMERA_H

/* Includes the maths file to be able to make vector and matrix calculations */
#include <maths.h>

/* Contains the current FOV to be used in the calculation of the projection matrix */
int fov = 0;

/* Contains the mode. 2D = 0 and 3D = 1 */
int mode = 0;

/* The matrices to be calculated and returned */
mat4 viewMatrix;
mat4 projectionMatrix;

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

/* Changes the mode to 2D or 3D */
void CAM_setMode                (int  mode);

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

/* Changes the FOV. Only called in 2D Mode. */
void CAM_zoomOut                ();

/* Changes the FOV. Only called in 2D Mode. */
void CAM_zoomIn                 ();

/* Resets the matrices and variables to default. Usually called if changed to 2D or 3D mode. */
void CAM_resetCamera            ();

/* Calculates and returns the view matrix */
mat4 CAM_getViewMatrix          ();

/* Calculates and returns the projection matrix */
mat4 CAM_getProjectionMatrix    ();

#endif //THE_FOURTH_AGE_CAMERA_H
