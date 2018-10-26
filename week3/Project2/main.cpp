/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 10-14-2018
** Description: Project 2 - Zoo Typhoon
*********************************************************************/


#include "Zoo.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {

	// used to create random ints in other parts of the program.
	srand(time(NULL));

	// create a zoo object.
	Zoo zoo;
	
	// begin the game
	if (!zoo.beginGame()) {

		return 0;

	}

	// loop until user desires to quick
	zoo.loopGame();

	return 0; 
}               

 
