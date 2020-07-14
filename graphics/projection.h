/* This file is responsible for returning perspective and orthogonal matrices. */

#ifndef FOURTH_AGE_CLIENT_PROJECTION
#define FOURTH_AGE_CLIENT_PROJECTION

#include "../libs/maths.h"

float   fov2d;
float   fov3d;

void    PRJ_increaseFov3d   ();

void    PRJ_decreaseFov3d   ();

void    PRJ_setFov3d        (float  fov);

void    PRJ_increaseFov2d   ();

void    PRJ_decreaseFov2d   ();

void    PRJ_setFov2d        (float  fov);

void    PRJ_getPerspectiveMatrix    (mat4   matrix, float  minClipSpace, float maxClipSpace, float aspectRatio);

void    PRJ_getOrthogonalMatrix     (mat4   matrix, float  minClipSpace, float maxClipSpace, float aspectRatio);

#endif
