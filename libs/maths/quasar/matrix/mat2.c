#include "mat2.h"

void qsrInitMat2f(QsrMat2f* mat) {
	
	mat->data[0][0] = 0.0f;
	mat->data[0][1] = 0.0f;
	mat->data[1][0] = 0.0f;
	mat->data[1][1] = 0.0f;
}

void qsrInitMat2fTo(QsrMat2f* mat, float number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
}

QsrMat2f qsrMultMat2f(QsrMat2f* input1, QsrMat2f* input2) {
	
	QsrMat2f output;
	
	int i, j, k;
	
	i = 0;
	while(i < 2) {
		
		j = 0;
		while(j < 2) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 2) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

QsrMat2f qsrGetIdentMat2f() {
	
	QsrMat2f output;
	output.data[0][0] = 1.0f;
	output.data[1][1] = 1.0f;
	
	return output;
}

void qsrIdentMat2f(QsrMat2f* input) {
	
	input->data[0][0] = 1.0f;
	input->data[1][1] = 1.0f;
}



void qsrInitMat2i(QsrMat2i* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
}

void qsrInitMat2iTo(QsrMat2i* mat, int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
}

QsrMat2i qsrMultMat2i(QsrMat2i* input1, QsrMat2i* input2) {
	
	QsrMat2i output;
	
	int i, j, k;
	
	i = 0;
	while(i < 2) {
		
		j = 0;
		while(j < 2) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 2) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

QsrMat2i qsrGetIdentMat2i() {
	
	QsrMat2i output;
	output.data[0][0] = 1;
	output.data[1][1] = 1;
	
	return output;
}

void qsrIdentMat2i(QsrMat2i* input) {
	
	input->data[0][0] = 1;
	input->data[1][1] = 1;
}



void qsrInitMat2u(QsrMat2u* mat) {
	
	mat->data[0][0] = 0;
	mat->data[0][1] = 0;
	mat->data[1][0] = 0;
	mat->data[1][1] = 0;
}

void qsrInitMat2uTo(QsrMat2u* mat, unsigned int number) {
	
	mat->data[0][0] = number;
	mat->data[0][1] = number;
	mat->data[1][0] = number;
	mat->data[1][1] = number;
}

QsrMat2u qsrMultMat2u(QsrMat2u* input1, QsrMat2u* input2) {
	
	QsrMat2u output;
	
	int i, j, k;
	
	i = 0;
	while(i < 2) {
		
		j = 0;
		while(j < 2) {
			
			output.data[i][j] = 0;
			
			k = 0;
			while(k < 2) {
				
				output.data[i][j] += input1->data[i][k] *
					input2->data[k][j];
				
				++k;
			}
			
			++j;
		}
		
		++i;
	}
	
}

QsrMat2u qsrGetIdentMat2u() {
	
	QsrMat2u output;
	output.data[0][0] = 1;
	output.data[1][1] = 1;
}

void qsrIdentMat2u(QsrMat2u* input) {
	
	input->data[0][0] = 1;
	input->data[1][1] = 1;
}

