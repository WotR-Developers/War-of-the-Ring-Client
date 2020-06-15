/* This file is responsible for the binding and unbinding of shaders as well as providing a function to push
 * matrices to the shader */

#ifndef THE_FOURTH_AGE_SHADER_H
#define THE_FOURTH_AGE_SHADER_H

/* A structure containing the shader name and the shader program ID */
struct Shader {
    const char*     name;           // The name of the shader
    int             shaderProgram;  // The shader program ID
};

/* List of shaders to be quickly used with the ID */
struct  Shader*     shaderList;

/* Reads shader and returns the ID.
 * If it is already in the list, returns the ID */
int     SHA_genShader       (char *path);

/* Binds a shader to OpenGL */
void    SHA_bindShader      (int  id);

/* Pushes matrix to the shader with the given uniform
 * provided by the name parameter. */
void    SHA_pushMatrix      (char *name);

#endif //THE_FOURTH_AGE_SHADER_H
