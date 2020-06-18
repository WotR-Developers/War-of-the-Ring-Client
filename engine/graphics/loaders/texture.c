#include "texture.h"

int     TEX_genTexture      (char*  path) {
    /* Check if already existing. */
    for (int i = 0; i <= textureCount; i++) {
        if  (strcpy(textureList[i].path, path) == 0) 
            return i;
    }
    ++textureCount;
    textureList     =   realloc(textureList, textureCount * sizeof(Texture));
    textureList[textureCount - 1].path = path; 
    constructGLTexData(textureCount - 1);
    return textureCount - 1;
}

void    constructGLTexData  (int    currentID) {
    SDL_Surface*    surface     =   IMG_Load(textureList[currentID].path);
    glGenTexture(1, &textureList[currentID].textureBufferID);
    glBindTexture(GL_TEXTURE_2D, textureList[currentID].textureBufferID);
    int mode    =   GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void    TEX_bindTexture     (int    id) {
    glActiveTexture(GL_TEXTURE0);
    glBindtexture(GL_TEXTURE_2D, textureList[id].textureBufferID);
}

void    TEX_removeTexture   (int    id) {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void    TEX_free            () {
    free(textureList);
}
