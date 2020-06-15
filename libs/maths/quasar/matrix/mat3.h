

typedef struct {
	
	float data[3][3];
	
} QsrMat3f;

void qsrInitMat3f(QsrMat3f* mat);
void qsrInitMat3fTo(QsrMat3f* mat, float number);
QsrMat3f qsrMultMat3f(QsrMat3f* input1, QsrMat3f* input2);



typedef struct {
	
	int data[3][3];
	
} QsrMat3i;

void qsrInitMat3i(QsrMat3i* mat);
void qsrInitMat3iTo(QsrMat3i* mat, int number);
QsrMat3i qsrMultMat3i(QsrMat3i* input1, QsrMat3i* input2);



typedef struct {
	
	unsigned int data[3][3];
	
} QsrMat3u;

void qsrInitMat3u(QsrMat3u* mat);
void qsrInitMat3uTo(QsrMat3u* mat, unsigned int number);
QsrMat3u qsrMultMat3u(QsrMat3u* input1, QsrMat3u* input2);

