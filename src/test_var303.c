// merge sort with inserion sort for small arrays
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME merge

#endif


// swaps two floats
void mergeSwap(float *a, float *b){
  float temp = *a;
  *a = *b;
  *b = temp;

}

// insertion sort for when the array is smaller
void insertionSort(float arr[], int left, int right){
  for(int i = left + 1; i <= right; i++){

    float key = arr[i];
    int j = i-1;

    while (j >= left && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
     }
     arr[j+1] = key;
  }
}

// makes two arrays, sorts them and then it joins the sorted back
void merge(float arr[], int left, int mid, int right){

  // legths of sub arrays
  int a = mid - left +1;
  int b = right -mid ;

  // sub arrays Left and Right
  float* L = (float*)malloc(a * sizeof(float));
  float* R = (float*)malloc(b * sizeof(float));

  // Fills subarrays
  for( int i = 0; i < a; i++)
    L[i] = arr[left+i];
  for( int j = 0; j <b; j++){
    R[j] = arr[mid +1 +j];}


  // initialize counters
  int i = 0;
  int j =0;
  int k = left;

  // merges arrays
  while( i < a && j < b){
    if (L[i] <= R[j]){
        arr[k] = L[i];
        i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // fills array if L still has contents
  while (i < a){
    arr[k] = L[i];
    i++;
    k++;
  }

  // fills array if R still has contents
  while (j < b){
    arr[k] = R[j];
    j++;
    k++;
  }

  // frees memory used by sub arrays.
  free(L);
  free(R);



  

}
  
void MergeSort(float arr[], int left, int right){
  //if array less that 16 sort.
  if(right - left <= 15){
    insertionSort(arr,left,right);
    return;
  }
  int n = right - left;
  // finds the middle
  int mid = left + (right -left) / 2;

  // recursively splits and sorts the array.

  #pragma omp task shared(arr) if (n > 100)
  MergeSort(arr,left,mid);

  #pragma omp task shared(arr) if (n > 100)
  MergeSort(arr, mid +1, right);

  #pragma omp taskwait
  merge(arr,left,mid,right);




}

void mergeSortArr(float arr[], int n){
  MergeSort(arr,0,n-1);
}

void COMPUTE_NAME( int m0,
		   float *x,
		   float *y ) 

{ 

  memcpy(y,x,sizeof(float) * m0);
  
  int numThreads = omp_get_num_threads();

  omp_set_dynamic(0);
  omp_set_num_threads(numThreads);

  #pragma omp parallel
  {

    #pragma omp single
    MergeSort(y,0,m0-1);

  }
  


}
