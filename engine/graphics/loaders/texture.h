/* This file is responsible for loading textures */

#ifndef THE_FOURTH_AGE_TEXTURE_H
#define THE_FOURTH_AGE_TEXTURE_H

#include <GL/glew.h>
#include <../../../libs/external/stb_image.h>

/* A texture structure which contains all necessary information to pass a texture to OpenGL */
struct Texture {
    int     textureWidth, textureHeight, bitsPerPixel;  // Pure texture information
    stbi_uc *textureBuffer;                             // The texture
    GLuint  textureBufferId;                            // The OpenGL texture ID
};

/* List of texture to quickly be used with the ID */
struct Texture *textureList;

/* Returns the ID of the texture to be set in the Object struct and adds it to textureList
 * if it has been already loaded returns the ID*/
int  TEX_genTexture         (char *path);

void constructGLTexData     (int currentID, struct Texture *currentTexture);

/* Binds the texture to the GPU */
void TEX_bindTexture        (int ID);

/* Removes the texture of the texture list */
void TEX_removeTexture      (int ID);

#endif //THE_FOURTH_AGE_TEXTURE_H
