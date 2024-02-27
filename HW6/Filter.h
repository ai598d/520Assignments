#ifndef FILTER
#define FILTER
#include <iostream>
#include "gtest/gtest.h"
#include "elma/elma.h"
#include <ratio>
#include <stdlib.h>     /* srand, rand */


class Filter : public elma::Process {
  public:
    
    double data;
    double run_avg;
    int count;
    
    Filter(std::string name) : Process(name) {}
    void init() { 
             
        }

    void start() {
        run_avg = 0;
        count = 0;
        data = 0;  
    }
    void update() {

        
        if (channel("link").nonempty()) {
        data = channel("link").latest();
      }
        count = count+1;
        run_avg = run_avg + (data/count) ;
        

        if(count==10){

            count = 0;

        }
        
    }
    void stop() {}

    double value();
};

double Filter::value(){

    return run_avg;
}

#endif