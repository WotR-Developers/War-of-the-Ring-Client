/* This file is responsible for loading PMF files */

#ifndef THE_FOURTH_AGE_MODEL_H
#define THE_FOURTH_AGE_MODEL_H

struct Vertex {
    float   x, y, z;
    float   normalX, normalY, normalZ;
    float   textureX, textureY;
};

/* A model structure with all necessary information to construct OpenGL data */
struct Model {
    const char*     path;                 // The path to the model file
    struct Vertex*  vertices;            // Array of vertices
    int             numVertices;          // Number of vertices
    unsigned int*   indices;      // Array of indices
    unsigned int    numIndices;    // Number of indices
};

/* List of models to access them quickly by ID */
struct  Model*   modelList;

/* Function which gets the path of the model
 * returns the ID of the model
 * sets the vertices, indices as well as their counts
 * If it has already been loaded returns the IDs*/
int     PMF_loadModel       (char *path, struct Vertex vertices[], unsigned int indices[], int *numVertices, unsigned int *numIndices);

/* Internal function to load the data of a PMF file */
void    loadPMF             (struct Model *currentModel);

/* Draws the Object and binds the OpenGl VAO */
void    PMF_drawModel       (int ID);

#endif //THE_FOURTH_AGE_MODEL_H
