#pragma once

#include <math.h>
#include <stdio.h>
#include "../vector/vec3.h"
#include "../math/toradians.h"

typedef struct {
	
	float data[4][4];
	
} QsrMat4f;

typedef struct {
	
	int data[4][4];
	
} QsrMat4i;

typedef struct {
	
	unsigned int data[4][4];
	
} QsrMat4u;



void qsrInitMat4f(QsrMat4f* mat);
void qsrInitMat4fTo(QsrMat4f* mat, float number);

QsrMat4i qsrGetMat4fAsMat4i(QsrMat4f* toConvert);
QsrMat4u qsrGetMat4fAsMat4u(QsrMat4f* toConvert);

QsrMat4f qsrMultMat4f(QsrMat4f* input1, QsrMat4f* input2);
QsrMat4f qsrGetIdentMat4f();
void qsrIdentMat4f(QsrMat4f* input);

void qsrPerspectiveMat4f(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest);
void qsrGetMat4fColumnMajor(QsrMat4f* mat, float* data);
void qsrTranslateMat4fVec(QsrMat4f* mat, QsrVec3f* toTranslate);
void qsrRotateMat4fVec(QsrMat4f* mat, QsrVec3f* toRotate);
void qsrMat4fLookAt(QsrMat4f* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);





void qsrInitMat4i(QsrMat4i* mat);
void qsrInitMat4iTo(QsrMat4i* mat, int number);

QsrMat4f qsrGetMat4iAsMat4f(QsrMat4i* toConvert);
QsrMat4u qsrGetMat4iAsMat4u(QsrMat4i* toConvert);

QsrMat4i qsrMultMat4i(QsrMat4i* input1, QsrMat4i* input2);
QsrMat4i qsrGetIdentMat4i();
void qsrIdentMat4i(QsrMat4i* input);

void qsrGetMat4iColumnMajor(QsrMat4i* mat, int* data);
void qsrTranslateMat4iVec(QsrMat4i* mat, QsrVec3i* toTranslate);
void qsrMat4iLookAt(QsrMat4i* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);





void qsrInitMat4u(QsrMat4u* mat);
void qsrInitMat4uTo(QsrMat4u* mat, unsigned int number);

QsrMat4f qsrGetMat4uAsMat4f(QsrMat4u* toConvert);
QsrMat4i qsrGetMat4uAsMat4i(QsrMat4u* toConvert);

QsrMat4u qsrMultMat4u(QsrMat4u* input1, QsrMat4u* input2);
QsrMat4u qsrGetIdentMat4u();
void qsrIdentMat4u(QsrMat4u* input);

void qsrGetMat4uColumnMajor(QsrMat4u* mat, unsigned int* data);
void qsrTranslateMat4uVec(QsrMat4u* mat, QsrVec3u* toTranslate);
void qsrMat4uLookAt(QsrMat4u* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);

