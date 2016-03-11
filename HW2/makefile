# Makefile
CXX = g++
CXXFLAGS = -std=c++11 -O2 -pg -g  

all: hw3 boost_test

hw3: hw3.o initialize.o output.o singlestep.o ticktock.o
	${CXX} -pg -o hw3 hw3.o initialize.o output.o singlestep.o ticktock.o

boost_test: boost_test.o singlestep.o
	${CXX} -o boost_test boost_test.o singlestep.o

hw3.o: hw3.cpp hw3.hpp ticktock.h initialize.hpp output.hpp singlestep.hpp
	${CXX} ${CXXFLAGS} -c -o hw3.o hw3.cpp
 
initialize.o: initialize.cpp initialize.hpp
	${CXX} ${CXXFLAGS} -c -o initialize.o initialize.cpp

output.o: output.cpp output.hpp
	${CXX} ${CXXFLAGS} -c -o output.o output.cpp

singlestep.o: singlestep.cpp singlestep.hpp
	${CXX} ${CXXFLAGS} -c -o singlestep.o singlestep.cpp

ticktock.o: ticktock.cc ticktock.h
	${CXX} ${CXXFLAGS} -c -o ticktock.o ticktock.cc

boost_test.o: boost_test.cpp boost_test.hpp
	${CXX} -c -o boost_test.o boost_test.cpp

gprof_modu: 
	gprof hw3 gmon.out > modulized_gprof.txt

gprof_original:
	gprof ants gmon.out > original_gprof.txt

clean: 
	rm -f *.o hw3 boost_test
