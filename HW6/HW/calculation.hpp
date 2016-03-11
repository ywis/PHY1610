//
//  correlation.hpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//
//

#ifndef calculation_hpp
#define calculation_hpp

#include <stdio.h>
#include <cblas.h>
#include <cmath>
#include <rarray>
#include <rarrayio>
#include <complex>
#include "fftw3.h"
//FT of the signal
rarray <std::complex<double>,1> fft_fast(rarray <std::complex<double>,1> signal);

// Power spectrum
rarray <double,1> power_spectrum(rarray <std::complex<double>,1> signal_hat);

// Correlation
double correlation_coefficient(rarray<double,1> F, rarray<double,1> G);

#endif /* calculation_hpp */
