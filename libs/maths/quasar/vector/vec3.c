#include "vec3.h"

void qsrInitVec3f(QsrVec3f* vec) {
	
	vec->x = 0.0f;
	vec->y = 0.0f;
	vec->z = 0.0f;
}

float qsrGetVec3fLength(QsrVec3f* vec) {
	
	return sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

QsrVec3f qsrNormalizeVec3f(QsrVec3f* vec) {
	
	QsrVec3f output;
	
	float length = qsrGetVec3fLength(vec);
	
	output.x = vec->x  / length;
	output.y = vec->y  / length;
	output.z = vec->z  / length;
	
	return output;
}





void qsrInitVec3i(QsrVec3i* vec) {
	
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

float qsrGetVec3iLength(QsrVec3i* vec) {
	
	return sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

QsrVec3i qsrNormalizeVec3i(QsrVec3i* vec) {
	
	QsrVec3i output;
	
	float length = qsrGetVec3iLength(vec);
	
	output.x = vec->x  / length;
	output.y = vec->y  / length;
	output.z = vec->z  / length;
	
	return output;
}





void qsrInitVec3u(QsrVec3u* vec) {
	
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

float qsrGetVec3uLength(QsrVec3u* vec) {
	
	return sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

QsrVec3u qsrNormalizeVec3u(QsrVec3u* vec) {
	
	QsrVec3u output;
	
	float length = qsrGetVec3uLength(vec);
	
	output.x = vec->x  / length;
	output.y = vec->y  / length;
	output.z = vec->z  / length;
	
	return output;
}

