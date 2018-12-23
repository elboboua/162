CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += FibonacciFunctions.cpp
SRCS += inputValidation.cpp

OBJS = main.o 
OBJS += FibonacciFunctions.o
OBJS += inputValidation.o

HEADERS = FibonacciFunctions.hpp
HEADERS = inputValidation.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
