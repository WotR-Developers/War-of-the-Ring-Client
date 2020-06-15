#include "qsrstring.h"

void qsrStrInit(QsrString* string) {
	
	string->data = NULL;
}

QsrString qsrStrGetInitted() {
	
	QsrString string;
	string.data = NULL;
	
	return string;
}



void qsrStrDestroy(QsrString* string) {
	
	free(string->data);
}



QsrString qsrStrGetFilled(char toFill, int length) {
	
	if(length < 1) {
		
		return qsrStrGetInitted();
	}
	
	QsrString string;
	string->data = (char*) malloc(length);
	
	qsrStrFill(&string, toFill, length);
	
	return string;
}

void qsrStrFill(QsrString* string, char toFill, int length) {
	
	if(length < 1) {
		
		return;
	}
	
	int charIndex = 0;
	
	while(charIndex < length) {
		
		string->data[charIndex] = toFill;
		
		charIndex++;
	}
	
}


void qsrStrAssignChar(QsrString* string, char* data) {
	
	int charIndex = 0;
	
	while(charIndex < length) {
		
		if(data[charIndex] == 0x00) {
			
			return;
		}
		charIndex++;
	}
	
	if(string->capacity < charIndex) {
		
		free(string->data);
		string->data = malloc(charIndex);
	}
	
	
	charIndex = 0;
	
	while(charIndex < length) {
		
		if(data[charIndex] == 0x00) {
			
			return;
		}
		
		string->data[charIndex] = data[charIndex];
		
		charIndex++;
	}
	
}



void qsrStrResize(QsrString* string, int length) {
	
	if(length < string->capacity) {
		
		string->length = length;
		
		return;
	}
	
	
	
	
	
}

void qsrStrSetSize(QsrString* string, unsigned int length) {
	
	
	
}



QsrString qsrStrToLowercase(QsrString* string) {
	
	
	
}

QsrString qsrStrToUppercase(QsrString* string) {
	
	
	
}

char* qsrStrToLowercaseChars(QsrString* string) {
	
	
	
}

char* qsrStrToUppercaseChars(QsrString* string) {
	
	
	
}



void qsrStrAppend(QsrString* string, QsrString* toAppend) {
	
	
	
}

void qsrStrAppendChars(QsrString* string, char* toAppend) {
	
	
	
}

