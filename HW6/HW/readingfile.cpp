//
//  readingfile.cpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//


#include "readingfile.hpp"

struct file_detection readingfile(std::string fname){
    // open the file
    std::ifstream f(fname);
    // read in the signal
    struct file_detection detect;
    f >> detect.times;
    f >> detect.signal;
    f.close();
    
    return detect;
}
