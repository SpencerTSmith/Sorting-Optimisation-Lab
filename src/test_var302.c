// block sort, merge with insertion sort with block size sqrt(arrsize)
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME block
#endif

// swaps two floats
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// insertion sort for when the array is smaller
void block_insertionSort(float arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {

        float key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// makes two arrays, sorts them and then it joins the sorted back
void blockMerge(float arr[], int left, int mid, int right) {

    // legths of sub arrays
    int a = mid - left + 1;
    int b = right - mid;

    // sub arrays Left and Right
    float *L = (float *)malloc(a * sizeof(float));
    float *R = (float *)malloc(b * sizeof(float));

    // Fills subarrays
    for (int i = 0; i < a; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < b; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // initialize counters
    int i = 0;
    int j = 0;
    int k = left;

    // merges arrays
    while (i < a && j < b) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // fills array if L still has contents
    while (i < a) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // fills array if R still has contents
    while (j < b) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // frees memory used by sub arrays.
    free(L);
    free(R);
}

void BlockSort(float arr[], int n, int blockSize) {

    // sort blocks
    for (int i = 0; i < n; i += blockSize) {
        int end = (i + blockSize - 1 < n) ? i + blockSize - 1 : n - 1;
        block_insertionSort(arr, i, end);
    }

    // merge
    for (int size = blockSize; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n) ? left + 2 * size - 1 : n - 1;
            if (mid < right) {
                blockMerge(arr, left, mid, right);
            }
        }
    }
}

void COMPUTE_NAME(int m0, float *x, float *y) {

    int bsize;
    double s = (double)m0;
    memcpy(y, x, sizeof(float) * m0);

    bsize = (int)sqrt(m0);
    BlockSort(y, m0, bsize);
}
