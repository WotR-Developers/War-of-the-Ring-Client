#include "camera2d.h"

void    CA2_initCam     () {
    cameraPosition2d =   {0.0f, 1.0f, 0.0f};
    cameraFront2d    =   {0.0f, 0.0f, -1.0f};
    cameraUp2d       =   {0.0f, 1.0f, 0.0f};
    worldUp2d        =   {0.0f, 1.0f, 0.0f};
    movementSpeed2d  =   0.05f;
    mouseSensitivity2D   =   0.1f;
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

mat4    CA2_getViewMatrix   () {
    cameraFront2d.x     =   cosf(qsrDegToRadf(yaw2d)) * cosf(qsrDegToRadf(pitch2d));
    cameraFront2d.y     =   sinf(qsrDegRoRadf(pitch2d));
    cameraFront2d.z     =   sinf(qsrDegToRadf(yaw2d)) * cosf(qsrDegToRadf(pitch2d));
    cameraFront2d       =   qsrNormalizeVec3f(&cameraFront2d);
    cameraRight2d       =   qsrNormalizeVec3f(cross(cameraFront2d, worldUp2d));
    qsrNormalizeVec3f(cameraRight2d);
    cameraUp2d          =   qsrNormalizeVec3f(cross(cameraRight2d, cameraFront2d));
    qsrNormalizeVec3f(cameraUp2d);
    qsrVec3f tempVector;
    tempVector          =   add(cameraPosition2d, cameraFront2d);
    qsrMat4f lookAt;
    qsrMat4fSetToLookAt(lookAt, cameraPosition2d, cameraFront2d, cameraRight2d, cameraUp2d);
    return lookAt;
}
