#include "resourcemanager.h"

void    RMG_loadResources   (char  path[]) {
    strcpy(basePath, path);

    char    entityFile[100];
    strcpy(entityFile, basePath);
    strcat(entityFile, "entities.txt");
    
    char    spriteFile[100];
    strcpy(spriteFile, basePath);
    strcat(spriteFile, "sprites.txt");

    FILE*   entitiesFile    =   fopen(entityFile, "r");
    if      (entitiesFile == NULL)
        LOG_error("File not found exception", "entities.txt could not be found. Terminating.");
    
    FILE*   spritesFile  =   fopen(spriteFile, "r");
    if      (spritesFile == NULL)
        LOG_error("File not found exception", "sprites.txt could not be found. Terminating.");

    char    line[100];
    int     lineNumber = 0;
    while   (fgets(line, sizeof(line), entitiesFile) != NULL) {
        ++lineNumber;
        int emptyString = 1;
        for (char* i = line; *i != '\0'; ++i) {
            if  (!isspace(*i)) 
                emptyString = 0;
        }
        if  (emptyString == 1)
            break;
        strcpy(names[lineNumber - 1].path, line);
        size_t lineLen =   strlen(names[lineNumber - 1].path);
        names[lineNumber - 1].path[lineLen - 1] = '\0';
        types[lineNumber - 1].type     =   0;
        ++entityCount;
        LOG_info("Registered entity", names[lineNumber - 1].path);
    }
    fclose(entitiesFile);

    memset(line, 0, sizeof(line));
    while   (fgets(line, sizeof(line), spritesFile) != NULL) {
        ++lineNumber;
        int     emptyString =   1;
        for     (char* i = line; *i != '\0'; ++i) {
            if      (!isspace(*i))
                emptyString = 0;
        }
        if  (emptyString == 1)
            break; 
        strcpy(names[lineNumber - 1].path, line);
        size_t lineLen =   strlen(names[lineNumber - 1].path);
        names[lineNumber - 1].path[lineLen - 1] = '\0';
        types[lineNumber - 1].type  =   1;
        ++spriteCount;
        LOG_info("Registered sprite", names[lineNumber - 1].path);
    }
    fclose(spritesFile);

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

    for     (int i = entityCount; i < entityCount + spriteCount; ++i) {
        strcpy(textures[i].path, basePath);
        strcat(textures[i].path, "textures/");
        strcat(textures[i].path, names[i].path);
        strcat(textures[i].path, ".png");
        LOG_info("Registered Sprite texture", textures[i].path);
    }

    for     (int i = entityCount; i < entityCount + spriteCount; ++i) {
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

    for     (int i = entityCount; i < entityCount + spriteCount; ++i) {
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

    for     (int i = entityCount; i < entityCount + spriteCount; ++i) {
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

    for     (int i = entityCount; i < entityCount + spriteCount; ++i) {
        strcpy(animations[i].path, basePath);
        strcat(animations[i].path, "animations/");
        strcat(animations[i].path, names[i].path);
        strcat(animations[i].path, ".eaf");
        LOG_info("Registered animation", animations[i].path);
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

void    RMG_free    () {
}
