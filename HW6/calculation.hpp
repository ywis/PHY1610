//
//  correlation.hpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//
//

#ifndef correlation_hpp
#define correlation_hpp

#include <stdio.h>
#include <blas.h>

//FT of the signal
rarray <std::complex<double>,1> fft_fast(rarray <std::complex<double>,1> signal);

// Power spectrum
rarray <double,1> power_spectrum(rarray <std::complex<double>,1> signal_hat);

// Correlation
double correlation_coefficient(rarray<double,1> F, rarray<double,1> G);

#endif /* correlation_hpp */
