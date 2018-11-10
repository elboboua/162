/********************************************************************* 
** Description: The implementation file for the Harry Potter Class
*********************************************************************/ 

#include "HarryPotter.hpp"
#include <iostream>

HarryPotter::HarryPotter() : Character(10,0, "Harry Potter") {
	hasBeenRevived = false;
}


// This function takes revives Harry if he has died once.
void HarryPotter::takeDamage(int damage) {

	Character::takeDamage(damage);

	if (strength <= 0 && !hasBeenRevived) {

		std::cout << "(Harry has come back to life) ";
		strength = 20;
		hasBeenRevived = true;
	}
}

 
