/********************************************************************* 
** Description: The specification file for the Transitional Space class
*********************************************************************/ 

// This class is for the desktop and browser objects. Nothing happens in these spaces, they are just spaces to go to other spaces

#pragma once

#include <string>

#include "Space.hpp"

class TransitionalSpace: public Space {

public:
	TransitionalSpace();
	TransitionalSpace(std::string);
	void dialogue();


};
