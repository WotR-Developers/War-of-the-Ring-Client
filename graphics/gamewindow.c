#include "gamewindow.h"

int     GWD_createWindow    (char  *title, int   resX, int   resY) {
    SDL_Init(SDL_INIT_EVERYTHING);   // Initialize SDL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); 
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glContext);
    SDL_SetRelativeMouseMode(1);
    CA3_initCamera();

    if   (window == NULL) {
        return EXIT_FAILURE;
    }
    else {
        return EXIT_SUCCESS;
    }
}

void    GWD_updateWindow    (float  deltaTime) {
    CA3_update(deltaTime);
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
                case SDLK_SPACE:
                    buttonSpace = 1;
                    break;
                case SDLK_ESCAPE:
                    return -1;
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
                    break;
                case SDLK_q:
                    buttonQ = 0;
                    break;
                case SDLK_e:
                    buttonE = 0;
                    break;
                case SDLK_SPACE:
                    buttonSpace = 0;
                    break;
            }
        }
        else if     (event.type == SDL_MOUSEMOTION) {
            CA3_processMouse(event.motion.xrel, event.motion.yrel);
        }
        return 0;
    }
        if  (buttonW == 1) 
            CA3_moveForward();
        if  (buttonS == 1) 
            CA3_moveBackward(); 
        if  (buttonA == 1)
            CA3_strafeLeft();
        if  (buttonD == 1) 
            CA3_strafeRight();
        if  (buttonSpace == 1)
            CA3_jump();
}

void    GWD_closeWindow     () {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
