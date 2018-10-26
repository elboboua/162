/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 10-24-2018
** Description: Lab 5 - Recursive functions practice  
*********************************************************************/


#include "recursiveFunctions.hpp"
#include "inputValidation.hpp"
#include <string>
#include <iostream>

// This is the menu function, defined below main
void menu();

// The main function
int main () {

	menu();

	return 0;
}

// This is menu function.
void menu () {

	bool quit = false;
	
	// This loops until the user quits
	while (!quit) {

		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "Pick from the following options:" << std::endl; 
		std::cout << "0. Quit" << std::endl; 
		std::cout << "1. Print a user created string in reverse." << std::endl; 
		std::cout << "2. Add the contents of a user generated array." << std::endl; 
		std::cout << "3. Return the triangle number for a given int n" << std::endl; 
		int input = isIntBetweenXAndY(0,3);
		std::cout << "----------------------------------------------------------" << std::endl;

		switch (input) {
			
			// User quits
			case 0:
				quit = true;
				std::cout << "Thanks for using my program!" << std::endl;
				break;

			// User enters a string to be printed in reverse 
			case 1:
				{				
					std::string str;
					std::cin.ignore();
					std::cout << "Enter a string to be reversed: ";
					getline(std::cin, str);
					std::cout << std::endl << "Reversed string: ";
					reverseString(str);
					std::cout << std::endl;
					break;
				}	

			// User creates an array to be added together.
			case 2:
				{
					int size;
					int * a;

					std::cout << "Please enter an integer to define the size of your array: ";
					size = isIntAboveX(-1);
					
					
					a = new int[size];

					for (int i = 0; i < size; i++) {
						std::cout << "Please enter element " << i << ": ";
						std::cin >> a[i];
					}

					std::cout << "The sum of all elements is: " << addArray(a,size) << std::endl << std::endl;

					delete a;
					a = nullptr;
					break;
				}

			// User enters and integer n and the function returns its triangle number.
			case 3:
				{

					int n;
					std::cout << "Enter an integer to display its triangle number: ";
					n = isIntBetweenXAndY(1, 100000);

					std::cout << calcTriNum(n) << std::endl;
					break;
				}
		}
	}
}
