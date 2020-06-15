/* To receive return status */
#include <stdlib.h>

/* To call OpenGL functions */
#define GLEW_STATIC
#include <GL/glew.h>

/* Include to create the game window */
#define SDL_MAIN_HANDLED
#include "engine/gamewindow.h"

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

    /* Main game loop. */
    while   (closeGame == 0) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        GWD_updateWindow();
        int processReturn = GWD_processInput();
        if  (processReturn == -1) {
            closeGame = 1;
        }
    }

    /* Program is finished. */
    printf("Logger has taken the last ship to Valinor\n");
    GWD_closeWindow();
}