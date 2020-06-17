#include "model.h"

int     PMF_loadModel   (char*  path, int   type) {
    ++numModels;
    modelList   =   realloc(modelList, numModels * sizeof(struct Model));
    modelList[numModels - 1].path   =   path;
    modelList[numModels - 1].type   =   type;
    return numModels - 1;
}

void    loadPMF         (int    id) {
    int     loadMode    =   0;  // 0 = Vertices, 1 = Indices
    FILE*   pmfFile     =   fopen(modelList[id].path, "r");
    ssize_t read;
    size_t  lineLength  =   0;
    char*   currentLine;
    int     linePointer =   0;

    /* Temporary variables for GL data construction. */
    struct Vertex*  vertices;
    unsigned int*   indices;
    int             numVertices     =   0;
    unsigned int    numIndices      =   0;

    char delimiter[]    =   " ";    // Separator between line Positions

    if  (!pmfFile)
        printf("[ERROR] File: %s could not be opened!", modelList[id].path);
    
    while   ((read  =   getline(&currentLine, &lineLength, pmfFile)) != -1) {
        int     linePosition    =   0;  // To switch between x/y/z/normalX/normalY/normalZ/textureX/textureY
        /* Split current line by spaces. */
        char*   lineWords   =   strtok(currentLine, delimiter);
        ++linePointer;
        /* Check if Load mode needs to be changed to Vertices. */
        if  (strncmp(currentLine, "Vertices", 8) == 0) {
            loadMode    =   0;
            break;
        }
        /* Check if Load mode needs to be changed to Indices. */
        if  (strncmp(currentLine, "Indices", 7) == 0) {
            loadMode    =   1;
            break;
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
            vertices[numvertices - 1] = tempVertex;
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
}

void    PMF_drawModel   (int    id) {

}
