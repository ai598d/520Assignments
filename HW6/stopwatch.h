#ifndef STOPWATCH
#define STOPWATCH

#include <iostream>
#include "gtest/gtest.h"
#include "elma/elma.h"
#include <ratio>

using namespace::elma;
using namespace::std;

class Stopwatch{

    public:

        Stopwatch();

        void start();              // starts the timer
        void stop();               // stops the timer
        void reset();              // sets stopwatch to zero

        std::chrono::high_resolution_clock::time_point get_time_t1();
        std::chrono::high_resolution_clock::time_point get_time_t2();

        double get_minutes();      // number of minutes counted, as a double
        double get_seconds();      // number of seconds counted, as a double
        double get_milliseconds(); // number of milliseconds counted, as a double
        double get_nanoseconds();  // number of nanoseconds counted, as a double




    private:

    std::chrono::high_resolution_clock::time_point t1, t2;






};

Stopwatch::Stopwatch(){
    typedef std::chrono::duration<int,std::nano> nanoseconds_type;
    auto t1 = nanoseconds_type::zero();
    auto t2 = nanoseconds_type::zero();
}

void Stopwatch::start(){

    t1 = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop(){

    t2 = std::chrono::high_resolution_clock::now();
}



std::chrono::high_resolution_clock::time_point Stopwatch:: get_time_t1(){

    return t1;


}

std::chrono::high_resolution_clock::time_point Stopwatch:: get_time_t2(){

    return t2;


}


double Stopwatch::get_nanoseconds(){

    return (t2-t1).count();
}

double Stopwatch::get_milliseconds(){
    
    return (t2-t1).count()*.0000001 ;
}

double Stopwatch::get_seconds(){
    
    return (t2-t1).count()*.0000000001 ;
}

double Stopwatch::get_minutes(){
    return ((t2-t1).count()*.0000000001)/60 ;
}

void Stopwatch::reset(){

    typedef std::chrono::duration<int,std::nano> nanoseconds_type;

    auto t1 = nanoseconds_type::zero();
    auto t2 = nanoseconds_type::zero();
}

#endif