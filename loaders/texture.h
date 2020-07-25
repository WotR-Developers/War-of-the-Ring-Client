/* This file is responsible for loading textures */

#ifndef FOURTH_AGE_TEXTURE
#define FOURTH_AGE_TEXTURE

/* To construct GL data. */
#include <GL/glew.h>

/* To load images. */
#include "../libs/ext/stb_image.h"

/* For dynamic memory. */
#include <stdlib.h>

/* For string comparisons. */
#include <string.h>

/* For debug log. */
#include <stdio.h>

/* A texture structure which contains all necessary information to pass a texture to OpenGL */
struct Texture {
    char*       path;
    GLuint      textureBufferID;                            // The OpenGL texture ID
    int         textureWidth;
    int         textureHeight;
};

/* To generate IDs */
int     textureCount;

/* List of texture to quickly be used with the ID */
struct      Texture*    textureList;

/* Returns the ID of the texture to be set in the Object struct and adds it to textureList
 * if it has been already loaded returns the ID*/
int     TEX_create          (char *path);

/* Internal function constructing the OpenGL buffers */
void    constructGLTexData  (int currentID);

/* Binds the texture to the GPU */
void    TEX_bind            (int id);

int     TEX_getWidth        (int id);

int     TEX_getHeight       (int id);

/* Removes the texture of the texture list */
void    TEX_remove          (int id);

/* Free dynamic memory. */
void    TEX_free            ();

#endif
