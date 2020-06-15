

typedef struct {
	
	float data[2][2];
	
} QsrMat2f;

void qsrInitMat2f(QsrMat2f* mat);
void qsrInitMat2fTo(QsrMat2f* mat, float number);

QsrMat2f qsrMultMat2f(QsrMat2f* input1, QsrMat2f* input2);
QsrMat2f qsrGetIdentMat2f();
void qsrIdentMat2f(QsrMat2f* input);



typedef struct {
	
	int data[2][2];
	
} QsrMat2i;

void qsrInitMat2i(QsrMat2i* mat);
void qsrInitMat2iTo(QsrMat2i* mat, int number);

QsrMat2i qsrMultMat2i(QsrMat2i* input1, QsrMat2i* input2);
QsrMat2i qsrGetIdentMat2i();
void qsrIdentMat2i(QsrMat2i* input);



typedef struct {
	
	unsigned int data[2][2];
	
} QsrMat2u;

void qsrInitMat2u(QsrMat2u* mat);
void qsrInitMat2uTo(QsrMat2u* mat, unsigned int number);

QsrMat2u qsrMultMat2u(QsrMat2u* input1, QsrMat2u* input2);
QsrMat2u qsrGetIdentMat2u();
void qsrIdentMat2u(QsrMat2u* input);

