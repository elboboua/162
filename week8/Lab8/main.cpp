/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 11-17-2018
** Description: Lab8 - Sorting and Searching Algorithms
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "inputValidation.hpp"
#include "Algorithms.hpp"

//main function
int main () {

	const int NORMALSIZE = 9;
	const int BIGGERSIZE = 10;
	int searchKey;

	int normal[NORMALSIZE], begin[BIGGERSIZE], middle[BIGGERSIZE], end[BIGGERSIZE];
	std::ifstream n("normal.txt"), b("early.txt"), m("middle.txt"), e("end.txt");

	// shows an error if there is a problem creating the ifstream objects.
	if ( !(n && b && m && e) ) {
		std::cout << "ERROR creating the ifstream objects!" << std::endl;
	}

	// puts the numbers in the text files in their respective arrays
	buildArray(normal, n);
	buildArray(begin, b);
	buildArray(middle, m);
	buildArray(end, e);

	// closes the ifstream files to avoid memory corruption
	n.close();
	b.close();
	m.close();
	e.close();

	// this sections performs a sequential search and displays if that value is found in each of the files
	std::cout << "What is the target value you'd like to check for in the text files?" << std::endl;
	searchKey = isInt();

	// checks the normal array
	std::cout << "normal.txt: target value ";
	if (simpleSearch(normal, NORMALSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;
	
	// checks the array with the 0 towards the beginning
	std::cout << "early.txt: target value ";
	if (simpleSearch(begin, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	// checks the array with the 0 towards the middle
	std::cout << "middle.txt: target value ";
	if (simpleSearch(middle, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	// checks the array with the 0 towards the end
	std::cout << "end.txt: target value ";
	if (simpleSearch(end, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	std::string fileName1,fileName2, fileName3;

	// sorts the beginning array, adds it to a user specified file, then displays it
	std::cout << "What would you like the name of the text file that saves the newly sorted early array to be?" << std::endl;
	std::cin >> fileName1;
	std::ofstream bSorted(fileName1);	
	bubbleSort(begin, BIGGERSIZE);
	saveArray(begin, BIGGERSIZE, bSorted);
	printArray(begin, BIGGERSIZE);
	std::cout << std::endl;		

	// sorts the middle array, adds it to a user specified file, then displays it
	std::cout << "What would you like the name of the text file that saves the newly sorted middle array to be?" << std::endl;
	std::cin >> fileName2;
	std::ofstream mSorted(fileName2);	
	bubbleSort(middle, BIGGERSIZE);
	saveArray(middle, BIGGERSIZE, mSorted);
	printArray(middle, BIGGERSIZE);
	std::cout << std::endl;		

	// sorts the end array, adds it to a user specified file, then displays it
	std::cout << "What would you like the name of the text file that saves the newly sorted end array to be?" << std::endl;
	std::cin >> fileName3;
	std::ofstream eSorted(fileName3);	
	bubbleSort(end, BIGGERSIZE);
	saveArray(end, BIGGERSIZE, eSorted);
	printArray(end, BIGGERSIZE);
	std::cout << std::endl;		


	// this sections performs a binary search and displays if that value is found in each of the files
	std::cout << "What is the target value you'd like to check for in the new text files?" << std::endl;
	searchKey = isInt();


	// checks the array with the 0 towards the beginning
	std::cout << fileName1 << ": target value ";
	if (binarySearch(begin, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	// checks the array with the 0 towards the middle
	std::cout << fileName2 << ": target value ";
	if (binarySearch(middle, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	// checks the array with the 0 towards the end
	std::cout << fileName3 << ": target value ";
	if (binarySearch(end, BIGGERSIZE, searchKey) > -1) {
		std::cout << "found";
	} else {
		std::cout << "not found";
	}
	std::cout <<std::endl;

	bSorted.close();
	mSorted.close();
	eSorted.close();
	return 0;
}
