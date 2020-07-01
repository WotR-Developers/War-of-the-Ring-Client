#include "maths.h"

float   degToRad    (float  deg) {

}

float   radToDeg    (float  rad) {

}

void    addVec3 (vec3   *dest, vec3 add) {

}
void    addVec4 (vec4   *dest, vec4 add) {

}

void    subVec3 (vec3   *dest, vec3 sub) {

}

void    subVec4 (vec4   *dest, vec4 sub) {

}

void    scaleVec3   (vec3   *dest, float    scale) {

}

void    scaleVec4   (vec4   *dest, float    scale) {

}

void    mulVec3 (vec3   *dest, vec3 mul) {

}

void    mulVec4 (vec4   *dest, vec4 mul) {

}

vec3    getConnectionVec3   (vec3   firstVec, vec3  secondVec) {

}

vec4    getConnectionVec4   (vec4   firstVec, vec4  secondVec) {

}

float   getMagnitudeVec3    (vec3   vec) {

}

float   getMagnitudeVec4    (vec4   vec) {

}

vec3    getNormalizedVec3   (vec3   vec) {

}

vec4    getNormalizedVec4   (vec4   vec) {

}

vec3    getCenterVec3   (vec3   firstVec, vec3  secondVec) {

}

vec4    getCenterVec4   (vec4   firstVec, vec4  secondVec) {

}

float   getAngleVec3    (vec3   firstVec, vec3  secondVec) {

}

float   getAngleVec4    (vec4   firstVec, vec3  secondVec) {

}

vec3    getCrossVec3    (vec3   firstVec, vec3  secondVec) {

}

vec4    getCrossVec4    (vec4   firstVec, vec4  secondVec) {

}

int     validateParallelismVec3 (vec3   firstVec, vec3  secondVec) {

}

int     validateParallelismVec4 (vec4   firstVec, vec4  secondVec) {

}

int     validateAntiParallelismVec3 (vec3   firstVec, vec3  secondVec) {

}

int     validateAntiParallelismVec4 (vec4   firstVec, vec4  secondVec) {

}

int     validateCounterVec3     (vec3   firstVec, vec3  secondVec) {

}

int     validateCounterVec4     (vec4   firstVec, vec4  secondVec) {

}

float**     getViewMatrix   (vec3   eye, vec3   at, vec3    up) {

}

float**     getPerspectiveMatrix    (float  top, float  bottom, float   right, float    left, float fov) {

}

float**     getOrthogonalMatrix     (float  top, float  bottom, float   right, float    left, float fov) {

}

float**     getModelMatrix  (vec3   position, vec3  rotation, vec3  scale) {

}

