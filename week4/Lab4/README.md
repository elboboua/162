Lab 4 - OSU Information System



#Classes#

*University:
	Attributes:
		(has)
		A pointer to a building object vector
		A pointer to a people object vector 

		nameOfUni
		
	Methods:
		printBuildings() - prints the information of on all buildings
		printPeople() - prints the information of all the people.

		assignWork(int number) - assigns a person work

		menu() - asks the user what they want to do from above

	

Buildings
	Attributes:
		string - name of the building
		double - size in sqft
		string - address of the building

	Methods:
		Constructor
		displayInfo		

People
	Attributes:
		name
		age

	Methods:
		do_work() - generates a random number for how many hours they will work then		outputs message whether the person is a student or an instructor (set range)



Student class: people
	Attributes:
		GPA - 0.0 - 4.0

	Methods:
		do_work() "name did X hours of homework"


Instructor class: people
	Attributes:
		rating 0.0-5.0

	Method:
		do_work() "Name graded papers for x hours"

#How it will work#

	As of right now it seems that the menu functions will be housed in the University object.






#To Do 
1. create second building
2. Deallocated pointers
