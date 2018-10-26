/********************************************************************* 
** Description: The implementation file for the People Class
*********************************************************************/ 

#include "People.hpp"
#include <iostream>


People::People (std::string name, int age) {
	
	this->name = name;
	this->age = age;

}

// Prints the name of the people object
void People::printName() {

	std::cout << name << std::endl;

}
