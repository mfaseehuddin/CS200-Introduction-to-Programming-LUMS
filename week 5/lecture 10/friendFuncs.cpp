#include <iostream>
using namespace std;

//class topic: Friend Functions && Operator Overloading
//diving deeper
/*
    what is friend function?
        a friend function is a function that is not a member of the class, but it can access the private members of the class.
        it is declared in the class, but it is not a member of the class.

    what is operator overloading?
        operator overloading is the ability to redefine the meaning of an operator in terms of a user-defined type. The operators that can be overloaded are, +, -, *, /, %, ^, &, |, ~, !, =, <, >, +=, -=, *=, /=, %=, ^=, &=, |=, <<=, >>=, ==, !=, <=, >=, ++, --, <<, >>, &&, ||, ,, ->*, ->, new, new[], delete, delete[]

        operators that can not be overloaded are, ::, .*, ., ?:, sizeof, typeid, and the scope resolution operator
*/

//example class: Complex
//what is a complex number?
    //a complex number is a number that can be expressed in the form a + bi, where a and b are real numbers and i is the imaginary unit
    //i^2 = -1
    //hence, a complex number can be expressed as a real number and an imaginary number
    //therefore we will have two data members, one for the real part and one for the imaginary part
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
        //destructors
        ~Complex(){
            cout << "Destructor called" << endl;
        }
        //overload + operator as a friend function
        friend Complex operator+(Complex, Complex);

        //overload = operator
        void operator=(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }

        //friend overload << operator using ref
        //what is ostream?
            //ostream is a class that represents the output stream
            //return type is ostream& because we are returning a reference to the ostream object
            //the reason we are returning a reference is because we want to be able to chain the << operator
            //simply, we want to be able to do cout << c1 << c2 << c3;
        friend ostream& operator<<(ostream &out, Complex c){
            out << c.real << " + " << c.imaginary << "i";
            return out;
        }

        //friend overload >> operator using ref
        friend istream& operator>>(istream &in, Complex &c){
            cout << "Enter real part: ";
            in >> c.real;
            cout << "Enter imaginary part: ";
            in >> c.imaginary;
            return in;
        }
        

};

//overload + operator as a friend function
//as the operator+ is a friend function, it is defined 
//we also do not use the scope resolution operator :: to define the function
Complex operator+(Complex c1, Complex c2){
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    cout << temp << endl;
    return temp;
}

int main()
{

    //calling the overloaded + operator
    Complex c1(1, 2), c2(3, 4), c4(5, 6);
    //as we have Complex return type of the overloaded + operator, we can store the result in a Complex object
    //hence, we can chain the overloaded + operator
    //chained + will resolve from left to right
    Complex c3 = c1 + c2 + c4;

    //we can not call the overloaded + operator as a normal function because it is a friend function
    //hence, we can not call it as operator+(c1, c2) or c3.operator+(c1)

    //valid
    // operator<<(cout, c3);

    cout << c1 << " + " << c2 << " + " << c4 << " = " << c3 << endl;
    //breakdown
    // cout << c1; -> out
    // out << " + " << c2 << " + " << c4 << " = " << c3 << endl;
    // out << " + " << c2; -> out
    // out << " + " << c4 << " = " << c3 << endl;
    // out << " + " << c4; -> out
    // out << " = " << c3 << endl;
    // out << " = " << c3; -> out
    // out << endl;
    


    return 0;
}