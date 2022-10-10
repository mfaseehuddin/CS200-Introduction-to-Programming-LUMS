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

        //overload prefix ++ operator
        Complex operator++(){
            Complex temp;
            temp.real = ++real;
            temp.imaginary = ++imaginary;
            return temp;
        }
        //overload postfix ++ operator
        Complex operator++(int x){
            Complex temp;
            temp.real = ++real;
            temp.imaginary = ++imaginary;
            return temp;
        }

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

class ComplexStack{
    private:
        Complex *stack;
        int top;
    public:
        //default constructor
        ComplexStack(){
            stack = new Complex[10];
            top = -1;
        }
        //copy constructor
        //deep copy
        ComplexStack(ComplexStack &cs){
            stack = new Complex[10];
            top = cs.top;
            for(int i = 0; i <= top; i++){
                stack[i] = cs.stack[i];
            }
        }
        //destructors
        ~ComplexStack(){
            delete [] stack;
        }
        //push
        void push(Complex c){
            stack[++top] = c;
        }
        //pop
        Complex pop(){
            return stack[top--];
        }
        //overload = operator
        //deep copy
        ComplexStack operator=(ComplexStack &cs){
            top = cs.top;
            for(int i = 0; i <= top; i++){
                stack[i] = cs.stack[i];
            }
            return (*this);
        }
        //overload << operator
        friend ostream& operator<<(ostream &out, ComplexStack cs){
            for(int i = 0; i <= cs.top; i++){
                out << cs.stack[i] << endl;
            }
            return out;
        }
        //overload >> operator
        friend istream& operator>>(istream &in, ComplexStack &cs){
            cs.stack = new Complex[10];
            cout << "Enter number of elements to add: ";
            in >> cs.top;
            for(int i = 0; i <= cs.top; i++){
                in >> cs.stack[i];
            }
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
    // Complex C4 = Complex(1,1); // <- copy constructor
    // Complex C5 = Complex(C1); // <- copy constructor

    //not using the copy constructor
    Complex C6;
    C6 = C1; // <- assignment operator

    //use the ComplexStack class
    ComplexStack cs1;
    cin >> cs1;
    cout << cs1;
    ComplexStack cs2(cs1);
    cout << cs2;
    ComplexStack cs3;
    cs3 = cs1;
    cout << cs3;


    return 0;
}