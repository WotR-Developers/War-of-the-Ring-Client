/* This file is responsible for returning perspective and orthogonal matrices. */

#ifndef FOURTH_AGE_CLIENT_PROJECTION
#define FOURTH_AGE_CLIENT_PROJECTION

#include "../libs/maths.h"

/* Contains the global FOV value for the perspective matrix. */
float   fov3d;

/* The min clip spaces for the orthogonal and perspective matrices. */
float   minClipSpace2d;
float   minClipSpace3d;

/* The max clip spaces for the orthogonal and perspective matrices. */
float   maxClipSpace2d;
float   maxClipSpace3d;

/* The aspect ratio of the screen. */
float   aspectRatio;

/* Sets the fov3d value. */
void    PRJ_setFov3d        (float  fov);

/* Sets the min clip space for the orthogonal matrix. */
void    PRJ_setMinClipSpace2d   (float  clipSpace);

/* Sets the max clip space for the orthogonal matrix. */
void    PRJ_setMaxClipSpace2d   (float  clipSpace);

/* Sets the min clip space for the perspective matrix. */
void    PRJ_setMinClipSpace3d   (float  clipSpace);

/* Sets the max clip space for the perspective matrix. */
void    PRJ_setMaxClipSpace3d   (float  clipSpace);

/* Sets the aspectRatio variable by the given value. */
void    PRJ_setAspectRatio      (float  aspectRat);

/* Calculates and returns a perspective matrix. */
void    PRJ_getPerspectiveMatrix    (mat4   matrix);

/* Calculates and returns an orthogonal matrix. */
void    PRJ_getOrthogonalMatrix     (mat4   matrix);

#endif
