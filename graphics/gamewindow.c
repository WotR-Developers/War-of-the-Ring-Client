#include "gamewindow.h"

int     GWD_createWindow    (char  *title, int   *resX, int   *resY) {
    SDL_Init(SDL_INIT_EVERYTHING);   // Initialize SDL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); 
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    *resX  =   displayMode.w;
    *resY =   displayMode.h;
    screenSizeX = displayMode.w;
    screenSizeY = displayMode.h;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w, displayMode.h, SDL_WINDOW_OPENGL);
    SDL_SetWindowFullscreen(window, SDL_TRUE);
    glContext = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glContext);
    SDL_SetRelativeMouseMode(1);
    if   (window == NULL) {
        return EXIT_FAILURE;
    }
    else {
        return EXIT_SUCCESS;
    }
}

float   GWD_getScreenSizeX  () {
    return screenSizeX;
}

float   GWD_getScreenSizeY  () {
    return screenSizeY;
}

void    GWD_updateWindow    (float  deltaTime) {
    SDL_GL_SwapWindow(window);
}

void    GWD_set2d           () {
    SDL_SetRelativeMouseMode(0);
    mode    =   0;
}

void    GWD_set3d           () {
    mode    =   1;
    SDL_SetRelativeMouseMode(1);
}


void    GWD_closeWindow     () {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
