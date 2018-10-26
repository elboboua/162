/********************************************************************* 
** Description: The implementation file containing the three recursive
** functions needed for this lab
*********************************************************************/

#include <string>
#include <iostream>

// This function prints the reverse of a given string along with a new line character
void reverseString(std::string str) {

	if (str.length() > 0) {

		std::cout << str[str.length()-1];
		str.pop_back();
		reverseString(str);

	} else {

		std::cout << "\n";
	}


}


// This function returns the value of the sumation of all elements in an array
int addArray(int arr[], int size) {

	if (size > 0) {
		return arr[size-1] + addArray(arr, size-1);

	} else {
		return 0;
	}



} 


// This function returns the triangle number of a given int n
int calcTriNum(int n) {

	if (n>0) {
		return n + calcTriNum(n-1);
	} else {
		return 0;
	}



}
