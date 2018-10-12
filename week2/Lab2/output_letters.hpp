/********************************************************************* 
** Description: The specification file for the output function
*********************************************************************/ 

#ifndef OUTPUT_FUNCTION_H
#define OUTPUT_FUNCTION_H

#include <fstream>
using std::ofstream;

// This function outputs the letter frequency information to a user chosen file.
void output_letters(ofstream&, int*);

#endif // OUTPUT_FUNCTION_H

