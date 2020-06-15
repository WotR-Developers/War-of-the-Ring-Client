typedef struct {
	
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
} QsrColorRGB;

void qsrInitColorRGB(QsrColorRGB* toInit) {
	
	toInit->r = 0;
	toInit->g = 0;
	toInit->b = 0;
}

