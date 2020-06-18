#include "qsrstring.h"

void qsrStrInit(QsrString* string) {
	
	string->data = NULL;
	string->length = 0;
	string->capacity = 0;
}

QsrString qsrStrGetInitted() {
	
	QsrString string;
	string.data = NULL;
	string.length = 0;
	string.capacity = 0;
	
	return string;
}



void qsrStrDestroy(QsrString* string) {
	
	if(string->data != NULL) {
		
		free(string->data);
	}
}



QsrString qsrStrGetFilled(char toFill, int length) {
	
	if(length < 1) {
		
		return qsrStrGetInitted();
	}
	
	QsrString string;
	string.data = (char*) malloc(length);
	
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


void qsrStrAssignChars(QsrString* string, char* data) {
	
	// Getting the length of data
	
	int charIndex = 0;
	while(true) {
		
		if(data[charIndex] == 0x00) {
			
			break;
		}
		charIndex++;
	}
	
	// If there is not enough space, allocate some
	if(string->capacity < charIndex) {
		
		free(string->data);
		string->data = malloc(charIndex+8);
		string->capacity = charIndex+8; 
		string->length = charIndex;
	}
	
	
	
	
	charIndex = 0;
	while(charIndex < string->length) {
		
		string->data[charIndex] = data[charIndex];
		
		charIndex++;
	}
	
}



void qsrStrResize(QsrString* string, int difference) {
	
	if(difference < 0) {
		
		string->length += difference;
		
		return;
	}
	
	
	
	
	
}

void qsrStrSetSize(QsrString* string, unsigned int length) {
	
	
	
}



QsrString qsrStrGetLowercase(QsrString* string) {
	
	QsrString output;
	output.data = malloc(string->length+8);
	
	
	// Doing some work with the numbers that make the ASCII-Characters.
	// NOTE: In ASCII, all lowercase and all uppercase characters
	//       are in order, so it is possible to just subtract/add
	//       the difference between them to make a character uppercase
	//       or lowercase. For better understanding, see: asciitable.com
	
	int charIndex = 0;
	while(charIndex < string->length) {
		
		if(string->data[charIndex] > 64 && string->data[charIndex] < 91) {
			
			output.data[charIndex] = string->data[charIndex]+32;
			
			charIndex++;
			continue;
		}
		
		output.data[charIndex] = string->data[charIndex];
		
		charIndex++;
	}
	
	return output;
}

QsrString qsrStrGetUppercase(QsrString* string) {
	
	QsrString output;
	output.data = malloc(string->length+8);
	
	
	// Doing some work with the numbers that make the ASCII-Characters.
	// NOTE: In ASCII, all lowercase and all uppercase characters
	//       are in one row, so it is possible to just subtract/add
	//       the difference between them to make a character uppercase
	//       or lowercase
	
	int charIndex = 0;
	while(charIndex < string->length) {
		
		if(string->data[charIndex] > 96 && string->data[charIndex] < 123) {
			
			output.data[charIndex] = string->data[charIndex]-32;
			
			charIndex++;
			continue;
		}
		
		output.data[charIndex] = string->data[charIndex];
		
		charIndex++;
	}
	
	return output;
}

void qsrStrToLowercase(QsrString* string) {
	
	
	
}

void qsrStrToUppercase(QsrString* string) {
	
	int charIndex = 0;
	while(charIndex < string->length) {
		
		if(string->data[charIndex] > 96 && string->data[charIndex] < 123) {
			
			string->data[charIndex] = string->data[charIndex]-32;
			
			charIndex++;
			continue;
		}
		
		charIndex++;
	}
	
}

char* qsrStrToLowercaseChars(QsrString* string) {
	
	
	
}

char* qsrStrToUppercaseChars(QsrString* string) {
	
	
	
}



void qsrStrAppend(QsrString* string, QsrString* toAppend) {
	
	
	
}

void qsrStrAppendChars(QsrString* string, char* toAppend) {
	
	
	
}

