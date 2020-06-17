#include "object.h"

int     OBJ_addObject       (char* name, float x, float y, float z) {
    ++objectCount;
    objectList   =   realloc(objectList, objectCount * sizeof(Object));
    objectList[objectCount - 1].position    =   {x, y, z};
    objectList[objectCount - 1].scale       =   {1.0f, 1.0f, 1.0f};
    objectList[objectCount - 1].rotation    =   {0.0f, 0.0f, 0.0f, 0.0f};
    objectList[objectCount - 1].textureID   =   TEX_genTexture  (path);
    objectList[objectCount - 1].shaderID    =   SHA_genShader   (path);
    objectList[objectCount - 1].modelID     =   PMF_loadModel   (path);
    objectList[objectCount - 1].existing    =   1;
    return objectCount - 1;
}

void    OBJ_drawObjects     (int    mode){
    for     (int i = 0; i < objectCount; ++i) {
        if  (objectList[i].existing == 0) 
            continue;
        PMF_bindShader  (objectList[i].shaderID);
        SHA_pushMatrix  ("modelMatrix", MAT_calculateModelMatrix(objectList[i].position, objectList[i].rotation, objectList[i].scale);
        TEX_bindTexture (objectList[i].textureID);
        PMF_drawModel   (objectList[i].modelID); 
    }
}

void    OBJ_transformObject     (int    id, float   x, float    y, float    z) {
    objectList[id].position =   {x, y, z}; 
}

void    OBJ_scaleObject         (int    id, float   x, float    y, float    z) {
    objectList[id].scale    =   {x, y, z};
}

void    OBJ_rotateObject        (int    id, float   degrees, float  x, float    y, float    z) {
    objectList[id].rotation =   {x, y, z, degrees};
}

void    OBJ_translateObject     (int    id, float   x, float    y, float    z) {
    objectList[id].position =   MAT_translateModelMatrix    (objectList[id].position, x, y, z);
}

void    OBJ_scaleAddObject      (int    id, float   x, float    y, float    z) {
    objectList[id].scale    =   MAT_scaleModelMatrix        (objectList[id].scale, x, y, z);
}

void    OBJ_rotateAddObject     (int    id, float   degrees, float  x, float    y, float    z) {
    objectList[id].rotation =   MAT_rotateModelMatrix       (objectList[id].rotation, x, y, z, degrees);
}

void    OBJ_removeObject        (int id) {
    objectList[id].existing =   0;
}


