/********************************************************************* 
** Description: The specification file for the People Class
*********************************************************************/

#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class People {

protected:
	std::string name;
	int age;

public:
	People(std::string, int);
	
	// Prints a string when called with a random number for hours
	virtual void do_work() = 0;

	// an abstract function that prints data from derived classes
	virtual void printInfo() = 0;

	// prints the name when cout
	void printName();

	// Virtual destructor necessary when using an abstract class
	virtual ~People(){};
};

#endif // PEOPLE_H
 
