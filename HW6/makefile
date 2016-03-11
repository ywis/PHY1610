CXX = g++
CXXFLAGS = -std=c++11 -O2 -g  
GSL_INC = -lgsl -lgslcblas

all: main

main: main.o calculation.o readingfile.o
	${CXX} -g main.o calculation.o calculation.o -o main ${GSL_INC}

main.o: main.cpp main.hpp calculation.hpp readingfile.hpp
	${CXX} -c -${CXXFLAGS} main.cpp -o main.o

calculation.o: calculation.cpp calculation.hpp 
	${CXX} -c ${CXXFLAGS} calculation.cpp -o calculation.o

readingfile.o: readingfile.cpp readingfile.hpp
	${CXX} -c ${CXXFLAGS} readingfile.cpp -o readingfile.o

clean: 
	rm -f *.o main