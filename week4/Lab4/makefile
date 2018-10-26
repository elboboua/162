#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp People.cpp Student.cpp Instructor.cpp Buildings.cpp University.cpp	inputValidation.cpp 
OBJS = main.o People.o Student.o Instructor.o Buildings.o University.o inputValidation.o
HEADERS = People.hpp Student.hpp Instructor.hpp Buildings.hpp University.hpp inputValidation.hpp

output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
