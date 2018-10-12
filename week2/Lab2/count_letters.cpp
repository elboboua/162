/********************************************************************* 
** Description: The implementation file for the count function
*********************************************************************/ 
#include "count_letters.hpp"
#include <string>
using std::string;


// This function counts the letters in a paragraph and fills a frequency array with the information for each letter.
void count_letters(ifstream& ifs, int* frequency) {

    // variable to take input
    string input;
    getline(ifs, input);

    // testing letter frequency in input 
    for (int i = 0; i < input.length(); i++) {

        for (int j = 0; j < 26; j++) {

            // uses the j variable to identify ascii upper and lower. 
            if (input[i] == (j+65) || input[i] == (j+97)) {
                frequency[j]++;
            }
        }
    }        
}
