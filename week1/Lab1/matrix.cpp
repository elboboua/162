/********************************************************************* 
*** Description: The implementation file for the matrix function
**********************************************************************/ 

#include "matrix.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// This function takes a 2d dynamic array, the desired size of the matrix
// The function them loops through the array and requests the value of each element.
void readMatrix(int size, int** a) {


    // loop through the array to fill the numbers
    int counter = 1;
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {

            int number;
              
             cout << "Enter number " << counter << ":" << endl;
             cin >> number;
             a[j][k] = number;
             counter++;

        }
}


}

