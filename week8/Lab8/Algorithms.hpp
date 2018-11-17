/********************************************************************* 
** Description: The specification file for the algorithm functions
*********************************************************************/ 

#include <fstream>


// This function takes an ifstream object and iterates until all ints from the file are stored
void buildArray(int [], std::ifstream&);

// This function prints an array
void printArray(int [], int);

// This function copies an array into an ofstream object
void saveArray(int [], int, std::ofstream&);

// Performs a sequential search and returns true if the searchKey is found
int simpleSearch(int [], int, int);

// Sorts the array it is given - from Textbook pg 616
void bubbleSort(int [], int);

// This functions performs a binary search on an array and returns the position of the 
// value if it is found - from Textbook pg 609
int binarySearch(int [], int, int);
