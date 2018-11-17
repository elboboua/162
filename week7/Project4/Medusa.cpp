/********************************************************************* 
** Description: The implementation file for the Medusa class
*********************************************************************/

#include "Medusa.hpp" 
#include <iostream>

Medusa::Medusa() : Character (8, 3, "Medusa") {
};

// This function includes Medusa's special ability, glare, which instantly kills the opponent
int Medusa::attack() {
	int total;

	int roll1 = 1+rand()%6;
	int roll2 = 1+rand()%6;

	total = roll1+roll2;

	if (total == 12) {

		return 20;

	} else {
		return total;
	}
}

// redefined for Medusa's damage rolls
int Medusa::defense(int damage) {
	int roll = 1+rand()%6;

	int totalDamage = damage - roll - armor;

	if (totalDamage < 0) {
		totalDamage = 0;
	}	

	takeDamage(totalDamage);

	return roll;	
}
