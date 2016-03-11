//
//  correlation.cpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//
//

#include "correlation.hpp"

//Fourier Transform of the complex signal
rarray <std::complex<double>,1> fft_fast(rarray <std::complex<double>,1> signal){
    
    rarray<std::complex<double>,1> signal_hat;
    fftw_plan p = fftw_plan_dft_1d(signal.size(),(fftw_complex*)signal.data(), (fftw_complex*)signal_hat.data(),FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    
    return signal_hat;
}

// Power spectrum of the rarray
rarray <double,1> power_spectrum(rarray <std::complex<double>,1> signal_hat){
    // get the conjugate first
    rarray<std::complex<double>,1> signal_hat_conjugate;
    // power spectrum
    rarray<double,1> F;
    for (int i = 0; i<=signal_hat.size(); i++) {
        std::complex <double> product = signal_hat[i]*std::conj(signal_hat[i]);
        F[i]=product.real;
    }
    return F;
}

// Correlation coefficient of 2 signals
double correlation_coefficient(rarray<double,1> F, rarray<double,1> G){
    double numerator_efficient = ddot(F.size(),F.data(),1,G.data(),1);
    double F_corr = ddot(F.size(),F.data(),1,F.data(),1);
    double G_corr = ddot(G.size(),G.data(),1,G.data(),1);
    double correlation_coefficient = numerator_efficient/sqrt(F_corr*G_corr);
    
    return correlation_coefficient;
}