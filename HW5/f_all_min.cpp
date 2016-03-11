//
//  f_all_min.cpp
//  
//
//  Created by Siqi Liu on 2016-02-23.

#include "f_all_min.hpp"
struct Params{
    int a,c,f;
    double b,d,g,m;
};

double f_all_min(double x_lo, double x_hi, double min_val, double min_val_expected, double m_val){
    
    struct Params par={1,100,2500,0.1,0.5,9.8,0.1};
    par.m = m_val;// change the value of m according to the input;
    
    int status;
    int iter=0, max_iter=100;
    double precision = 1e-5;
    double result_value; //return value of x(local minima)
    const gsl_min_fminimizer_type *T;
    gsl_min_fminimizer *s;
    gsl_function F;
    F.function = &Et;
    F.params = &par;
    T = gsl_min_fminimizer_brent;
    s = gsl_min_fminimizer_alloc (T);
    gsl_min_fminimizer_set (s,&F,min_val,x_lo,x_hi);
    //printf ("using %s method\n", gsl_min_fminimizer_name (s));
    //printf ("%5s [%9s, %9s] %9s %10s %9s\n","iter", "lower", "upper", "min", "err", "err(est)");
    //printf ("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",iter, x_lo, x_hi, min_val, min_val - min_val_expected, x_hi - x_lo);
    
    do{
        iter++;
        status = gsl_min_fminimizer_iterate (s);
        min_val = gsl_min_fminimizer_minimum (s);
        x_lo = gsl_min_fminimizer_x_lower (s);
        x_hi = gsl_min_fminimizer_x_upper (s);
        status = gsl_min_test_interval (x_lo, x_hi, precision, 0.0);
        result_value = x_hi; //return the higher limit of the region, if the higher limit is 0.25,which means we did not find the first local minima, it will be recognized.
        
        //  printf ("%5d [%.7f, %.7f] " "%.7f %+.7f %.7f\n", iter, x_lo, x_hi, min_val, min_val - min_val_expected, x_hi - x_lo);
    }while (status == GSL_CONTINUE && iter < max_iter);
    
    gsl_set_error_handler_off();
    gsl_min_fminimizer_free(s);
    return result_value;
}
