#include "eventmanager.h"

void    EMG_startGame   (char   gameDirectory[], int    windowWidth, int    windowHeight) {
    GWD_set3d();
    RMG_loadResources(gameDirectory);
    OBJ_addObject("map", 0.0f, 0.0f, 0.0f);
    CA2_initCamera();
    PRJ_setFov3d(45.0f);
    aspectRatio = (float)windowWidth / (float)windowHeight;
    PRJ_setMinClipSpace3d(0.0f);
    PRJ_setMaxClipSpace3d(100.0f);
    PRJ_setAspectRatio(aspectRatio);
    PRJ_setMinClipSpace2d(0.1f);
    PRJ_setMaxClipSpace2d(100.0f);
}

void    EMG_doGameTick  () {

}

void    EMG_doRenderTick    (float  deltaTime) {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    OBJ_drawObjects(0);
    GWD_updateWindow(deltaTime);
    EMG_processInput();
    CA2_updateCamera();
}

void    EMG_processInput    () {
    /* Catch keys pressed and released. */
    SDL_Event event;
    while   (SDL_PollEvent(&event)) {
        switch  (event.type) {
            case    SDL_KEYDOWN:
                switch  (event.key.keysym.sym) {
                    case    SDLK_w:
                        buttonW =   1;
                        break;
                    case    SDLK_s:
                        buttonS =   1;
                        break;
                    case    SDLK_a:
                        buttonA =   1;
                        break;
                    case    SDLK_d:
                        buttonD =   1;
                        break;
                    case    SDLK_ESCAPE:
                        buttonEsc   =   1;
                        break;
                }
                break;
            case    SDL_KEYUP:
                switch  (event.key.keysym.sym) {
                    case    SDLK_w:
                        buttonW =   0;
                        break;
                    case    SDLK_s:
                        buttonS =   0;
                        break;
                    case    SDLK_a:
                        buttonA =   0;
                        break;
                    case    SDLK_d:
                        buttonD =   0;
                        break;
                    case    SDLK_ESCAPE:
                        buttonEsc   =   0;
                    break;
                }
                break;
            case    SDL_MOUSEMOTION:
                CA3_processMouse(event.motion.xrel, event.motion.yrel);
            default:
                break;
        }
    }
    /* Execute code for keys */
    if  (buttonW)
        CA2_moveForward();
    if  (buttonS)
        CA2_moveBackward();
    if  (buttonA)
        CA2_strafeLeft();
    if  (buttonD)
        CA2_strafeRight();
    if  (buttonEsc)
        GWD_closeWindow();
}

void    EMG_endGame     () {
    RMG_free();
}

