#pragma once

#include <math.h>

typedef struct {
	
	float x;
	float y;
	float z;
	
} QsrVec3f;

typedef struct {
	
	int x;
	int y;
	int z;
	
} QsrVec3i;

typedef struct {
	
	unsigned int x;
	unsigned int y;
	unsigned int z;
	
} QsrVec3u;



void qsrInitVec3f(QsrVec3f* vec);

float qsrGetVec3fLength(QsrVec3f* vec);
QsrVec3f qsrNormalizeVec3f(QsrVec3f vec);


void qsrInitVec3i(QsrVec3i* vec);

float qsrGetVec3iLength(QsrVec3i* vec);
QsrVec3i qsrNormalizeVec3i(QsrVec3i vec);



void qsrInitVec3u(QsrVec3u* vec);

float qsrGetVec3uLength(QsrVec3u* vec);
QsrVec3u qsrNormalizeVec3u(QsrVec3u vec);

QsrVec3f qsrAddVec3f(QsrVec3f vec1, QsrVec3f vec2);
QsrVec3f qsrSubVec3f(QsrVec3f vec1, QsrVec3f vec2);

QsrVec3f qsrCrossVec3f(QsrVec3f vec1, QsrVec3f vec2);
QsrVec3f qsrScaleVec3f(QsrVec3f vec, float scalar);
