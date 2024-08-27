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
  for( int i0 = 0; i0 < m0; ++i0 )
    y[i0] = x[i0];
  

  // perform the absolute worse in-place bubble sort.
  for( int i0 = 0; i0 < m0; ++i0 )
    for( int j0 = 0; j0 < m0-1; ++j0 )
    {
      if( y[j0] > y[j0+1])
	{
	  float z = y[j0];
	  y[j0]   = y[j0+1];
	  y[j0+1] = z;
	}

    }

}
