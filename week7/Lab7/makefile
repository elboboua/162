CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += Queue.cpp
SRCS += inputValidation.cpp

OBJS = main.o 
OBJS += Queue.o
OBJS += inputValidation.o

HEADERS = Queue.hpp
HEADERS = inputValidation.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
