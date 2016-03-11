#Loading modules: rarray/1.1, fftw/3.3.0-gcc-openmpi, openblas/0.2.13-gcc-threaded
CXX = g++
CXXFLAGS = -std=c++11 -O2 -g 
GSL_INC = -lgsl -lgslcblas
BLAS_INC = -I${SCINET_OPENBLAS_INC}
BLAS_LIB = -L${SCINET_OPENBLAS_LIB} -lopenblas 
FFTW_INC = -lfftw3 -lm

all: main

main: main.o calculation.o readingfile.o
	${CXX} -g main.o calculation.o readingfile.o -o main ${BLAS_LIB} ${FFTW_INC}

main.o: main.cpp 
	${CXX} -c -${CXXFLAGS} main.cpp -o main.o ${BLAS_INC} ${FFTW_INC}

calculation.o: calculation.cpp  
	${CXX} -c ${CXXFLAGS} calculation.cpp -o calculation.o ${BLAS_INC} ${FFTW_INC}

readingfile.o: readingfile.cpp 
	${CXX} -c ${CXXFLAGS} readingfile.cpp -o readingfile.o

clean: 
	rm  *.o main
