#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	
	char* data;
	
	unsigned int length;
	unsigned int capacity;
	
} QsrString;



void qsrStrInit(QsrString* string);
QsrString qsrStrGetInitted();

void qsrStrDestroy(QsrString* string);

QsrString qsrStrGetFilled(char toFill, int length);
void qsrStrFill(QsrString* string, char toFill, int length);

void qsrStrAssignChars(QsrString* string, char* data);
void qsrStrAssignCharLen(QsrString* string, char* data, int length);

void qsrStrResize(QsrString* string, int length);
void qsrStrSetSize(QsrString* string, unsigned int length);

QsrString qsrStrGetLowercase(QsrString* string);
QsrString qsrStrGetUppercase(QsrString* string);
void qsrStrToLowercase(QsrString* string);
void qsrStrToUppercase(QsrString* string);
char* qsrStrToLowercaseChars(QsrString* string);
char* qsrStrToUppercaseChars(QsrString* string);

void qsrStrAppend(QsrString* string, QsrString* toAppend);
void qsrStrAppendChars(QsrString* string, char* toAppend);


