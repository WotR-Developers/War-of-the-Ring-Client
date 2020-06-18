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

   CA3_initCamera();
   CA2_initCamera();
}

void    GWD_updateWindow    () {
    SDL_GL_SwapWindow(window);
}

void    GWD_set2d           () {
    mode    =   0;
}

void    GWD_set3d           () {
    mode    =   1;
}

int     GWD_processInput    () {
    SDL_Event event;
    while   (SDL_PollEvent(&event)) {
        if  (event.type == SDL_QUIT) {
            return -1;
        }
        else if     (event.type == SDL_kEYDOWN) {
            switch  (event.key.keysym.sym) {
                case SDLK_w:
                    if  (mode == 0)
                        CA2_moveForward();
                    else if     (mode == 1)
                        CA3_moveForward();
                    break;
                case SDLK_s:
                    if  (mode == 0)
                        CA2_moveBackward();
                    else if     (mode == 1)
                        CA3_moveBackward();
                    break;
                case SDLK_a:
                    if  (mode == 0) 
                        CA2_strafeLeft();
                    else if     (mode == 1)
                        CA3_strafeLeft();
                    break;
                case SDLK_d:
                    if  (mode == 0)
                        CA2_strafeRight();
                    else if     (mode == 1)
                        CA3_strafeRight();
                    break;
                case SDLK_q:
                    if  (mode == 0)
                        CA2_rotateLeft();
                    break;
                case SDLK_e:
                    if  (mode == 0) 
                        CA2_rotateRight();
                    break;
            }
        }
    }
    return 0;
}

void    GWD_closeWindow     () {
    SDL_DestroyWindow(window);
}
