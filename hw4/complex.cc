#include <math.h>
#include "complex.h"

double Complex::magnitude() const {

    return sqrt(re*re + im*im);

}

double Complex::real() const{

    return re;


}

double Complex:: imaginary()const{

    return im;
}

Complex Complex::conjugate(){

    return Complex(re, (-1)*im);
}

bool operator<(const Complex& a, const Complex& b) {

    return a.magnitude() < b.magnitude();

}

bool operator==(const Complex& a, const Complex& b){

    return (a.real()==b.real()) && (a.imaginary()==b.imaginary());

}

Complex operator+(const Complex& a, const Complex& b){

    Complex x( (a.real()+b.real()), (a.imaginary()+b.imaginary()) );

    return x;
}

Complex operator*(const Complex& a, const Complex& b){

    double new_real = (a.real()*b.real()) - (a.imaginary()*b.imaginary());
    double new_im = (a.real()*b.imaginary())+(b.real()*a.imaginary());

}
