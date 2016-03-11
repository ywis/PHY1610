//
//  singlestep.cpp
//  
//
//  Created by Siqi Liu on 2016-01-26.
//
//

#include "singlestep.hpp"

void singlestep(const int n_ants, float totants, rarray<float,2> new_number_of_ants, rarray<float,2> number_of_ants, rarray<float,2> velocity_of_ants)
{
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            new_number_of_ants[i][j] = 0.0;
        }
    }
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            int di = 1.9*sin(velocity_of_ants[i][j]);
            int dj = 1.9*cos(velocity_of_ants[i][j]);
            int i2 = i + di;
            int j2 = j + dj;
            // some ants do not walk
            new_number_of_ants[i][j] += 0.8*number_of_ants[i][j];
            // the rest of the ants walk, but some fall of the table
            if (i2 >= 0 and i2 < n_ants and j2 >= 0 and j2 < n_ants) {
                new_number_of_ants[i2][j2] += 0.2*number_of_ants[i][j];
            }
        }
    }
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            number_of_ants[i][j] = new_number_of_ants[i][j];
            totants += number_of_ants[i][j];
        }
    }
}
