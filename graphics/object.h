/* Constructs new objects sets appropriate textures and shaders and models for them
 * passes all matrices to the shaders and calls the appropriate draw calls. */

#ifndef FOURTH_AGE_CLIENT_OBJECT
#define FOURTH_AGE_CLIENT_OBJECT

/* To call the loading of structs for the right objects. */
#include "../loaders/texture.h"
#include "../loaders/shader.h"
#include "../loaders/model.h"

/* To get the view matrices. */
#include "camera3d.h"
#include "camera2d.h"

/* To retrieve the paths and pass them on to the loaders. */
#include "../libs/resourcemanager.h"

/* To construct and pass the model matrix and get the necessary types. */
#include "../libs/maths.h"

/* To retrieve a projection matrix and pass it to the shader. */
#include "projection.h"

/* To get the screen sizes to calculate the 2D texture object size. */
#include "gamewindow.h"

/* To perform dynamic memory allocations. */
#include <stdlib.h>


/* An Object struct containing the loader IDs 
 * and the necessary information to construct a model matrix. */
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

/* An array of objects to access by ID. */
struct  Object*         objectList;

/* The total number counter of objects. */
int     numObjects;

/* Ads a new Object, if the type of this object has already been created copies the Loader IDs.
 * Returns the ID of the new object.
 * Moves the object to its spawn location. */
int     OBJ_add             (char *name, float x, float y, float z);

/* Iterates through the object list and draws every object, passes the uniforms to the shaders. */
void    OBJ_draw            (int  mode);

/* Transforms the object with the given ID to the given location. */
void    OBJ_transform       (int id, float x, float y, float z);

/* Scales the object with the given ID to the given size. */
void    OBJ_scale           (int id, float x, float y, float z);

/* Rotates the object with the given ID to the given degrees using x-y-z as the axis. */
void    OBJ_rotate          (int id, float degrees, float x, float y, float z);

/* Translates the object with the given ID by the given coordinates. */
void    OBJ_translate       (int id, float x, float y, float z);

/* Scales the object with the given ID by the given size. */
void    OBJ_addScale        (int id, float x, float y, float z);

/* Rotates the object with the given ID by the given degrees using x-y-z as the axis. */
void    OBJ_addRotate       (int id, float degrees, float x, float y, float z);

/* Removes the object with the given ID from the objectList. */
void    OBJ_remove          (int id);

/* Frees dynamically allocated memory. */
void    OBJ_free            ();

#endif
