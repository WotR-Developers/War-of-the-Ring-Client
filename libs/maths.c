#include "maths.h"

float   MAT_degToRad    (float  deg) {
    return (deg * PI / 180);
}

float   MAT_radToDeg    (float  rad) {
    return (rad * 180 / PI);
}

void    MAT_addVec3 (vec3   *dest, vec3 add) {
    dest->x +=  add.x;
    dest->y +=  add.y;
    dest->z +=  add.z;
}

void    MAT_addVec4 (vec4   *dest, vec4 add) {
    dest->x +=  add.x;
    dest->y +=  add.y;
    dest->z +=  add.z;
    dest->w +=  add.w;
}

void    MAT_subVec3 (vec3   *dest, vec3 sub) {
    dest->x -=  sub.x;
    dest->y -=  sub.y;
    dest->z -=  sub.z;
}

void    MAT_subVec4 (vec4   *dest, vec4 sub) {
    dest->x -=  sub.x;
    dest->y -=  sub.y;
    dest->z -=  sub.z;
    dest->w -=  sub.w;
}

void    MAT_scaleVec3   (vec3   *dest, float    scale) {
    dest->x *=  scale;
    dest->y *=  scale;
    dest->z *=  scale;
}

void    MAT_scaleVec4   (vec4   *dest, float    scale) {
    dest->x *=  scale;
    dest->y *=  scale;
    dest->z *=  scale;
    dest->w *=  scale;
}

void    MAT_mulVec3 (vec3   *dest, vec3 mul) {
    dest->x *=  mul.x;
    dest->y *=  mul.y;
    dest->z *=  mul.z;
}

void    MAT_mulVec4 (vec4   *dest, vec4 mul) {
    dest->x *=  mul.x;
    dest->y *=  mul.y;
    dest->z *=  mul.z;
    dest->w *=  mul.w;
}

void    MAT_crossVec3 (vec3   *dest, vec3 mul) {
    vec3 temp;
    temp.x  =   dest->y * mul.z - dest->z * mul.y;
    temp.y  =   dest->z * mul.x - dest->x * mul.z;
    temp.z  =   dest->x * mul.y - dest->y * mul.x;
    dest->x =   temp.x;
    dest->y =   temp.y;
    dest->z =   temp.z;
}

void    MAT_crossVec4 (vec4   *dest, vec4 mul) {
    vec3 temp;
    temp.x  =   dest->y * mul.z - dest->z * mul.y;
    temp.y  =   dest->z * mul.x - dest->x * mul.z;
    temp.z  =   dest->x * mul.y - dest->y * mul.x;
    dest->x =   temp.x;
    dest->y =   temp.y;
    dest->z =   temp.z;
}

vec3    MAT_getAddVec3  (vec3   firstVec, vec3  secondVec) {
    vec3    returnVec;
    returnVec.x =   firstVec.x + secondVec.x;
    returnVec.y =   firstVec.y + secondVec.y;
    returnVec.z =   firstVec.z + secondVec.z;
    return returnVec;
}

vec4    MAT_getAddVec4  (vec4   firstVec, vec4  secondVec) {
    vec4    returnVec;
    returnVec.x =   firstVec.x + secondVec.x;
    returnVec.y =   firstVec.y + secondVec.y;
    returnVec.z =   firstVec.z + secondVec.z;
    return returnVec;
}

vec3    MAT_getSubVec3  (vec3   firstVec, vec3  secondVec) {
    vec3    returnVec;
    returnVec.x =   firstVec.x - secondVec.x;
    returnVec.y =   firstVec.y - secondVec.y;
    returnVec.z =   firstVec.z - secondVec.z;
    return returnVec;
}

vec4    MAT_getSubVec4  (vec4   firstVec, vec4  secondVec) {
    vec4    returnVec;
    returnVec.x =   firstVec.x - secondVec.x;
    returnVec.y =   firstVec.y - secondVec.y;
    returnVec.z =   firstVec.z - secondVec.z;
    return returnVec;
}

vec3    MAT_getCrossVec3    (vec3   firstVec, vec3  secondVec) {
    vec3 temp;
    temp.x  =   firstVec.y * secondVec.z - firstVec.z * secondVec.y;
    temp.y  =   firstVec.z * secondVec.x - firstVec.x * secondVec.z;
    temp.z  =   firstVec.x * secondVec.y - firstVec.y * secondVec.x;
    return temp;
}

vec4    MAT_getCrossVec4    (vec4   firstVec, vec4  secondVec) {
    vec4 temp;
    temp.x  =   firstVec.y * secondVec.z - firstVec.z * secondVec.y;
    temp.y  =   firstVec.z * secondVec.x - firstVec.x * secondVec.z;
    temp.z  =   firstVec.x * secondVec.y - firstVec.y * secondVec.x;
    return temp;
}

vec3    MAT_getConnectionVec3   (vec3   firstVec, vec3  secondVec) {
    MAT_subVec3(&secondVec, firstVec);
    return secondVec;
}

vec4    MAT_getConnectionVec4   (vec4   firstVec, vec4  secondVec) {
    MAT_subVec4(&secondVec, firstVec);
    return secondVec;
}

float   MAT_getMagnitudeVec3    (vec3   vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float   MAT_getMagnitudeVec4    (vec4   vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

vec3    MAT_getNormalizedVec3   (vec3   vec) {
    vec3 temp;
    float magnitude = MAT_getMagnitudeVec3(vec);
    if  (magnitude == 0.0f) {
        return vec;
    }
    temp.x = vec.x / magnitude;
    temp.y = vec.y / magnitude;
    temp.z = vec.z / magnitude;
    return temp;
}

vec4    MAT_getNormalizedVec4   (vec4   vec) {
    vec4 temp;
    float magnitude = MAT_getMagnitudeVec4(vec);
    temp.x = vec.x / magnitude;
    temp.y = vec.y / magnitude;
    temp.z = vec.z / magnitude;
    temp.w = vec.w / magnitude;
    return temp;

}

vec3    MAT_getCenterVec3   (vec3   firstVec, vec3  secondVec) {
   vec3 temp;
   temp.x = firstVec.x + secondVec.x;
   temp.y = firstVec.y + secondVec.y;
   temp.z = firstVec.z + secondVec.z;
   temp.x /= 2;
   temp.y /= 2;
   temp.z /= 2;
   return temp;
}

vec4    MAT_getCenterVec4   (vec4   firstVec, vec4  secondVec) {
    vec4 temp;
    temp.x = firstVec.x + secondVec.x;
    temp.y = firstVec.y + secondVec.y;
    temp.z = firstVec.z + secondVec.z;
    temp.w = firstVec.w + secondVec.w;
    temp.x /= 2;
    temp.y /= 2;
    temp.z /= 2;
    temp.w /= 2;
    return temp;
}

float   MAT_getAngleVec3    (vec3   firstVec, vec3  secondVec) {
    float v =   firstVec.x * secondVec.x + firstVec.y * secondVec.y + firstVec.z * secondVec.z;
    return acos(v / MAT_getMagnitudeVec3(firstVec) / MAT_getMagnitudeVec3(secondVec));
}

float   MAT_getAngleVec4    (vec4   firstVec, vec4  secondVec) {
    float v =   firstVec.x * secondVec.x + firstVec.y * secondVec.y + firstVec.z * secondVec.z + firstVec.w * secondVec.w;
    return acos(v / MAT_getMagnitudeVec4(firstVec) / MAT_getMagnitudeVec4(secondVec));
}

float   MAT_getDotProductVec3   (vec3   firstVec, vec3  secondVec) {
    return firstVec.x * secondVec.x + firstVec.y * secondVec.y + firstVec.z * secondVec.z;
}

float   MAT_getDotProductVec4   (vec4   firstVec, vec4  secondVec) {
    return firstVec.x * secondVec.x + firstVec.y * secondVec.y + firstVec.z * secondVec.z;
}

vec3    MAT_getScaleVec3    (vec3   vec, float  scale) {
    vec3    temp    =   vec;
    temp.x  *=  scale;
    temp.y  *=  scale;
    temp.z  *=  scale;
    return temp;
}

vec4    MAT_getScaleVec4    (vec4   vec, float  scale) {
    vec4    temp    =   vec;
    temp.x  *=  scale;
    temp.y  *=  scale;
    temp.z  *=  scale;
    return temp;
}

int     MAT_validateParallelismVec3 (vec3   firstVec, vec3  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale < 0) 
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

int     MAT_validateParallelismVec4 (vec4   firstVec, vec4  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale < 0)
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

int     MAT_validateAntiParallelismVec3 (vec3   firstVec, vec3  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale > 0) 
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

int     MAT_validateAntiParallelismVec4 (vec4   firstVec, vec4  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale > 0) 
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

int     MAT_validateCounterVec3     (vec3   firstVec, vec3  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale != -1) 
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

int     MAT_validateCounterVec4     (vec4   firstVec, vec4  secondVec) {
    float firstScale = firstVec.x / secondVec.x;
    if  (firstScale != -1) 
        return 0;
    if  ((firstVec.y / secondVec.y) != firstScale)
        return 0;
    if  ((firstVec.z / secondVec.z) != firstScale)
        return 0;
    return 1;
}

void    MAT_getViewMatrix       (mat4   viewMatrix, vec3   eye, vec3   at, vec3    up) {
    /* Look At calculation. */
    vec3    zaxis   =   MAT_getNormalizedVec3(MAT_getSubVec3(at, eye)); //eye-at
    vec3    xaxis   =   MAT_getNormalizedVec3(MAT_getCrossVec3(zaxis, up));
    vec3    yaxis   =   MAT_getCrossVec3(xaxis, zaxis);
    for     (int i = 0; i < 4; ++i) {
        for     (int j = 0; j < 4; ++j) {
            viewMatrix[i][j]    =   0.0f;
            if  (i == j)
                viewMatrix[i][j] = 1.0f;
        } 
    }
    viewMatrix[0][0]    =   xaxis.x;
    viewMatrix[1][0]    =   xaxis.y;
    viewMatrix[2][0]    =   xaxis.z;
    viewMatrix[0][1]    =   yaxis.x;
    viewMatrix[1][1]    =   yaxis.y;
    viewMatrix[2][1]    =   yaxis.z;
    viewMatrix[0][2]    =   -zaxis.x;
    viewMatrix[1][2]    =   -zaxis.y;
    viewMatrix[2][2]    =   -zaxis.z;
    viewMatrix[3][0]    =   -MAT_getDotProductVec3(xaxis, eye);
    viewMatrix[3][1]    =   -MAT_getDotProductVec3(yaxis, eye);
    viewMatrix[3][2]    =   MAT_getDotProductVec3(zaxis, eye);
}

void    MAT_getPerspectiveMatrix    (mat4   perspectiveMatrix, float   near, float far, float  fov, float  aspectRatio) {
    float   top     =   tan(fov / 2);
    float   bottom  =   -top;
    float   right   =   top * aspectRatio;
    float   left    =   bottom * aspectRatio;
    for     (int i = 0; i < 4; ++i) {
        for     (int j = 0; j < 4; ++j) {
            perspectiveMatrix[i][j] =   0.0f;
            if  (i == j)
                perspectiveMatrix[i][j] = 1.0f;
        }
    }
    perspectiveMatrix[0][0] =   1.0f / (aspectRatio * top);
    perspectiveMatrix[1][1] =   1.0f / top;
    perspectiveMatrix[2][2] =   far / (near - far);
    perspectiveMatrix[2][3] =   -1.0f;
    perspectiveMatrix[3][2] =   -(far * near) / (far - near);
    perspectiveMatrix[3][3] =   0.0f;
}

void    MAT_getOrthogonalMatrix     (mat4   orthogonalMatrix, float   near, float far, float  fov, float  aspectRatio) {
    float   top     =   tan(fov / 2) * near;
    float   bottom  =   -top;
    float   right   =   top * aspectRatio;
    float   left    =   bottom * aspectRatio;
    for     (int i = 0; i < 4; ++i) {
        for     (int j = 0; j < 4; ++j) {
            orthogonalMatrix[i][j] = 0.0f;
        }
    }
    orthogonalMatrix[0][0]  =   2 / (right - left);
    orthogonalMatrix[0][3]  =   -((right + left) / (right - left));
    orthogonalMatrix[1][1]  =   2 / (top - bottom);
    orthogonalMatrix[1][3]  =   -((top + bottom) / (top - bottom));
    orthogonalMatrix[2][2]  =   -2 / (far - near);
    orthogonalMatrix[2][3]  =   -((far + near) / (far - near));
    orthogonalMatrix[3][3]  =   1;
}

void    MAT_getModelMatrix          (mat4   modelMatrix, vec3 position, vec3  rotation, vec3  scale) {
    for     (int i = 0; i < 4; ++i) {
        for     (int j = 0; j < 4; ++j) {
            modelMatrix[i][j]   =   0.0f;
        }
    }
    modelMatrix[3][0]   =   position.x;
    modelMatrix[3][1]   =   position.y;
    modelMatrix[3][2]   =   position.z;
    modelMatrix[0][0]   =   scale.x;
    modelMatrix[1][1]   =   scale.y;
    modelMatrix[2][2]   =   scale.z;
    modelMatrix[3][3]   =   1.0f;
}

