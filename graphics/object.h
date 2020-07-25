/* Constructs new objects sets appropriate textures and shaders and models for them
 * passes all matrices to the shaders. */

#ifndef FOURTH_AGE_CLIENT_OBJECT
#define FOURTH_AGE_CLIENT_OBJECT

/* To call the loading of structs for the right objects. */
#include "../loaders/texture.h"
#include "../loaders/shader.h"
#include "../loaders/model.h"

#include "camera3d.h"
#include "camera2d.h"
/* To retrieve the paths an pass them on to the loaders. */
#include "../libs/resourcemanager.h"

/* To pass on the model matrices. */
#include "../libs/maths.h"
#include "projection.h"

#include "gamewindow.h"

/* To perform dynamic memory allocations. */
#include <stdlib.h>

struct  Object {
    char*   name;
    int     type;
    int     textureId;
    int     modelId;
    unsigned    int     shaderId;
    vec3    position;
    vec3    scale;
    vec4    rotation;
    mat4    modelMatrix;
};

struct  Object*         objectList;

int     numObjects;

int     OBJ_add             (char *name, float x, float y, float z);

void    OBJ_draw            (int  mode);

void    OBJ_transform       (int id, float x, float y, float z);

void    OBJ_scale           (int id, float x, float y, float z);

void    OBJ_rotate          (int id, float degrees, float x, float y, float z);

void    OBJ_translate       (int id, float x, float y, float z);

void    OBJ_addScale        (int id, float x, float y, float z);

void    OBJ_addRotate       (int id, float degrees, float x, float y, float z);

void    OBJ_remove          (int id);

void    OBJ_free            ();

#endif
