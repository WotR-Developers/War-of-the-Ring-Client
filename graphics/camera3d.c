#include "camera3d.h"

void    CA3_init            () {
    movementSpeed       =   0.05f;
    mouseSensitivity    =   0.1f;
    cameraPosition      =   (vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f};
    cameraFront         =   (vec3){.x = 0.0f, .y = 0.0f, .z = -1.0f};
    cameraUp            =   (vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f};
    worldUp             =   (vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f};
}

void    CA3_moveForward     () {
    MAT_addVec3(&cameraPosition, MAT_getScaleVec3(cameraFront, movementSpeed));
}

void    CA3_moveBackward    () {
    MAT_subVec3(&cameraPosition, MAT_getScaleVec3(cameraFront, movementSpeed));
}

void    CA3_strafeRight () {
    MAT_addVec3(&cameraPosition, MAT_getScaleVec3(cameraRight, movementSpeed));
}

void    CA3_strafeLeft  () {
    MAT_subVec3(&cameraPosition, MAT_getScaleVec3(cameraRight, movementSpeed));
}

void    CA3_processMouse    (double     xpos, double    ypos) {
    yaw     +=  xpos * mouseSensitivity;
    pitch   -=  ypos * mouseSensitivity;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f; 
}

void    CA3_update          (float deltaTime) {
    cameraFront.x       =   cos(MAT_degToRad(pitch)) * cos(MAT_degToRad(yaw));
    cameraFront.y       =   sin(MAT_degToRad(pitch));
    cameraFront.z       =   cos(MAT_degToRad(pitch)) * sin(MAT_degToRad(yaw)); 
    cameraFront =   MAT_getNormalizedVec3(cameraFront);
    cameraRight =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraFront, worldUp));
    cameraUp    =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraRight, cameraFront));
    movementSpeed   =   0.05f * deltaTime;
}

void    CA3_getViewMatrix   (mat4 matrix) {
    MAT_getViewMatrix(matrix, cameraPosition, MAT_getAddVec3(cameraPosition, cameraFront), cameraUp);
}
