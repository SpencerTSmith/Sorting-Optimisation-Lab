/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/

#include <stdbool.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void COMPUTE_NAME(int m0, float *x, float *y) {
	/*
	  NOTE: This is just a copy of the baseline. You need to modify
	  and iterate on this.
	*/

	/*
	   We need an out-of-place sort (input array != output array)
	   so we will do the slowest but easiest thing to get a working
	   implementation. First we will copy the contents of the input
	   array x into array y, then perform an in-place sort on y.

	*/

	// copy the contents of the input array into the output array
	for (int i0 = 0; i0 < m0; ++i0)
		y[i0] = x[i0];

	// perform the absolute worse in-place bubble sort.
	for (int i = 0; i < m0; ++i) {
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
