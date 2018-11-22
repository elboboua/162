CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += Menu.cpp
SRCS += inputValidation.cpp

OBJS = main.o 
OBJS += Menu.o
OBJS += inputValidation.o

HEADERS = Menu.hpp
HEADERS = inputValidation.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
