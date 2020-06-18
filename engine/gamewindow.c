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
        else if     (event.type == SDL_KEYDOWN) {
            switch  (event.key.keysym.sym) {
                case SDLK_w:
                    buttonW = 1;
                    break;
                case SDLK_s:
                    buttonS = 1;
                    break;
                case SDLK_a:
                    buttonA = 1;
                    break;
                case SDLK_d:
                    buttonD = 1;
                    break;
                case SDLK_q:
                    buttonQ = 1;
                    break;
                case SDLK_e:
                    buttonE = 1;
                    break;
            }
        }
        else if     (event.type == SDL_KEYUP) {
            switch      (event.key.keysym.sym) {
                case SDLK_w:
                    buttonW = 0;
                    break;
                case SDLK_s:
                    buttonS = 0;
                    break;
                case SDLK_a:
                    buttonA = 0;
                    break;
                case SDLK_d:
                    buttonD = 0;
                case SDLK_q:
                    buttonQ = 0;
                case SDLK_e:
                    buttonE = 0;
            }
        }
        else if     (event.type == SDL_MOUSEMOTION) {
           CA3_processMouse(event.motion.xrel, event.motion.yrel); 
        }
        /* Call functions if keys are still pressed. */
        if  (buttonW) {
            if  (mode == 0)
                CA2_moveForward();
            else if     (mode == 1)
                CA3_moveForward();
        }
        if  (buttonS) {
            if  (mode == 0)
                CA2_moveBackward();
            else if     (mode == 1)
                CA3_moveBackward();
        }
        if  (buttonA) {
            if  (mode == 0) 
                CA2_strafeLeft();
            else if     (mode == 1)
                CA3_strafeLeft();
        }
        if  (buttonD) {
            if  (mode == 0)
                CA2_strafeRight();
            else if     (mode == 1)
                CA3_strafeRight();
        }
        if  (buttonQ) {
            if  (mode == 0)
                CA2_rotateLeft();
        }
        if  (buttonE) {
            if  (mode == 0) 
                CA2_rotateRight();
        }
    }
    return 0;
}

void    GWD_closeWindow     () {
    SDL_DestroyWindow(window);
}
