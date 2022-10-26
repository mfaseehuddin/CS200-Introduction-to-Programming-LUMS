#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructor: Base" << endl;
    }
    virtual void print()
    {
        cout << "print(): Base" << endl;
    }
    virtual ~Base()
    {
        cout << "Destructor: Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructor: Derived" << endl;
    }
    //this function overrides the base class function.
    void print()
    {
        cout << "print(): Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructor: Derived" << endl;
    }
};


//the virtual keyword is used to tell the compiler that the function is virtual
//virtual functions are functions that can be overridden in derived classes

/////////but i made the derived class print function a virtual function and it still works, why? -> because the base class print function is virtual
/////////but it was not virtual in the base class, why does it work? -> because the base class print function is virtual

int main(){
    Base *b = new Base();
    b->print();
    delete b;
    cout << endl;

    b = new Derived();
    b->print(); 
    delete b; //this has a problem -> the base class destructor is called, but the derived class destructor is not called
    //to fix this problem, we need to make the base class destructor virtual // as done in the class above
    cout << endl;
    return 0;
}

// int main()
// {

//     //when the base class print function was not virtual, this was static binding/compile time binding/early binding
//     //when the base class print function was virtual, this was dynamic binding/run time binding/late binding

//     //explain the difference between static and dynamic binding
//     //static binding is when the compiler knows which function to call at compile time
//     //dynamic binding is when the compiler does not know which function to call at compile time, so it waits until run time to figure out which function to call
//         //this is done by using a virtual function table
//             //what is that?
//                 //a virtual function table is a table that contains the addresses of all the virtual functions in the class
//                 //the virtual function table is stored in the class object
//                 //the virtual function table is used to determine which function to call at run time
//                 //the virtual function table is created when the class object is created



//     cout << "step1:" << endl;
//     Base *bPtr = new Base();
//     bPtr->print();
//     // delete bPtr;
//     cout << endl;
    
//     cout << "step2:" << endl;
//     Derived *dPtr = new Derived();
//     dPtr->print(); //what is happening here? -> the derived class print function is being called
//     cout << endl;

//     cout << "step3:" << endl;
//     bPtr = dPtr;
//     bPtr->print();
//     cout << endl;


//     return 0;
// }