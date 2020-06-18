#include "camera.h"

void    CA3_initCam     () {
    cameraPosition  =   {0.0f, 1.0f, 0.0f};
    cameraFront     =   {0.0f, 0.0f, -1.0f};
    cameraUp        =   {0.0f, 1.0f, 0.0f};
    worldUp         =   {0.0f, 1.0f, 0.0f};
    movementSpeed   =   0.05f;
    mouseSensitivity   =   0.1f;
}

void    CA3_moveForward () {
    cameraFront     =   scale(cameraFront, movementSpeed);
    cameraPosition  =   add(cameraPosition, cameraFront);
}

void    CA3_moveBack    () {
    cameraFront     =   scale(cameraFront, movementSpeed);
    cameraPosition  =   sub(cameraPosition, cameraFront);
}

void    CA3_strafeRight () {
    vec3 temp;
    temp = normalize(cross(cameraFront, cameraUp));
    temp = scale(temp, movementSpeed);
    cameraPosition = add(cameraPosition, temp);
}

void    CA3_strafeLeft  () {
    vec3 temp;
    temp = normalize(cross(cameraFront, cameraUp));
    temp = scale(temp, movementSpeed);
    cameraPosition = sub(cameraPosition, temp);
}

void    CA3_rotateRight () {
    yaw += 1.0f;
}

void    CA3_rotateLeft  (){
    yaw -= 1.0f;
}

mat4    CA3_getViewMatrix   () {
    cameraFront[0]      =   cos(radians(yaw)) * cos(radians(pitch));
    cameraFront[1]      =   sin(radians(pitch));
    cameraFront[2]      =   sin(radians(yaw)) * cos(radians(pitch));
    normalize(cameraFront);
    cameraRight         =   normalize(cross(cameraFront, worldUp));
    normalize(cameraRight);
    cameraUp            =   normalize(cross(cameraRight, cameraFront));
    normalize(cameraUp);
    vec3 tempVector;
    tempVector      =   add(cameraPosition, cameraFront);
    return  lookAt(cameraPosition, tempVector, cameraUp);
}
