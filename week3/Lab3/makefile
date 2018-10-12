output: main.o Die.o Die.hpp LoadedDie.o LoadedDie.hpp Game.o Game.hpp
	g++ main.o Die.o LoadedDie.o Game.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++11 -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++11 -c LoadedDie.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp
