#ifndef FOURTH_AGE_CLIENT_RESOURCEMANAGER
#define FOURTH_AGE_CLIENT_RESOURCEMANAGER

/* The number of objects to be loaded. */
#define     OBJECT_COUNT    100

/* For logging. */
#include "logger.h"

/* To use dynamic memory management. */
#include <stdlib.h>

/* To read files. */
#include <stdio.h>
#include <ctype.h>

/* To use string operations. */
#include <string.h>

/* Contains the OS-specific path set at startup containing the assets base path. */
char   basePath[150];

/* Structs to simplify access and alignment of the resource-arrays. */

struct RMGName {
    char    path[100];
};

struct Type {
    int type;
};

struct TexturePath {
    char    path[100];
};

struct ModelPath {
    char    path[100];
};

struct VertexShaderPath {
    char    path[100];
};

struct FragmentShaderPath {
    char    path[100];
};

struct AnimationPath {
    char    path[100];
};

/* For saving necessary information about the GUIs. */

struct  GUIInformation {
    char    name[100];
    float   positionX,  positionY;
    float   sizeX,      sizeY;
    struct  GUIElement*     elements;
    int     elementCount;
    char    texturePath[100];
};


struct  GUIElement {
    float   positionX,  positionY;
    float   sizeX,      sizeY;
    float   w;
    char    texturePath[100];
};

/* Arrays of the resources. */

struct RMGName      names[OBJECT_COUNT];
struct Type         types[OBJECT_COUNT];
struct TexturePath  textures[OBJECT_COUNT];
struct ModelPath    models[OBJECT_COUNT];
struct VertexShaderPath     vertexShaders[OBJECT_COUNT];
struct FragmentShaderPath   fragmentShaders[OBJECT_COUNT];  
struct AnimationPath    animations[OBJECT_COUNT];
struct GUIInformation   guis[OBJECT_COUNT]; 

/* Counters for the different types of objects. */
int     entityCount;
int     spriteCount;
int     guiCount;

/* To be called on start
 * sets basePath
 * loads all resources. */
void    RMG_loadResources   (char  path[]);

/* Returns the type of object name. */
int     RMG_getType         (char*  objectName);

/* Returns the full texture path of object name. */
void    RMG_getTexture      (char*  dest, char* objectName);

/* Returns the full model path of object name. */
void    RMG_getModel        (char*  dest, char* objectName);

/* Returns the full vertex shader path of object name. */
void    RMG_getVertexShader     (char*  dest, char* objectName);

/* Returns the full fragment shader path of object name. */
void    RMG_getFragmentShader   (char*  dest, char* objectName);

/* Returns the full animation path of object name. */
void    RMG_getAnimation    (char*  dest, char* objectName);

void    RMG_getGuiPosition  (float  *positionX, float   *positionY, char*   name);

void    RMG_getGuiSize      (float  *sizeX, float   *sizeY, char*   name);

void    RMG_getGuiTexture   (char*  dest,   char*   name);

int     RMG_getGuiElementCount  (char*  name);

float   RMG_getGuiElementW      (char*  name, int   id);

void    RMG_getGuiElementPosition   (float  *positionX, float   *positionY, char*   name, int   id);

void    RMG_getGuiElementSize       (float  *sizeX, float   *sizeY, char*   name, int   id);

void    RMG_getGuiElementTexture    (char*  dest, char* name, int   id);

/* Free pointer which have been dynamically allocated. */
void    RMG_free            ();

#endif
