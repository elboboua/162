/********************************************************************* 
** Description: The specification file for the Space class
*********************************************************************/ 

#pragma once

#include <string>

// The required abstract space class 
class Space {

private:
	std::string name;
	Space *top;
	Space *bottom;
	Space *left;
	Space *right;

public:
	Space();
	Space(std::string);
	virtual void dialogue() = 0;

	std::string getName();
	int getSolvesNum();	

	Space * getTop();
	Space * getBottom();
	Space * getLeft();
	Space * getRight();

	void setName(std::string);
	void setTop(Space*);
	void setBottom(Space*);
	void setLeft(Space*);
	void setRight(Space*);
};
