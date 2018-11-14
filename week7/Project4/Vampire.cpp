/********************************************************************* 
** Description: The implementation file for the Vampire class
*********************************************************************/

#include "Vampire.hpp"

Vampire::Vampire(): Character(18, 1, "Vampire") {
}


// redefines the attack for the vamp character
int Vampire::attack() {
	
	int roll = 1+rand()%12;

	return roll;

} 

// This function incorporates the vamp's special ability - charm
int Vampire::defense(int damage) {

	int chance= rand()%2;

	if (chance == 0) {
		std::cout << "(The vampire's charm has caused him to not be attacked) ";
		lastHit = 0;
		return 0;	
	} else {
		int roll = 1+rand()%6;
		int totalDamage = damage - roll - armor;
		
		if (totalDamage < 0) {
			totalDamage = 0;
		}

		takeDamage(totalDamage);

		return roll;	
	}
}
