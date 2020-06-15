typedef struct {
	
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
	
} QsrColorRGBA;

void qsrInitColorRGBA(QsrColorRGBA* toInit) {
	
	toInit->r = 0;
	toInit->g = 0;
	toInit->b = 0;
	toInit->a = 0;
}

