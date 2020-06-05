#include "maths.h"

void MAT_addVec4                (vec4 *source, vec4 add) {
    source->x   +=  add.x;
    source->y   +=  add.y;
    source->z   +=  add.z;
    source->w   +=  add.w;
}

void MAT_addVec3                (vec3 *source, vec3 add) {
    source->x   +=  add.x;
    source->y   +=  add.y;
    source->z   +=  add.z;
}

void MAT_subVec4                (vec4 *source, vec4 sub) {
    source->x   -=  sub.x;
    source->y   -=  sub.y;
    source->z   -=  sub.z;
    source->w   -=  sub.w;
}

void MAT_subVec3                (vec3 *source, vec3 sub) {
    source->x   -=  sub.x;
    source->y   -=  sub.y;
    source->z   -=  sub.z;
}

void MAT_mulVec4                (vec4 *source, float scalar) {
    source->x   *=  scalar;
    source->y   *=  scalar;
    source->z   *=  scalar;
}

void MAT_mulVec3                (vec3 *source, float scalar) {
    source->x   *=  scalar;
    source->y   *=  scalar;
    source->z   *=  scalar;
}

void MAT_crossVec4              (vec4 *source, vec4 cross) {
    source->x   =   source->y * cross.z - source->z * cross.y;
    source->y   =   source->z * cross.x - source->x * cross.z;
    source->z   =   source->x * cross.y - source->y * cross.x;
}

void MAT_crossVec3              (vec3 *source, vec3 cross) {
    source->x   =   source->y * cross.z - source->z * cross.y;
    source->y   =   source->z * cross.x - source->x * cross.z;
    source->z   =   source->x * cross.y - source->y * cross.x;
}

void MAT_dotVec4                (vec4 *source, vec4 cross) {
    source->x   *=  cross.x;
    source->y   *=  cross.y;
    source->z   *=  cross.z;
}

void MAT_dotVec3                (vec3 *source, vec3 cross) {
    source->x   *=  cross.x;
    source->y   *=  cross.y;
    source->z   *=  cross.z;
}

double MAT_getMagnitudeVec4     (vec4 source) {
    return sqrt(source.x * source.x + source.y * source.y + source.z * source.z);
}

double MAT_getMagnitudeVec3     (vec3 source) {
    return sqrt(source.x * source.x + source.y * source.y + source.z * source.z);
}

void MAT_unitVec4(vec4 *source) {
    double magnitude    =   MAT_getMagnitudeVec4(*source);
    MAT_mulVec4(source, 1 / magnitude);
}

void MAT_unitVec3(vec3 *source) {
    double magnitude    =   MAT_getMagnitudeVec3(*source);
    MAT_mulVec3(source, 1 / magnitude);
}

void MAT_identityMat4           (mat4 *source) {
    source[0]->x    =   1.0f;
    source[1]->y    =   1.0f;
    source[2]->z    =   1.0f;
    source[3]->w    =   1.0f;
}

void MAT_dotMat4                (mat4 *source, mat4  mul) {
    for     (int i = 0; i < 4; i++) {
        source[i]->x    =   source[i]->x * mul[0].x + source[i]->y * mul[1].x +
                            source[i]->z * mul[2].x + source[i]->w * mul[3].x;
        source[i]->y    =   source[i]->x * mul[0].y + source[i]->y * mul[1].y +
                            source[i]->z * mul[2].y + source[i]->w * mul[3].y;
        source[i]->z    =   source[i]->x * mul[0].z + source[i]->y * mul[1].z +
                            source[i]->z * mul[2].z + source[i]->w * mul[3].z;
        source[i]->w    =   source[i]->x * mul[0].w + source[i]->y * mul[1].w +
                            source[i]->z * mul[2].w + source[i]->w * mul[3].w;
    }
}
