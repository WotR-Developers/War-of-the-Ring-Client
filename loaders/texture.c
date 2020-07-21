#include "texture.h"

int     TEX_genTexture      (char*  path) {
    /* Check if already existing. */
    for (int i = 0; i < textureCount; i++) {
        if  (strcmp(textureList[i].path, path) == 0) 
            return i;
    }
    stbi_set_flip_vertically_on_load(1);
    ++textureCount;
    textureList     =   realloc(textureList, textureCount * sizeof(struct Texture));
    textureList[textureCount - 1].path = path; 
    constructGLTexData(textureCount - 1);
    return textureCount - 1;
}

void    constructGLTexData  (int    currentID) {
    int textureWidth;
    int textureHeight;
    int bitsPerPixel;
    stbi_uc *textureBuffer = stbi_load(textureList[textureCount - 1].path, &textureWidth, &textureHeight, &bitsPerPixel, 4);
    glGenTextures(1, &textureList[currentID].textureBufferID);
    glBindTexture(GL_TEXTURE_2D, textureList[currentID].textureBufferID);
    int mode    =   GL_RGBA;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, mode, textureWidth, textureHeight, 0, mode, GL_UNSIGNED_BYTE, textureBuffer);
}

void    TEX_bindTexture     (int    id) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureList[id].textureBufferID);
}

void    TEX_removeTexture   (int    id) {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void    TEX_free            () {
    free(textureList);
}
