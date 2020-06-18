#include "mat4.h"

void qsrMat4fInit(QsrMat4f* mat) {
	
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

void qsrMat4fInitTo(QsrMat4f* mat, float number) {
	
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

QsrMat4i qsrMat4fToMat4i(QsrMat4f* toConvert) {
	
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

QsrMat4u qsrMat4fToMat4u(QsrMat4f* toConvert) {
	
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

QsrMat4f qsrMat4fMultiply(QsrMat4f* input1, QsrMat4f* input2) {
	
	QsrMat4f output;
	qsrMat4fInit(&output);
	
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

QsrMat4f qsrMat4fGetIdent() {
	
	QsrMat4f mat;
	qsrMat4fInit(&mat);
	
	mat.data[0][0] = 1.0f;
	mat.data[1][1] = 1.0f;
	mat.data[2][2] = 1.0f;
	mat.data[3][3] = 1.0f;
	
	return mat;
}

void qsrMat4fSetToIdent(QsrMat4f* mat) {
	
	qsrMat4fInit(mat);
	mat->data[0][0] = 1.0f;
	mat->data[1][1] = 1.0f;
	mat->data[2][2] = 1.0f;
	mat->data[3][3] = 1.0f;
}

void qsrMat4fWriteTransposed(QsrMat4f* mat, float* data) {
	
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

void qsrMat4fTranspose(QsrMat4f* mat) {
	
	QsrMat4f workspace;
	
	workspace.data[0][0] = mat->data[0][0];
	workspace.data[1][0] = mat->data[0][1];
	workspace.data[2][0] = mat->data[0][2];
	workspace.data[3][0] = mat->data[0][3];
	
	workspace.data[0][1] = mat->data[1][0];
	workspace.data[1][1] = mat->data[1][1];
	workspace.data[2][1] = mat->data[1][2];
	workspace.data[3][1] = mat->data[1][3];
	
	workspace.data[0][2] = mat->data[2][0];
	workspace.data[1][2] = mat->data[2][1];
	workspace.data[2][2] = mat->data[2][2];
	workspace.data[3][2] = mat->data[2][3];
	
	workspace.data[0][3] = mat->data[3][0];
	workspace.data[1][3] = mat->data[3][1];
	workspace.data[2][3] = mat->data[3][2];
	workspace.data[3][3] = mat->data[3][3];
	
	(*mat) = workspace;
}

void qsrMat4fPersp(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrMat4fInit(mat);
	qsrMat4fSetToIdent(mat);
	
	// Checking for invalid values
	if(FOV <= 0 && aspectRatio != 0) {
		
		return;
	}
	
	// Calculating the perspective matrix
	float tanHalfFOV = tan(FOV / 2);
	
	mat->data[0][0] = 2 / (aspectRatio * tanHalfFOV);
	mat->data[1][1] = 2 / tanHalfFOV;
	mat->data[2][2] = - (farest+nearest) / (farest-nearest);
	mat->data[2][3] = -1;
	mat->data[3][2] = - (2 * farest * nearest) / (farest - nearest);
}

void qsrMat4fOrtho(QsrMat4f* mat, float FOV, float aspectRatio,
 float nearest, float farest) {

}

void qsrMat4fTranslateByVec(QsrMat4f* mat, QsrVec3f* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}


void qsrMat4fScaleByVec(QsrMat4f* mat, QsrVec3f* toScale) {
	
	mat->data[0][0] += toScale->x;
	mat->data[1][1] += toScale->y;
	mat->data[2][2] += toScale->z;
}

void qsrMat4fRotateByVec(QsrMat4f* mat, QsrVec3f* degToRotate) {
	
	QsrMat4f rotationX;
	QsrMat4f rotationY;
	QsrMat4f rotationZ;
	
	float x = qsrDegToRadf(degToRotate->x);
	float y = qsrDegToRadf(degToRotate->y);
	float z = qsrDegToRadf(degToRotate->z);
	
	
	QsrMat4f output;
	qsrMat4fInit(&output);
	
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
	
	int xIndex = 0;
	while(xIndex < 4) {
		
		int yIndex = 0;
		while(yIndex < 4) {
			
			mat->data[xIndex][yIndex] = output.data[xIndex][yIndex];
			
			yIndex++;
		}
		
		xIndex++;
	}
}

void qsrMat4fSetToLookAt(QsrMat4f* mat, QsrVec3f* position, QsrVec3f* direction,
	QsrVec3f* right, QsrVec3f* up) {
	
	QsrMat4f output;
	qsrMat4fInit(&output);
	
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
	qsrMat4fInit(&positions);
	
	positions.data[3][0] = position->x;
	positions.data[3][1] = position->y;
	positions.data[3][2] = position->z;
	
	positions.data[3][3] = 1;
	
	qsrMat4fMultiply(&output, &positions);
	
	(*mat) = output;
}

char* qsrMat4fToChars(QsrMat4f* input) {
	
	
	
}

void qsrMat4fPrint(QsrMat4f* input, char* label) {
	
	if(label == NULL) {
		
		printf("Matrix:\n %f  %f  %f  %f\n %f  %f  %f  %f\n %f  %f  %f  %f\n %f  %f  %f  %f\n",
			input->data[0][0], input->data[0][1], input->data[0][2], input->data[0][3],
			input->data[1][0], input->data[1][1], input->data[1][2], input->data[1][3],
			input->data[2][0], input->data[2][1], input->data[2][2], input->data[2][3],
			input->data[3][0], input->data[3][1], input->data[3][2], input->data[3][3]
		);
		
	} else {
		
		
	}
	
}





void qsrMat4iInit(QsrMat4i* mat) {
	
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

void qsrMat4iInitTo(QsrMat4i* mat, int number) {
	
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

QsrMat4f qsrMat4iToMat4f(QsrMat4i* toConvert) {
	
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

QsrMat4u qsrMat4iToMat4u(QsrMat4i* toConvert) {
	
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

QsrMat4i qsrMat4iMultiply(QsrMat4i* input1, QsrMat4i* input2) {
	
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

QsrMat4i qsrMat4iGetIdent() {
	
	QsrMat4i mat;
	qsrMat4iInit(&mat);
	
	mat.data[0][0] = 1;
	mat.data[1][1] = 1;
	mat.data[2][2] = 1;
	mat.data[3][3] = 1;
	
	return mat;
}

void qsrMat4iSetToIdent(QsrMat4i* mat) {
	
	qsrMat4iInit(mat);
	mat->data[0][0] = 1;
	mat->data[1][1] = 1;
	mat->data[2][2] = 1;
	mat->data[3][3] = 1;
}


void qsrMat4iWriteTransposed(QsrMat4i* mat, int* data) {
	
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

void qsrMat4iTranspose(QsrMat4i* mat) {
	
	QsrMat4i workspace;
	
	workspace.data[0][0] = mat->data[0][0];
	workspace.data[1][0] = mat->data[0][1];
	workspace.data[2][0] = mat->data[0][2];
	workspace.data[3][0] = mat->data[0][3];
	
	workspace.data[0][1] = mat->data[1][0];
	workspace.data[1][1] = mat->data[1][1];
	workspace.data[2][1] = mat->data[1][2];
	workspace.data[3][1] = mat->data[1][3];
	
	workspace.data[0][2] = mat->data[2][0];
	workspace.data[1][2] = mat->data[2][1];
	workspace.data[2][2] = mat->data[2][2];
	workspace.data[3][2] = mat->data[2][3];
	
	workspace.data[0][3] = mat->data[3][0];
	workspace.data[1][3] = mat->data[3][1];
	workspace.data[2][3] = mat->data[3][2];
	workspace.data[3][3] = mat->data[3][3];
	
	(*mat) = workspace;
}

void qsrMat4iPersp(QsrMat4i* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrMat4iInit(mat);
	qsrMat4iSetToIdent(mat);
	
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

void qsrMat4iTranslateByVec(QsrMat4i* mat, QsrVec3i* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}

void qsrMat4iScaleByVec(QsrMat4i* mat, QsrVec3i* toScale) {
	
	mat->data[0][0] += toScale->x;
	mat->data[1][1] += toScale->y;
	mat->data[2][2] += toScale->z;
}

void qsrMat4iSetToLookAt(QsrMat4i* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up) {
	
	
	
}

char* qsrMat4iToChars(QsrMat4i* input) {
	
	
	
}

void qsrMat4iPrint(QsrMat4i* input, char* label) {
	
	
	
}





void qsrMat4uInit(QsrMat4u* mat) {
	
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

void qsrMat4uInitTo(QsrMat4u* mat, unsigned int number) {
	
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

QsrMat4f qsrMat4uToMat4f(QsrMat4u* toConvert) {
	
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

QsrMat4i qsrMat4uToMat4i(QsrMat4u* toConvert) {
	
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

QsrMat4u qsrMat4uMultiply(QsrMat4u* input1, QsrMat4u* input2) {
	
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

QsrMat4u qsrMat4uGetIdent() {
	
	QsrMat4u mat;
	qsrMat4uInit(&mat);
	
	mat.data[0][0] = 1;
	mat.data[1][1] = 1;
	mat.data[2][2] = 1;
	mat.data[3][3] = 1;
	
	return mat;
}

void qsrMat4uSetToIdent(QsrMat4u* mat) {
	
	qsrMat4uInit(mat);
	mat->data[0][0] = 1;
	mat->data[1][1] = 1;
	mat->data[2][2] = 1;
	mat->data[3][3] = 1;
}


void qsrMat4uWriteTransposed(QsrMat4u* mat, unsigned int* data) {
	
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

void qsrMat4uTranspose(QsrMat4u* mat) {
	
	QsrMat4u workspace;
	
	workspace.data[0][0] = mat->data[0][0];
	workspace.data[1][0] = mat->data[0][1];
	workspace.data[2][0] = mat->data[0][2];
	workspace.data[3][0] = mat->data[0][3];
	
	workspace.data[0][1] = mat->data[1][0];
	workspace.data[1][1] = mat->data[1][1];
	workspace.data[2][1] = mat->data[1][2];
	workspace.data[3][1] = mat->data[1][3];
	
	workspace.data[0][2] = mat->data[2][0];
	workspace.data[1][2] = mat->data[2][1];
	workspace.data[2][2] = mat->data[2][2];
	workspace.data[3][2] = mat->data[2][3];
	
	workspace.data[0][3] = mat->data[3][0];
	workspace.data[1][3] = mat->data[3][1];
	workspace.data[2][3] = mat->data[3][2];
	workspace.data[3][3] = mat->data[3][3];
	
	(*mat) = workspace;
}

void qsrMat4uPersp(QsrMat4u* mat, float FOV, float aspectRatio,
 float nearest, float farest) {
	
	// Making the matrix an identity matrix
	qsrMat4uInit(mat);
	qsrMat4uGetIdent(mat);
	
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

void qsrMat4uTranslateByVec(QsrMat4u* mat, QsrVec3u* toTranslate) {
	
	mat->data[3][0] += toTranslate->x;
	mat->data[3][1] += toTranslate->y;
	mat->data[3][2] += toTranslate->z;
}

void qsrMat4uScaleByVec(QsrMat4u* mat, QsrVec3u* toScale) {
	
	mat->data[0][0] += toScale->x;
	mat->data[1][1] += toScale->y;
	mat->data[2][2] += toScale->z;
}

void qsrMat4uSetToLookAt(QsrMat4u* mat, QsrVec3f* position, QsrVec3f* direction, QsrVec3f* right, QsrVec3f* up) {
	
	
	
}

char* qsrMat4uToChars(QsrMat4u* input) {
	
	
	
}

void qsrMat4uPrint(QsrMat4u* input, char* label) {
	
	
	
}

