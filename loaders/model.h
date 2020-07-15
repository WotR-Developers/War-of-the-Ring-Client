/* This file is responsible for loading PMF files */

#ifndef FOURTH_AGE_MODEL
#define FOURTH_AGE_MODEL

/* For memory management. */
#include <stdlib.h>

/* To create GL data. */
#include <GL/glew.h>

/* To make string comparisons. */
#include <string.h>

/* To read from file and write debug log. */
#include <stdio.h>

struct Vertex {
    float   x, y, z;
    float   normalX, normalY, normalZ;
    float   textureX, textureY;
};

/* A model structure with all necessary information to construct OpenGL data */
struct Model {
    const char*     path;               // The path to the model file
    unsigned int    VAO;                // Vertex Array Object
    unsigned int    VBO;                // Vertex Buffer Object
    unsigned int    EBO;                // Element Buffer Object
    int             type;               // 0 = 2D, 1 = 3D
    unsigned int    numIndices;
};

/* List of models to access them quickly by ID */
struct  Model*   modelList;

/* To calculate the current ID. */
int     numModels;

/* Function which gets the path of the model
 * returns the ID of the model
 * If it has already been loaded returns the IDs*/
int     MOD_loadModel       (char*  path, int   type);

/* Internal function to load the data of a PMF file */
void    loadPMF             (int    id);

/* Draws the Object and binds the OpenGl VAO */
void    MOD_drawModel       (int    id);

/* Frees dynamic memory. */
void    MOD_free            ();

#endif
