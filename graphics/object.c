#include "object.h"

int     OBJ_addObject       (char *name, float x, float y, float z) {
    ++numObjects;
    objectList  =   realloc(objectList, numObjects * sizeof(struct Object));
    char    texturePath[100];
    char    modelPath[100];
    char    vertexShaderPath[100];
    char    fragmentShaderPath[100];
    RMG_getTexture(texturePath, name);
    RMG_getModel(modelPath, name);
    RMG_getVertexShader(vertexShaderPath, name);
    RMG_getFragmentShader(fragmentShaderPath, name);
    objectList[numObjects - 1].textureId    =   TEX_genTexture(texturePath);
    objectList[numObjects - 1].modelId      =   MOD_loadModel(modelPath, 0);
    objectList[numObjects - 1].shaderId     =   SHA_genShader(vertexShaderPath, fragmentShaderPath);
    return numObjects - 1;
}

void    OBJ_drawObjects     (int  mode) {
     for    (int i = 0; i < numObjects; ++i) {
        SHA_bindShader(objectList[i].shaderId);
        mat4    projectionMatrix;
        MAT_getPerspectiveMatrix(projectionMatrix, 0.1f, 100.0f, 45.0f, 1920.0f / 1080.0f);
        mat4    viewMatrix;
        CA3_getViewMatrix(viewMatrix);
        SHA_pushMatrix("viewMatrix", viewMatrix);
        SHA_pushMatrix("projectionMatrix", projectionMatrix);        
        TEX_bindTexture(objectList[i].textureId);
        MOD_drawModel(objectList[i].modelId);
     }
}

void    OBJ_transformObject (int id, float x, float y, float z) {

}

void    OBJ_scaleObject     (int id, float x, float y, float z) {

}

void    OBJ_rotateObject    (int id, float x, float y, float z) {

}

void    OBJ_translateObject (int id, float x, float y, float z) {

}

void    OBJ_scaleAddObject  (int id, float x, float y, float z) {

}

void    OBJ_rotateAddObject (int id, float degrees, float x, float y, float z) {

}

void    OBJ_removeObject    (int id) {

}

void    OBJ_free            () {

}

