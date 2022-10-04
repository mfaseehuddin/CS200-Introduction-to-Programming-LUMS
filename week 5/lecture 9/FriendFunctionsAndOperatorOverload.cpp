#include <iostream>
using namespace std;

//class Topic: Friend Functions && Operator overloading

/*

    The benefits of using a friend function is that it can access the private members of the class.
    It is not a member of the class, but it can access the private members of the class.
    However, it is declared in the class, because it is a friend of the class. It doesnt make sense, but it is.
*/

//define a class of complex numbers
// what are complex numbers?
    // a complex number is a number that can be expressed in the form a + bi, where a and b are real numbers and i is the imaginary unit
    // i^2 = -1
    //hence, a complex number can be expressed as a real number and an imaginary number
    //therefore we will have two data members, one for the real part and one for the imaginary part

class Complex{
    private:
        int real;
        int imaginary;
    public:
        //default constructor
        Complex(){
            real = 0;
            imaginary = 0;
        }
        //parameterized constructor
        Complex(int real, int imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
        //copy constructor
        Complex(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }
        //overloading the + operator using ref
        Complex operator+(Complex &c){
            Complex temp;
            temp.real = real + c.real;
            temp.imaginary = imaginary + c.imaginary;
            return temp;
        }
        //overloading the + operator using pointer
        Complex operator+(Complex *c){
            Complex temp;
            temp.real = real + c->real;
            temp.imaginary = imaginary + c->imaginary;
            return temp;
        }  
        //overloading the << operator
        friend ostream& operator<<(ostream &out, Complex &c){
            out << c.real << " + " << c.imaginary << "i" << endl;
            return out;
        }
        //overloading the >> operator
        friend istream& operator>>(istream &in, Complex &c){
            cout << "Enter the real part: ";
            in >> c.real;
            cout << "Enter the imaginary part: ";
            in >> c.imaginary;
            return in;
        }
        //overloading the = operator
        void operator=(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }
};


//define a class of box
class Box{
    private:
        double length;
        double breadth;
        double height;
        string unit;
    public:
        //default constructor
        Box(){
            length = 0;
            breadth = 0;
            height = 0;
            unit = "m";
        }
        //parameterised constructor
        Box(double l, double b, double h, string u){
            length = l;
            breadth = b;
            height = h;
            unit = u;
        }
        //friend function
        friend string volume(Box box){
            //return volume to only 2 decimal places //doesnt work properly
            return to_string(box.length * box.breadth * box.height).substr(0,4) + " " + box.unit + "^3";
        }
};

//object -> a=10 b=10 c=10

int main()
{
    Box box;
    string vol = volume(box);
    
    cout << "Volume of box is: " << vol << endl;

    //use the imaginary class by defining an object

    Complex c1(2,3);
    Complex c2(4,5);
    //add them
    Complex c3 = c1 + c2;
    //print the result
    cout << c3 << endl;


    return 0;
}