//
//  hw3.cpp
//  
//
//  Created by Siqi Liu on 2016-01-21.
//
//

#include "hw3.hpp"
#include "ticktock.h"

int main()
{
    // ants walk on a table
    const int n_ants = 356;
    const int total_ants = 1010; // initial number of ants
    
   // use rarray to allocate the array
    rarray<float,2> number_of_ants(n_ants,n_ants);
    rarray<float,2> new_number_of_ants(n_ants,n_ants);
    rarray<float,2> velocity_of_ants(n_ants,n_ants);
    
    //use ticktock
    TickTock stopwatch, stopwatch1, stopwatch2;
    
    // initialize
    stopwatch.tick();
    initialize (n_ants, total_ants, velocity_of_ants, number_of_ants);
    // measure time and save elapsed time
    double calctime = stopwatch.silent_tock();
    // output of the result of the calculation:
    std::cout << "#Initilize Calculation took:\t" << calctime << " sec" << std::endl;
    
    // run simulation
    double calctime1 = 0.0;
    double calctime2 = 0.0;
    
    for (int t = 0; t < 40; t++) {
        float totants = 0.0;
        stopwatch1.tick();
        output(n_ants,t,totants,number_of_ants);
        calctime1 += stopwatch1.silent_tock();
        
        stopwatch2.tick();
        singlestep(n_ants, totants, new_number_of_ants, number_of_ants, velocity_of_ants);
        calctime2 += stopwatch2.silent_tock();
    }
    std::cout << "#Looping Calculation took:\t" << calctime1 << " sec" << std::endl;
    std::cout << "#Looping Calculation took:\t" << calctime2 << " sec" << std::endl;

    return 0;
}
