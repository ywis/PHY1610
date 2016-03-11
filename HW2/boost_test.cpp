//
//  boost_test.cpp
//  
//
//  Created by Siqi Liu on 2016-02-02.
//
//
#define BOOST_TEST_MAIN myTest
#include "boost_test.hpp"

BOOST_AUTO_TEST_SUITE(myTest)
BOOST_AUTO_TEST_CASE(num_of_ants)//just a self-defined name
{
    
    // ants walk on a table
    const int n_ants = 356;
    const int total_ants = 1010; // initial number of ants
    
    // use rarray to allocate the array
    rarray<float,2> number_of_ants(n_ants,n_ants);
    rarray<float,2> new_number_of_ants(n_ants,n_ants);
    rarray<float,2> velocity_of_ants(n_ants,n_ants);
    
    // initialize
    number_of_ants.fill(1.0);
    new_number_of_ants.fill(1.0);
    
    // run simulation
    float totants = 0.0;
    float totants1,totants2;
    int t = 0;
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            totants += number_of_ants[i][j];
        }
    }
    singlestep(n_ants, totants, new_number_of_ants, number_of_ants, velocity_of_ants);
    totants1=totants;
    
    t = 1;
    totants = 0.0;
    for (int i=0;i<n_ants;i++) {
        for (int j=0;j<n_ants;j++) {
            totants += number_of_ants[i][j];
        }
    }
    singlestep(n_ants, totants, new_number_of_ants, number_of_ants, velocity_of_ants);
    totants2=totants;

    BOOST_REQUIRE(totants1 >= totants2);
    //BOOST_REQUIRE(totants1 == totants2);
    //BOOST_ERROR('Something went wrong here...');
    if(totants1 < totants2) BOOST_ERROR("Ouch...");
    //if(add(2,2)!=5) BOOST_FAIL("Ouch...");
    //BOOST_CHECK_MESSAGE(add(2,2)==4,"msg...");
    //BOOST_CHECK_EQUAL(add(2,2),4);
}
BOOST_AUTO_TEST_SUITE_END();
