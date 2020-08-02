#include "object.h"

int     OBJ_add             (char *name, float x, float y, float z) {
    ++numObjects;
    objectList  =   realloc(objectList, numObjects * sizeof(struct Object));
    objectList[numObjects - 1].name =   name;
    
    /* Check if object is already existing, copy over values but set another spawn position. */
    for     (int i = 0; i < numObjects - 1; ++i) {
        if  (strcmp(objectList[i].name, name) == 0) {
            objectList[numObjects - 1].type         =   objectList[i].type;
            objectList[numObjects - 1].textureId    =   objectList[i].textureId;
            objectList[numObjects - 1].modelId      =   objectList[i].modelId;
            objectList[numObjects - 1].shaderId     =   objectList[i].shaderId;
            MAT_initMat4(objectList[numObjects - 1].modelMatrix);
            MAT_translateMatrix(objectList[numObjects - 1].modelMatrix, (vec3){x, y, z});
            return numObjects - 1;
        }
        else {
            continue;
        }
    }
    
    /* Construct a new object. */
    char    texturePath         [100];
    char    modelPath           [100];
    char    vertexShaderPath    [100];
    char    fragmentShaderPath  [100];

    //RMG_getTexture(texturePath, name);
    //RMG_getModel(modelPath, name);
    //RMG_getVertexShader(vertexShaderPath, name);
    //RMG_getFragmentShader(fragmentShaderPath, name);
    
    //objectList[numObjects - 1].type         =   RMG_getType(name);
    objectList[numObjects - 1].textureId    =   TEX_create(texturePath);
    
    MAT_initMat4(objectList[numObjects - 1].modelMatrix);
    MAT_translateMatrix(objectList[numObjects - 1].modelMatrix, (vec3){x, y, z});
    
    if  (objectList[numObjects - 1].type == 0) {
        objectList[numObjects - 1].modelId  =   MOD_create(modelPath, 0);
    }
    
    else if (objectList[numObjects - 1].type == 1) {
        objectList[numObjects - 1].modelId  =   MOD_create(modelPath, 1);
        float   scaleFactorX    =   (TEX_getWidth(objectList[numObjects - 1].textureId) / GWD_getScreenSizeX()) - 1;
        float   scaleFactorY    =   (TEX_getHeight(objectList[numObjects - 1].textureId) / GWD_getScreenSizeY()) - 1;
        vec3    scale           =   {.x = scaleFactorX, .y = scaleFactorY};
        MAT_scaleMatrix(objectList[numObjects - 1].modelMatrix, scale);
    }

    objectList[numObjects - 1].shaderId     =   SHA_create(vertexShaderPath, fragmentShaderPath);
    return numObjects - 1;
}

void    OBJ_draw            (int  mode) {
    for     (int i = 0; i < numObjects; ++i) {
        if      (mode != objectList[i].type)
            continue;
        
        SHA_bind(objectList[i].shaderId);
        
        mat4    projectionMatrix;
        if  (objectList[i].type == 0)
            PRJ_getPerspectiveMatrix(projectionMatrix);
        if  (objectList[i].type == 1) 
            PRJ_getOrthogonalMatrix(projectionMatrix);
        
        mat4    viewMatrix;
        if  (objectList[i].type == 0)
            CA3_getViewMatrix(viewMatrix);
        if  (objectList[i].type == 1)
            CA2_getViewMatrix(viewMatrix);
        
        SHA_pushMatrix("viewMatrix", viewMatrix);
        SHA_pushMatrix("projectionMatrix", projectionMatrix);
        SHA_pushMatrix("modelMatrix", objectList[i].modelMatrix);
        
        TEX_bind(objectList[i].textureId);
        MOD_draw(objectList[i].modelId);
     }
}

void    OBJ_transform       (int id, float x, float y, float z) {
    MAT_translateMatrix(objectList[id].modelMatrix, (vec3){x - objectList[id].position.x, y - objectList[id].position.y, z - objectList[id].position.z});
    objectList[id].position =   (vec3){x, y, z};
}

void    OBJ_scale           (int id, float x, float y, float z) {
    MAT_scaleMatrix(objectList[id].modelMatrix, (vec3){x - objectList[id].scale.x, y - objectList[id].scale.y, z - objectList[id].scale.z});
}

void    OBJ_rotate          (int id, float degrees, float x, float y, float z) {
    objectList[id].rotation =   (vec4){degrees, x, y, z};
    MAT_rotateMatrix(objectList[id].modelMatrix, degrees, (vec3){x, y, z});
}

void    OBJ_translate       (int id, float x, float y, float z) {
    objectList[id].position =   (vec3){objectList[id].position.x + x, objectList[id].position.y + y, objectList[id].position.z + z};
    MAT_translateMatrix(objectList[id].modelMatrix, (vec3){x, y, z});
}

void    OBJ_addScale        (int id, float x, float y, float z) {
    objectList[id].scale    =   (vec3){objectList[id].scale.x + x, objectList[id].scale.y + y, objectList[id].scale.z + z};
    MAT_scaleMatrix(objectList[id].modelMatrix, (vec3){x, y, z});
}

void    OBJ_addRotate       (int id, float degrees, float x, float y, float z) {
    float   angleT  =   degrees + objectList[id].rotation.x;
    vec3    rot     =   {.x = (x * degrees + objectList[id].rotation.x * objectList[id].rotation.w) / angleT,
                        .y = (y * degrees + objectList[id].rotation.y * objectList[id].rotation.w) / angleT,
                        .z = (z * degrees + objectList[id].rotation.z * objectList[id].rotation.w) / angleT};
    MAT_rotateMatrix(objectList[id].modelMatrix, angleT, rot);
    objectList[id].rotation =   (vec4){angleT, rot.x, rot.y, rot.z};
}

void    OBJ_remove          (int id) {

}

void    OBJ_free            () {

}

