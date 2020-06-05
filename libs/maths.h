#ifndef THE_FOURTH_AGE_MATHS_H
#define THE_FOURTH_AGE_MATHS_H

#include <stdio.h>
#include <math.h>

typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

typedef vec4 mat4[4];

void  MAT_addVec4               (vec4  *source, vec4  add);

void  MAT_addVec3               (vec3  *source, vec3  add);

void   MAT_subVec4              (vec4  *source, vec4  sub);

void   MAT_subVec3              (vec3  *source, vec3  sub);

void   MAT_mulVec4              (vec4  *source, float scalar);

void   MAT_mulVec3              (vec3  *source, float scalar);

void   MAT_crossVec4            (vec4  *source, vec4  cross);

void   MAT_crossVec3            (vec3  *source, vec3  cross);

void   MAT_dotVec4              (vec4  *source, vec4  cross);

void   MAT_dotVec3              (vec3  *source, vec3  cross);

void   MAT_unitVec4             (vec4  *source);

void   MAT_unitVec3             (vec3  *source);

double MAT_getMagnitudeVec4     (vec4  source);

double MAT_getMagnitudeVec3     (vec3  source);

void   MAT_identityMat4         (mat4  *source);

void   MAT_dotMat4              (mat4  *source, mat4  mul);

#endif //THE_FOURTH_AGE_MATHS_H
