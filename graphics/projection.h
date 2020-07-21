/* This file is responsible for returning perspective and orthogonal matrices. */

#ifndef FOURTH_AGE_CLIENT_PROJECTION
#define FOURTH_AGE_CLIENT_PROJECTION

#include "../libs/maths.h"

float   fov2d;
float   fov3d;

float   minClipSpace2d;
float   minClipSpace3d;

float   maxClipSpace2d;
float   maxClipSpace3d;

float   aspectRatio;

void    PRJ_increaseFov3d   ();

void    PRJ_decreaseFov3d   ();

void    PRJ_setFov3d        (float  fov);

void    PRJ_increaseFov2d   ();

void    PRJ_decreaseFov2d   ();

void    PRJ_setMinClipSpace2d   (float  clipSpace);

void    PRJ_setMaxClipSpace2d   (float  clipSpace);

void    PRJ_setMinClipSpace3d   (float  clipSpace);

void    PRJ_setMaxClipSpace3d   (float  clipSpace);

void    PRJ_setAspectRatio      (float  aspectRat);

void    PRJ_getPerspectiveMatrix    (mat4   matrix);

void    PRJ_getOrthogonalMatrix     (mat4   matrix);

#endif
