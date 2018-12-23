/********************************************************************* 
** Description: The specification file for the Issue class
*********************************************************************/ 

#pragma once

#include <string>

// This class stores the issues the student will encounter
// and the num of the issue, so the program knows 
// in which space the issue can be solved.
class Issue {

private:
	std::string issue;
	int num;

public:
	Issue();
	Issue(std::string, int);
	
	std::string getIssue();
	int getNum();

	void setIssue(std::string);

};

