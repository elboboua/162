/********************************************************************* 
** Description: The specification file for the Action Space class       
*********************************************************************/ 

// this class is for spaces in which issues can be resolved

#pragma once
#include <string>
#include "Space.hpp"

class ActionSpace: public Space {

private:
	int canResolve;

public:
	ActionSpace();
	ActionSpace(std::string, int);
	void dialogue();

	// returns true if this space can solve the current issue
	bool canResolveIssue(int);

	void setCanResolve(int);
	int getCanResolve();

};
