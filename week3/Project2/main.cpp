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

srand(time(NULL));

	Zoo zoo;
	zoo.addTiger();
	zoo.addTurtle();
	zoo.addPenguin();

	zoo.ageAnimals();
	zoo.ageAnimals();
	zoo.ageAnimals();
	zoo.ageAnimals();
	zoo.ageAnimals();

	zoo.randomEvent();

	return 0;
 
}               

 
