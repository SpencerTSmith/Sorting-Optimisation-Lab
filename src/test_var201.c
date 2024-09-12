/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif


void COMPUTE_NAME( int m0,
		   float *x,
		   float *y )

{


  /* 
     We need an out-of-place sort (input array != output array)
     so we will do the slowest but easiest thing to get a working
     implementation. First we will copy the contents of the input
     array x into array y, then perform an in-place sort on y.

  */

  // copy the contents of the input array into the output array
  //for( int i0 = 0; i0 < m0; i0++ )
    //y[i0] = x[i0];
  

  // perform the absolute worse in-place bubble sort.
  for( int i0 = 0; i0 < m0 - 1; i0++ )
  {
     // Find the minimum element in unsorted array
        int min_idx = i0;
        for (int j0 = i0 + 1; j0 < m0; j0++) {
            if (x[j0] < x[min_idx]) {
                min_idx = j0;
            }
        }

        // Swap the found minimum element with the first
        // element in the unsorted part
        float temp = x[min_idx];
        x[min_idx] = x[i0];
        x[i0] = temp;
	//copy to y
	y[min_idx]=x[min_idx];
	y[i0]=x[i0];
  }

}

