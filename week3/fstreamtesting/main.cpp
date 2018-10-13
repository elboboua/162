#include <fstream>
#include <iostream>
#include <string>

int main () {

    std::ofstream ofs("test.txt", std::ios::out | std::ios::app);
    
    if (!ofs) 
        std::cout << "There has been an error" << std:: endl;

    ofs << "This is a string. Put it in the file.\n";

    std::ifstream ifs("input.txt", std::ios::in);

    std::string input;  
    getline(ifs, input);  

    std::cout << input;
    
    return 0;
}
