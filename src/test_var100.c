#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// all straight from wikipedia for now
int partition(float *x, int low, int high) {
	// naive pivot choice... optimizations?
	float pivot = x[high];

	int i = low;

	for (int j = low; j <= high - 1; j++) {
		if (x[j] <= pivot) {
			float temp = x[i];
			x[i] = x[j];
			x[j] = temp;
			i++;
		}
	}

	float temp = x[i];
	x[i] = x[high];
	x[high] = temp;
	return i;
}

void quick_sort(float *x, int low, int high) {
	if (low >= high || low < 0) {
		return;
	}

	int part_i = partition(x, low, high);

	quick_sort(x, low, part_i - 1);
	quick_sort(x, part_i + 1, high);
}

// quick sort!
void COMPUTE_NAME(int m0, float *x, float *y) {
	quick_sort(x, 0, m0 - 1);

	memcpy(y, x, sizeof(float) * m0);
}
