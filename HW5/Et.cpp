//
//  function.cpp
//  
//
//  Created by Siqi Liu on 2016-02-25.
//
//

#include "Et.hpp"
struct Params{
    int a,c,f;
    double b,d,g,m;
};

double Es (double x, void* params)
{
    struct Params* p=(Params*) params;
    
    int a=p->a;
    double b=p->b;
    int c=p->c;
    double d=p->d;
    int f=p->f;
    
    return a*(b/x + pow(d,2.0)/f/(pow((x-d),2.0)) -exp(-c*pow((x-b),2)/(2.0*a)));
}

double Ew (double x, void* params)
{
    struct Params* p = (Params*) params;
    double g=p->g;
    double m=p->m;
    return -m*g*x;
}

double Et (double x, void* params){
    struct Params* p = (Params*) params;
    return Es(x,params)+ Ew(x,params);
}
