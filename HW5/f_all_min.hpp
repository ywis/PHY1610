//
//  f_all_min.hpp
//  
//
//  Created by Siqi Liu on 2016-02-23.
//
//

#ifndef f_all_min_hpp
#define f_all_min_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>  
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_min.h>
#include <gsl/gsl_multimin.h>
#include <iomanip>
#include <locale>
#include "Et.hpp"

extern double f_all_min(double a, double b, double min_val, double min_val_expected, double m_val);

#endif /* f_all_min_hpp */
