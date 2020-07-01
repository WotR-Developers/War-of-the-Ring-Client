/* To call OpenGL functions. */
#define GLEW_STATIC
#include <GL/glew.h>

/* To initialize GWD and open the window. */
#define SDL_MAIN_HANDLED
#include "graphics/gamewindow.h"

/* To check for function success. */
#include <stdlib.h>

/* For error and info handling. */
#include "libs/logger.h"

/* To update timers and pass deltaTime. */
#include "libs/time.h"

/* To initialize RMG. */
#include "libs/resourcemanager.h"

int     closeGame   =   0;

int main(int    argc, char* argv[]) {
    printf("Hello Arda!\n");

    /* Check if enough command line input is specified. */
    if  (argc != 2) {
        LOG_error("Too less or too many arguments specified.", "Startup error");
        return -1;
    }

    /* Create GWD window */
    if  ((GWD_createWindow("The Fourth Age", 1920, 1080)) == EXIT_FAILURE) {
        LOG_error("GWD window could not be created.", "EXIT_FAILURE");
        return -1;
    }


     /* Initialize GLEW. */
    GLenum openGLInitError = glewInit();
    

    /* Check if init of GLEW failed. */
    if  (openGLInitError != GLEW_OK) {
        LOG_error("The OpenGL context could not be created.", (const char*)glewGetErrorString(openGLInitError));
        closeGame = 1;
    }


    /* Debug information at upstart. */
    LOG_info("Your OpenGL version", (const char*)glGetString(GL_VERSION));
    LOG_info("Your GPU vendor", (const char*)glGetString(GL_VENDOR));
    LOG_info("Your shader language version", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
    LOG_info("Available renderer", (const char*)glGetString(GL_RENDERER));


    /* Init everything. */
    GWD_set3d();
    RMG_loadResources(argv[1]);

    /* Main game loop. */
    while   (closeGame == 0) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        TIM_updateTimers();
        TIM_updateDeltaTime();
        GWD_updateWindow();
        int processReturn = GWD_processInput();
        if  (processReturn == -1) {
            closeGame = 1;
        }
    }


    /* Ending tasks. */
    RMG_free();
    TIM_free();
    printf("Taking the last ship to Valinor.\n");
}
