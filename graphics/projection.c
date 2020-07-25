#include "projection.h"

void    PRJ_getPerspectiveMatrix    (mat4   matrix) {
    MAT_getPerspectiveMatrix(matrix, minClipSpace3d, maxClipSpace3d, fov3d, aspectRatio);
}

void    PRJ_getOrthogonalMatrix     (mat4   matrix) {
    MAT_getOrthogonalMatrix(matrix, 1.0f, -1.0f, minClipSpace2d, maxClipSpace2d);
}

void    PRJ_setFov3d        (float  fov) {
    fov3d   =   fov;
}

void    PRJ_setMinClipSpace2d   (float  clipSpace) {
    minClipSpace2d  =   clipSpace;
}

void    PRJ_setMaxClipSpace2d   (float  clipSpace) {
    maxClipSpace2d  =   clipSpace;
}

void    PRJ_setMinClipSpace3d   (float  clipSpace) {
    minClipSpace3d  =   clipSpace;
}

void    PRJ_setMaxClipSpace3d   (float  clipSpace) {
    maxClipSpace3d  =   clipSpace;
}

void    PRJ_setAspectRatio      (float  aspectRat) {
    aspectRatio     =   aspectRat;
}

