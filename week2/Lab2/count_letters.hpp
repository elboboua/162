/********************************************************************* 
** Description: The specification file for the count function
*********************************************************************/ 

#ifndef COUNT_FUNCTION_H
#define COUNT_FUNCTION_H


#include <fstream>
using std::ifstream;

// This function counts the letters in a paragraph and fills a frequency array with the information for each letter.
void count_letters(ifstream&, int*);


#endif // COUNT_FUNCTION_H
