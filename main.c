/* To receive return status */
#include <stdlib.h>

/* To call OpenGL functions */
#define GLEW_STATIC
#include <GL/glew.h>

/* Include to create the game window */
#define SDL_MAIN_HANDLED
#include "engine/gamewindow.h"

/* To initialize projection. */
#include "engine/graphics/projection.h"

/* To initialize cameras. */
#include "engine/graphics/camera2d.h"
#include "engine/graphics/camera3d.h"

/* To set ResourceManager base path and fire it up. */
#include "libs/resourcemanager.h"

/* To load and update time library. */
#include "engine/time.h"

/* To draw the objects and call the free method. */
#include "engine/graphics/object.h"

/* Gets 1 if the game should close. */
int closeGame   =   0; 

int main() {
    /* Startup message. */
    printf("Hello Arda!\n");
    
    /* Try open game window with GWD. */
    if  ((GWD_createWindow("The Fourth Age", 1920, 1080)) == EXIT_FAILURE) {
        printf("[ERROR] The GWD_createWindow function returned EXIT_FAILURE.\n");
    }

    /* Initialize GLEW */
    GLenum openGLInitError = glewInit();
    
    /* Check if init of GLEW failed */
    if  (openGLInitError != GLEW_OK) {
        printf("[ERROR] The GLEW OpenGL context could not be created.\n");
        printf("[ERROR] GLEW returned: %s\n", glewGetErrorString(openGLInitError));
        closeGame = 1;
    }

    /* Startup user information */
    printf("[INFO] OpenGL loaded with version: %s. \n", glGetString(GL_VERSION));
    printf("[INFO] Your GPU vendor: %s. \n", glGetString(GL_VENDOR));
    printf("[INFO] Available shader language version: %s. \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("[INFO] Available renderer: %s. \n", glGetString(GL_RENDERER));

    /* Init everything. */
    PRJ_initProjection(1920.0f/1080.0f);
    PRJ_setPerspective();
    CA2_initCamera();
    CA3_initCamera();
    GWD_set3d();
    RMG_setBasePath("/assets");
    RMG_loadResources();

    /* Main game loop. */
    while   (closeGame == 0) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        TIM_updateTimers();
        GWD_updateWindow();
        OBJ_drawObjects(1);
        int processReturn = GWD_processInput();
        if  (processReturn == -1) {
            closeGame = 1;
        }
    }

    /* Program is finished. */
    printf("Logger has taken the last ship to Valinor\n");
    GWD_closeWindow();

    /* Call functions which free dynamic memory. */
    RMG_free();
    TIM_free();
    OBJ_free();
}
