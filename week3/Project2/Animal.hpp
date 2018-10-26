/********************************************************************* 
** Description: The specification file for the animal class.
*********************************************************************/ 

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {

protected:
    int age;
    int cost;
    int numOfBabies;
    int baseFoodCost;
    int payOff;    

public: 
    Animal(int,int,int,int);


    int getAge();
    int getCost();
    int getNumOfBabies();
    int getBaseFoodCost();
    int getPayOff();

    // increases the animals age by 1 
	void growAnimal();

	void setAge(int); 

	// returns true if the age is >= 3  
	bool isAdult(); 
};

#endif // ANIMAL_H
