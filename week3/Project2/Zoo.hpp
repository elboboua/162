/********************************************************************* 
** Description: The specification file for the Zoo class.
*********************************************************************/ 

#ifndef ZOO_H
#define ZOO_H

#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Zoo {

private:

	// pointers to the base class. 
	Animal *tigers;
	Animal *turtles;
	Animal *penguins;
	
	// variables to keep track of the size of the animals
	int sizeofTigers;
	int sizeofTurtles;
	int sizeofPenguins;
	
	// the number of animals in the zoo by type
	int numOfTigers;
	int numOfTurtles;
	int numOfPenguins;

	// Zoo info
	int budget;
	int turns;

public:
	Zoo();

	// returns budget
	int getBudget();

	// adds a new animal type to the array
	// The first bool is true if the animal is a baby at age 0, false if not
	// The second bool is true if the animal is an adult, false if not. 
	void addTiger(bool = false, bool = false);
	void addTurtle(bool = false, bool = false);
	void addPenguin(bool = false, bool = false);


	// ages the animals by a day
	void ageAnimals();

	// feeds the animals
	void feedAnimals();

	// causes a random event to occur
	void randomEvent();
	// this function is inside the random birth functioni
	bool anyAdults();

	// functions that introduce and display the rounds of the game
	bool beginGame();
	void loopGame();
	void makePurchase(int);
	void depositPayoff();
	void displayAnimals();

	// destructor
	~Zoo();
};

#endif // ZOO_H
