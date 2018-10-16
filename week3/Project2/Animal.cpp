/********************************************************************* 
** Description: The implementation file for the Animal Class
*********************************************************************/ 


#include "Animal.hpp"


Animal::Animal ( int cost, int numOfBabies, int baseFoodCost, int payOff) {
	// age is set to one when animal is born
    this->age = 1;
    this->cost = cost;
    this->numOfBabies = numOfBabies;
    this->baseFoodCost = baseFoodCost;
    this->payOff = payOff;

}


int Animal::getAge() {

    return age;

}

int Animal::getCost() {

    return cost;

}

int Animal::getNumOfBabies() {

    return numOfBabies;

}

int Animal::getBaseFoodCost() {

    return baseFoodCost;

}

int Animal::getPayOff() {

    return payOff;

}

void Animal::growAnimal() {

    this->age++;

}

void Animal::createBaby() {

	age = 0;

}




bool Animal::isAdult() {

	if (age >= 3) {
		return true;
	} else {
		return false;
	}

}
