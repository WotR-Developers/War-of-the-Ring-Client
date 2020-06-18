#include "projection.h"

void    PRJ_initProjection  (float  aspRat) {
    fov = 45.0f;
    aspectRatio = aspRat;
    qsrPerspectiveMat4f(&projPerspectiveMatrix, FOV_3D, aspRat, NEAREST, FAREST);
}

void    PRJ_setOrthogonal   () {
    mode = 0;
}

void    PRJ_setPerspective  () {
    mode = 1;
}

void    PRJ_zoom            (float  yoffset) {
    if  (mode == 0) {
        fov -= yoffset;
        if      (fov < 1.0f)
            fov = 1.0f;
        else if     (fov > 45.0f)
            fov = 45.0f;
    }
    else {
        printf("[DEBUG] Tried to Change FOV in 3D Mode\n");
    }
}

QsrMat4f    PRJ_returnProjection    () {
    if      (mode == 0) {
        /* Return and recalculate orthogonal matrix. */
        //qsrOrthogonalMat4f(*projOrthogonalMatrix, fov, aspectRatio, NEAREST, FAREST);
        return projOrthogonalMatrix;
    }
    else if     (mode == 1) {   
        /* Return perspective matrix. */
        return projPerspectiveMatrix;
    }
}
