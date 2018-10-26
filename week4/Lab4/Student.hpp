/********************************************************************* 
** Description: The specification file for the Student class
*********************************************************************/ 

#ifndef STUDENT_H
#define STUDENT_H

#include "People.hpp"

#include <string>



class Student: public People {

private:
	double gpa;


public:
	Student(double, std::string, int);

	// prints a string specific to students
	void do_work();

	// prints gpa, name, and age
	void printInfo();
	
	// necessary when the base is abstract
	virtual ~Student(){};
};



#endif // STUDENT_H

