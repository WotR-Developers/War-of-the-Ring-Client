#pragma once

#include <stdlib.h>

typedef struct {
	
	char* data;
	
	unsigned int length;
	unsigned int capacity;
	
} QsrString;



void qsrStrInit(QsrString* string);
QsrString qsrStrGetInitted();

void qsrStrDestroy(QsrString* string);

QsrString qsrStrGetFilled(char toFill, int length);
void qsrStrFill(QsrString* string, char toFill);

void qsrStrAssignChar(QsrString* string, char* data);
void qsrStrAssignCharLen(QsrString* string, char* data, int length);

void qsrStrResize(QsrString* string, int length);
void qsrStrSetSize(QsrString* string, unsigned int length);

QsrString qsrStrToLowercase(QsrString* string);
QsrString qsrStrToUppercase(QsrString* string);
char* qsrStrToLowercaseChars(QsrString* string);
char* qsrStrToUppercaseChars(QsrString* string);

void qsrStrAppend(QsrString* string, QsrString* toAppend);
void qsrStrAppendChars(QsrString* string, char* toAppend);


