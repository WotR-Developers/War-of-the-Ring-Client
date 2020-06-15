#include "mat4.h"

void qsrInitMat4f(QsrMat4f* mat) {
	
	mat->data[0][0] = 0.0f;
	mat->data[0][1] = 0.0f;
	mat->data[0][2] = 0.0f;
	mat->data[0][3] = 0.0f;
	mat->data[1][0] = 0.0f;
	mat->data[1][1] = 0.0f;
	mat->data[1][2] = 0.0f;
	mat->data[1][3] = 0.0f;
	mat->data[2][0] = 0.0f;
	mat->data[2][1] = 0.0f;
	mat->data[2][2] = 0.0f;
	mat->data[2][3] = 0.0f;
	mat->data[3][0] = 0.0f;
	mat->data[3][1] = 0.0f;
	mat->data[3][2] = 0.0f;
	mat->data[3][3] = 0.0f;
}

void qsrInitMat4fTo(QsrMat4f* mat, float number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[0][3] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[1][3] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
	mat->data[2][3] = number;
	mat->data[3][0] = number;
	mat->data[3][1] = number;
	mat->data[3][2] = number;
	mat->data[3][3] = number;
}

QsrMat4i qsrGetMat4fAsMat4i(QsrMat4f* toConvert) {
	
	QsrMat4i converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4u qsrGetMat4fAsMat4u(QsrMat4f* toConvert) {
	
	QsrMat4u converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4f qsrMultMat4f(QsrMat4f* input1, QsrMat4f* input2) {
	
	QsrMat4f output;
	qsrInitMat4f(&output);
	
	int i, j, k;
	
	i = 0;
	while(i < 4) {
		
		j = 0;
		while(j < 4) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 4) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				k++;
			}
			
			j++;
		}
		
		i++;
	}
	
}

QsrMat4f qsrGetIdentMat4f() {
	
	QsrMat4f mat;
	qsrInitMat4f(&mat);
	
	mat.data[0][0] = 1.0f;
	mat.data[1][1] = 1.0f;
	mat.data[2][2] = 1.0f;
	mat.data[3][3] = 1.0f;
	
	return mat;
}

void qsrIdentMat4f(QsrMat4f* mat) {
	
	mat->data[0][0] = 1.0f;
	mat->data[1][1] = 1.0f;
	mat->data[2][2] = 1.0f;
	mat->data[3][3] = 1.0f;
}

void qsrPerspectiveMat4f(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrInitMat4f(mat);
	qsrIdentMat4f(mat);
	
	// Checking for invalid values
	if(FOV <= 0 && aspectRatio != 0) {
		
		return;
	}
	
	// Calculating the perspective matrix
	
	float frustrumDepth = farest-nearest; // How deep the rendered area (frustrum) is
	float oneOverDepth = 1 / frustrumDepth;
	
	mat->data[1][1] = 1 / tanf(0.5 * FOV);
	mat->data[0][0] = 1 * mat->data[1][1] / aspectRatio;
	mat->data[2][2] = farest * oneOverDepth;
	mat->data[3][2] = (-farest * nearest) * oneOverDepth;
	mat->data[2][3] = 1;
	mat->data[3][3] = 0;
}

void qsrGetMat4fColumnMajor(QsrMat4f* mat, float* data) {
	
	data[0]  = mat->data[0][0];
	data[1]  = mat->data[1][0];
	data[2]  = mat->data[2][0];
	data[3]  = mat->data[3][0];
	
	data[4]  = mat->data[0][1];
	data[5]  = mat->data[1][1];
	data[6]  = mat->data[2][1];
	data[7]  = mat->data[3][1];
	
	data[8]  = mat->data[0][2];
	data[9]  = mat->data[1][2];
	data[10] = mat->data[2][2];
	data[11] = mat->data[3][2];
	
	data[12] = mat->data[0][3];
	data[13] = mat->data[1][3];
	data[14] = mat->data[2][3];
	data[15] = mat->data[3][3];
}

void qsrTranslateMat4fVec(QsrMat4f* mat, QsrVec3f* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}

void qsrRotateMat4fVec(QsrMat4f* mat, QsrVec3f* degToRotate) {
	
	QsrMat4f rotationX;
	QsrMat4f rotationY;
	QsrMat4f rotationZ;
	
	float x = qsrDegToRadf(degToRotate->x);
	float y = qsrDegToRadf(degToRotate->y);
	float z = qsrDegToRadf(degToRotate->z);
	
	
	QsrMat4f output;
	qsrInitMat4f(&output);
	
	output.data[0][0] = cosf(z) * cosf(y);
	output.data[1][0] = -sinf(z);
	output.data[2][0] = sinf(y);
	output.data[3][0] = 0;
	
	output.data[0][1] = sinf(z);
	output.data[1][1] = cosf(z) * cosf(x);;
	output.data[2][1] = -sinf(x);
	output.data[3][1] = 0;
	
	output.data[0][2] = -sinf(y);
	output.data[1][2] = -sinf(x);
	output.data[2][2] = cosf(x) * cosf(y);
	output.data[3][2] = 0;
	
	output.data[0][3] = 0;
	output.data[1][3] = 0;
	output.data[2][3] = 0;
	output.data[3][3] = 1;
	
	(*mat) = output;
}

void qsrMat4fLookAt(QsrMat4f* mat, QsrVec3f* position, QsrVec3f* direction,
	QsrVec3f* right, QsrVec3f* up) {
	
	QsrMat4f output;
	qsrInitMat4f(&output);
	
	output.data[0][0] = right->x;
	output.data[1][0] = right->y;
	output.data[2][0] = right->z;
	
	output.data[0][1] = up->x;
	output.data[1][1] = up->y;
	output.data[2][1] = up->z;
	
	output.data[0][2] = direction->x;
	output.data[1][2] = direction->y;
	output.data[2][2] = direction->z;
	
	output.data[3][3] = 1;
	
	QsrMat4f positions;
	qsrInitMat4f(&positions);
	
	positions.data[3][0] = -position->x;
	positions.data[3][1] = -position->y;
	positions.data[3][2] = -position->z;
	
	positions.data[3][3] = 1;
	
	qsrMultMat4f(&output, &positions);
	
	(*mat) = output;
}



void qsrInitMat4i(QsrMat4i* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[0][2] = 0;
	mat->data[0][3] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
	mat->data[1][2] = 0;
	mat->data[1][3] = 0;
	mat->data[2][0] = 0;
	mat->data[2][1] = 0;
	mat->data[2][2] = 0;
	mat->data[2][3] = 0;
	mat->data[3][0] = 0;
	mat->data[3][1] = 0;
	mat->data[3][2] = 0;
	mat->data[3][3] = 0;
}

void qsrInitMat4iTo(QsrMat4i* mat, int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[0][3] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[1][3] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
	mat->data[2][3] = number;
	mat->data[3][0] = number;
	mat->data[3][1] = number;
	mat->data[3][2] = number;
	mat->data[3][3] = number;
}

QsrMat4f qsrGetMat4iAsMat4f(QsrMat4i* toConvert) {
	
	QsrMat4f converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4u qsrGetMat4iAsMat4u(QsrMat4i* toConvert) {
	
	QsrMat4u converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4i qsrMultMat4i(QsrMat4i* input1, QsrMat4i* input2) {
	
	QsrMat4i output;
	
	int i, j, k;
	
	i = 0;
	while(i < 4) {
		
		j = 0;
		while(j < 4) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 4) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

QsrMat4i qsrGetIdentMat4i() {
	
	QsrMat4i mat;
	
	mat.data[0][0] = 1;
	mat.data[1][1] = 1;
	mat.data[2][2] = 1;
	mat.data[3][3] = 1;
	
	return mat;
}

void qsrIdentMat4i(QsrMat4i* mat) {
	
	mat->data[0][0] = 1;
	mat->data[1][1] = 1;
	mat->data[2][2] = 1;
	mat->data[3][3] = 1;
}

void qsrPerspectiveMat4i(QsrMat4i* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrInitMat4i(mat);
	qsrIdentMat4i(mat);
	
	// Checking for invalid values
	if(FOV <= 0 && aspectRatio != 0) {
		
		return;
	}
	
	// Calculating the perspective matrix
	
	float frustrumDepth = farest-nearest; // How deep the rendered area (frustrum) is
	float oneOverDepth = 1 / frustrumDepth;
	
	mat->data[1][1] = 1 / tanf(0.5 * FOV);
	mat->data[0][0] = 1 * mat->data[1][1] / aspectRatio;
	mat->data[2][2] = farest * oneOverDepth;
	mat->data[3][2] = (-farest * nearest) * oneOverDepth;
	mat->data[2][3] = 1;
	mat->data[3][3] = 0;
}

void qsrGetMat4iColumnMajor(QsrMat4i* mat, int* data) {
	
	data[0]  = mat->data[0][0];
	data[1]  = mat->data[1][0];
	data[2]  = mat->data[2][0];
	data[3]  = mat->data[3][0];
	
	data[4]  = mat->data[0][1];
	data[5]  = mat->data[1][1];
	data[6]  = mat->data[2][1];
	data[7]  = mat->data[3][1];
	
	data[8]  = mat->data[0][2];
	data[9]  = mat->data[1][2];
	data[10] = mat->data[2][2];
	data[11] = mat->data[3][2];
	
	data[12] = mat->data[0][3];
	data[13] = mat->data[1][3];
	data[14] = mat->data[2][3];
	data[15] = mat->data[3][3];
}

void qsrTranslateMat4iVec(QsrMat4i* mat, QsrVec3i* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}

void qsrMat4iLookAt(QsrMat4i* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up) {
	
	
	
}



void qsrInitMat4u(QsrMat4u* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[0][2] = 0;
	mat->data[0][3] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
	mat->data[1][2] = 0;
	mat->data[1][3] = 0;
	mat->data[2][0] = 0;
	mat->data[2][1] = 0;
	mat->data[2][2] = 0;
	mat->data[2][3] = 0;
	mat->data[3][0] = 0;
	mat->data[3][1] = 0;
	mat->data[3][2] = 0;
	mat->data[3][3] = 0;
}

void qsrInitMat4uTo(QsrMat4u* mat, unsigned int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[0][3] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[1][3] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
	mat->data[2][3] = number;
	mat->data[3][0] = number;
	mat->data[3][1] = number;
	mat->data[3][2] = number;
	mat->data[3][3] = number;
}

QsrMat4f qsrGetMat4uAsMat4f(QsrMat4u* toConvert) {
	
	QsrMat4f converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4i qsrGetMat4uAsMat4i(QsrMat4u* toConvert) {
	
	QsrMat4i converted;
	converted.data[0][0] = toConvert->data[0][0];
	converted.data[0][1] = toConvert->data[0][1];
	converted.data[0][2] = toConvert->data[0][2];
	converted.data[0][3] = toConvert->data[0][3];
	
	converted.data[1][0] = toConvert->data[1][0];
	converted.data[1][1] = toConvert->data[1][1];
	converted.data[1][2] = toConvert->data[1][2];
	converted.data[1][3] = toConvert->data[1][3];
	
	converted.data[2][0] = toConvert->data[2][0];
	converted.data[2][1] = toConvert->data[2][1];
	converted.data[2][2] = toConvert->data[2][2];
	converted.data[2][3] = toConvert->data[2][3];
	
	converted.data[3][0] = toConvert->data[3][0];
	converted.data[3][1] = toConvert->data[3][1];
	converted.data[3][2] = toConvert->data[3][2];
	converted.data[3][3] = toConvert->data[3][3];
	
	return converted;
}

QsrMat4u qsrMultMat4u(QsrMat4u* input1, QsrMat4u* input2) {
	
	QsrMat4u output;
	
	int i, j, k;
	
	i = 0;
	while(i < 4) {
		
		j = 0;
		while(j < 4) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 4) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

QsrMat4u qsrGetIdentMat4u() {
	
	QsrMat4u mat;
	
	mat.data[0][0] = 1;
	mat.data[1][1] = 1;
	mat.data[2][2] = 1;
	mat.data[3][3] = 1;
	
	return mat;
}

void qsrIdentMat4u(QsrMat4u* mat) {
	
	mat->data[0][0] = 1;
	mat->data[1][1] = 1;
	mat->data[2][2] = 1;
	mat->data[3][3] = 1;
}

void qsrPerspectiveMat4u(QsrMat4u* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrInitMat4u(mat);
	qsrIdentMat4u(mat);
	
	// Checking for invalid values
	if(FOV <= 0 && aspectRatio != 0) {
		
		return;
	}
	
	// Calculating the perspective matrix
	
	float frustrumDepth = farest-nearest; // How deep the rendered area (frustrum) is
	float oneOverDepth = 1 / frustrumDepth;
	
	mat->data[1][1] = 1 / tanf(0.5 * FOV);
	mat->data[0][0] = 1 * mat->data[1][1] / aspectRatio;
	mat->data[2][2] = farest * oneOverDepth;
	mat->data[3][2] = (-farest * nearest) * oneOverDepth;
	mat->data[2][3] = 1;
	mat->data[3][3] = 0;
}

void qsrGetMat4uColumnMajor(QsrMat4u* mat, unsigned int* data) {
	
	data[0]  = mat->data[0][0];
	data[1]  = mat->data[1][0];
	data[2]  = mat->data[2][0];
	data[3]  = mat->data[3][0];
	
	data[4]  = mat->data[0][1];
	data[5]  = mat->data[1][1];
	data[6]  = mat->data[2][1];
	data[7]  = mat->data[3][1];
	
	data[8]  = mat->data[0][2];
	data[9]  = mat->data[1][2];
	data[10] = mat->data[2][2];
	data[11] = mat->data[3][2];
	
	data[12] = mat->data[0][3];
	data[13] = mat->data[1][3];
	data[14] = mat->data[2][3];
	data[15] = mat->data[3][3];
}

void qsrTranslateMat4uVec(QsrMat4u* mat, QsrVec3u* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}

void qsrMat4uLookAt(QsrMat4u* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up) {
	
	
	
}

