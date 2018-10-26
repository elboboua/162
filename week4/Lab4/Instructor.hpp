/********************************************************************* 
** Description: The specification file for the Instructor class
*********************************************************************/ 

#include "People.hpp"

#include <string>

class Instructor: public People {

private:
	double rating;

public:
	Instructor(double, std::string, int);

	// prints a string for instructor work
	void do_work();
	
	// prints rating, age, and name
	void printInfo();

	// Necessary because the base class is virtual
	virtual ~Instructor(){};
};
