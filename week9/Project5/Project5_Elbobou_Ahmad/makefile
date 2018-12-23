CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += Game.cpp
SRCS += inputValidation.cpp
SRCS += Issue.cpp
SRCS += Space.cpp
SRCS += NoSpace.cpp
SRCS += TransitionalSpace.cpp
SRCS += ActionSpace.cpp


OBJS = main.o 
OBJS += Game.o
OBJS += inputValidation.o
OBJS += Issue.o
OBJS += Space.o
OBJS += NoSpace.o
OBJS += TransitionalSpace.o
OBJS += ActionSpace.o

HEADERS = Game.hpp
HEADERS += inputValidation.hpp
HEADERS += Issue.hpp
HEADERS += Space.hpp
HEADERS += NoSpace.hpp
HEADERS += TransitionalSpace.hpp
HEADERS += ActionSpace.hpp

output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
