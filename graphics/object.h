/* Constructs new objects sets appropriate textures and shaders and models for them
 * passes all matrices to the shaders. */

#ifndef FOURTH_AGE_CLIENT_OBJECT
#define FOURTH_AGE_CLIENT_OBJECT

/* To call the loading of structs for the right objects. */
#include "../loaders/texture.h"
#include "../loaders/shader.h"
#include "../loaders/model.h"

#include "camera3d.h"
/* To retrieve the paths an pass them on to the loaders. */
#include "../libs/resourcemanager.h"

/* To pass on the model matrices. */
#include "../libs/maths.h"

/* To perform dynamic memory allocations. */
#include <stdlib.h>

float objangle;
struct  Object {
    mat4    modelMatrix;
    int     textureId;
    int     modelId;
    int     shaderId;
};

struct  Object*         objectList;

int     numObjects;

int     OBJ_addObject       (char *name, float x, float y, float z);

void    OBJ_drawObjects     (int  mode);

void    OBJ_transformObject (int id, float x, float y, float z);

void    OBJ_scaleObject     (int id, float x, float y, float z);

void    OBJ_rotateObject    (int id, float x, float y, float z);

void    OBJ_translateObject (int id, float x, float y, float z);

void    OBJ_scaleAddObject  (int id, float x, float y, float z);

void    OBJ_rotateAddObject (int id, float degrees, float x, float y, float z);

void    OBJ_removeObject    (int id);

void    OBJ_free            ();

#endif
