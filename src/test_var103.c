#include <pthread.h>
#include <string.h>
#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// Using old partition as it doesn't actually seem to be faster?

#define DEPTH 10000

// Indices now
int partition(float *x, int low, int high) {
    // naive pivot choice... optimizations?
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

typedef struct {
    float *x;
    int low;
    int high;
} qsort_args;

void *threaded_qsort(void *arg_struct) {
    // unpack
    float *x = ((qsort_args *)arg_struct)->x;
    int low = ((qsort_args *)arg_struct)->low;
    int high = ((qsort_args *)arg_struct)->high;

    if (high - low > DEPTH) {
        int part_i = partition(x, low, high);

        pthread_t low_thread;
        qsort_args low_arg = {x, low, part_i - 1};
        pthread_create(&low_thread, NULL, threaded_qsort, &low_arg);

        pthread_t high_thread;
        qsort_args high_arg = {x, part_i + 1, high};
        pthread_create(&high_thread, NULL, threaded_qsort, &high_arg);

        pthread_join(low_thread, NULL);
        pthread_join(high_thread, NULL);
    } else {
        quick_sort(x, low, high);
    }

    pthread_exit(NULL);
}

// quick sort!
void COMPUTE_NAME(int m0, float *x, float *y) {
    memcpy(y, x, sizeof(float) * m0);

    pthread_t starter;
    qsort_args args = {y, 0, m0 - 1};
    pthread_create(&starter, NULL, threaded_qsort, &args);
    pthread_join(starter, NULL);
}
