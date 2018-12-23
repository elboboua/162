/********************************************************************* 
** Description: The implementation file for the Action Space class
*********************************************************************/ 

#include "ActionSpace.hpp"
#include <iostream>

// constructors
ActionSpace::ActionSpace() : Space() {
	canResolve = 0;
}

ActionSpace::ActionSpace(std::string name, int canResolve) : Space(name) {
	this->canResolve = canResolve;
}

// presents the user with a message
void ActionSpace::dialogue() {
	std::cout << "Your current location is: " << getName() << std::endl;	
}

// returns a bool
bool ActionSpace::canResolveIssue(int issue) {
	return canResolve == issue;
}

// getters and setters
void ActionSpace::setCanResolve(int canResolve) {
	this->canResolve = canResolve;
}

int ActionSpace::getCanResolve() {
	return canResolve;
}
