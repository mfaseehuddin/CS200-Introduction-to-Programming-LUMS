#include <iostream>
using namespace std;

class Complex{
    private:
        int real;
        int imaginary;
    public:
        //parameterized constructor
        Complex(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
        //default constructor
        Complex(){
            real = 0;
            imaginary = 0;
        }
        //copy constructor
        //The parameter of the copy constructor is a reference to the object of the class, because we do not want to create a new object
        //if it is pass-by-value then it means the copy constructor is called when we pass the object to a function
        //and then for that copy constructor to be called, the copy constructor is called again
        //and then for that copy constructor to be called, the copy constructor is called again
        //and so on
        //hence we pass by reference
        Complex(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }
};

int main()
{

    return 0;
}