/*********************************************************************
** Author: Ahmad El-Bobou
** Date: 10-27-2018
** Description: Project 3 - Fantasy Combat game
*********************************************************************/

#include "Barbarian.hpp"
#include <cstdlib>
#include <ctime>

#include <iostream>

int main() {


	srand(time(NULL));

	Barbarian player1;

	std::cout << "BB strength =" << player1.getStrength() << std::endl;
	std::cout << "BB armor =" << player1.getArmor() << std::endl;
	std::cout << "BB attack =" << player1.attack() << std::endl;
	std::cout << "BB defense =" << player1.defense() << std::endl;
	

	std::cout << "BB set strength as 50:" <<  std::endl; 
	player1.setStrength(50);
	std::cout << "BB strength =" << player1.getStrength() << std::endl;

	
	std::cout << "BB inflicted damage of 40"  << std::endl;
	player1.takeDamage(40);
	std::cout << "BB strength =" << player1.getStrength() << std::endl;



	return 0;
}
