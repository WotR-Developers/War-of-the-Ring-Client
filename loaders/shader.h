/* This file is responsible for the binding and unbinding of shaders as well as providing a function to push
 * matrices to the shader */

#ifndef FOURTH_AGE_SHADER
#define FOURTH_AGE_SHADER

/* To have access to OpenGL functions. */
#include <GL/glew.h>

/* To have aceess to memory management. */
#include <stdlib.h>
#include <string.h>

/* To do string comparisons. */
#include <string.h>

/* To read files and make debug log. */
#include <stdio.h>

#include <stdlib.h>

/* To push matrices as uniforms. */
#include "../libs/maths.h"

struct Uniform {
    char            name[25];
    int             uniformLocation;
};

/* A structure containing the shader name and the shader program ID */
struct Shader {
    const char*     vertexName;     // The name of the vertex shader
    const char*     fragmentName;   // The name of the fragment shader
    unsigned int    shaderProgram;  // The shader program ID
    struct  Uniform*    cachedUniforms;
    int             uniformCount;
};

/* List of shaders to be quickly used with the ID */
struct  Shader*     shaderList;

/* To generate the ID */
unsigned    int     numShaders;

/* Current Shader ID to know which Shader to pass to the uniforms */
unsigned    int     currentShader;

/* Reads shader and returns the ID.
 * If it is already in the list, returns the ID */
unsigned int     SHA_genShader       (char*  vertexShaderPath, char* fragmentShaderPath);

/* Binds a shader to OpenGL */
void    SHA_bindShader      (unsigned int    id);

/* Pushes matrix to the shader with the given uniform
 * provided by the name parameter. */
void    SHA_pushMatrix      (char*  name, mat4  matrix);

/* Free dynamic memory. */
void    SHA_free            ();

#endif 
