/********************************************************************* 
** Description: The implementation file for the Issue class
*********************************************************************/ 

#include "Issue.hpp"

Issue::Issue() {
	issue = "";
	num = 0;
}

Issue::Issue(std::string issue, int num) {

	this->issue = issue;
	this->num = num;	

}

std::string Issue::getIssue() {
	return issue;
}

int Issue::getNum() {
	return num;
}

void Issue::setIssue(std::string issue) {
	this->issue = issue;
}
