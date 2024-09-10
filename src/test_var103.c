#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// Using old partition as it doesn't actually seem to be faster?

// Indices now
int partition(float *x, int *inds, int low, int high) {
    // naive pivot choice... optimizations?
    float pivot = x[inds[high]];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (x[j] <= pivot) {
            int temp = inds[i];
            inds[i] = inds[j];
            inds[j] = temp;
            i++;
        }
    }

    int temp = inds[i + 1];
    inds[i + 1] = inds[high];
    inds[high] = temp;
    return i + 1;
}

void quick_sort(float *x, int *inds, int low, int high) {
    if (low < high) {
        int part_i = partition(x, inds, low, high);

        quick_sort(x, inds, low, part_i - 1);
        quick_sort(x, inds, part_i + 1, high);
    }
}

// quick sort!
void COMPUTE_NAME(int m0, float *x, float *y) {
    int inds[m0];
    quick_sort(x, inds, 0, m0 - 1);

    for (int i = 0; i < m0; i++) {
        y[i] = x[inds[i]];
    }
}
