/* This file is responsible for the binding and unbinding of shaders as well as providing a function to push
 * matrices to the shader */

#ifndef THE_FOURTH_AGE_SHADER_H
#define THE_FOURTH_AGE_SHADER_H

/* To have access to OpenGL functions. */
#include <GL/glew.h>
/* To have aceess to memory management. */
#include <alloc.h>
#include <cstring.h>

/* A structure containing the shader name and the shader program ID */
struct Shader {
    const char*     vertexName;     // The name of the vertex shader
    const char*     fragmentName;   // The name of the fragment shader
    int             shaderProgram;  // The shader program ID
};

/* List of shaders to be quickly used with the ID */
struct  Shader*     shaderList;

/* To generate the ID */
int     numShaders;

/* Current Shader ID to know which Shader to pass to the uniforms */
int     currentShader;

/* Reads shader and returns the ID.
 * If it is already in the list, returns the ID */
int     SHA_genShader       (char*  vertexShaderPath, char* fragmentShaderPath);

/* Binds a shader to OpenGL */
void    SHA_bindShader      (int    id);

/* Pushes matrix to the shader with the given uniform
 * provided by the name parameter. */
void    SHA_pushMatrix      (char*  name, mat4  matrix);

/* Free dynamic memory. */
void    SHA_free            ();

#endif //THE_FOURTH_AGE_SHADER_H
