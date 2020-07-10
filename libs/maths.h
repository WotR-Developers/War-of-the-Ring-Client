#ifndef FOURTH_AGE_CLIENT_MATHS
#define FOURTH_AGE_CLIENT_MATHS

/* To get access to maths functions. */
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/* Mathematical defines. */
#define     PI  3.1415926535

/* Mathematical structures. */

typedef struct {
    float   x;
    float   y;
    float   z;
} vec3;

typedef struct {
    float   x;
    float   y;
    float   z;
    float   w;
} vec4;

typedef float mat4[4][4];

/* General functions. */
float   MAT_degToRad    (float  deg);
float   MAT_radToDeg    (float  rad);

/* Vector functions. */

void    MAT_addVec3 (vec3   *dest, vec3 add);
void    MAT_addVec4 (vec4   *dest, vec4 add);

void    MAT_subVec3 (vec3   *dest, vec3 sub);
void    MAT_subVec4 (vec4   *dest, vec4 sub);

void    MAT_scaleVec3   (vec3   *dest, float    scale);
void    MAT_scaleVec4   (vec4   *dest, float    scale);

void    MAT_mulVec3 (vec3   *dest, vec3 mul);
void    MAT_mulVec4 (vec4   *dest, vec4 mul);

void    MAT_crossVec3   (vec3   *dest, vec3 mul);
void    MAT_crossVec4   (vec4   *dest, vec4 mul);

vec3    MAT_getAddVec3  (vec3   firstVec, vec3  secondVec);
vec4    MAT_getAddVec4  (vec4   firstVec, vec4  secondVec);

vec3    MAT_getSubVec3  (vec3   firstVec, vec3  secondVec);
vec4    MAT_getSubVec4  (vec4   firstVec, vec4  secondVec);

vec3    MAT_getCrossVec3    (vec3   firstVec, vec3  secondVec);
vec4    MAT_getCrossVec4    (vec4   firstVec, vec4  secondVec);

vec3    MAT_getConnectionVec3   (vec3   firstVec, vec3  secondVec);
vec4    MAT_getConnectionVec4   (vec4   firstVec, vec4  secondVec);

float   MAT_getMagnitudeVec3    (vec3   vec);
float   MAT_getMagnitudeVec4    (vec4   vec);

vec3    MAT_getNormalizedVec3   (vec3   vec);
vec4    MAT_getNormalizedVec4   (vec4   vec);

vec3    MAT_getCenterVec3   (vec3   firstVec, vec3  secondVec);
vec4    MAT_getCenterVec4   (vec4   firstVec, vec4  secondVec);

float   MAT_getAngleVec3    (vec3   firstVec, vec3  secondVec);
float   MAT_getAngleVec4    (vec4   firstVec, vec4  secondVec);

float   MAT_getDotProductVec3   (vec3   firstVec, vec3  secondVec);
float   MAT_getDotProductVec4   (vec4   firstVec, vec4  secondVec);

vec3    MAT_getScaleVec3    (vec3   vec, float  scale);
vec4    MAT_getScaleVec4    (vec4   vec, float  scale);

/* Returns 1 if parallel, 0 if not. */
int     MAT_validateParallelismVec3 (vec3   firstVec, vec3  secondVec);
int     MAT_validateParallelismVec4 (vec4   firstVec, vec4  secondVec);

/* Returns 1 if antiparallel, 0 if not. */
int     MAT_validateAntiParallelismVec3 (vec3   firstVec, vec3  secondVec);
int     MAT_validateAntiParallelismVec4 (vec4   firstVec, vec4  secondVec);

/* Returns 1 if counter-vector, 0 if not. */
int     MAT_validateCounterVec3     (vec3   firstVec, vec3  secondVec);
int     MAT_validateCounterVec4     (vec4   firstVec, vec4  secondVec);

/* Matrix functions. */

void    MAT_initMat4            (mat4   mat);

void    MAT_printMat4           (mat4   mat);

void    MAT_multiplyMat4        (mat4   firstMat,   mat4    secondMat);

void    MAT_getViewMatrix       (mat4   modelMatrix, vec3   eye, vec3   at, vec3    up);

void    MAT_getPerspectiveMatrix    (mat4 perspectiveMatrix, float   near, float far, float  fov, float  aspectRatio);

void    MAT_getOrthogonalMatrix (mat4   orthogonalMatrix, float   near, float far, float  fov, float  aspectRatio);

void    MAT_getModelMatrix      (mat4   modelMatrix, vec3   position, vec3  rotation, vec3  scale);

#endif
