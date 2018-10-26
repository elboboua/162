/********************************************************************* 
** Description: The specification file for the Buildings class
*********************************************************************/ 


#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <string>


class Buildings {

private:
	std::string name;
	double size;
	std::string address;
	
public:
	Buildings(std::string, double, std::string);
	void printInfo();

};


#endif // BUILDINGGS_H
