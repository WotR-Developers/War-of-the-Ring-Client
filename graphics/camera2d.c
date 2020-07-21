#include "camera2d.h"

void    CA2_initCamera     () {
    cameraPosition2d.x  =   0.0f;
    cameraPosition2d.y  =   1.0f;
    cameraPosition2d.z  =   0.0f;
    cameraFront2d.x     =   0.0f;
    cameraFront2d.y     =   0.0f;
    cameraFront2d.z     =   -1.0f;
    cameraUp2d.x        =   0.0f;
    cameraUp2d.y        =   1.0f;
    cameraUp2d.z        =   0.0f;
    worldUp2d.x         =   0.0f;
    worldUp2d.y         =   1.0f;
    worldUp2d.z         =   0.0f;
    movementSpeed2d  =   0.05f;
    mouseSensitivity2d   =   0.1f;
}

void    CA2_moveForward () {
    cameraPosition2d.x  += cameraFront2d.x * movementSpeed2d;
    cameraPosition2d.z  += cameraFront2d.z * movementSpeed2d;
}

void    CA2_moveBackward    () {
    cameraPosition2d.x  -= cameraFront2d.x * movementSpeed2d;
    cameraPosition2d.z  -= cameraFront2d.z * movementSpeed2d;
}

void    CA2_strafeRight () {
    cameraPosition2d.x  += cameraRight2d.x * movementSpeed2d;
    cameraPosition2d.z  += cameraRight2d.z * movementSpeed2d;
}

void    CA2_strafeLeft  () {
    cameraPosition2d.x  -= cameraRight2d.x * movementSpeed2d;
    cameraPosition2d.z  -= cameraRight2d.z * movementSpeed2d;
}

void    CA2_rotateRight () {
    yaw2d += 1.0f;
}

void    CA2_rotateLeft  (){
    yaw2d -= 1.0f;
}

void    CA2_updateCamera    () {
    cameraFront2d       =   MAT_getNormalizedVec3(cameraFront2d);
    cameraRight2d       =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraFront2d, worldUp2d));
    cameraUp2d          =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraRight2d, cameraFront2d));
}

void    CA2_getViewMatrix   (mat4   viewMatrix) {
    MAT_getViewMatrix(viewMatrix, cameraPosition2d, MAT_getAddVec3(cameraPosition2d, cameraFront2d), cameraUp2d);
}
