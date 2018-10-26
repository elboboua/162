/********************************************************************* 
** Description: The implementation file for the University class
*********************************************************************/

#include "University.hpp"
#include "inputValidation.hpp"

#include <iostream>

// A constructor that sets the name of the UNI, creates 2 people, and 1 building
University::University() {

	name = "Oregon State University";
	people.push_back(new Student(3.8, "Ahmad El-Bobou", 25));
	people.push_back(new Instructor(4.0, "Dr. Rooker", 50)); 

	buildings.push_back(new Buildings("Adam's Hall", 11168, "606 SW 15TH ST"));
	buildings.push_back(new Buildings("Aero Engineering Lab", 3637, "852 SW 30TH STREET"));
} 

// A function that prints all the buildings associated with the University in the system
void University::printBuildings() {

	std::cout << "==================================================" << std::endl;

	std::cout << "Buildings at OSU:" << std::endl;


	std::cout << "--------------------------------------------------" << std::endl;

	for (int i = 0; i < buildings.size(); i++) {

		buildings[i]->printInfo();
		std::cout << std::endl;

	}


	std::cout << "==================================================" << std::endl;
}

// A function that prints all the people associated with the University in the system
void University::printPeople() {

	std::cout << "==================================================" << std::endl;

	std::cout << "People at OSU:" << std::endl;


	std::cout << "--------------------------------------------------" << std::endl;

	for (int i = 0; i < people.size(); i++) {

		people[i]->printInfo();
		std::cout << std::endl;

	}


	std::cout << "==================================================" << std::endl;
}

// A function that prints all the people associated with the University in the system
// Then allows you to assign work to one of them
void University::assignWork() {

	std::cout << "==================================================" << std::endl;

	std::cout << "People available for work at OSU:" << std::endl;


	std::cout << "--------------------------------------------------" << std::endl;

	for (int i = 0; i < people.size(); i++) {
		std::cout << "Option " << i+1 << std::endl;
		people[i]->printName();
		std::cout << std::endl;

	}


	std::cout << "==================================================" << std::endl;


	int input;
	std::cout << "Please enter the number of the person you'd like to assign work." << std::endl;
	input = isIntBetweenXAndY(1,people.size());
	std::cout << std::endl;	
	people[input-1]->do_work();
	

	std::cout << "==================================================" << std::endl;


}

// Looping menu function
void University::menu() {

	bool quit = false;

	while (!quit) {
		
		std::cout << "==================================================" << std::endl;

		int input;
		std::cout << "Please choose from the following options:" << std::endl;
		std::cout << "Enter 0 to quit." << std::endl;
		std::cout << "Enter 1 to list buildings."  << std::endl;
		std::cout << "Enter 2 to list people." << std::endl;
		std::cout << "Enter 3 to assign work." << std::endl;

		input = isIntBetweenXAndY(0,3);

		std::cout << "==================================================" << std::endl;

		switch (input) {

			case 1:
				printBuildings();
				break;

			case 2:
				printPeople();
				break;

			case 3:
				assignWork();
				break;

			default:
				std::cout << "Thanks for visiting!" << std::endl;				 
				quit = true;
		}

	}
}

// Destructor to deallocated the dyanamic vectors
University::~University() {

	for (int i = 0; i < people.size(); i++) {

		delete people[i];
		people[i] = nullptr;

	}


	for (int i = 0; i < buildings.size(); i++) {

		delete buildings[i];
		buildings[i] = nullptr;

	}
}
