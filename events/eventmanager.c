#include "eventmanager.h"

void    EMG_startGame   (char   gameDirectory[], int    windowWidth, int    windowHeight) {
    GWD_set3d();
    RMG_loadResources(gameDirectory);
    CA2_initCamera();
    CA3_initCamera();
    PRJ_setFov3d(45.0f);
    aspectRatio =   (float)windowWidth / (float)windowHeight;
    PRJ_setMinClipSpace3d(0.1f);
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
    OBJ_drawObjects(phase);
    GWD_updateWindow(deltaTime);
    EMG_processInput();
    if  (phase == 0)
        CA3_update(deltaTime);
    else if (phase == 1)
        CA2_updateCamera();
}

void    EMG_startBattlePhase    () {
    phase   =   0;
    GWD_set3d();
}

void    EMG_startTurnPhase      () {
    phase   =   1;
    GWD_set2d();
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
                if  (phase == 0)
                    CA3_processMouse(event.motion.xrel, event.motion.yrel);
            default:
                break;
        }
    }
    /* Execute code for keys */
    if  (buttonW)
        if  (phase == 0)
            CA3_moveForward();
        else if (phase == 1)
            CA2_moveForward();
    
    if  (buttonS)
        if  (phase == 0)
            CA3_moveBackward();
        else if (phase == 1)
            CA2_moveBackward();
    
    if  (buttonA)
        if  (phase == 0)
            CA3_strafeLeft();
        else if (phase == 1)
            CA2_strafeLeft();
    
    if  (buttonD)
        if  (phase == 0)
            CA3_strafeRight();
        else if (phase == 1)
            CA2_strafeRight();
    
    if  (buttonEsc)
        GWD_closeWindow();
}

void    EMG_endGame     () {
    RMG_free();
}

