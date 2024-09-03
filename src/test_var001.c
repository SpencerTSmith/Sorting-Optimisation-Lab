#include <stdbool.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void COMPUTE_NAME(int m0, float *x, float *y) {

	// copy the contents of the input array into the output array
	for (int i0 = 0; i0 < m0; ++i0)
		y[i0] = x[i0];

	for (int i = 0; i < m0; ++i) {
		// if we haven't swapped we know it's sorted
		bool swapped = false;
		for (int j = 0; j < m0 - 1; ++j) {
			if (y[j] > y[j + 1]) {
				float temp = y[j];
				y[j] = y[j + 1];
				y[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
