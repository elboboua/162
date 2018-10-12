/********************************************************************* 
** Description: The implementation file for the output function
*********************************************************************/

#include "output_letters.hpp"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// This function outputs the letter frequency information to a user chosen file.
void output_letters(ofstream& ofs, int* frequency) {
    string outputFile;

    // Requesets file information from user
    cout << "Please enter the name of the file you'd like to send the letter frequency information:" << endl;
    cin >> outputFile;    
    // Opens the file with the user specified name
    ofs.open(outputFile.c_str());

    // Checks if the file opens
    if (!ofs) {
        cout << "There was an error in opening the file." << endl;
    }

    // Outputting frequency data onto file
    ofs << "In this Paragraph, the frequency of the letters are as follows:" << endl;

    for (int i = 0; i < 26; i++) {
    ofs << char(i+97) << ": " << frequency[i] << endl;

    }
    
    

}

 
