#include "model.h"

int     MOD_loadModel   (char*  path, int   type) {
    int     alreadyExisting = 0;
    /* Check if model is already existing. */
    ++numModels;
    modelList   =   realloc(modelList, numModels * sizeof(struct Model));
    modelList[numModels - 1].path   =   path;
    modelList[numModels - 1].type   =   type;
    if  (type == 0) {
        loadPmf3d(numModels - 1);
    }
    else if (type == 1) {
        loadPmf2d(numModels - 1);
    }
    return numModels - 1;
}

void    loadPmf3d         (int    id) {
    int     loadMode    =   0;  // 0 = Vertices, 1 = Indices
    FILE*   pmfFile     =   fopen(modelList[id].path, "r");
    char    currentLine[100];
    int     linePointer =   0;

    /* Temporary variables for GL data construction. */
    struct Vertex*  vertices    =   malloc(sizeof(struct Vertex));
    unsigned int*   indices     =   malloc(sizeof(unsigned int));
    int             numVertices     =   0;
    unsigned int    numIndices      =   0;

    char delimiter[]    =   " ";    // Separator between line Positions

    if  (!pmfFile)
        printf("[ERROR] File: %s could not be opened!", modelList[id].path);
   
    while   (fgets(currentLine, 100, pmfFile)) {
        int     linePosition    =   0;  // To switch between x/y/z/normalX/normalY/normalZ/textureX/textureY
        /* Split current line by spaces. */
        char*   lineWords   =   strtok(currentLine, delimiter);
        ++linePointer;
        /* Check if Load mode needs to be changed to Vertices. */
        if  (strncmp(currentLine, "Vertices", 8) == 0) {
            loadMode    =   0;
            continue;
        }
        /* Check if Load mode needs to be changed to Indices. */
        if  (strncmp(currentLine, "Indices", 7) == 0) {
            loadMode    =   1;
            continue;
        }
        /* Fill in Vertices. */
        if          (loadMode   ==  0) {
            ++numVertices;
            vertices    =   realloc(vertices, numVertices * sizeof(struct Vertex));
            struct Vertex   tempVertex;
            while   (lineWords) {
                float vertexAsNumber = atof(lineWords);
                switch(linePosition){
                    case 0:
                        tempVertex.x = vertexAsNumber;
                        break;
                    case 1:
                        tempVertex.y = vertexAsNumber;
                        break;
                    case 2:
                        tempVertex.z = vertexAsNumber;
                        break;
                    case 3:
                        tempVertex.normalX = vertexAsNumber;
                        break;
                    case 4:
                        tempVertex.normalY = vertexAsNumber;
                        break;
                    case 5:
                        tempVertex.normalZ = vertexAsNumber;
                        break;
                    case 6:
                        tempVertex.textureX = vertexAsNumber;
                        break;
                    case 7:
                        tempVertex.textureY = vertexAsNumber;
                        break;
                    default:
                        break;
                }
                /* Go to next space and increase linePosition to get next data. */
                ++linePosition;
                lineWords   =   strtok(NULL, delimiter);
            }
            /* Push back tempVertex to the list of vertices. */
            vertices[numVertices - 1] = tempVertex;
        }
        /* Fill in indices. */
        else if     (loadMode   ==  1) {
            ++numIndices;
            indices     =   realloc(indices, numIndices * sizeof(unsigned int));
            sscanf(currentLine, "%u", &indices[numIndices-1]);
        }
        else {
            printf("[ERROR] Unexpected loadMode in Model loader. How could this even happen?\n");
        }
    }

    /* Construct the OpenGL data of the vertices and indices. */
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(struct Vertex), &vertices[0], GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)offsetof(struct Vertex, normalX));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)offsetof(struct Vertex, textureX));
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // Unneccessary?
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), &indices[0], GL_DYNAMIC_DRAW);

    /* Push back GL data. */
    modelList[id].VAO   =   VAO;
    modelList[id].VBO   =   VBO;
    modelList[id].EBO   =   EBO;
    modelList[id].numIndices    =   numIndices;

    /* Free dynamic memory. */
    free(vertices);
    free(indices);
    fclose(pmfFile);
}

void    loadPmf2d   (int    id) {
    int loadMode    =   0;
    FILE*   pmfFile =   fopen(modelList[id].path, "r");
    char    currentLine[100];
    int     linePointer =   0;

    struct  Vertex* vertices    =   malloc(sizeof(struct Vertex));
    unsigned int*   indices     =   malloc(sizeof(unsigned int));
    int     numVertices =   0;
    unsigned int    numIndices  =   0;

    char    delimiter[]   =   " ";
    if  (!pmfFile)
        printf("Could not load 2d pmf file\n");
    while   (fgets(currentLine, 100, pmfFile)) {
        int     linePosition    =   0;
        char*   lineWords   =   strtok(currentLine, delimiter);
        ++linePointer;
        
        if  (strncmp(currentLine, "Vertices", 8) == 0) {
            loadMode    =   0;
            continue;
        }
        if  (strncmp(currentLine, "Indices", 7) == 0) {
            loadMode    =   1;
            continue;
        }
        if  (loadMode   ==  0) {
            ++numVertices;
            vertices    =   realloc(vertices, numVertices * sizeof(struct Vertex));
            struct Vertex   tempVertex;
            while   (lineWords) {
                float   vertexAsNumber  =   atof(lineWords);
                switch  (linePosition) {
                    case 0:
                        tempVertex.x    =   vertexAsNumber;
                        break;
                    case 1:
                        tempVertex.y    =   vertexAsNumber;
                        break;
                    case 2:
                        tempVertex.z    =   vertexAsNumber;
                    default:
                        break;
                }
                ++linePosition;
                lineWords   =   strtok(NULL, delimiter);
            }
            vertices[numVertices - 1]   =   tempVertex;
        }
        else if     (loadMode   ==  1) {
            ++numIndices;
            indices =   realloc(indices, numIndices * sizeof(unsigned int));
            sscanf(currentLine, "%u", &indices[numIndices - 1]);
        }
        else {
            printf("unexpected error in 2d loading.\n");
        }
    }

    unsigned int    VAO;
    unsigned int    VBO;
    unsigned int    EBO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(struct Vertex), &vertices[0], GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), &indices[0], GL_DYNAMIC_DRAW);

    modelList[id].VAO   =   VAO;
    modelList[id].VBO   =   VBO;
    modelList[id].EBO   =   EBO;
    modelList[id].numIndices    =   numIndices;

    free(vertices);
    free(indices);
    fclose(pmfFile);
}

void    MOD_drawModel   (int    id) {
    glBindVertexArray(modelList[id].VAO);
    glDrawElements(GL_TRIANGLES, modelList[id].numIndices, GL_UNSIGNED_INT, 0);
}

void    MOD_free        () {
    free(modelList);
}

