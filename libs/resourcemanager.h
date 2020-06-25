#ifndef FOURTH_AGE_CLIENT_RESOURCEMANAGER
#define FOURTH_AGE_CLIENT_RESOURCEMANAGER

/* For logging. */
#include "logger.h"

/* To use dynamic memory management. */
#include <stdlib.h>

/* To read files. */
#include <stdio.h>

/* To use string operations. */
#include <string.h>

/* Contains the OS-specific path set at startup containing the assets base path. */
char*   basePath;

/* Structs to simplify access and alignment of the resource-arrays. */
struct RMGName {
    char*   path;
};

struct TexturePath {
    char*   path;
};

struct ModelPath {
    char*   path;
};

struct VertexShaderPath {
    char*   path;
};

struct FragmentShaderPath {
    char*   path;
};

struct AnimationPath {
    char*   path;
};

/* Arrays of the resources. */
struct RMGName*     names;
struct TexturePath* textures;
struct ModelPath*   models;
struct VertexShaderPath*    vertexShaders;
struct FragmentShaderPath*  fragmentShaders;  
struct AnimationPath*   animations;

/* Count of various types of objects. */
int entityCount;

/* To be called on start
 * sets basePath
 * loads all resources. */
void    RMG_loadResources   (char*  path);

/* Returns the type of object name. */
char*   RMG_getType         (char*  objectName);

/* Returns the full texture path of object name. */
char*   RMG_getTexture      (char*  objectName);

/* Returns the full model path of object name. */
char*   RMG_getModel        (char*  objectName);

/* Returns the full vertex shader path of object name. */
char*   RMG_getVertexShader (char*  objectName);

/* Returns the full fragment shader path of object name. */
char*   RMG_getFragmentShader   (char*  objectName);

/* Returns the full animation path of object name. */
char*   RMG_getAnimation    (char*  objectName);

/* Free pointer which have been dynamically allocated. */
void    RMG_free            ();

#endif
