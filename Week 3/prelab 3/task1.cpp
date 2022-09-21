#include <iostream>
#include <cmath>
using namespace std;

struct ComplexNumber {
    double real;
    double imag;
};

ComplexNumber Conjugate(ComplexNumber &c) {
    ComplexNumber result;
    result.real = c.real;
    result.imag = -c.imag;
    return result;
}

ComplexNumber Modulus(ComplexNumber &c) {
    ComplexNumber result;
    result.real = sqrt(c.real * c.real + c.imag * c.imag);
    result.imag = 0;
    return result;
}

int Compare(ComplexNumber &a, ComplexNumber &b){
    //if the modulus of a is equal to the modulus of b, return 0
    if(Modulus(a).real == Modulus(b).real) {
        return 0;
    }
    //if the modulus of a is greater than the modulus of b, return 1
    else if(Modulus(a).real > Modulus(b).real) {
        return 1;
    }
    //if the modulus of a is less than the modulus of b, return -1
    else if(Modulus(a).real < Modulus(b).real) {
        return -1;
    }
}

ComplexNumber Add(ComplexNumber &a, ComplexNumber &b) {
    ComplexNumber result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

ComplexNumber Subtract(ComplexNumber &a, ComplexNumber &b) {
    ComplexNumber result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}



int main()
{

    return 0;
}