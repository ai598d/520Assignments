#ifndef INTEGRATOR
#define INTEGRATOR
#include <iostream>
#include "gtest/gtest.h"
#include "elma/elma.h"
#include <ratio>
#include <stdlib.h>     /* srand, rand */


class Integrator : public elma::Process {
  public:
    
    double data;
    double intg;
    const double delta=.001;
    
    
    Integrator(std::string name) : Process(name) {}
    void init() { 
 
              
        }

    void start() {
        data = 0;
        intg = 0;
        

    }
    void update() {

        if (channel("link").nonempty()) {
        data = channel("link").latest();
      }

        intg = intg+ (delta*data);
    }
    void stop() {}

    double value();
};

double Integrator::value(){

    return intg;
}

#endif