#include "object.h"

int     OBJ_addObject       (char* name, float x, float y, float z) {
    ++objectCount;
    objectList   =   realloc(objectList, objectCount * sizeof(struct Object));
    objectList[objectCount - 1].position    =   {x, y, z};
    objectList[objectCount - 1].scale       =   {1.0f, 1.0f, 1.0f};
    objectList[objectCount - 1].rotation    =   {0.0f, 0.0f, 0.0f};
    objectList[objectCount - 1].textureID   =   TEX_genTexture  (RMG_getTexture(name));
    objectList[objectCount - 1].shaderID    =   SHA_genShader   (RMG_getShader(name));
    objectList[objectCount - 1].modelID     =   PMF_loadModel   (RMG_getModel(name));
    objectList[objectCount - 1].existing    =   1;
    return objectCount - 1;
}

void    OBJ_drawObjects     (int    mode){
    for     (int i = 0; i < objectCount; ++i) {
        if  (objectList[i].existing == 0) 
            continue;
        PMF_bindShader  (objectList[i].shaderID);
        int     shaderCache[objectCount - 1];
        newShader = 1;
        for     (int j = 0; j < (i-1); j++) {
            if  (shaderCache[j] == objectList[i].shaderID)
                newShader = 0;
        }
        shaderCache[i] = objectList[i].shaderID;
        mat4 modelMatrix;
        qsrTranslateMat4fVec(modelMatrix, *objectList[i].position);
        qsrRotateMat4fVec   (modelMatrix, *objectList[i].rotate);
        qsrScaleMat4fVec    (modelMatrix, *objectList[i].scale);
        SHA_pushMatrix  ("modelMatrix", modelMatrix);
        if  (newShader) {
            SHA_pushMatrix  ("projectionMatrix", PRJ_returnProjection());
            if  (mode == 0) {
                SHA_pushMatrix("viewMatrix", CA2_getViewMatrix());
            }
            else if     (mode == 1) {
                SHA_pushMatrix("viewMatrix", CA3_getViewMatrix());
            }
            else {
                printf("[ERROR] Unknown mode in object source\n");
            }
        }
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

void    OBJ_rotateObject        (int    id, float  x, float    y, float    z) {
    objectList[id].rotation =   {x, y, z};
}

void    OBJ_translateObject     (int    id, float   x, float    y, float    z) {  
    objectList[id].position.x   +=  x;
    objectList[id].position.y   +=  y;
    objectList[id].position.z   +=  z;
}

void    OBJ_scaleAddObject      (int    id, float   x, float    y, float    z) {
    objectList[id].scale.x  +=  x;
    objectList[id].scale.y  +=  y;
    objectList[id].scale.z  +=  z;
}

void    OBJ_rotateAddObject     (int    id, float   degrees, float  x, float    y, float    z) {
    objectList[id].rotation.x +=  x;
    objectList[id].rotation.y +=  y;
    objectList[id].rotation.z +=  z;
}

void    OBJ_removeObject        (int id) {
    objectList[id].existing =   0;
}

void    OBJ_free                () {
    free(objectList);
    TEX_free();
    SHA_free();
    PMF_free();
}

