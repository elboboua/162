/********************************************************************* 
** Description: The implementation file for the Transitional Space class
*********************************************************************/ 

#include "TransitionalSpace.hpp"

#include <iostream>


TransitionalSpace::TransitionalSpace(): Space() {
};

TransitionalSpace::TransitionalSpace(std::string name): Space(name) {
};

void TransitionalSpace::dialogue() {
	std::cout << "Your current location is: " << getName() << std::endl;	
}
