//
//  initialize.cpp
//  
//
//  Created by Siqi Liu on 2016-01-25.
//
//

#include "initialize.hpp"

void initialize (const int n_ants, const int total_ants, rarray<float,2> velocity_of_ants, rarray<float,2> number_of_ants){
   
    //initial velocities of the ants
    int i,j;
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
        }
    }
    //initialize the number of the ants
    int n = 0;
    float z = 0;
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
    
    while (n < total_ants) {
        for (int i=0;i<n_ants;i++) {
            for (int j=0;j<n_ants;j++) {
                z += sin(0.3*(i+j));//what is the meaning of z here
                if (z>1 and n!=total_ants) {
                    number_of_ants[i][j] += 1;
                    n += 1;
                }
            }
        }
    }
}