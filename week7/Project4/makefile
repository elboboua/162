#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp Character.cpp Barbarian.cpp Vampire.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp inputValidation.cpp Menu.cpp Queue.cpp
OBJS = main.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o inputValidation.o Menu.o Queue.o
HEADERS = Character.hpp Barbarian.hpp Vampire.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp inputValidation.hpp Menu.hpp Queue.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
