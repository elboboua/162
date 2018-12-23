/********************************************************************* 
** Description: The specification file for the NoSpace class
*********************************************************************/ 

// This class is used for when the player goes out of bounds

#pragma once

#include "Space.hpp"

#include <string>

class NoSpace: public Space {

public:
	NoSpace(std::string);

	void dialogue();

};
