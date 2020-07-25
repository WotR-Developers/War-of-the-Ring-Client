#include "texture.h"

int     TEX_create          (char*  path) {
    /* Check if already existing. */
    stbi_set_flip_vertically_on_load(1);
    ++textureCount;
    textureList     =   realloc(textureList, textureCount * sizeof(struct Texture));
    textureList[textureCount - 1].path = path; 
    constructGLTexData(textureCount - 1);
    return textureCount - 1;
}

void    constructGLTexData  (int    currentID) {
    int bitsPerPixel;
    stbi_uc *textureBuffer  =   stbi_load(textureList[currentID].path, &textureList[currentID].textureWidth, &textureList[currentID].textureHeight, &bitsPerPixel, 4);
    glGenTextures(1, &textureList[currentID].textureBufferID);
    glBindTexture(GL_TEXTURE_2D, textureList[currentID].textureBufferID);
    int mode    =   GL_RGBA;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, mode, textureList[currentID].textureWidth, textureList[currentID].textureHeight, 0, mode, GL_UNSIGNED_BYTE, textureBuffer);
}

int     TEX_getWidth        (int id) {
    return textureList[id].textureWidth;
}

int     TEX_getHeight       (int id) {
    return textureList[id].textureHeight;
}

void    TEX_bind            (int    id) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureList[id].textureBufferID);
}

void    TEX_remove          (int    id) {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void    TEX_free            () {
    free(textureList);
}
