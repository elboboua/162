/********************************************************************* 
** Description: The implementation file for the BlueMen class
*********************************************************************/ 

#include "BlueMen.hpp"

// Constructor
BlueMen::BlueMen (): Character(12, 3, "Blue Men") {
};

// special attack function
int BlueMen::attack() {

	int roll1 = 1+rand()%10;
	int roll2 = 1+rand()%10;

	return roll1+roll2;
}

// This defense function takes into account the special ability of the Blue Men
int BlueMen::defense(int damage) {

	int dice;
	int totalDamage, totalRolls=0;
	
	if (strength > 8) {
		dice = 3;
	} else if (strength == 8 || strength > 4) {
		dice = 2;
	} else {
		dice = 1;
	}

	for (int i = 0; i < dice; i++) {
		totalRolls+= 1+rand()%6;	
	}



	totalDamage = damage - totalRolls - armor;

	if (totalDamage < 0) {
		totalDamage = 0;
	}

	takeDamage(totalDamage);	

	return totalRolls;

}

