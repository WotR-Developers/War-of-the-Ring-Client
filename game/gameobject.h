/* Called by game/ this file adds GameObjects to the list and if they are in visible range of the player
 * creates an engine object which is then drawn*/

#ifndef THE_FOURTH_AGE_GAMEOBJECT_H
#define THE_FOURTH_AGE_GAMEOBJECT_H

/* A structure containing all necessary information of a GameObject */
struct GameObject {
    float   posX, posY, posZ;     // The position of the GameObject
    int     objectID;             // The ID of the Object of the GameObject if there is one
};

/* The list of all GameObjects */
struct  GameObject*     gameObjectList;

/* Counter of GameObjects */
int     numGameObjects;

/* Adds a new GameObject and inserts it into the gameObjectList
 * Adds 1 to the numGameObjects*/
int     GOJ_addGameObject       ();

/* Figures out which GameObjects are in the area of the player by using the playerPos coordinates.
 * If one moved inside the area, adds an object for it.
 * If one moved outside the area, removes its object to prevent it from being rendered */
void    GOJ_updateGameObjects   (float playerPosX, float playerPosY, float playerPosZ);

/* Adds to the position of the GameObject.
 * If in sight, executes animation and changes location of object */
void    GOJ_moveGameObject      (int  id, float x, float y, float z);

/* Changes the position of the GameObject.
 * If in sight, executes animation and changes location of the object */
void    GOJ_moveGameObjectToPos (int  id, float x, float y, float z);

/* Removes the GameObject from the list.
 * Removes 1 from the numGameObjects */
void    GOJ_removeGameObject    ();

#endif //THE_FOURTH_AGE_GAMEOBJECT_H
