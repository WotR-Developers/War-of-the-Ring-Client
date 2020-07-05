#include "camera3d.h"

void    CA3_initCamera     () {
    cameraPosition.x    =   0.0f;
    cameraPosition.y    =   0.0f;
    cameraPosition.z    =   -3.0f;
    cameraFront.x       =   0.0f;
    cameraFront.y       =   0.0f;
    cameraFront.z       =   -1.0f;
    cameraUp.x          =   0.0f;
    cameraUp.y          =   1.0f;
    cameraUp.z          =   0.0f;
    worldUp.x           =   0.0f;
    worldUp.y           =   1.0f;
    worldUp.z           =   0.0f;
    movementSpeed   =   0.05f;
    mouseSensitivity   =   0.1f;
}

void    CA3_moveForward () {
    MAT_scaleVec3(&cameraFront, movementSpeed);
    MAT_addVec3(&cameraPosition, cameraFront);
}

void    CA3_moveBack    () {
    MAT_scaleVec3(&cameraFront, movementSpeed);
    MAT_subVec3(&cameraPosition, cameraFront);
}

void    CA3_strafeRight () {
    vec3 temp;
    temp = MAT_getNormalizedVec3(MAT_getCrossVec3(cameraFront, cameraUp));
    MAT_scaleVec3(&temp, movementSpeed);
    MAT_addVec3(&cameraPosition, temp);
}

void    CA3_strafeLeft  () {
    vec3 temp;
    temp = MAT_getNormalizedVec3(MAT_getCrossVec3(cameraFront, cameraUp));
    MAT_scaleVec3(&temp, movementSpeed);
    MAT_subVec3(&cameraPosition, temp);
}

void    CA3_rotateRight () {
    yaw += 1.0f;
}

void    CA3_rotateLeft  (){
    yaw -= 1.0f;
}

void    CA3_processMouse    (double     xpos, double    ypos) {
    xOffSet = xpos - lastX;
    yOffSet = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    xOffSet *= mouseSensitivity;
    yOffSet *= mouseSensitivity;
    yaw += xOffSet;
    pitch += yOffSet;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f; 
}

void    CA3_getViewMatrix   (mat4 matrix) {
    cameraFront.x       =   cos(MAT_degToRad(yaw)) * cos(MAT_degToRad(pitch));
    cameraFront.y       =   sin(MAT_degToRad(pitch));
    cameraFront.z       =   sin(MAT_degToRad(yaw)) * cos(MAT_degToRad(pitch));
    cameraFront         =   MAT_getNormalizedVec3(cameraFront);
    cameraRight         =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraFront, worldUp));
    cameraRight         =   MAT_getNormalizedVec3(cameraRight);
    cameraUp            =   MAT_getNormalizedVec3(MAT_getCrossVec3(cameraRight, cameraFront));
    cameraUp            =   MAT_getNormalizedVec3(cameraUp);
    vec3    tempVector;
    tempVector      =   MAT_getAddVec3(cameraPosition, cameraFront);
    MAT_getViewMatrix(matrix, cameraPosition, cameraFront, cameraUp);
}
