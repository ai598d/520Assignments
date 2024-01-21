#ifndef COMPLEX_H
#define COMPLEX_H

/*! @file */

/*! \breif Complex object and method definitions
 *
 *  A complex object is a struct with a real, denoted real, and
 *  a imaginary, denoted imag. Varions Methods that take complex number and return 
 *  complex number do arithmetical operations on them.
 */
typedef struct {
    double real;
    double imag;
} Complex;

/*! Add two fractions together
 *  \param a The first summand
 *  \param b The second summand
 */
Complex add ( Complex a, Complex b );

/*! Multiply two fractions together (does not reduce)
 *  \param a The first term
 *  \param b The second term
 */
Complex multiply ( Complex a, Complex b );


Complex negate(Complex a, Complex b );

double magnitude (Complex a );


#endif