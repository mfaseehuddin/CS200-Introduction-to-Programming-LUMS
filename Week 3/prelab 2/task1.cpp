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

int Modulus(ComplexNumber &c) {
    int result;
    result =sqrt(c.real * c.real + c.imag * c.imag);
    return result;
}

int Compare(ComplexNumber &a, ComplexNumber &b){
    //if the modulus of a is equal to the modulus of b, return 0
    if(Modulus(a) == Modulus(b)) {
        return 0;
    }
    //if the modulus of a is greater than the modulus of b, return 1
    else if(Modulus(a) > Modulus(b)) {
        return 1;
    }
    //if the modulus of a is less than the modulus of b, return -1
    else if(Modulus(a) < Modulus(b)) {
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

    //testing all the functions
    ComplexNumber a;
    a.real = 1;
    a.imag = 2;
    ComplexNumber b;
    b.real = 3;
    b.imag = 4;

    //testing the Conjugate function
    ComplexNumber c = Conjugate(a);
    cout << "Conjugate of a is: " << c.real << " + " << c.imag << "i" << endl;

    //testing the Modulus function
    cout << "Modulus of a is: " << Modulus(a) << endl;

    //testing the Compare function
    cout << "Compare a and b: " << Compare(a, b) << endl;

    //testing the Add function
    ComplexNumber d = Add(a, b);
    cout << "Add a and b: " << d.real << " + " << d.imag << "i" << endl;

    //testing the Subtract function
    ComplexNumber e = Subtract(a, b);
    cout << "Subtract a and b: " << e.real << " + " << e.imag << "i" << endl;

    return 0;
}