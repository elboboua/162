#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp recursiveFunctions.cpp inputValidation.cpp
OBJS = main.o recursiveFunctions.o inputValidation.o
HEADERS = recursiveFunctions.hpp inputValidation.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
