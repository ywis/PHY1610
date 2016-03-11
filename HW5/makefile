CXX = g++
CXXFLAGS = -std=c++11 -O2 -g  
GSL_INC = -lgsl -lgslcblas

all: main

main: main.o f_all_min.o Et.o
	${CXX} -g main.o f_all_min.o Et.o -o main ${GSL_INC}

main.o: main.cpp main.hpp f_all_min.hpp Et.hpp
	${CXX} -c -${CXXFLAGS} main.cpp -o main.o

f_all_min.o: f_all_min.cpp f_all_min.hpp Et.hpp
	${CXX} -c ${CXXFLAGS} f_all_min.cpp -o f_all_min.o

Et.o: Et.cpp Et.hpp
	${CXX} -c ${CXXFLAGS} Et.cpp -o Et.o

clean: 
	rm -f *.o main
	
