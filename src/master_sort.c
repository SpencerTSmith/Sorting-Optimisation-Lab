#include <string.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void insertion_sort(float *arr, int n) {
    for (int i = 1; i < n; i++) {

        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(float *x, int low, int high) {
    // naive pivot choice... actually faster than hoare
    float pivot = x[high];

    int i = low;

    for (int j = low; j < high; j++) {
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
    if (low < high) {
        int part_i = partition(x, low, high);

        quick_sort(x, low, part_i - 1);
        quick_sort(x, part_i + 1, high);
    }
}

// quick sort!
void COMPUTE_NAME(int m0, float *x, float *y) {
    if (m0 <= 16) {
        for (int i = 0; i < m0; i++) {
            y[i] = x[i];
        }
        insertion_sort(y, m0);
        return;
    } else {
        memcpy(y, x, sizeof(float) * m0);
        quick_sort(y, 0, m0 - 1);
    }
}
