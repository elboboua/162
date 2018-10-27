#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp Character.cpp Barbarian.cpp 
OBJS = main.o Character.o Barbarian.o
HEADERS = Character.hpp Barbarian.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
