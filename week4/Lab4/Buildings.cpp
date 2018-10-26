/********************************************************************* 
** Description: The implementation file for the Buildings class
*********************************************************************/


#include "Buildings.hpp"
#include <iostream>

// Constructor for the building class
Buildings::Buildings (std::string name, double size, std::string address) {

	this->name = name;
	this->size = size;
	this->address = address;

}



// functions that displays all the info for a given building object
void Buildings::printInfo() {

	std::cout << "Building Name: " << name << std::endl;	
	std::cout << "Building size in sqft: " << size << std::endl;	
	std::cout << "Building address : " << address << std::endl;	

}

