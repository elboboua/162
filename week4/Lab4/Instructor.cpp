/********************************************************************* 
** Description: The implementation file for the Instructor class
*********************************************************************/ 

#include "Instructor.hpp"

#include <iostream>


Instructor::Instructor(double rating, std::string name, int age): People(name, age) {

	this->rating = rating;

}

// Prints a string for instructor work
void Instructor::do_work() {

	int hours = 1+rand()%8;

	std::cout << this->name << " graded papers for " << hours << " hours." << std::endl;
	
}

// prints name, rating, and age of the instructor
void Instructor::printInfo() {

	std::cout << "Instructor name: " << this->name << std::endl;
	std::cout << "Instructor rating: " << this->rating << std::endl;
	std::cout << "Instructor age: " << this->age << std::endl;


}
