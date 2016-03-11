//
//  main.cpp
//  
//
//  Created by Siqi Liu on 2016-02-25.

#include "main.hpp"
struct Params{
    int a,c,f;
    double b,d,g,m;
};


int indexofSmallestElement(double array[], int size)
{
    int index =0;
    double array_abs[size];
    array_abs[0] = fabs(array[0]);    
    for(int i = 1; i < size; i++)
    {   array_abs[i] = fabs(array[i]);
        //std::cout << array_abs[i]<<"\n";
        if(array_abs[i] < array_abs[index]){
            index = i;}
    }
    return index;
}


int main(){
    // mass extension- Part 2
    // The two regions are divided by plotting them in mathematica.
    
    //the upper and lower limit for the first local minima
    double min_val_1 = 0.15, min_val_expected_1=0.18;
    double a_1 = 0.14, b_1 = 0.25;
    
    //the upper and lower limit for the second local minima
    double min_val_2 = 0.405, min_val_expected_2=0.45;
    double a_2 = 0.3, b_2 = 0.48;
    double global_min;
    struct Params par={1,100,2500,0.1,0.5,9.8,0.1};
 
    //===========Second Part of the Assignment=====================
    //write to a file
    std::ofstream myfile;
    myfile.open ("Output_HW5_2.txt");
    myfile<<"m    ,Et \n";
    
    for (int m_0=1; m_0<=25; m_0++) {
        double m = (double)m_0/50.0;
        par.m = m;
        double min_val1 = f_all_min(a_1,b_1,min_val_1,min_val_expected_1,m);
        double Et1 = Et(min_val1,&par);
        double min_val2 = f_all_min(a_2,b_2,min_val_2,min_val_expected_2,m);
        double Et2 = Et(min_val2,&par);
        if (min_val1 == 0.25) {
            global_min = Et2;
        }
        else{
            global_min = fmin(Et1,Et2);}
        myfile<<std::setw(4) <<m<<" "<<std::setw(8) <<global_min<<"\n";
    }
    myfile.close();
    
    
    // =============The third part of the assignment=================
    //Have a previous estimation that the m lies within 0.1-0.2
    int n =100; // number of trials
    double difference[n];
    for (int m_0=0; m_0<=n; m_0++) {
        double m = (double)m_0/1000.0+0.1;
        par.m = m;
        double min_val1 = f_all_min(a_1,b_1,min_val_1,min_val_expected_1,m);
        double Et1 = Et(min_val1,&par);
        double min_val2 = f_all_min(a_2,b_2,min_val_2,min_val_expected_2,m);
        double Et2 = Et(min_val2,&par);
        difference[m_0-1] = Et1- Et2;
    }
    //Printing the smallest element
    //for (int i = n - 1; i >= 0; i--)
    //    std::cout <<i+1 << " " << difference[i]<<"\n";
    int m_index = indexofSmallestElement(difference,n);
    double m_max_load = (double)m_index/1000.0+0.1;
    std::cout << m_max_load <<"\n";

    return 0;
}
