#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructor: Base" << endl;
    }
    void print()
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
    virtual void print()
    {
        cout << "print(): Derived" << endl;
    }
    ~Derived()
    {
        cout << "Destructor: Derived" << endl;
    }
};



int main()
{
    cout << "step1:" << endl;
    Base *bPtr = new Base();
    bPtr->print();
    // delete bPtr;
    cout << endl;
    
    cout << "step2:" << endl;
    Derived *dPtr = new Derived();
    dPtr->print(); //what is happening here? -> the derived class print function is being called
    cout << endl;

    cout << "step3:" << endl;
    bPtr = dPtr;
    bPtr->print();
    cout << endl;

    return 0;
}