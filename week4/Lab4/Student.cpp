/********************************************************************* 
** Description: The implementation file for the Student class
*********************************************************************/ 

#include "Student.hpp"
#include <iostream>

Student::Student(double gpa, std::string name, int age): People(name,age) {

	this->gpa = gpa;

}

// prints a string specific to students
void Student::do_work() {

	int hours = 2+rand()%15;
	
	std::cout << this->name << " did " << hours << " hours of homework." << std::endl;


}

// prints gpa, name, age
void Student::printInfo() {

	std::cout << "Student name: " << this->name << std::endl;
	std::cout << "Student GPA: " << this->gpa << std::endl;
	std::cout << "Student Age: " << this->age << std::endl;

}

