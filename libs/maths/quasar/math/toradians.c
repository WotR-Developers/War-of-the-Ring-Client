#include "toradians.h"

float qsrDegToRadf(float degrees) {
	
	return 2*3.1415926535 * (degrees / 360);
}

int qsrDegToRadi(int degrees) {
	
	return (int) (2*3.1415926535 * (degrees / 360));
}

