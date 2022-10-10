#include <iostream>
using namespace std;

//class topic: copy constructor

//example class: Complex
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
        Complex(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
        }


        //destructors
        ~Complex(){
            cout << "Destructor called" << endl;
        }
        //overload + operator as a friend function
        friend Complex operator+(Complex, Complex);

        //overload = operator
        Complex operator=(Complex &c){
            real = c.real;
            imaginary = c.imaginary;
            //why are we returning? 
                //because we want to be able to chain the = operator
            return *this; //??
        }
        //overload << operator
        friend ostream& operator<<(ostream &out, Complex c){
            out << c.real << " + " << c.imaginary << "i";
            return out;
        }
        //overload >> operator
        friend istream& operator>>(istream &in, Complex &c){
            cout << "Enter real part: ";
            in >> c.real;
            cout << "Enter imaginary part: ";
            in >> c.imaginary;
            return in;
        }
};

int main()
{
    //what is a copy constructor?
        //a copy constructor is a constructor that creates an object by initializing it with an object of the same class, which has been created previously
        //the copy constructor is used to:
            //initialize one object from another of the same type
            //copy an object to pass it as an argument to a function
            //copy an object to return it from a function
            //the compiler provides a default copy constructor if you do not define one
            //the default copy constructor performs a member-wise copy, which means that it copies each member of the source object to the corresponding member of the target object
            //if a class contains pointers to dynamically allocated memory, the default copy constructor will copy the pointer, but not the memory to which the pointer points


    //using the copy constructor
    Complex C1(1,1);
    //ways to use the copy constructor
    Complex C2(C1); // <- copy constructor
    Complex C3 = C1; // <- copy constructor
    Complex C4 = Complex(1,1); // <- copy constructor
    Complex C5 = Complex(C1); // <- copy constructor

    //not using the copy constructor
    Complex C4;
    C4 = C1; // <- assignment operator
    Complex C5 = {1,1}; // <- parameterized constructor

    return 0;
}