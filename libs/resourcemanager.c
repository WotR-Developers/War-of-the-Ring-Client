#include "resourcemanager.h"

void    RMG_loadResources   (char  path[]) {
    strcpy(basePath, path);

    char    entityFile[100];
    strcpy(entityFile, basePath);
    strcat(entityFile, "entities.txt");
    
    char    spriteFile[100];
    strcpy(spriteFile, basePath);
    strcat(spriteFile, "sprites.txt");

    char    guiFile[100];
    strcpy(guiFile, basePath);
    strcat(guiFile, "guis.txt");

    FILE*   entitiesFile    =   fopen(entityFile, "r");
    if      (entitiesFile == NULL)
        LOG_error("File not found exception", "entities.txt could not be found. Terminating.");
    
    FILE*   spritesFile  =   fopen(spriteFile, "r");
    if      (spritesFile == NULL)
        LOG_error("File not found exception", "sprites.txt could not be found. Terminating.");

    FILE*   guisFile    =   fopen(guiFile, "r");
    if      (guisFile == NULL)
        LOG_error("File not found exception", "guis.txt could not be found. Terminating.");

    /* Load entities. */
    char    line[100];
    int     lineNumber  =   0;
    while   (fgets(line, sizeof(line), entitiesFile) != NULL) {
        ++lineNumber;
        int emptyString =   1;
        for (char* i = line; *i != '\0'; ++i) {
            if  (!isspace(*i)) 
                emptyString =   0;
        }
        if  (emptyString == 1)
            break;
        strcpy(names[lineNumber - 1].path, line);
        size_t  lineLen =   strlen(names[lineNumber - 1].path);
        names[lineNumber - 1].path[lineLen - 1] =   '\0';
        types[lineNumber - 1].type      =   0;
        ++entityCount;
        LOG_info("Registered entity", names[lineNumber - 1].path);
    }
    fclose(entitiesFile);

    /* Load sprites. */
    memset(line, 0, sizeof(line));
    while   (fgets(line, sizeof(line), spritesFile) != NULL) {
        ++lineNumber;
        int emptyString =   1;
        for     (char* i = line; *i != '\0'; ++i) {
            if      (!isspace(*i))
                emptyString =   0;
        }
        if  (emptyString == 1)
            break; 
        strcpy(names[lineNumber - 1].path, line);
        size_t  lineLen =   strlen(names[lineNumber - 1].path);
        names[lineNumber - 1].path[lineLen - 1] =   '\0';
        types[lineNumber - 1].type  =   1;
        ++spriteCount;
        LOG_info("Registered sprite", names[lineNumber - 1].path);
    }
    fclose(spritesFile);

    /* Load GUIs. */
    memset(line, 0, sizeof(line));
    while   (fgets(line, sizeof(line), guisFile) != NULL) {
        ++lineNumber;
        int emptyString =   1;
        for     (char*  i = line; *i != '\0'; ++i) {
            if      (!isspace(*i))
                emptyString =   0;
        }
        if  (emptyString == 1)
            break;
        strcpy(names[lineNumber - 1].path, line);
        size_t  lineLen =   strlen(names[lineNumber - 1].path);
        names[lineNumber - 1].path[lineLen - 1] = '\0';
        types[lineNumber - 1].type  =   2;
        ++guiCount;
        LOG_info("Registered gui", names[lineNumber - 1].path);
    }
    fclose(guisFile);

    for     (int i = 0; i < entityCount; ++i) {
        strcpy(textures[i].path, basePath);
        strcat(textures[i].path, "textures/");
        strcat(textures[i].path, names[i].path);
        strcat(textures[i].path, ".png");
        LOG_info("Registered texture", textures[i].path);
    }

    for     (int i = 0; i < entityCount; ++i) {
        strcpy(models[i].path, basePath);
        strcat(models[i].path, "models/");
        strcat(models[i].path, names[i].path);
        strcat(models[i].path, ".pmf");
        LOG_info("Registered model", models[i].path);
    }


    for     (int i = 0; i < entityCount; ++i) {
        strcpy(vertexShaders[i].path, basePath);
        strcat(vertexShaders[i].path, "shaders/");
        strcat(vertexShaders[i].path, names[i].path);
        strcat(vertexShaders[i].path, ".vs");
        FILE*   testFile    =   fopen(vertexShaders[i].path, "r");
        if      (testFile == NULL) {
            strcpy(vertexShaders[i].path, basePath);
            strcat(vertexShaders[i].path, "shaders/entities_default.vs");
        }
        else {
            fclose(testFile);
        }
        LOG_info("Registered vertex shader", vertexShaders[i].path);
    }


    for     (int i = 0; i < entityCount; ++i) {
        strcpy(fragmentShaders[i].path, basePath);
        strcat(fragmentShaders[i].path, "shaders/");
        strcat(fragmentShaders[i].path, names[i].path);
        strcat(fragmentShaders[i].path, ".fs");
        FILE*   testFile    =   fopen(fragmentShaders[i].path, "r");
        if      (testFile == NULL) {
            strcpy(fragmentShaders[i].path, basePath);
            strcat(fragmentShaders[i].path, "shaders/entities_default.fs");
        }
        else {
            fclose(testFile);
        }
        LOG_info("Registered fragment shader", fragmentShaders[i].path);
    }

    for     (int i = 0; i < entityCount; ++i) {
        strcpy(animations[i].path, basePath);
        strcat(animations[i].path, "animations/");
        strcat(animations[i].path, names[i].path);
        strcat(animations[i].path, ".eaf");
        LOG_info("Registered animation", animations[i].path);
    }

    for     (int i = spriteCount; i < entityCount + spriteCount; ++i) {
        strcpy(textures[i].path, basePath);
        strcat(textures[i].path, "textures/");
        strcat(textures[i].path, names[i].path);
        strcat(textures[i].path, ".png");
        LOG_info("Registered Sprite texture", textures[i].path);
    }

    for     (int i = spriteCount; i < entityCount + spriteCount; ++i) {
        strcpy(models[i].path, basePath);
        strcat(models[i].path, "models/");
        strcat(models[i].path, names[i].path);
        strcat(models[i].path, ".pmf");
        FILE*   testFile    =   fopen(models[i].path, "r");
        if      (testFile == NULL) {
            strcpy(models[i].path, basePath);
            strcat(models[i].path, "models/default_sprite.pmf");
        } else {
            fclose(testFile);
        }
        LOG_info("Registered Sprite model", models[i].path);

    }

    for     (int i = spriteCount; i < entityCount + spriteCount; ++i) {
        strcpy(vertexShaders[i].path, basePath);
        strcat(vertexShaders[i].path, "shaders/");
        strcat(vertexShaders[i].path, names[i].path);
        strcat(vertexShaders[i].path, ".vs");
        FILE*   testFile    =   fopen(vertexShaders[i].path, "r");
        if      (testFile == NULL) {
            strcpy(vertexShaders[i].path, basePath);
            strcat(vertexShaders[i].path, "shaders/sprite_default.vs");
        }
        else {
            fclose(testFile);
        }
        LOG_info("Registered Sprite vertex shader", vertexShaders[i].path);
    }

    for     (int i = spriteCount; i < entityCount + spriteCount; ++i) {
        strcpy(fragmentShaders[i].path, basePath);
        strcat(fragmentShaders[i].path, "shaders/");
        strcat(fragmentShaders[i].path, names[i].path);
        strcat(fragmentShaders[i].path, ".fs");
        FILE*   testFile    =   fopen(fragmentShaders[i].path, "r");
        if      (testFile == NULL) {
            strcpy(fragmentShaders[i].path, basePath);
            strcat(fragmentShaders[i].path, "shaders/sprite_default.fs");
        }
        else {
            fclose(testFile);
        }
        LOG_info("Registered Sprite fragment shader", fragmentShaders[i].path);
    }

    for     (int i = spriteCount; i < entityCount + spriteCount; ++i) {
        strcpy(animations[i].path, basePath);
        strcat(animations[i].path, "animations/");
        strcat(animations[i].path, names[i].path);
        strcat(animations[i].path, ".eaf");
        LOG_info("Registered animation", animations[i].path);
    }

    /* Register GUIs. */
    for     (int i = spriteCount + entityCount; i < entityCount + spriteCount + guiCount; ++i) {
        char    guiPath[100];
        strcpy(guiPath, basePath);
        strcat(guiPath, "guis/");
        strcat(guiPath, names[i].path);
        strcat(guiPath, ".cfg");
        FILE*   guiFileLoad =   fopen(guiPath, "r");
        if  (guiFileLoad == NULL) 
            LOG_error("File not found exception", "GUI file could not be found");
        char    currentLine[100];
        int     linePointer =   0;              // Current line of file
        char    delimiter[] =   " ";
        
        while   (fgets(currentLine, 100, guiFileLoad)) {
            int     linePosition    =   0;      // Current word of line
            char*   lineWords       =   strtok(currentLine, delimiter);
            ++linePointer;
            while   (lineWords) {
                if  (linePointer == 1) {
                    switch  (linePosition) {
                        case 0:
                            strcpy(guis[i].name, lineWords);
                            break;
                        case 1:
                            guis[i].positionX   =   atof(lineWords);
                            break;
                        case 2:
                            guis[i].positionY   =   atof(lineWords);
                            break;
                        case 3:
                            guis[i].sizeX       =   atof(lineWords);
                            break;
                        case 4:
                            guis[i].sizeY       =   atof(lineWords);
                            break;
                        case 5:
                            strcpy(guis[i].texturePath, basePath);
                            strcat(guis[i].texturePath, "textures/");
                            strcat(guis[i].texturePath, lineWords);
                    }
                }
                else {
                    switch  (linePosition) {
                        case 0: 
                            ++guis[i].elementCount;
                            guis[i].elements    =   realloc(guis[i].elements, guis[i].elementCount * sizeof(struct GUIElement));
                            break;
                        case 1:
                            guis[i].elements[guis[i].elementCount - 1].positionX    =   atof(lineWords);
                            break;
                        case 2:
                            guis[i].elements[guis[i].elementCount - 1].positionY    =   atof(lineWords);
                            break;
                        case 3:
                            guis[i].elements[guis[i].elementCount - 1].sizeX        =   atof(lineWords);
                            break;
                        case 4:
                            guis[i].elements[guis[i].elementCount - 1].sizeY        =   atof(lineWords);
                            break;
                        case 5:
                            guis[i].elements[guis[i].elementCount - 1].w            =   atof(lineWords);
                            break;
                        case 6:
                            strcpy(guis[i].elements[guis[i].elementCount - 1].texturePath, basePath);
                            strcpy(guis[i].elements[guis[i].elementCount - 1].texturePath, "textures/");
                            strcpy(guis[i].elements[guis[i].elementCount - 1].texturePath, lineWords);
                    }
                }
                ++linePosition;
                lineWords   =   strtok(NULL, delimiter);
            }
        }
        fclose(guiFileLoad);
    }
}

int     RMG_getType         (char*  objectName) { 
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            return types[i].type;             
        }
    }
}

void    RMG_getTexture      (char*  dest, char* objectName) {
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            strcpy(dest, textures[i].path);
        }
    }
}

void    RMG_getModel        (char*  dest, char* objectName) {
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            strcpy(dest, models[i].path);
        }
    }
}

void    RMG_getVertexShader     (char*  dest, char* objectName) {
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            strcpy(dest, vertexShaders[i].path);
        }
    }
}

void    RMG_getFragmentShader   (char*  dest, char* objectName) {
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            strcpy(dest, fragmentShaders[i].path);
        }
    }   
}

void    RMG_getAnimation    (char*  dest, char* objectName) {
    for (int i = 0; i < entityCount + spriteCount; ++i) {
        if  (strcmp(names[i].path, objectName) == 0) {
            dest = animations[i].path;
        }
    }
}

void    RMG_getGuiPosition  (float  *positionX, float   *positionY, char*   name) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            *positionX  =   guis[i].positionX;
            *positionY  =   guis[i].positionY;
        }
    }
}

void    RMG_getGuiSize      (float  *sizeX, float   *sizeY, char*   name) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            *sizeX      =   guis[i].sizeX;
            *sizeY      =   guis[i].sizeY;
        }
    }
}

void    RMG_getGuiTexture   (char*  dest,   char*   name) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            strcmp(dest, guis[i].texturePath);
        }
    }
}

int     RMG_getGuiElementCount  (char*  name) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            return guis[i].elementCount;
        }
    }
}

float   RMG_getGuiElementW      (char*  name, int   id) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            return guis[i].elements[id].w;
        }
    }
}

void    RMG_getGuiElementPosition   (float  *positionX, float   *positionY, char*   name, int   id) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            *positionX  =   guis[i].elements[id].positionX;
            *positionY  =   guis[i].elements[id].positionY;
        }
    }
}

void    RMG_getGuiElementSize       (float  *sizeX, float   *sizeY, char*   name, int   id) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            *sizeX  =   guis[i].elements[id].sizeX;
            *sizeY  =   guis[i].elements[id].sizeY;
        }
    }
}

void    RMG_getGuiElementTexture    (char*  dest, char* name, int   id) {
    for     (int i = spriteCount + entityCount; i < spriteCount + entityCount + guiCount; ++i) {
        if  ((strcmp(guis[i].name, name)) == 0) {
            strcmp(dest, guis[i].elements[id].texturePath);
        }
    }
}

void    RMG_free    () {
}
