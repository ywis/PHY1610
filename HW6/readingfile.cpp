//
//  readingfile.cpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//


#include "readingfile.hpp"

readingfile(std::string fname){
    // open the file
    std::ifstream f(fname);
    f >> detect.times;
    f >> detect.signal;
    return detect;
}