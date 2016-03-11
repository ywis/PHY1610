//
//  correlation.cpp
//  
//
//  Created by Siqi Liu on 2016-03-09.
//
//

#include "calculation.hpp"

//Fourier Transform of the complex signal
rarray <std::complex<double>,1> fft_fast(rarray <std::complex<double>,1> signal){
    rarray<std::complex<double>,1> signal_hat(signal.size());// f_k
    fftw_plan p = fftw_plan_dft_1d(signal.size(), (fftw_complex*)signal.data(), (fftw_complex*)signal_hat.data(), FFTW_FORWARD, FFTW_ESTIMATE);//to create a plan, which is an object that contains all the data that FFTW needs to compute the FFT. 
    fftw_execute(p);//computing the actual transforms
    fftw_destroy_plan(p);//de-allocate the plan
    return signal_hat;
}

// Power spectrum of the rarray
rarray <double,1> power_spectrum(rarray <std::complex<double>,1> signal_hat){
    // power spectrum
    rarray<double,1> F(signal_hat.size());
    for (int i = 0; i<signal_hat.size(); i++) {
        std::complex<double> product = signal_hat[i]*std::conj(signal_hat[i]);
	double temp = product.real();
        F[i]=temp;
    }
    return F;
}

// Correlation coefficient of 2 signals
double correlation_coefficient(rarray<double,1> F, rarray<double,1> G){
    double numerator_efficient = cblas_ddot(F.size(),F.data(),1,G.data(),1);
    double F_corr = cblas_ddot(F.size(),F.data(),1,F.data(),1);
    double G_corr = cblas_ddot(G.size(),G.data(),1,G.data(),1);
    double correlation_coefficient = numerator_efficient/sqrt(F_corr*G_corr);
    return correlation_coefficient;
}
