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

    // This is the only set variable needed.
    void growAnimal();
	void createBaby();   
	bool isAdult(); 
};

#endif // ANIMAL_H
