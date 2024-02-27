#include <iostream>
#include "gtest/gtest.h"
#include "elma/elma.h"
#include <ratio>
#include <Stopwatch.h>
#include <stdlib.h>     /* srand, rand */
#include <RandomProcess.h>
#include <Filter.h>
#include <Integrator.h>
#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(1500))

using namespace::elma;
using namespace::std;



int main(){

    Stopwatch w; // should set the stopwatch to 0 seconds
    w.start();
    SLEEP;
    w.stop();
    std::cout << w.get_seconds() << "\n"; // about 1.5
    SLEEP;
    std::cout << w.get_seconds() << "\n"; // still about 1.5
    w.start();
    SLEEP;
    w.stop();
    std::cout << w.get_seconds() << "\n"; // about 3.0
    w.reset();
    std::cout << w.get_seconds() << "\n"; // 0.0


    // filter check
    elma::Manager m;

    RandomProcess r("random numbers");
    Filter f("filter");
    Integrator i("integrator");
    elma::Channel link("link");

    m.schedule(r, 1_ms)
    .schedule(f, 1_ms)
    .add_channel(link)
    .init()
    .run(1000_ms);

    cout<<"Checking Filter running average"<<f.value()<<endl;

    // integral check
    m.schedule(r, 10_ms)
    .schedule(i, 10_ms)
    .add_channel(link)
    .init()
    .run(1000_ms);

    cout<<"Checking integral"<<i.value()<<endl;

    return 0;
}



