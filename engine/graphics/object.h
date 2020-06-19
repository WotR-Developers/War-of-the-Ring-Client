/* Here are the functions to create new objects and delete existing as well as drawing objects.
 * It gets the paths to construct the OpenGL data and necessary information from the ResourceManager.
 * It uses the files in loaders/ to create the data.
 * It uses the matrices libraries to provide transform functions.*/

#ifndef THE_FOURTH_AGE_OBJECT_H
#define THE_FOURTH_AGE_OBJECT_H

/* Include the loaders to load the necessary data into the object structure. */
#include "loaders/model.h"
#include "loaders/animation.h"
#include "loaders/shader.h"
#include "loaders/texture.h"

/* Include the ResourceManager to retrieve the paths to pass them to the loaders. */
#include "../../libs/resourcemanager.h"

/* Include the maths library to calculate the model matrix. */
#include "../../libs/maths/quasar/matrix/mat4.h"
#include "../../libs/maths/quasar/vector/vec3.h"

/* The number of objects. */
int     objectCount;

/* Contains all the necessary object information and OpenGL data. */
struct Object {
    QsrVec3f    position;
    QsrVec3f    scale;
    QsrVec3f    rotation;
    int     modelID;    // To get access to the correct model struct.
    int     textureID;  // To get access to the correct texture struct.
    int     shaderID;   // To get access to the correct shader struct.
    int     existing;   // If this object is still exsisting. 0 = false, 1 = true.
};

/* A list of objects for faster access using the ID. */
struct  Object*         objectList;

/* Fills in the Object struct for a new object using the ResourceManager and adds it to objectList.
 * Transforms it to the given location.
 * Returns the ID of the object.
 * Constructs the OpenGL data using loaders.
 * Adds 1 to the objectCount. */
int     OBJ_addObject       (char *name, float x, float y, float z);

/* Draws objects if they fit into the given mode(2D or 3D or UI)..
 * Calculates the model matrix and passes it to shader. */
void    OBJ_drawObjects     (int  mode);

/* Transforms the object with the given ID to the given location. */
void    OBJ_transformObject (int id, float x, float y, float z);

/* Scales the object with the given ID to the given scale. */
void    OBJ_scaleObject     (int id, float x, float y, float z);

/* Rotates the object with the given ID around the given axis by the given degrees. */
void    OBJ_rotateObject    (int id, float x, float y, float z);

/* Translates the object with the given ID by the given vector. */
void    OBJ_translateObject (int id, float x, float y, float z);

/* Adds a scale to the object with the given ID by the given vector. */
void    OBJ_scaleAddObject  (int id, float x, float y, float z);

/* Adds a rotation to the object with the given ID by the given axis with the given degrees. */
void    OBJ_rotateAddObject (int id, float degrees, float x, float y, float z);

/* Removes the object with the given ID and frees it from the objectList.
 * Removes 1 from the objectCount.*/
void    OBJ_removeObject    (int id);

/* Frees dynamic memory, including loaders */
void    OBJ_free            ();

#endif //THE_FOURTH_AGE_OBJECT_H
