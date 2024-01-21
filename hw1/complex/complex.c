#include <stdio.h>
#include <math.h> 
#include "complex.h"


double mysqrt ( double x );

int main(){

    Complex a,b;

    a.real = 2;
    b.real = 3;

    a.imag = 4;
    a.imag = 6;

    Complex c;

    c = add(a,b);

    printf("-------------Testing Addition-------------\n");
    printf("real part:%f\n",c.real);
    printf("imag part:%f\n",c.imag);


    c = negate(c,a);
    printf("-------------Testing Negation-------------\n");
    printf(" real part:%f\n",c.real);
    printf(" imag part:%f\n",c.imag);


    c = multiply(c,b);
    printf("-------------Testing Multiplication-------------\n");
    printf("real part:%f\n",c.real);
    printf("imag part:%f\n",c.imag);

    
    double d = magnitude(c);
    printf("-------------Testing magnitude-------------\n");
    printf("magnitdue:%f\n",d);
    

    



    return 0;
}



// addition function
Complex add ( Complex a, Complex b ){

Complex c;

c.real = a.real+b.real;

c.imag = a.imag+b.imag;

    return c;
}

// multiply
Complex multiply ( Complex a, Complex b ){

    Complex c ;

    c.real = (a.real*b.real - a.imag*b.imag);

    c.imag = (a.real*b.imag + a.imag*b.real);

    return c;

}

// negate
Complex negate(Complex a, Complex b ){

    Complex c;

    c.real = a.real-b.real;

    c.imag = a.imag-b.imag;

    return c;

}

//sqrt
double mysqrt ( double x ){

    return sqrt(x);

}

// magnitude
double magnitude (Complex a ){


    double x;
    double y;

    x = a.real*a.real;
    y = a.imag*a.imag;

    return mysqrt(x+y);

}

// 