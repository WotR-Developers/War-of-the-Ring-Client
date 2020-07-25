#include "shader.h"

unsigned    int     SHA_genShader       (char*  vertexShaderPath, char* fragmentShaderPath) {
    /* Check if already exists. */
    ++numShaders;
    shaderList  =   realloc(shaderList, numShaders * sizeof(struct Shader));
    char*           vertexShaderSource;
    char*           fragmentShaderSource;
    int             fragmentSourceLength;
    int             vertexSourceLength;
    FILE*           vertexShaderFile;
    FILE*           fragmentShaderFile;
    char            textBuffer[256];
    char            infoLogBuffer[512];

    /* Open Shader files */
    vertexShaderFile    =   fopen(vertexShaderPath, "r");
    fragmentShaderFile  =   fopen(fragmentShaderPath, "r");

    /* Read line by line vertex shader and add to source. */
    
    fseek(vertexShaderFile, 0, SEEK_END);
    long    vsFileSize  =   ftell(vertexShaderFile);
    fseek(vertexShaderFile, 0, SEEK_SET);
    vertexShaderSource  =   malloc((vsFileSize + 1) * sizeof(char));
    fread(vertexShaderSource, vsFileSize, 1, vertexShaderFile);
    fclose(vertexShaderFile);
    vertexShaderSource[vsFileSize]  =   0;

    /* Read line by line fragment shader and add to source. */
    
    fseek(fragmentShaderFile, 0, SEEK_END);
    long    fsFileSize  =   ftell(fragmentShaderFile);
    fseek(fragmentShaderFile, 0, SEEK_SET);
    fragmentShaderSource    =   malloc((fsFileSize + 1) * sizeof(char));
    fread(fragmentShaderSource, fsFileSize, 1, fragmentShaderFile);
    fclose(fragmentShaderFile);
    fragmentShaderSource[fsFileSize]    =   0;

    /* Create and compile shaders, check for success. */
    unsigned int    vertexShader    =   glCreateShader(GL_VERTEX_SHADER);
    unsigned int    fragmentShader  =   glCreateShader(GL_FRAGMENT_SHADER);

    const char*     vsSource    =   vertexShaderSource;
    const char*     fsSource    =   fragmentShaderSource;

    glShaderSource(vertexShader, 1, &vsSource, NULL);
    glShaderSource(fragmentShader, 1, &fsSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);
    
    int     vertexBoolSuccess;
    int     fragmentBoolSuccess;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexBoolSuccess);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentBoolSuccess);

    if  (!vertexBoolSuccess) {
        printf("[ERROR] Compilation of Vertex Shader failed. \n");
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLogBuffer);
        printf("[ERROR] %s\n", infoLogBuffer);
    }
    if  (!vertexBoolSuccess) {
        printf("[ERROR] Compilation of Fragment Shader failed. \n");
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLogBuffer);
        printf("[ERROR] %s\n", infoLogBuffer);
    }

    /* Create shader program. */
    unsigned int    shaderProgram   =   glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int boolLinkingSuccess;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &boolLinkingSuccess);
    if  (!boolLinkingSuccess) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLogBuffer);
        printf("[ERROR] Linking of shader program failed.\n");
        printf("[ERROR] %s\n", infoLogBuffer);
    }

    /* Set values and return. */
    shaderList[numShaders - 1].vertexName       =   vertexShaderPath;
    shaderList[numShaders - 1].fragmentName     =   fragmentShaderPath;
    shaderList[numShaders - 1].shaderProgram    =   shaderProgram;

    printf("Loaded shader program: %u\n", shaderProgram);
    
    /* Get all uniforms and cach them. */
    glUseProgram(shaderProgram);
    int     uniformCount;
    glGetProgramiv(shaderProgram, GL_ACTIVE_UNIFORMS, &uniformCount);
    shaderList[numShaders - 1].cachedUniforms   =   malloc(uniformCount * sizeof(struct Uniform));
    shaderList[numShaders - 1].uniformCount     =   uniformCount;
    GLsizei     nameLength;
    GLint       uniformSize;
    GLenum      uniformType;
    for     (int i = 0; i < uniformCount; ++i) {
        glGetActiveUniform(shaderProgram, i, 25, &nameLength, &uniformSize, &uniformType, shaderList[numShaders - 1].cachedUniforms[i].name);
        shaderList[numShaders - 1].cachedUniforms[i].uniformLocation    =   
            glGetUniformLocation(shaderProgram, shaderList[numShaders - 1].cachedUniforms[i].name);
    }
    
    glUseProgram(0);

    /* Free dynamic memory. */
    free(vertexShaderSource);
    free(fragmentShaderSource);

    return numShaders - 1;
}

void    SHA_bindShader      (unsigned   int    id) {
    glUseProgram(shaderList[id].shaderProgram);
    currentShader   =   shaderList[id].shaderProgram;
}

void    SHA_pushMatrix      (char*  name, mat4  matrix) {
    int     shaderUniform   =   -1;
    for     (int i = 0; i < shaderList[numShaders - 1].uniformCount; ++i) {
        if      (strcmp(shaderList[numShaders - 1].cachedUniforms[i].name, name) == 0) {
            shaderUniform   =   shaderList[numShaders - 1].cachedUniforms[i].uniformLocation;
            break;
        } 
    }
    glUniformMatrix4fv(shaderUniform, 1, GL_FALSE, &matrix[0][0]);
    if  (shaderUniform == -1)
        printf("Uniform: %s not found in shader program: %u\n", name, currentShader);
}

void    SHA_free            () {
    for     (int i = 0; i < numShaders; ++i) {
        free(shaderList[numShaders - 1].cachedUniforms);
    }
    free(shaderList);
}
