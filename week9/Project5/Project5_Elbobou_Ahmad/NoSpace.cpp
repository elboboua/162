/********************************************************************* 
** Description: The implementation file for the NoSpace class
*********************************************************************/ 

#include "NoSpace.hpp"
#include <iostream>

NoSpace::NoSpace(std::string name): Space(name) {
}

void NoSpace::dialogue() {

	std::cout << "You have gone out of bounds. You've wasted 10 minutes playing around." << std::endl;	

}
