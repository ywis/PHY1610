//  main.cpp
//  Created by Siqi Liu on 2016-03-08.

//#include "main.hpp"
#include <fstream>
#include <complex>
#include <iostream>
#include <rarray>
#include <rarrayio>
#include "fftw3.h"
#include "cblas.h"
#include <vector>
#include "readingfile.hpp"
#include "calculation.hpp"
#include <algorithm>
#include <utility>
int main() {
    int Num_of_detections=32;
    
    // Read the prediction signal and times
    struct file_detection prediction = readingfile("data/GWprediction.rat");
    rarray<double,1> times;
    rarray<std::complex<double>,1> signal;
    signal = prediction.signal;
    times  = prediction.times;
    
    //std::cout<<signal[2].real()<<std::endl;

    //std::cout<<times[2]<<std::endl;
    // Do the Fourier transform of the signal calculating the power spectrum of the prediction
    rarray <std::complex<double>,1> signal_hat = fft_fast(signal);

    //std::cout<<signal_hat[2]<<std::endl;
    rarray <double,1> ps = power_spectrum(signal_hat);
    //std::cout<<ps[2]<<std::endl;
    //std::vector<double> co_ef(Num_of_detections);
    
    std::vector<std::pair<double, int> > co_ef_pair(Num_of_detections);
    co_ef_pair.reserve(Num_of_detections);
    // Read the prediction file sequently
    for (int i=1;i <=Num_of_detections; i++){
	std::string fname;
    	if (i<=9){
           // read one of the GW signal from observations
           fname = "data/detection0" + std::to_string(i) + ".rat";
           //std::cout<<fname<<std::endl;
        }
	else{
	   fname = "data/detection" + std::to_string(i) + ".rat";
           //std::cout<<fname<<std::endl;
        }
	//std::cout<<fname<<std::endl;
    	struct file_detection detection0 = readingfile(fname);
    	//std::cout<<fname<<std::endl;
	rarray<double,1> times0;
    	rarray<std::complex<double>,1> signal0;
    	signal0 = detection0.signal;
    	times0  = detection0.times;        
        //std::cout << times0[2]<< std::endl;        
	
	rarray<std::complex<double>,1> signal_hat0 = fft_fast(signal0);
    	rarray<double,1> ps0 = power_spectrum(signal_hat0);
    	double co_ef_0=correlation_coefficient(ps0, ps);
    	//std::cout<<co_ef_0<<std::endl;
//	co_ef[i-1] = co_ef_0;
	co_ef_pair.push_back(std::make_pair(co_ef_0, i));
	
    }
    //std::sort(co_ef.rbegin(), co_ef.rend());//sorting in a descending way
    std::cout<<"rank  " << "co_efficients" <<std::endl;
    
    //std::sort(vec.begin(), vec.end(), std::something_magic<int, int, std::less>());
    //std::sort(co_ef_pair.begin(), co_ef_pair.end(), [](const std::pair<int,double> &left, const std::pair<int,double> &right) {
    std::sort(co_ef_pair.rbegin(),co_ef_pair.rend());
//    return left.second < right.second;
//});
    //for (int i=0;i<=4;i++){
      //  std::cout<<i+1<<"  "<<co_ef[i]<<std::endl;
    //}
    for (int i=0;i<=4;i++){
	std::cout<<co_ef_pair[i].second<<"  "<<co_ef_pair[i].first<<std::endl;
}
    return 0;
}
