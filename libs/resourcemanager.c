#include "resourcemanager.h"

void    RMG_loadResources   (char*  path) {
    basePath = path;
    
    char entityFile[100];
    strcpy(entityFile, basePath);
    strcat(entityFile, "entities.txt");
    
    FILE*   entitiesFile = fopen(entityFile, "r");
    if(entitiesFile == NULL)
        LOG_error("File not found exception", "entities.txt could not be found. Terminating.");
    
    char    line[100];
    int     lineNumber;   
    while   (fgets(line, sizeof(line), entitiesFile) != NULL) {
        ++lineNumber;
        ++entityCount;
        for     (int i = 0; ;i++) {
            if      (line[i] == '\n') {
                line[i] = '\0';
                break;
            }
        }
        names   =   realloc(names, lineNumber * sizeof(struct RMGName));
        strcpy(&names[entityCount].path, line);
        textures    =   realloc(textures, lineNumber * sizeof(struct TexturePath)); //Invalid pointer on third loop iteration
        models  =   realloc(models, lineNumber * sizeof(struct ModelPath));
        vertexShaders   =   realloc(vertexShaders, lineNumber * sizeof(struct VertexShaderPath));
        fragmentShaders =   realloc(fragmentShaders, lineNumber * sizeof(struct FragmentShaderPath));
        animations   =   realloc(animations, lineNumber * sizeof(struct AnimationPath));
    }
    
    for     (int i = 0; i <= entityCount; i++) {
        strcpy(&textures[entityCount].path, basePath);
        strcat(&textures[entityCount].path, "textures/");
        strcat(&textures[entityCount].path, &names[entityCount].path);
        strcat(&textures[entityCount].path, ".png");
    }

    for     (int i = 0; i <= entityCount; i++) {
        strcpy(&models[entityCount].path, basePath);
        strcat(&models[entityCount].path, "models/");
        strcat(&models[entityCount].path, &names[entityCount].path);
        strcat(&models[entityCount].path, ".pmf");
    }


    for     (int i = 0; i <= entityCount; i++) {
        strcpy(&vertexShaders[entityCount].path, basePath);
        strcat(&vertexShaders[entityCount].path, "shaders/");
        strcat(&vertexShaders[entityCount].path, &names[entityCount].path);
        strcat(&vertexShaders[entityCount].path, ".vs");
    }


    for     (int i = 0; i <= entityCount; i++) {
        strcpy(&fragmentShaders[entityCount].path, basePath);
        strcat(&fragmentShaders[entityCount].path, "shaders/");
        strcat(&fragmentShaders[entityCount].path, &names[entityCount].path);
        strcat(&fragmentShaders[entityCount].path, ".fs");
    }

    for     (int i = 0; i <= entityCount; i++) {
        strcpy(&animations[entityCount].path, basePath);
        strcat(&animations[entityCount].path, "animations/");
        strcat(&animations[entityCount].path, &names[entityCount].path);
        strcat(&animations[entityCount].path, ".eaf");
    }
}

void    RMG_free    () {
    free(names);
    free(textures);
    free(models);
    free(vertexShaders);
    free(fragmentShaders);
    free(animations);
}
