#include "projection.h"

void    PRJ_getPerspectiveMatrix    (mat4   matrix, float  minClipSpace, float maxClipSpace, float aspectRatio) {
    MAT_getPerspectiveMatrix(matrix, minClipSpace, maxClipSpace, fov3d, aspectRatio);
}

void    PRJ_getOrthogonalMatrix     (mat4   matrix, float  minClipSpace, float maxClipSpace, float aspectRatio) {
    MAT_getOrthogonalMatrix(matrix, minClipSpace, maxClipSpace, fov2d, aspectRatio);
}

void    PRJ_increaseFov3d   () {
    ++fov3d;
}

void    PRJ_decreaseFov3d   () {
    --fov3d;
}

void    PRJ_setFov3d        (float  fov) {
    fov3d   =   fov;
}

void    PRJ_increaseFov2d   () {
    ++fov2d;
}

void    PRJ_decreaseFov2d   () {
    --fov2d;
}

void    PRJ_setFov2d        (float fov) {
    fov2d   =   fov;
}

