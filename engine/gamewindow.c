#include "gamewindow.h"

int     GWD_createWindow    (char  *title, int   resX, int   resY) {
   SDL_Init(SDL_INIT_EVERYTHING);   // Initialize SDL

   window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, SDL_WINDOW_OPENGL);
   SDL_GLContext glContext = SDL_GL_CreateContext(window);

   if   (window == NULL) {
        return EXIT_FAILURE;
   }
   else {
        return EXIT_SUCCESS;
   }
}

void    GWD_updateWindow    () {
    SDL_GL_SwapWindow(window);
}

int     GWD_processInput    () {
    SDL_Event event;
    while   (SDL_PollEvent(&event)) {
        if  (event.type == SDL_QUIT) {
            return -1;
        }
    }
    return 0;
}

void    GWD_closeWindow     () {
    SDL_DestroyWindow(window);
}
