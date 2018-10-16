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

	// variables necessary to keep track of animals
	Tiger *tigers;
	Turtle *turtles;
	Penguin *penguins;

	int sizeofTigers;
	int sizeofTurtles;
	int sizeofPenguins;
	
	int numOfTigers;
	int numOfTurtles;
	int numOfPenguins;

	// Zoo info
	int budget;
	int turns;

public:
	Zoo();

	int getBudget();

	// adds a new animal type to the array
	void addTiger(bool = false);
	void addTurtle(bool = false);
	void addPenguin(bool = false);


	// ages the animals by a day
	void ageAnimals();

	// feeds the animals
	void feedAnimals();

	// causes a random event to occur
	void randomEvent();
	// this function is inside the random birth functioni
	bool anyAdults();
	bool randomBirth(int randInt, bool&);
};

#endif // ZOO_H

