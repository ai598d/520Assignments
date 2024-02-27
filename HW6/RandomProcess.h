#ifndef RANDOMPROCESS
#define RANDOMPROCESS
#include <iostream>
#include "gtest/gtest.h"
#include "elma/elma.h"
#include <ratio>
#include <stdlib.h>     /* srand, rand */


class RandomProcess : public elma::Process {
  public:
    
    double data;
    
    RandomProcess(std::string name) : Process(name) {}
    void init() {}
    void start() {}
    void update() {


      data = rand() % 2;

      channel("link").send(data);

        
    }

    void stop() {}

    double value(){return data;}
};











#endif