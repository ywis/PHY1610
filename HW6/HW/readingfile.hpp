//
//  readingfile.hpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//
//

#ifndef readingfile_hpp
#define readingfile_hpp

#include <stdio.h>
#include <rarray>
#include <rarrayio>
#include <fstream>
#include <complex>
struct file_detection{
    rarray<double,1> times;
    rarray<std::complex<double>,1> signal;
};

struct file_detection readingfile(std::string fname);

#endif /* readingfile_hpp */
