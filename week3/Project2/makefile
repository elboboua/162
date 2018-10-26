#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp Animal.cpp Tiger.cpp Turtle.cpp Penguin.cpp Zoo.cpp inputValidation.cpp
OBJS = main.o Animal.o Tiger.o Turtle.o Penguin.o Zoo.o inputValidation.o
HEADERS = Animal.hpp Tiger.hpp Turtle.hpp Penguin.hpp Zoo.hpp inputValidation.hpp

output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
