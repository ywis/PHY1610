//
//  main.cpp
//  
//
//  Created by Siqi Liu on 2016-03-08.
//
//

//#include "main.hpp"
#include <fstream>
#include <complex>
#include <iostream>
#include <rarray>
#include <rarrayio>
#include <fftw3.h>
#include <vector>

struct file_detection(){
    rarray<double,1> times;
    rarray<std::complex<double>,1> signal;
}

int main() {
    int Num_of_detections 32;
    
    // Read the prediction signal and times
    file_detection prediction = readingfile("data/GWprediction.rat");
    signal = prediction.signal;
    times  = prediction.times;

    str::string dir = 'data/';
    // Do the Fourier transform of the signal calculating the power spectrum of the prediction
    rarray <std::complex<double>,1> signal_hat = fft_fast(signal01);
    rarray <double,1> ps = power_spectrum(rarray <std::complex<double>,1> signal_hat01);

    // Read the prediction file sequently
    //for (i=01; i <= Num_of_detections; i++) {
        // read one of the GW signal from observations
    int i=1;
    fname = "detection"+"01"+".rat";
    file_detection detection01 = readingfile("data/detection01.rat");
    signal01 ＝ detection01.signal;
    times01 = detection01.times;
        
        rarray <std::complex<double>,1> signal_hat01 = fft_fast(signal01);

        rarray <double,1> ps01 = power_spectrum(rarray <std::complex<double>,1> signal_hat01);

        double co_ef_01=correlation_coefficient(ps01, ps);
        
        vector <double> co_ef(Num_of_detections);
        co_ef[0] = co_ef;
    
    std::sort(co_ef.begin(), co_ef.end());
    std::cout<<co_ef[0]<<co_ef[-1]<<std::endl;
    
    //}

    return 0;

}