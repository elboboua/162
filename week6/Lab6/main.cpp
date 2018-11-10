/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 11-02-2018
** Description: Lab 6 - Doubly Linked List 
*********************************************************************/

#include "DoublyLinkedList.hpp"
#include "inputValidation.hpp"
#include <iostream>

void menu();

int main () {

	menu();

	return 0;
}

// This menu function first asks the user if they want to generate a list from info from a text file
// Then it gives them 7 options until the user quits
void menu() {

	bool quit = false;
	DLL dll;
	int input,value;

	std::cout << "Would you like to create an initial list from a provided text file?" << std::endl;
	std::cout << "Enter 1 for yes, 0 for no:" << std::endl;
	input = isIntBetweenXAndY(0,1);
	if (input == 1) {

		dll.createListFromFile();
		dll.traverse();
	}


	while (!quit) {


		std::cout << std::endl;

		std::cout <<  "Please choose from the following options:" << std::endl;	
		std::cout <<  "0. Quit" << std::endl;	
		std::cout <<  "1. Add a new node to the front of the list" << std::endl;	
		std::cout <<  "2. Add a new node to the back of the list" << std::endl;	
		std::cout <<  "3. Delete the first node of the list" << std::endl;	
		std::cout <<  "4. Delete the last node of the list" << std::endl;	
		std::cout <<  "5. Print the list from last node to first node" << std::endl;	
		std::cout <<  "6. Print the value of the head node" << std::endl;	
		std::cout <<  "7. Print the value of the tail node" << std::endl;	
	
		input = isIntBetweenXAndY(0,7);

		switch (input) {

			// quit
			case 0:
				std::cout << "Thanks for using my program!!!" << std::endl;
				quit = true;
				break;

			// add at the front
			case 1:
				std::cout << "Please enter an integer to add to the beginning of the list" << std::endl;
				value = isInt();
				dll.addToHead(value);
				dll.traverse();				
				break;

			// add at the end
			case 2:
				std::cout << "Please enter an integer to add to the end of the list" << std::endl;
				value = isInt();
				dll.addToTail(value);
				dll.traverse();				
				break;
			// delete front
			case 3:
				dll.deleteFirstNode();
				dll.traverse();
				break;

			// delete last
			case 4:
				dll.deleteLastNode();
				dll.traverse();
				break;

			// print reverse
			case 5:
				dll.traverseReverse();
				break;

			// print head
			case 6:
				dll.printHead();				
				break;

			// print tail
			case 7:
				dll.printTail();
				break;

		}


	}
}
