/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 11-10-2018
** Description:Lab7 - Working with a circular linked list as a queue  
*********************************************************************/

#include "Queue.hpp"
#include "inputValidation.hpp"
#include <iostream>

// The menu function defined below that allows the user to manipulate the queue
void menu();

// main function runs the menu()
int main() {

	menu();

	return 0;
}

void menu() {
	Queue queue;
	bool quit = false;
	int choice,input;

	// loops until user quits
	while (!quit) {
	
		// presents options
		std::cout << "=========================================================" << std::endl;
		std::cout << "" << std::endl;


		std::cout << "Choose from the following options: " << std::endl;
		std::cout << "1. Enter a value to be enqueued." << std::endl;
		std::cout << "2. Display the first node of the queue" << std::endl;
		std::cout << "3. Dequeue the first node of the queue" << std::endl;
		std::cout << "4. Display the queue contents" << std::endl;
		std::cout << "5. Exit" << std::endl;
		
		std::cout << "" << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
		choice = isIntBetweenXAndY(1,5);
		std::cout << "" << std::endl;


		switch (choice) {
			// enqueue a value
			case 1:
				std::cout << "Please enter an integer to be enqueued: ";
				input = isInt();
				queue.addBack(input);
				break;
			// display first in line
			case 2:
				if (!queue.isEmpty()) {
					std::cout << "The value of the first node is: " << queue.getFront() << std::endl;
				} else {
					std::cout << "The queue is empty." << std::endl;
				}
				break;
			// dequeue the first node
			case 3:
				if (!queue.isEmpty()) {
					queue.removeFront();
				} else {
					std::cout << "The queue is empty." << std::endl;
				}
				
				break;
			// display the queue
			case 4:
				if (!queue.isEmpty()) {
					std::cout << "The current queue: ";
					queue.printQueue();
				} else {
					std::cout << "The queue is empty." << std::endl;
				}
				break;
			// quit
			case 5:
				quit = true;
				std::cout << "Thank you for using the program!" << std::endl;
				break;

		}

		std::cout << "=========================================================" << std::endl;
	}
}
