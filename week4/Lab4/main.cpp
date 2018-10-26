/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 10-21-2018
** Description: Lab 4 - OSU Information System 
*********************************************************************/

#include "University.hpp"

#include <cstdlib>
#include <ctime>


// This program presents people and buildings that are already in the system 
int main () {
	
	// Create a random seed for the random functions in the program
	srand(time(NULL));

	// create a university object
	University osu;
	
	// start the object menu
	osu.menu();

	return 0;
}
