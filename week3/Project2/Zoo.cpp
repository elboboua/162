/********************************************************************* 
** Description: Implementation file from the Zoo class
*********************************************************************/ 


#include "Zoo.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


// Constructs the zoo object for the beginning of a new zoo. 
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
void Zoo::addTiger(bool baby, bool adult) {
	
	numOfTigers++;

	// if there are more tigers than the array is large, the array doubles in size.
	if (numOfTigers > sizeofTigers) {

		sizeofTigers*=2;
		tigers = new Tiger[sizeofTigers];
	}
	
	if (baby) {
		tigers[numOfTigers-1].setAge(0);
	} else if (adult) {
		tigers[numOfTigers-1].setAge(3);
	}

}


// adds a new turtle to the array
void Zoo::addTurtle(bool baby, bool adult) {
	
	numOfTurtles++;

	// if there are more turtles than the array is large, the array doubles in size.
	if (numOfTurtles > sizeofTurtles) {

		sizeofTurtles*=2;
		turtles = new Turtle[sizeofTurtles];
	}
	if (baby) {
		penguins[numOfTurtles-1].setAge(0);
	} else if (adult) {
		tigers[numOfTurtles-1].setAge(3);
	}
}


// adds a new penguin to the array
void Zoo::addPenguin(bool baby, bool adult) {
	
	numOfPenguins++;

	// if there are more penguins than the array is large, the array doubles in size.
	if (numOfPenguins > sizeofPenguins) {

		sizeofPenguins*=2;
		penguins = new Penguin[sizeofPenguins];
	}


	if (baby) {
		penguins[numOfPenguins-1].setAge(0);
	} else if (adult) {
		tigers[numOfPenguins-1].setAge(3);
	}
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
	
	std::cout << "You just fed your animals." << std::endl;
	std::cout << "You spent $" << cost << "." << std::endl;
}

// This function returns the budget variable
int Zoo::getBudget() {
	return budget;
}



// In this function, a random event occurs. 
void Zoo::randomEvent() {

	int randInt = rand()%4;

	switch (randInt) {
		// An animal dies from sickness
		case 0:
			{ 
				std::string deadAnimal = " ";
				bool triedTigers = false;
				bool triedTurtles = false;
				bool triedPenguins = false;
				while (deadAnimal == " " && !(triedTigers&&triedTurtles&&triedPenguins)) {
					
					int randomDeath = (rand()%3)
;
					if (randomDeath == 0) {
						triedTigers = true;
						if (numOfTigers > 0) {
							deadAnimal = "Tiger";
							numOfTigers--;
						}			
					} else if (randomDeath ==1) {
						triedTurtles = true;
						if (numOfTurtles > 0) {
							deadAnimal = "Turtle";
							numOfTurtles--;
						}
					} else {
						triedPenguins = true;
						if (numOfPenguins > 0) {
							deadAnimal = "Penguin";
							numOfPenguins--;	
						}		
					}
				}
				if (deadAnimal != " ") {
					std::cout << "Oh no! :( A " << deadAnimal << " has died from sickness." << std::endl;
				}
				break;
			}
		case 1:
			// A boom in zoo attendance occurs:
			{
				int randBonus = ((rand()%250)+250)*numOfTigers;
				std::cout << "You got a random bonus of: $" << randBonus << std::endl;
				budget+=randBonus;
				break;
			}
		case 2:
		{	// A baby animal is born:
			bool nobaby = true;
			bool triedTiger = false;
			bool triedTurtle = false;
			bool triedPenguin = false;
			
			// This loop tries gives a random baby if there is an adult animal.
			// If no animals are adults, it informs the user. 
			do {    
				int randInt = rand()%3;
				bool adult;

				if (randInt == 0) {
				
					for (int i =0; i < numOfTigers; i++) {
							if (tigers[i].isAdult()){
								addTiger(true);
								nobaby = false;
								std::cout  << "A baby tiger was born!" << std::endl;
								break;
							}
						}
					
					triedTiger = true;
				
				} else if (randInt == 1) {

					for (int i =0; i < numOfTurtles; i++) {
							if (turtles[i].isAdult()){
								for (int j = 0; j < turtles->getNumOfBabies(); j++) {
									addTurtle(true);
								}
								nobaby = false;
								std::cout << turtles->getNumOfBabies()  << " baby turtles were born!" << std::endl;
								break;
							}
					}

					triedTurtle = true;
				} else if (randInt == 2) {
				
						for (int i =0; i < numOfPenguins; i++) {
							if (penguins[i].isAdult()){
								for (int j = 0; j < penguins->getNumOfBabies(); j++) {
									addPenguin(true);
								}
								nobaby = false;
								std::cout << penguins->getNumOfBabies()  << " baby penguins were born!" << std::endl;
								break;
							}
						}
						
						triedPenguin = true;
				} else {

				}

			
			} while (nobaby && !(triedTiger&&triedTurtle&&triedPenguin));

			if (nobaby) {
			
				std::cout << "None of your animals were old enough to have babies." << std::endl;
			}
			break;
		}
		case 3:
			// Nothing happens
			std::cout << "It seems like nothing random happened today." << std::endl;		
	}
}	



// This function iterates through the animals to check for adults. 
bool Zoo::anyAdults() {

	bool adult = false;

	
	for (int i =0; i < numOfTigers; i++) {
		if (tigers[i].isAdult()){
			adult = true;
		}
	}


	for (int i =0; i < numOfTurtles; i++) {
		if (turtles[i].isAdult()){
			adult = true;
		}
	}

	for (int i =0; i < numOfPenguins; i++) {
		if (penguins[i].isAdult()){
			adult = true;
		}
	}
	return adult;
}


// This starts the game
bool Zoo::beginGame() {
	
	bool quit = false;
	int input;

	// display game title
	std::cout << "Welcome to Zoo Tycoon! Build your zoo with us!" << std::endl;

	// wanna play?
	std::cout << "Enter 1 to play and 0 to quit: " << std::endl;	
	input = isIntAboveXBelowY(-1,2);
	if (input == 0) {
		return false;
	}
	// display money
	std::cout << "Your starting budget is: " << budget << "." << std::endl;

	// ask to buy animal
	std::cout << "Start your zoo career by purchasing a few animals!" << std::endl;
	std::cout << "Would you like to buy 1 or 2 tigers?" << std::endl;
	input = isIntAboveXBelowY(0,3);
	
	// buy starter tigers
	makePurchase(input*tigers[0].getCost());
	
	for (int i = 0; i < input; i++) {
		addTiger();	
	}

	std::cout << "You have purchased " << input << " tiger(s)" << std::endl;

	// buy starter turtles
	std::cout << "Would you like to buy 1 or 2 turtles?" << std::endl;
	input = isIntAboveXBelowY(0,3);
	makePurchase(input*turtles[0].getCost());

	for (int i = 0; i < input; i++) {
		addTurtle();	
	}

	std::cout << "You have purchased " << input << " turtle(s)" << std::endl;

	// buy starter penguins
	std::cout << "Would you like to buy 1 or 2 penguins?" << std::endl;
	input = isIntAboveXBelowY(0,3);
	makePurchase(input*penguins[0].getCost());

	for (int i = 0; i < input; i++) {
		addPenguin();	
	}

	std::cout << "You have purchased " << input << " penguin(s)" << std::endl;


	// this function returns a bool
	return true;

}


// This function takes an int value and subtracts it from the budget. 
void Zoo::makePurchase(int purchase) {

		budget-= purchase;
		std::cout << "You have spent $" << purchase << "." << std::endl;

}

void Zoo::loopGame() {

	bool quit = false;

	while (!quit) {

		// A divider for the turns
		std::cout << "---------------------------------------------------------------------------------" << std::endl;
		std::cout << "Round " << turns+1 << "." << std::endl;
		turns++;


		// give some space
		std::cout << std::endl << std::endl;

		// age animals
		ageAnimals();
		
		// feed animals
		feedAnimals();
	
		// random event
		randomEvent();
		
        // display payOff
		depositPayoff();		

		// display budget
		std::cout << "You have $" << budget << " in the bank." << std::endl;

		// Offer to buy animals
		int input;
		std::cout << "Would you like to purchase an animal? Enter 1 for yes, 0 for no." << std::endl;
		input = isIntAboveXBelowY(-1,2);
		
		if (input == 1) {
			
			std::cout << "To purchase a tiger enter 1." << std::endl;
			std::cout << "To purchase a turtle enter 2." << std::endl;
			std::cout << "To purchase a penguin enter 3." << std::endl;
			input = isIntAboveXBelowY(0,4);
				
				if (input == 1) {
					
					addTiger(false,true);
					std::cout << "You have bought a tiger!" << std::endl;
					makePurchase(tigers->getCost());
				} else if (input == 2) {

					addTurtle(false,true);
					std::cout << "You have bought a turtle!" << std::endl;
					makePurchase(turtles->getCost());

				} else {

					addPenguin(false,true);
					std::cout << "You have bought a penguin!" << std::endl;
					makePurchase(penguins->getCost());


				}
			
		}
		std::cout << std::endl;
				
		// display Animals
		displayAnimals();		


		// Check budget, offer to play again

		if (budget <= 0) {
			std::cout << "Oops! It looks like you ran out of money :(" << std::endl;
			std::cout << "GAME OVER!" << std::endl;
			quit = true;
			} else if (numOfTigers == 0 && numOfTurtles == 0 && numOfPenguins == 0) {
			std::cout << "Oops! It looks like all your animals died :(" << std::endl;
			std::cout << "GAME OVER!" << std::endl;
			quit = true;
			} else {
			int input;
			std::cout << "If you'd like to continue, enter 1. If not, enter 0." << std::endl;
			input = isIntAboveXBelowY(-1,2);
		
				if (input == 0) {
					std::cout << "GAME OVER!" << std::endl;	
					quit = true;
				}

		}		
	}
}


// This function calculates the payoff from all the animals. 
void Zoo::depositPayoff() {

	int payOff=0;

	payOff += numOfTigers*tigers->getPayOff();	
	payOff += numOfTurtles*turtles->getPayOff();	
	payOff += numOfPenguins*penguins->getPayOff();	

	std::cout << "You have made $" << payOff << " in zoo revenue." << std::endl;
	budget+=payOff;	
}

// This function displays the number of animals to the user
void Zoo::displayAnimals() {

	std::cout << "You have " << numOfTigers << " tiger(s)." << std::endl;
	std::cout << "You have " << numOfTurtles << " turtle(s)." << std::endl;
	std::cout << "You have " << numOfPenguins << " penguin(s)." << std::endl;

}


// This destructor deletes the dynamically allocated arrays and sets them to nullptrs. 
Zoo::~Zoo() {
	
	delete tigers;
	tigers = nullptr;

	delete turtles;
	turtles = nullptr;

	delete penguins;
	penguins = nullptr;

}
