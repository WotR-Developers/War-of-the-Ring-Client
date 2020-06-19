#include "camera2d.h"

void    CA2_initCam     () {
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

void    CA2_moveBack    () {
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

QsrMat4f    CA2_getViewMatrix   () {
    cameraFront2d.x     =   cosf(qsrDegToRadf(yaw2d)) * cosf(qsrDegToRadf(pitch2d));
    cameraFront2d.y     =   sinf(qsrDegToRadf(pitch2d));
    cameraFront2d.z     =   sinf(qsrDegToRadf(yaw2d)) * cosf(qsrDegToRadf(pitch2d));
    cameraFront2d       =   qsrNormalizeVec3f(cameraFront2d);
    cameraRight2d       =   qsrNormalizeVec3f(qsrCrossVec3f(cameraFront2d, worldUp2d));
    cameraRight2d       =   qsrNormalizeVec3f(cameraRight2d);
    cameraUp2d          =   qsrNormalizeVec3f(qsrCrossVec3f(cameraRight2d, cameraFront2d));
    cameraUp2d          =   qsrNormalizeVec3f(cameraUp2d);
    QsrVec3f tempVector;
    tempVector          =   qsrAddVec3f(cameraPosition2d, cameraFront2d);
    QsrMat4f lookAt;
    qsrMat4fSetToLookAt(&lookAt, &cameraPosition2d, &cameraFront2d, &cameraRight2d, &cameraUp2d);
    return lookAt;
}
