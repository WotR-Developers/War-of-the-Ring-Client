#include "mat3.h"

void qsrInitMat3f(QsrMat3f* mat) {
	
	mat->data[0][0] = 0.0f;
	mat->data[0][1] = 0.0f;
	mat->data[0][2] = 0.0f;
	mat->data[1][0] = 0.0f;
	mat->data[1][1] = 0.0f;
	mat->data[1][2] = 0.0f;
	mat->data[2][0] = 0.0f;
	mat->data[2][1] = 0.0f;
	mat->data[2][2] = 0.0f;
}

void qsrInitMat3fTo(QsrMat3f* mat, float number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
}

QsrMat3f qsrMultMat3f(QsrMat3f* input1, QsrMat3f* input2) {
	
	QsrMat3f output;
	
	int i, j, k;
	
	i = 0;
	while(i < 3) {
		
		j = 0;
		while(j < 3) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 3) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}



void qsrInitMat3i(QsrMat3i* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[0][2] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
	mat->data[1][2] = 0;
	mat->data[2][0] = 0;
	mat->data[2][1] = 0;
	mat->data[2][2] = 0;
}

void qsrInitMat3iTo(QsrMat3i* mat, int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
}

QsrMat3i qsrMultMat3i(QsrMat3i* input1, QsrMat3i* input2) {
	
	QsrMat3i output;
	
	int i, j, k;
	
	i = 0;
	while(i < 3) {
		
		j = 0;
		while(j < 3) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 3) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}



void qsrInitMat3u(QsrMat3u* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[0][2] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
	mat->data[1][2] = 0;
	mat->data[2][0] = 0;
	mat->data[2][1] = 0;
	mat->data[2][2] = 0;
}

void qsrInitMat3uTo(QsrMat3u* mat, unsigned int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[0][2] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
	mat->data[1][2] = number;
	mat->data[2][0] = number;
	mat->data[2][1] = number;
	mat->data[2][2] = number;
}

QsrMat3u qsrMultMat3u(QsrMat3u* input1, QsrMat3u* input2) {
	
	QsrMat3u output;
	
	int i, j, k;
	
	i = 0;
	while(i < 3) {
		
		j = 0;
		while(j < 3) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 3) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

