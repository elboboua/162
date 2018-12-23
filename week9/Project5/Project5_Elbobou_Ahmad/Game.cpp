/********************************************************************* 
** Description: The implementation file for the Game class
*********************************************************************/ 


#include "Game.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>

Game::Game() {


	timeLimit = 60;
	checklist = new Issue[11];
	checklistSize = 0;
	quit = false;
	
	currentIssue = 0;	
	// issues resolved by:
	// Canvas
	issues.push_back(Issue("You don't quite understand the project requirements.", 1));
	issues.push_back(Issue("You're worried what your grade will be if you bomb this assignment. You desparately need to check your grades before you continue", 1));
	// Stack overflow
	issues.push_back(Issue("The project requires you to use a structure not in the reading", 2));
	issues.push_back(Issue("You've encountered a problem that a quick search could fix", 2));
	// Slack
	issues.push_back(Issue("You want to brainstorm with other students about your project design", 3));
	issues.push_back(Issue("You need to talk to a smart student... NOW", 3));
	// Piazza
	issues.push_back(Issue("You encounter an issue that seems like it would come up for other students.", 4));
	issues.push_back(Issue("You want to see what your instructors have said about a project outside of canvas", 4));
	// CS book
	issues.push_back(Issue("Your memory of the concepts from the reading is foggy.", 5));
	issues.push_back(Issue("You need a simple reminder of what a basic data structure does.", 5));
	// VIM
	issues.push_back(Issue("You have an idea of what you want to code.", 6));

	// shuffle the vector
	std::random_shuffle(issues.begin(), issues.end());

	// randomize the output
	srand(time(NULL));

	// Spaces are hardcoded
	// transitional spaces first
	desktop= new TransitionalSpace("Desktop");
	browser= new TransitionalSpace("Browser");
	// canvas = 1, SOF = 2, Slack = 3, Piazza = 4, CS book = 5, VIM = 6
	canvas = new ActionSpace("Canvas", 1);
	stackOverFlow = new ActionSpace("Stack Overflow", 2);
	slack = new ActionSpace("Slack", 3);
	piazza = new ActionSpace("Piazza", 4);
	book = new ActionSpace("Computer Science Book", 5);
	vim = new ActionSpace("VIM", 6);	

	// out of bounds class
	noSpace = new NoSpace("OOB");
	// linking the spaces
	book->setTop(noSpace);	
	book->setBottom(noSpace);	
	book->setRight(noSpace);	
	book->setLeft(desktop);	

	desktop->setTop(slack);	
	desktop->setBottom(vim);	
	desktop->setRight(book);	
	desktop->setLeft(browser);	

	browser->setTop(piazza);	
	browser->setBottom(canvas);	
	browser->setRight(desktop);	
	browser->setLeft(stackOverFlow);	

	stackOverFlow->setTop(noSpace);	
	stackOverFlow->setBottom(noSpace);	
	stackOverFlow->setRight(browser);	
	stackOverFlow->setLeft(noSpace);	

	piazza->setTop(noSpace);
	piazza->setBottom(browser);	
	piazza->setRight(noSpace);	
	piazza->setLeft(noSpace);	

	canvas->setTop(browser);	
	canvas->setBottom(noSpace);	
	canvas->setRight(noSpace);	
	canvas->setLeft(noSpace);	

	slack->setTop(noSpace);	
	slack->setBottom(desktop);	
	slack->setRight(noSpace);	
	slack->setLeft(noSpace);	

	vim->setTop(desktop);	
	vim->setBottom(noSpace);	
	vim->setRight(noSpace);	
	vim->setLeft(noSpace);	


	// initial location = desktop
	location = desktop;

}

// destructor
Game::~Game() {

	// deallocate all the memory allocated with new
	delete [] checklist;
	checklist = nullptr;

	delete desktop;
	desktop = nullptr;

	delete browser;
	browser = nullptr;

	delete vim;
	vim = nullptr;

	delete book;
	book = nullptr;

	delete slack;
	slack = nullptr;

	delete stackOverFlow;
	stackOverFlow = nullptr;

	delete piazza;
	piazza = nullptr;

	delete canvas;
	canvas = nullptr;

	delete noSpace;
	noSpace = nullptr;

	location = nullptr;

}

// shows the map layout
void Game::displayMap() {

	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "  Piazza" << std::setw(5) << "" << std::setw(10) << "Slack" << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;
	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;
	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;
	std::cout << std::setw(10) << "Stack OF " << std::setw(5) << "-----" << std::setw(10) << "Browser " << std::setw(5) << "-----" << std::setw(10) << "Desktop " << std::setw(5) <<  "-----" << std::setw(10) << "CS book" << std::endl;

	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;
	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) << "" << std::setw(10) << "|   " << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;

	std::cout << std::setw(10) << "" << std::setw(5) << "" << std::setw(10) << "Canvas" << std::setw(5) << "" << std::setw(10) << "VIM  " << std::setw(5) <<  "" << std::setw(10) << "" << std::endl;
}

// loop for the game
void Game::loop() {


	std::cout << "OH NO! You were so busy with CS 261 that you just realized that you have 60 minutes to turn in your final project for CS 162." << std::endl;
	std::cout << "You get started, but you realize that there are a ton of issues you need to solve before turning it in." << std::endl;
	std::cout << "The map represents the different spaces where issues can be solved. All spaces on the board are unlocked" << std::endl;
	std::cout << "but you can only travel on the dashes. If you go out off the board, you waste some of your time to work on the project." << std::endl;

	std::cout << std::endl;
	displayMap();
	std::cout << std::endl;

	std::cout << "Each issue must be solved in a certain space. You must move to the space and interact with it to solve the issue." << std::endl;
	std::cout << "Each time you interact with a space, you spend some of your time." << std::endl;
	std::cout << "When you solve all 11 issues, you submit your project before the deadline" << std::endl;
	std::cout << "If you run out of time, you don't get a chance to submit." << std::endl;
	pause();


	while (!quit && checklistSize != 11 && timeLimit > 0)  {
		
		std::cout << "==============================================================================" << std::endl;

		// display current location and time left
		std::cout << "Your current location: " << location->getName() << std::endl;
		std::cout << "TIME LEFT: " << timeLimit << std::endl;
		std::cout << "Your current issue to resolve: " << issues[currentIssue].getIssue() << std::endl;

		//switch statement for different choices
		std::cout << std::endl;
		displayMap();
		std::cout << std::endl;

		int input;
		std::cout << "Please choose your action: " << std::endl;
		std::cout << "1. move" << std::endl;
		std::cout << "2. interact with space" << std::endl;
		std::cout << "3. view checklist" << std::endl;
		std::cout << "4. quit" << std::endl;
		input = isIntBetweenXAndY(1,4);

		switch (input) {

			case 1:
				move();
				break;
		
			case 2:
				interact();
				pause();
				break;

			case 3:
				viewChecklist();
				pause();
				break;

			case 4:
				quitGame();
				break;


		}



		std::cout << "==============================================================================" << std::endl;
		std::cout << "\n" << std::endl;
	}

	// if else statement for quit or win

	if (quit == true) {
		std::cout << "Thanks for playing!" << std::endl;
	} else if (timeLimit <= 0) {
		std::cout << "You ran out of time :(. Looks like you won't be submitting this assignment." << std::endl;
	} else {
		std::cout << "Good job winning!!! You finished with " << timeLimit << " minutes to spare!" << std::endl;
		std::cout << "Hope you read the requirements and checked for memory leaks!" << std::endl;
	}

}

// responsible for moving from space to space
void Game::move() {

	std::cout << "Enter a number to move to a different location" << std::endl; 
	std::cout << "1. Up" << std::endl; 
	std::cout << "2. Down" << std::endl; 
	std::cout << "3. Left" << std::endl; 
	std::cout << "4. Right" << std::endl; 
	int input = isIntBetweenXAndY(1,4);

	switch (input) {

		case 1:
			location = location->getTop();
			break;
		case 2:
			location = location->getBottom();
			break;
		case 3:
			location = location->getLeft();
			break;
		case 4:
			location = location->getRight();
			break;
	}	

	if (location->getName() == "OOB") {
		location->dialogue();
		timeLimit -=10;
		// change location to desktop
		location = desktop;
	}
}

// prints the completed tasks to the user
void Game::viewChecklist() {

	if (checklistSize == 0) {
		std::cout << "It looks like you haven't completed any tasks. GET TO WORK!" << std::endl;
	} else {
		std::cout << "You have checked off the following issues:" << std::endl;
		for(int i = 0; i < checklistSize; i++ ) {
			std::cout << checklist[i].getIssue() << std::endl;
		}
	}

}

// quits the game
void Game::quitGame() {
	quit = true;
}

// allows the user the option to interact with a space
void Game::interact() {
	
	int timeSpent;

	// if transitinal space
	if (location->getName() == "Desktop" || location->getName() == "Browser") {
		
		timeSpent = 1+ rand()%10;

		std::cout << "You wasted " << timeSpent << " minutes here. Try interacting somewhere else." << std::endl; 

		timeLimit -= timeSpent;
	} else {

		// time spent to remove
		timeSpent = 1+rand()%5;
		timeLimit -= timeSpent;

		// if else statement to see if the issue can be resolved in the ActionSpace
		if (static_cast<ActionSpace *>(location)->getCanResolve() == issues[currentIssue].getNum()) {
			
			std::cout << "You've resolved the issue! You spent " << timeSpent << " minutes here." << std::endl;
			checklist[currentIssue].setIssue(issues[currentIssue].getIssue());
			checklistSize++;
			currentIssue++;
			
		} else {

			std::cout << "Looks like your problem cannot be resolved here. You wasted " << timeSpent << " minutes trying to find the answer." << std::endl; 

		}	

	}

}

void Game::pause() {
	std::cout << "Press ENTER to continue.";
	std::cin.ignore();
	getchar();

}
