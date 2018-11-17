/********************************************************************* 
** Description: The implementation file for the algorithm functions
*********************************************************************/ 

#include "Algorithms.hpp"
#include <iostream>

// This function takes an ifstream object and iterates until all ints from the file are stored
void buildArray(int a[], std::ifstream& ifs) {

	int index = 0;
	while (ifs >> a[index]) {
		index++;
	}
}

// This function prints an array
void printArray(int a[], int SIZE) {

	for (int i = 0; i < SIZE; i++) {
		std::cout << a[i] << " ";
	}
}

// This function copies an array into an ofstream object
void saveArray(int a[], int SIZE, std::ofstream & ofs) {

	for (int i = 0; i < SIZE; i++) {
		ofs << a[i] << " ";
	}
}

// Performs a sequential search and returns true if the searchKey is found
int simpleSearch(int a[], int SIZE, int searchKey) {
	int position = -1;

	for (int i = 0; i < SIZE; i++) {
		if (a[i] == searchKey) {
			position = i;
		}
	}
	return position;
}

// Sorts the array it is given - from Textbook pg 616
void bubbleSort(int a[], int SIZE) {

	bool swap;
	int temp;

	do {
		swap = false;

		for (int i = 0; i < SIZE - 1; i++) {
			if ( a[i] > a[i+1] ) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swap = true;			
			}
		}
	} while (swap == true);
}

// This functions performs a binary search on an array and returns the position of the 
// value if it is found - from Textbook pg 609
int binarySearch(int a[], int SIZE, int searchKey) {

	bool found = false;
	int position = -1;
	int middle;
	int first = 0;
	int last = SIZE - 1;

	while (!found && first <= last) {

		middle = (first+last)/2;

		if (a[middle] == searchKey) {
			found = true;
			position = middle;
		} else if (a[middle] > searchKey) {
			last = middle - 1;
		} else {
			first = middle +1;
		}	
	}


	return position;
}


