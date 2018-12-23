/********************************************************************* 
** Description: The specification file for the Game class
*********************************************************************/ 

#pragma once

#include "Issue.hpp"
#include "NoSpace.hpp"
#include "TransitionalSpace.hpp"
#include "ActionSpace.hpp"
#include "inputValidation.hpp"
#include <vector>

class Game {

private:
	Space * location;
	NoSpace * noSpace;
	// vector to hold the issues
	std::vector<Issue> issues;	
	int currentIssue;
	// required time limit
	int timeLimit;
	// Array container for issue items
	Issue * checklist;
	int checklistSize;
	
	bool quit;

	// Spaces
	TransitionalSpace * desktop;
	TransitionalSpace * browser;
	ActionSpace * canvas;
	ActionSpace * slack;
	ActionSpace * stackOverFlow;
	ActionSpace * piazza;
	ActionSpace * book;
	ActionSpace * vim;
	
public:
	Game();
	~Game();

	//display the map
	void displayMap();

	// loops the game
	void loop();

	// functions responsible for interacting with the gameboard
	void move();
	void interact();
	void viewChecklist();
	void quitGame();
	void pause();
};
