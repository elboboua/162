/********************************************************************* 
** Description: Implementation file from the Zoo class
*********************************************************************/ 


#include "Zoo.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Zoo::Zoo() {

	sizeofTigers = 10;
	sizeofTurtles = 10;
	sizeofPenguins = 10;


	tigers = new Tiger[sizeofTigers];
	turtles = new Turtle[sizeofTurtles];
	penguins = new Penguin[sizeofPenguins];

	// No animals at the beginning of the zoo.
	numOfTigers = 0;
	numOfTurtles = 0;
	numOfPenguins = 0;

	// Starting budget $100,000
	budget = 100000;

	turns = 0;
}


// adds a new tiger to the array
void Zoo::addTiger(bool baby) {
	
	numOfTigers++;

	// if there are more tigers than the array is large, the array doubles in size.
	if (numOfTigers > sizeofTigers) {

		sizeofTigers*=2;
		tigers = new Tiger[sizeofTigers];
	}
	if (!baby) {
		std::cout << "A new tiger was added" << std::endl;
	} else if (baby) {
		std::cout << "A baby tiger was born" << std::endl;
		tigers[numOfTigers-1].createBaby();
		std::cout << "The baby tiger is : " << tigers[numOfTigers-1].getAge() << std::endl;
		std::cout << "The baby tiger is worth: " << tigers[numOfTigers-1].getCost() << std::endl;

	}
	std::cout << "sizeofTigers: " << sizeofTigers << std::endl;
	std::cout << "numOfTigers: " << numOfTigers << std::endl;	

}


// adds a new turtle to the array
void Zoo::addTurtle(bool baby) {
	
	numOfTurtles++;

	// if there are more turtles than the array is large, the array doubles in size.
	if (numOfTurtles > sizeofTurtles) {

		sizeofTurtles*=2;
		turtles = new Turtle[sizeofTurtles];
	}

	if (!baby) {
		std::cout << "A new turtle was added" << std::endl;
	} else if (baby) {
		std::cout << "A baby turtle was born" << std::endl;
		turtles[numOfTurtles-1].createBaby();
		std::cout << "The baby turtle is : " << turtles[numOfTurtles-1].getAge() << std::endl;
	}
	std::cout << "sizeofTurtles: " << sizeofTurtles << std::endl;
	std::cout << "numOfTurtles: " << numOfTurtles << std::endl;	
}


// adds a new penguin to the array
void Zoo::addPenguin(bool baby) {
	
	numOfPenguins++;

	// if there are more penguins than the array is large, the array doubles in size.
	if (numOfPenguins > sizeofPenguins) {

		sizeofPenguins*=2;
		penguins = new Penguin[sizeofPenguins];
	}

	if (!baby) {
		std::cout << "A new penguin was added" << std::endl;
	} else if (baby) {
		std::cout << "A baby penguin was born" << std::endl;
		penguins[numOfPenguins-1].createBaby();
		std::cout << "The baby penguin is : " << penguins[numOfPenguins-1].getAge() << std::endl;
	}
	std::cout << "sizeofPenguins: " << sizeofPenguins << std::endl;
	std::cout << "numOfPenguins: " << numOfPenguins << std::endl;	
}


// This function ages the animal by a day
void Zoo::ageAnimals () {

	// Age tigers
	for (int i = 0; i < numOfTigers; i++) {
		tigers[i].growAnimal();
	}
	// Age turtles
	for (int i = 0; i < numOfTurtles; i++) {
		turtles[i].growAnimal();
	}
	// Age penguins
	for (int i = 0; i < numOfPenguins; i++) {
		penguins[i].growAnimal();
	}
}

// This function simulates feeding your animals and subtracts from your money. 
void Zoo::feedAnimals(){

	int cost = 0; 

	cost += (numOfTigers*tigers->getBaseFoodCost());
	cost += (numOfTurtles*turtles->getBaseFoodCost());
	cost += (numOfPenguins*penguins->getBaseFoodCost());

	budget-=cost;
}

// This function returns the budget variable
int Zoo::getBudget() {
	return budget;
}



// In this function, a random event occurs. 
void Zoo::randomEvent() {

	int randInt =rand()%4;

	switch (randInt) {
		// An animal dies from sickness
		case 0:
			{ 
				int randomDeath = (rand()%3);
				std::string deadAnimal;
				if (randomDeath == 0) {
					deadAnimal = "Tiger";
					numOfTigers--;			
				} else if (randomDeath ==1) {
					deadAnimal = "Turtle";
					numOfTurtles--;
				} else {
					deadAnimal = "Penguin";
					numOfTigers--;			
				}

				std::cout << "Oh no! :( A " << deadAnimal << " has died from sickness." << std::endl;
				break;
			}
		case 1:
			// A boom in zoo attendance occurs:
			{
				int randBonus = ((rand()%250)+250)*numOfTigers;
				std::cout << "You got a random bonus of: $" << randBonus << std::endl;
				budget+=randBonus;
				std::cout << "You're current budget is: " << getBudget() << std::endl;
				break;
			}
		case 2:
			// A baby animal is born:
			{    
				int randInt = rand()%3;
				bool adult;


				if (randInt == 0) {
				
					for (int i =0; i < numOfTigers; i++) {
							std::cout << tigers[i].getAge()<< std::endl;
							if (tigers[i].getAge() >= 3){
								addTiger(true);
								break;
							}
						}
				
				} else if (randInt == 1) {

					for (int i =0; i < numOfTurtles; i++) {
							std::cout << turtles[i].getAge()<< std::endl;
							if (turtles[i].getAge() >= 3){
								addTurtle(true);
								break;
							}
					}
				} else if (randInt == 2) {
				
						for (int i =0; i < numOfPenguins; i++) {
							std::cout << penguins[i].getAge()<< std::endl;
							if (penguins[i].getAge() >= 3){
								addPenguin(true);
								break;
							}
						}
				} else {

				}

				break;
			}
		case 3:
			// Nothing happens
			std::cout << "It seems like nothing random happened today." << std::endl;		
	}
}	




bool Zoo::anyAdults() {

	bool adult = false;

	
	for (int i =0; i < numOfTigers; i++) {
		std::cout << tigers[i].getAge()<< std::endl;
		if (tigers[i].getAge() >= 3){
			adult = true;
		}


	for (int i =0; i < numOfTurtles; i++) {
		std::cout << turtles[i].getAge()<< std::endl;
		if (turtles[i].getAge() >= 3){
			adult = true
		}

	for (int i =0; i < numOfPenguins; i++) {
		std::cout << penguins[i].getAge()<< std::endl;
		if (penguins[i].getAge() >= 3){
			adult = true;
		}

	return adult;
}



