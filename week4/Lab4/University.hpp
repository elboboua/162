/********************************************************************* 
** Description: The specification file for the University class
*********************************************************************/


#include "People.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

#include "Buildings.hpp"

#include <string>
#include <vector>

class University {

private:
	std::string name;
	std::vector<People*> people;
	std::vector<Buildings*> buildings;
public:
	University();
	
	// prints buildings in the system
	void printBuildings();

	// prints people in the system
	void printPeople();

	// allows you to pick a person to execute the do_work() function on
	void assignWork();

	// Looping menu function
	void menu();

	// Destructor to deallocate the dynamic vectors
	~University();
}; 
