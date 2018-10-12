/*********************************************************************
 ** Author: Ahmad El-Bobou
 ** Date: 09-25-2018
 ** Description: Lab 1 - A program to find the determinant of a matrix
 *********************************************************************/

#include "matrix.h"
#include "determinant.h"
#include <string>
using std::string;
using std::stoi;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Prototyping the input validation function
int intChecker (string);


// Main function
int main () {

    string num;
    int size;
    int dtrmt;

    // Asks the user to choose the size of the matrix
    cout << "Choose the size of your matrix." << endl;
    cout << "Enter 2 for a 2x2 or 3 for a 3x3: ";
    getline(cin, num);
    size = intChecker(num);
    cout << endl;

    // Dynamically allocates the memory space for the matrix
    // Idea adapted from the top answer on the following stack overflow question on Pointers to 2d Arrays
    // http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    int ** a = new int * [size];
    for (int i = 0; i < size; i++) {
        a[i] = new int[size];
        }   

    // using readMatrix() to prompt the user to enter the appropriate amount of integers
    readMatrix(size, a);

    //calculate the determinant using determinant()
    dtrmt = determinant(size, a);

    // Display the matrix in square format and the determinant to the user
    cout << "This is the matrix: " << endl;
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
           cout << a[j][k] << " ";
         }
            cout << endl;
    }

    cout << "This is the determinant: " << dtrmt << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < size; ++i) {
        delete [] a[i];
    }
    delete [] a;
    a = NULL;
        

    return 0;
}

// Defining the input validation function
int intChecker(string number) {

    bool appropriateNumber;
    int theInt;
    do {

    appropriateNumber = true;

    for (int i = 0; i < number.size(); i++) {
        if (number[i] < 50 || number[i] >  51) {

            appropriateNumber = false;
         }
    }

    if (!appropriateNumber) {
        cout << "It seems you've not entered an appropriate number." << endl;
        cout << "Please enter 2 or 3:" << endl;
        cin >> number;
     }
    } while (appropriateNumber == false);
    
    //converts string to int
    theInt = stoi(number);
    return theInt;
}










