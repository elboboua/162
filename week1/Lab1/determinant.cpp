/********************************************************************* 
*** Description: The implementation file for the determinant function
**********************************************************************/ 


#include "determinant.h"



// This function takes a dynamically allocated 2d array and returns its determinant.
int determinant(int size, int**a) {

    int d;

    if (size == 2) {

    // this is the calculation for a 2x2 matrix determinant
    d = ((a[0][0] * a[1][1]) - (a[0][1]*a[1][0]));




    } else if (size == 3) {

    // this is the calculation for a 3x3 matrix determinant
    d =
            (a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])) -

            (a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])) +

            (a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]));



    }

    return d;
}
