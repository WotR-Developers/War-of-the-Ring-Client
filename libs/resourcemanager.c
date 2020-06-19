#include "resourcemanager.h"

void RMG_setBasePath(char *path) {
    basePath = path;
}

void RMG_loadResources() {
    /* Variables containing the paths. */
    char *animationPath;
    char *texturePath;
    char *modelPath;
    char *shaderPath;
    char *configPath;

    /* Contains a list of objects constructed through the configs and
     * the amount of objects. */
    char **objectList;
    int  objectCount;

    /* Construct the paths. */
    animationPath   = combineStrings(basePath, "animations/");
    texturePath     = combineStrings(basePath, "textures/");
    modelPath       = combineStrings(basePath, "models/");
    shaderPath      = combineStrings(basePath, "/shaders");
    configPath      = combineStrings(basePath, "/configs");

    /* Fill in the objectList */
    objectList = getFilesInDir(configPath, &objectCount);

    /* Temporary variables to read files */
    size_t maxLineLength = 255;
    char *line = malloc(maxLineLength * sizeof(char));
    int  currentLine = 0;
    char *objectName;
    char *objectType;
    char *objectModelName;
    char *objectTextureName;
    char *objectShaderName;
    char *objectAnimationName;
    FILE *tmpFileModelPath;
    FILE *tmpFileTexturePath;
    FILE *tmpFileShaderPath;
    FILE *tmpFileAnimationPath;

    /* Reads the config files in object lists,
     * tries to open the files set there,
     * if it fails exits with error code,
     * else pushes it back in appropriate array */
    for     (int i = 0; i < objectCount; i++) {
        FILE *tmpFile;      // A temporary file to open the config path.
        char*   fileToOpen  =   combineStrings(configPath, objectList[i][0]);
        tmpFile = fopen(fileToOpen, "r");
        free(fileToOpen);
        /* Check if file could be opened */
        if  (!tmpFile) {
            printf("[ResourceManager]\treturned critical error: Calculated config path could not be found!\n");
            return;
        }

        /* Read the file line by line */
        while   (fgets(line, maxLineLength, tmpFile)) {
            switch  (currentLine) {
                case 0:
                    /* Line 1, here is the object name. */
                    sscanf(line, "%s", &objectName);
                    currentLine++;
                case 1:
                    /* Line 2, here is the object type. */
                    sscanf(line, "%s", &objectType);
                    currentLine++;
                case 2:
                    /* Line 3, here is the model name. */
                    sscanf(line, "%s", &objectModelName);
                    currentLine++;
                case 3:
                    /* Line 4, here is the texture name. */
                    sscanf(line, "%s", &objectTextureName);
                    currentLine++;
                case 4:
                    /* Line 5, here is the shader name. */
                    sscanf(line, "%s", &objectShaderName);
                    currentLine++;
                case 5:
                    /* Line 6, here is the animation name. */
                    sscanf(line, "%s", &objectAnimationName);
                    currentLine++;
                default:
                    /* Not posible, throws error. */
                    printf("[ResourceManager]\tencountered critical error, config of object in invalid path reading line: %s\n", line);
                    return;
            }
        }

        /* Test if the files are existing.
         * For this create the test paths.*/
        // Test the model path.
        char*   pmfPath    =   combineStrings(modelPath, objectModelName);
        tmpFileModelPath = fopen(pmfPath, "r");
        if      (!tmpFileModelPath) {
            printf("[ResourceManager]\tcould not open model file of %s\n", objectName);
            return;
        }
        // Test the texture path.
        char*   texPath    =   combineStrings(texturePath, objectTextureName);
        tmpFileTexturePath = fopen(texPath, "r");
        if      (!tmpFileTexturePath) {
            printf("[ResourceManager]\tcould not open texture file of %s\n", objectName);
            return;
        }
        // Test the shader path.
        char*   shaPath    =   combineStrings(shaderPath, objectShaderName);
        tmpFileShaderPath = fopen(shaPath, "r");
        if      (!tmpFileShaderPath) {
            printf("[ResourceManager]\tcould not open shader file of %s\n", objectName);
            return;
        }
        // Test the animation path.
        char*   aniPath    =   combineStrings(animationPath, objectAnimationName);
        tmpFileAnimationPath = fopen(aniPath, "r");
        free(aniPath);
        if      (!tmpFileAnimationPath) {
            printf("[ResourceManager]\tcould not open animation file of %s\n", objectName);
            return;
        }

        /* Push the values back to the appropriate lists */
        names[i][0] = objectName;
        types[i][0] = objectType;
        textureNames[i][0] = texPath;
        animationNames[i][0] = aniPath;
        modelNames[i][0] = pmfPath;
        shaderNames[i][0] = shaPath;

        /* Clean up the variables */
        line = '\0';
        objectName = '\0';
        objectType = '\0';
        objectTextureName = '\0';
        objectAnimationName = '\0';
        objectModelName = '\0';
        objectShaderName = '\0';
        fclose(tmpFileModelPath);
        fclose(tmpFileTexturePath);
        fclose(tmpFileShaderPath);
        fclose(tmpFileAnimationPath);
        currentLine = 0;

        /* Increase object count */
        objectCount++;
    }
    free(line);
    free(animationPath);
    free(texturePath);
    free(modelPath);
    free(shaderPath);
    free(configPath);
}

char *RMG_getType(char *objectName) {
    int id;
    for     (id = 0; id < objectCount; id++) {
        if      (strcmp(objectName, &names[id]) == 0) {
            return &types[id];
        }
    }
    printf("[ResourceManager]\tTexture of %s could not be found!\n", objectName);
    return '\0';
}

char *RMG_getTexture(char *objectName) {
    int id;
    for     (id = 0; id < objectCount; id++) {
        if      (strcmp(objectName, &names[id]) == 0) {
            return &textureNames[id];
        }
    }
    printf("[ResourceManager]\tTexture of %s could not be found!\n", objectName);
    return '\0';
}

char *RMG_getModel(char *objectName) {
    int id;
    for     (id = 0; id < objectCount; id++) {
        if      (strcmp(objectName, &names[id]) == 0) {
            return &modelNames[id];
        }
    }
    printf("[ResourceManager]\tTexture of %s could not be found!\n", objectName);
    return '\0';
}

char *RMG_getAnimation(char *objectName) {
    int id;
    for     (id = 0; id < objectCount; id++) {
        if      (strcmp(objectName, &names[id]) == 0) {
            return &animationNames[id];
        }
    }
    printf("[ResourceManager]\tTexture of %s could not be found!\n", objectName);
    return '\0';
}

char *RMG_getShader(char *objectName) {
    int id;
    for     (id = 0; id < objectCount; id++) {
        if      (strcmp(objectName, &names[id]) == 0) {
            return &shaderNames[id];
        }
    }
    printf("[ResourceManager]\tTexture of %s could not be found!\n", objectName);
    return '\0';
}

char **getFilesInDir(char *path, int  *numContents) {
    char *currentFile;      // A temporary variable containing the name of the current file.
    char **returnList;      // A variable containing the list which will be returned.

    int numFiles = 0;       // Containing the current amount of files in the directory.
    int numLetters = 0;     // Containing the current amount of letters in the file name.

    DIR *readDir;
    struct dirent *readDirEntry;
    readDir = opendir(path);
    if      (readDir) {
        while       ((readDirEntry = readdir(readDir))) {
            if      (strcmp(readDirEntry->d_name, ".") && strcmp(readDirEntry->d_name, "..")) {
                for     (int i = 0; i < 256; i++) {
                    if      (readDirEntry->d_name[i] != '\0') {
                        /* Adds letter of current directory to the name of the directory */
                        numLetters++;
                        currentFile = realloc(currentFile, numLetters * sizeof(char));
                        currentFile[i] = readDirEntry->d_name[i];
                    }
                    else {
                        /* Adds current directory name to the returnList */
                        numFiles++;
                        returnList = realloc(returnList, numFiles * sizeof(char*));
                        returnList[numFiles - 1] = currentFile;
                        /* Resets variables */
                        numLetters = 0;
                        currentFile = malloc(1 * sizeof(char));
                        break;
                    }
                }
            }
            else {
                /* Finished reading directory, closes the directory and returns the returnList. */
                closedir(readDir);
                *numContents = numFiles;
                return returnList;
            }
        }
    }
    else {
        printf("[ResourceManager]\thas been called with an invalid path!\n");
        char *t = "\0";
        return *t;
    }
    free(currentFile);
    free(returnList);
}

char *combineStrings(char *str1, char *str2) {
    int  length = 0;            // The length of str1 + str2.
    int  oldStringLength = 0;   // The length of str1.
    char *out;
    /* Supposes the string is null-terminated and reads str1 as well as sets oldStringLength and Length.
     * Reallocates memory for the out  list. */
    for     (int i = 0; i < 200; i++) {
        if      (str1[i] != '\0') {
            length++;
            out = realloc(out, length * sizeof(char));
            out[i] = str1[i];
        }
        else {
            oldStringLength = length;
            break;
        }
    }
    /* Uses the oldStringLength to access the proper element of the array and reallocates memory
     * for the out list and returns it. */
    for     (int j = oldStringLength; j < 200; j++) {
        if      (str2[j - oldStringLength] != '\0') {
            length++;
            out = realloc(out, length * sizeof(char));
            out[j] = str2[j - oldStringLength];
        }
        else {
            out[length] = '\0';
            break;
        }
    }
    return out;
}

void    RMG_free    () {
    for     (int i = 0; i < objectCount; ++i) {
        free(names[i]);
        free(types[i]);
        free(textureNames[i]);
        free(animationNames[i]);
        free(modelNames[i]);
        free(shaderNames[i]);
    }
}
