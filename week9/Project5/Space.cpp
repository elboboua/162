/********************************************************************* 
** Description: The implementation file for the Space class
*********************************************************************/ 

#include "Space.hpp"

Space::Space() {

	name = "";
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
}

Space::Space(std::string name) {
	this->name = name;
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
}

// getters
std::string Space::getName() {
	return name;
}

Space * Space::getTop() {
	return top;
}
Space * Space::getBottom() {
	return bottom;
}
Space * Space::getLeft() {
	return left;
}
Space * Space::getRight() {
	return right;
}

// setters

void Space::setName(std::string s) {
	name = s;
}

void Space::setTop(Space* sp) {
	top = sp;
}
void Space::setBottom(Space* sp) {
	bottom = sp;
}
void Space::setLeft(Space* sp) {
	left = sp;
}

void Space::setRight(Space* sp) {
	right = sp;
}
