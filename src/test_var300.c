// merge sort with inserion sort for small arrays
#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif




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
 
  if (left < right){
  // finds the middle
  int mid = left + (right -left) / 2;

  // recursively splits and sorts the array.
  MergeSort(arr,left,mid);
  MergeSort(arr, mid +1, right);

  merge(arr,left,mid,right);
  }



}

void mergeSortArr(float arr[], int n){
  MergeSort(arr,0,n-1);
}

void COMPUTE_NAME( int m0,
		   float *x,
		   float *y )

{
  

 
  for( int i0 = 0; i0 < m0; ++i0 )
    y[i0] = x[i0];
  
  
  mergeSortArr(y,m0);



}
