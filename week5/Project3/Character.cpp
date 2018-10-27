/********************************************************************* 
** Description: The implementation file for the Character base Class
*********************************************************************/ 

#include "Character.hpp"

// Constructor
Character::Character(int strength, int armor) {

	this->strength = strength;
	this->armor = armor;

}


// getters and setter
int Character::getStrength() {
	return this->strength;
}

int Character::getArmor() {
	return this->armor;
}

void Character::setStrength(int strength) {
	this->strength = strength;
}

// gets the rolls for the attack and defense
int Character::attack() {
	int roll1,roll2;

	roll1 = 1+rand()%6;
	roll2 = 1+rand()%6;

	return roll1+roll2;

}


int Character::defense() {
	int roll1,roll2;

	roll1 = 1+rand()%6;
	roll2 = 1+rand()%6;

	return roll1+roll2;
}



// The function used to assign damage to the character
void Character::takeDamage(int damage) {
	this->strength-= damage;
}
