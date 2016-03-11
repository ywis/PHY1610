//Scientific Computing for Physicists PHY1610 (Winter 2016)
//Siqi Liu

//hw1.cpp print out cos(2x) and sin(3x) for x ranging from -5 to 5 in double precision


#include <math.h> //use the math module for sin and cos
#include <iostream> //for printing out the input and output
#include <fstream>

double f(double x){
    return sin(2*x);
}

double g(double x){
    return cos(3*x);
}

int main()
{
    const float x_min = -5;
    const float x_max = 5;//starting and ending points
    const int n = 100;//divide into 100 segments
    
    double x[n],y[n],z[n];
    //Calculating cos(2x) and sin(3x) and store into the array
    int i;
    for (i=0;i<n;i++){
        x[i] = x_min+i*(x_max-x_min)/(n-1);
        y[i] = f(x[i]);
        z[i] = g(x[i]);
    }
    
    //Print out into the file
    std::ofstream fout("hw1.txt");
    fout << "x       y       z"<< "\n";
    
    for (i=0;i<n;i++){
        fout <<x[i] <<' '<< y[i] <<' '<< z[i] << "\n";
    }
    fout.close();
    return 0;
    
}
