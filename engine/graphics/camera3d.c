#include "camera3d.h"

void    CA3_initCamera     () {
    cameraPosition.x    =   0.0f;
    cameraPosition.y    =   1.0f;
    cameraPosition.z    =   0.0f;
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
    cameraFront     =   qsrScaleVec3f(cameraFront, movementSpeed);
    cameraPosition  =   qsrAddVec3f(cameraPosition, cameraFront);
}

void    CA3_moveBack    () {
    cameraFront     =   qsrScaleVec3f(cameraFront, movementSpeed);
    cameraPosition  =   qsrSubVec3f(cameraPosition, cameraFront);
}

void    CA3_strafeRight () {
    QsrVec3f temp;
    temp = qsrNormalizeVec3f(qsrCrossVec3f(cameraFront, cameraUp));
    temp = qsrScaleVec3f(temp, movementSpeed);
    cameraPosition = qsrAddVec3f(cameraPosition, temp);
}

void    CA3_strafeLeft  () {
    QsrVec3f temp;
    temp = qsrNormalizeVec3f(qsrCrossVec3f(cameraFront, cameraUp));
    temp = qsrScaleVec3f(temp, movementSpeed);
    cameraPosition = qsrSubVec3f(cameraPosition, temp);
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

QsrMat4f    CA3_getViewMatrix   () {
    cameraFront.x       =   cosf(qsrDegToRadf(yaw)) * cosf(qsrDegToRadf(pitch));
    cameraFront.y       =   sinf(qsrDegToRadf(pitch));
    cameraFront.z       =   sinf(qsrDegToRadf(yaw)) * cosf(qsrDegToRadf(pitch));
    cameraFront         =   qsrNormalizeVec3f(cameraFront);
    cameraRight         =   qsrNormalizeVec3f(qsrCrossVec3f(cameraFront, worldUp));
    cameraRight         =   qsrNormalizeVec3f(cameraRight);
    cameraUp            =   qsrNormalizeVec3f(qsrCrossVec3f(cameraRight, cameraFront));
    cameraUp            =   qsrNormalizeVec3f(cameraUp);
    QsrVec3f tempVector;
    tempVector      =   qsrAddVec3f(cameraPosition, cameraFront);
    QsrMat4f lookAt;
    qsrMat4fSetToLookAt(&lookAt, &cameraPosition, &cameraFront, &cameraRight, &cameraUp);
    return lookAt;
}
