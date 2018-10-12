output: main.o matrix.o determinant.o
	g++  main.o matrix.o determinant.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

determinant.o: determinant.cpp determinant.h
	g++ -c determinant.cpp

clean: 
	rm *.o output
