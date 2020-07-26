/* Responsible for opening and closing GUIs
 * calls function of the GUI callback. */

#ifndef FOURTH_AGE_CLIENT_GUI
#define FOURTH_AGE_CLIENT_GUI

/* A struct containing the necessary information about a GUI. */
struct GUI {
    float   positionX;
    float   positionY;
    float   sizeX;
    float   sizeY;
};

/* Opens a new GUI of the given name. */
int     openGUI             (char*  name);

/* Figures out topmost GUI at the given position.
 * Calls callback functions.*/
void    processLeftClick    (float  posX, float posY);

/* Figures out topmost GUI at the given position.
 * Calls callback functions. */
void    processRightClick   (float  posX, float posY);

/* Closes the GUI with the given ID. */
void    closeGUI            (int    id);

#endif
