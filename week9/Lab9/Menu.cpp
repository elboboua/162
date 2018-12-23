/********************************************************************* 
** Description: The implementation for the Menu class
*********************************************************************/ 

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Menu.hpp"
#include "inputValidation.hpp"

Menu::Menu() {

	srand(time(NULL));

}


Menu::~Menu() {

}


// simulates a buffer
void Menu::bufferSim() {

	std::queue<int> buffer;
	int rounds;
	int n;
	int addPercent, removePercent;
	int addChance, removeChance;
	int len = 0;
	double aveLen = 0;

	std::cout << "How may rounds would you like to simulate?" << std::endl;
	rounds = isIntAboveX(0);
	std::cout << "What percent chance should we add a number?" << std::endl;
	addPercent = isIntBetweenXAndY(0,100);
	std::cout << "What percent chance should we remove a number?" << std::endl;
	removePercent = isIntBetweenXAndY(0,100);
	std::cout << std::endl;


	for (int i = 0; i < rounds; i++) {
		// generate random number
		n = 1 + rand()%1000;
		addChance = 1 + rand()%100;
		removeChance = 1 + rand()%100;
		// display to user
		std::cout << "The randomly generated number is: " << n << std::endl;

		if (addChance <= addPercent) {
			buffer.push(n);
			std::cout << "The value has been added to the buffer." << std::endl;
		} else {
			std::cout << "The value has not been added to the buffer." << std::endl;
		}

		if (removeChance <= removePercent && !buffer.empty()) {
			buffer.pop();
			std::cout << "A value has been removed the buffer." << std::endl;
		} else {
			std::cout << "A value has not been removed the buffer." << std::endl;
		}
		
		// display the values
		displayBuffer(buffer);
		std::cout << "The buffer length is: " << buffer.size() << std::endl;

		// average length	
		len = buffer.size();
		// round = i+1
		aveLen = (aveLen * ((i+1)- 1) + len) / (i+1);
		std::cout << "The average length is: " << aveLen << std::endl; 
		std::cout << std::endl;
	}


}


// prints the values of a buffer; if empty, prints message 
void Menu::displayBuffer(std::queue<int> buffer) {

	if (buffer.empty()) {

		std::cout << "Your buffer is empty." << std::endl;		

	} else {

		std::queue<int> copy;
		copy = buffer;


		while (!copy.empty()) {

			std::cout << copy.front() << " ";
			copy.pop();
		}
		
		std::cout << std::endl;

	}
}

// creates a palindrome from a string
void Menu::palindrome() {

	std::stack<char> pMaker;
	std::string input;

	std::cout << "Enter a string to be palindromized" << std::endl;
	getline(std::cin, input); 

	for (int i = 0; i < input.size(); i++) {

		pMaker.push(input[i]);
	}


	while (!pMaker.empty()) {

		input += pMaker.top();	
		pMaker.pop();
	}

	std::cout << input;
	std::cout << std::endl;
	

}


// responsible for looping the menu
void Menu::loop() {

	bool quit = false;
	int input;

	while (!quit) {

		std::cout << "Please enter an integer for the following choices:" << std::endl;
		std::cout << "1. Simulate a buffer" << std::endl;
		std::cout << "2. Make a palindrome" << std::endl;
		std::cout << "3. Quit" << std::endl;
		input = isIntBetweenXAndY(1,3);
		std::cin.ignore();

		switch (input) {

			case 1:
				bufferSim();
				break;

			case 2:
				palindrome();
				break;

			case 3:
				quit = true;
				break;
	
		}
	
		std::cout << std::endl;
	}
}

