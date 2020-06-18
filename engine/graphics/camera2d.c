#include "camera.h"

void    CA2_initCam     () {
    cameraPosition2d =   {0.0f, 1.0f, 0.0f};
    cameraFront2d    =   {0.0f, 0.0f, -1.0f};
    cameraUp2d       =   {0.0f, 1.0f, 0.0f};
    worldUp2d        =   {0.0f, 1.0f, 0.0f};
    movementSpeed2d  =   0.05f;
    mouseSensitivity2D   =   0.1f;
}

void    CA2_moveForward () {
    cameraPosition2d[0] += cameraFront2d[0] * movementSpeed2d;
    cameraPosition2d[2] += cameraFront2d[2] * movementSpeed2d;
}

void    CA2_moveBack    () {
    cameraPosition2d[0] -= cameraFront2d[0] * movementSpeed2d;
    cameraPosition2d[2] -= cameraFront2d[2] * movementSpeed2d;
}

void    CA2_strafeRight () {
    cameraPosition2d[0] += cameraRight2d[0] * movementSpeed2d;
    cameraPosition2d[2] += cameraRight2d[2] * movementSpeed2d;
}

void    CA2_strafeLeft  () {
    cameraPosition2d[0] -= cameraRight2d[0] * movementSpeed2d;
    cameraPosition2d[2] -= cameraRight2d[2] * movementSpeed2d;
}

void    CA2_rotateRight () {
    yaw2d += 1.0f;
}

void    CA2_rotateLeft  (){
    yaw2d -= 1.0f;
}

mat4    CA2_getViewMatrix   () {
    cameraFront2d[0]    =   cos(radians(yaw2d)) * cos(radians(pitch2d));
    cameraFront2d[1]    =   sin(radians(pitch2d));
    cameraFront2d[2]    =   sin(radians(yaw2d)) * cos(radians(pitch2d));
    normalize(cameraFront2d);
    cameraRight2d       =   normalize(cross(cameraFront2d, worldUp2d));
    normalize(cameraRight2d);
    cameraUp2d          =   normalize(cross(cameraRight2d, cameraFront2d));
    normalize(cameraUp2d);
    vec3 tempVector;
    tempVector      =   add(cameraPosition2d, cameraFront2d);
    return  lookAt(cameraPosition2d, tempVector, cameraUp2d);
}
