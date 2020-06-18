#pragma once

#include <math.h>
#include <stdio.h>
#include "../vector/vec3.h"
#include "../math/toradians.h"
#include "../strings/qsrstring.h"

typedef struct {
	
	float data[4][4];
	
} QsrMat4f;

typedef struct {
	
	int data[4][4];
	
} QsrMat4i;

typedef struct {
	
	unsigned int data[4][4];
	
} QsrMat4u;



void qsrMat4fInit(QsrMat4f* mat);
void qsrMat4fInitTo(QsrMat4f* mat, float number);

QsrMat4i qsrMat4fToMat4i(QsrMat4f* toConvert);
QsrMat4u qsrMat4fToMat4u(QsrMat4f* toConvert);

QsrMat4f qsrMat4fMultiply(QsrMat4f* input1, QsrMat4f* input2);
QsrMat4f qsrMat4fGetIdent();
void qsrMat4fSetToIdent(QsrMat4f* input);

void qsrMat4fPersp(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest);
void qsrMat4fOrtho(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest);
void qsrMat4fWriteTransposed(QsrMat4f* mat, float* data);
void qsrMat4fTranspose(QsrMat4f* mat); // TODO
void qsrMat4fTranslateByVec(QsrMat4f* mat, QsrVec3f* toTranslate);
void qsrMat4fRotateByVec(QsrMat4f* mat, QsrVec3f* toRotate);
void qsrMat4fScaleByVec(QsrMat4f* mat, QsrVec3f* toScale);
void qsrMat4fSetToLookAt(QsrMat4f* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);

char* qsrMat4fGetChars(QsrMat4f* input); // TODO
QsrString qsrMat4fGetQsrString(QsrMat4f* input); // TODO
// NOTE: If the label is NULL, no label/ name of the mat4 will be printed
void  qsrMat4fPrint(QsrMat4f* input, char* label);



void qsrMat4iInit(QsrMat4i* mat);
void qsrMat4iInitTo(QsrMat4i* mat, int number);

QsrMat4f qsrMat4iToMat4f(QsrMat4i* toConvert);
QsrMat4u qsrMat4iToMat4u(QsrMat4i* toConvert);

QsrMat4i qsrMat4iMultiply(QsrMat4i* input1, QsrMat4i* input2);
QsrMat4i qsrMat4iGetIdent();
void qsrMat4iSetToIdent(QsrMat4i* input);

void qsrMat4iWriteTransposed(QsrMat4i* mat, int* data);
void qsrMat4iTranspose(QsrMat4i* mat); // TODO
void qsrMat4iTranslateByVec(QsrMat4i* mat, QsrVec3i* toTranslate);
void qsrMat4iScaleByVec(QsrMat4i* mat, QsrVec3i* toScale);
void qsrMat4iSetToLookAt(QsrMat4i* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);

char* qsrMat4iGetChars(QsrMat4i* input); // TODO
QsrString qsrMat4iGetQsrString(QsrMat4i* input); // TODO
// NOTE: If the label is NULL, no label/ name of the mat4 will be printed
void  qsrMat4iPrint(QsrMat4i* input, char* label);

// TODO: Add some more convenience - functions, e.g. getting matrix-contents as QsrString or a way to transpose a matrix and let it look in-place


void qsrMat4uInit(QsrMat4u* mat);
void qsrMat4uInitTo(QsrMat4u* mat, unsigned int number);

QsrMat4f qsrMat4uToMat4f(QsrMat4u* toConvert);
QsrMat4i qsrMat4uToMat4i(QsrMat4u* toConvert);

QsrMat4u qsrMat4uMult(QsrMat4u* input1, QsrMat4u* input2);
QsrMat4u qsrMat4uGetIdent();
void qsrMat4uSetToIdent(QsrMat4u* input);

void qsrMat4uWriteTransposed(QsrMat4u* mat, unsigned int* data);
void qsrMat4uTranspose(QsrMat4u* mat); // TODO
void qsrMat4uTranslateByVec(QsrMat4u* mat, QsrVec3u* toTranslate);
void qsrMat4uScaleByVec(QsrMat4u* mat, QsrVec3u* toScale);
void qsrMat4uSetToLookAt(QsrMat4u* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up);

char* qsrMat4uGetChars(QsrMat4u* input); // TODO
QsrString qsrMat4uGetQsrString(QsrMat4u* input); // TODO
// NOTE: If the label is NULL, no label/ name of the mat4 will be printed
void  qsrMat4uPrint(QsrMat4u* input, char* label);

