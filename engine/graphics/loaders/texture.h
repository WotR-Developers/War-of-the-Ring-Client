/* This file is responsible for loading textures */

#ifndef THE_FOURTH_AGE_TEXTURE_H
#define THE_FOURTH_AGE_TEXTURE_H

#include <GL/glew.h>
#include <SDL2/SDL_Image.h>

/* A texture structure which contains all necessary information to pass a texture to OpenGL */
struct Texture {
    char*       path;
    GLuint      textureBufferID;                            // The OpenGL texture ID
};

/* To generate IDs */
int     textureCount;

/* List of texture to quickly be used with the ID */
struct      Texture*    textureList;

/* Returns the ID of the texture to be set in the Object struct and adds it to textureList
 * if it has been already loaded returns the ID*/
int     TEX_genTexture      (char *path);

/* Internal function constructing the OpenGL buffers */
void    constructGLTexData  (int currentID);

/* Binds the texture to the GPU */
void    TEX_bindTexture     (int id);

/* Removes the texture of the texture list */
void    TEX_removeTexture   (int id);

#endif //THE_FOURTH_AGE_TEXTURE_H
