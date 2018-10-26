# creates the executable
output: main.o ant.o ant.hpp menu.o menu.hpp inputValidation.o inputValidation.hpp
	g++  main.o ant.o menu.o inputValidation.o -o output


# creates the object files
main.o: main.cpp
	g++ -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -std=c++11 -c inputValidation.cpp


# cleans the folder of object files and the executable
clean:
	rm *.o output
