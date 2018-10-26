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


// increases the animals age by 1
void Animal::growAnimal() {

    this->age++;

}

void Animal::setAge(int age) {

	this->age = age;

}



// returns true if the age is >= 3 and false otherwise
bool Animal::isAdult() {

	if (age >= 3) {
		return true;
	} else {
		return false;
	}

}
