#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// Hoare partion scheme, order of magnitude faster on the largest default array
// size!
int partition(float *x, int *indxs, int low, int high) {
    float pivot = x[low];

    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (x[i] < pivot);

        do {
            j--;
        } while (x[j] > pivot);

        if (i >= j)
            return j;

        float temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
}

void quick_sort(float *x, int *indxs, int low, int high) {
    if (low >= high || low < 0 || high < 0) {
        return;
    }

    int part_i = partition(x, indxs, low, high);

    quick_sort(x, indxs, low,
               part_i); // we include the pivot in the lower portion
    quick_sort(x, indxs, part_i + 1, high);
}

// quick sort!
void COMPUTE_NAME(int m0, float *x, float *y) {
    // how is this allowed, c standard?
    int indxs[m0];
    quick_sort(x, indxs, 0, m0 - 1);
}
