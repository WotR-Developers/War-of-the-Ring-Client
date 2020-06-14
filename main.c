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
    printf("Hello Arda!\n");
    if  ((GWD_createWindow("The Fourth Age", 1920, 1080)) == EXIT_FAILURE) {
        printf("[ERROR] The GWD_createWindow function returned EXIT_FAILURE.\n");
    }
    while   (closeGame == 0) {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        GWD_updateWindow();
        int processReturn = GWD_processInput();
        if  (processReturn == -1) {
            closeGame = 1;
        }
    }
    printf("Logger has taken the last ship to Valinor\n");
    GWD_closeWindow();
}
