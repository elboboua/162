# The make file for the war dice game


# create output
output: main.o Die.o Die.hpp LoadedDie.o LoadedDie.hpp Game.o Game.hpp inputValidation.o inputValidation.hpp
	g++ main.o Die.o LoadedDie.o Game.o inputValidation.o -o output


# create object files
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++11 -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++11 -c LoadedDie.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -std=c++11 -c inputValidation.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

# clean
clean:
	rm *.o output
