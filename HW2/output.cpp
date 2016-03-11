//
//  simulate.cpp
//  
//
//  Created by Siqi Liu on 2016-01-25.
//
//

#include "output.hpp"

void output(const int n_ants,int t, float totants, rarray<float,2> number_of_ants){
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            totants += number_of_ants[i][j];
        }
    }
    std::cout << t<< " " << totants << std::endl;
}
