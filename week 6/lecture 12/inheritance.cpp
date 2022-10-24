#include <iostream>
using namespace std;

//topic: Inheritance
//what is inheritance?
    //inheritance is a way to reuse code
    //it is a way to create a new class from an existing class
    //the new class is called the derived class
    //the existing class is called the base class
    //the derived class inherits the properties of the base class
    //the derived class can add new properties
    //the derived class can override the properties of the base class
    //the derived class can add new methods
    //the derived class can override the methods of the base class
    //the derived class can add new constructors
    //the derived class can override the constructors of the base class
    //the derived class can add new destructors
    //the derived class can override the destructors of the base class
    //the derived class can add new operators
    //the derived class can override the operators of the base class
    //the derived class can add new friends
    //the derived class can override the friends of the base class
    //the derived class can add new data members
    //the derived class can override the data members of the base class
    //the derived class can add new static members
    //the derived class can override the static members of the base class
    //the derived class can add new static methods
    //the derived class can override the static methods of the base class
    //the derived class can add new static constructors
    //the derived class can override the static constructors of the base class
    //the derived class can add new static destructors
    //the derived class can override the static destructors of the base class
    //the derived class can add new static operators
    //the derived class can override the static operators of the base class
    //the derived class can add new static friends
    //the derived class can override the static friends of the base class
    //the derived class can add new static data members
    //the derived class can override the static data members of the base class
    //the derived class can add new virtual methods
    //the derived class can override the virtual methods of the base class
    //the derived class can add new virtual constructors
    //the derived class can override the virtual constructors of the base class
    //the derived class can add new virtual destructors
    //the derived class can override the virtual destructors of the base


class Counter
{
protected:
    int count;
public:
    Counter(){
        count = 0;
        cout << "Counter constructor called" << endl;
    }
    Counter(int count){
        this->count = count;
        cout << "Counter parameterised constructor called" << endl;
    }
    int inc(){
        count++;
        return count;
    }
    ~Counter(){
        cout << "Counter destructor called" << endl;
    };

    void print(){
        cout << "Base Class count: " << count << endl;
    }
};



///now we will create a derived class from the Counter class
// what does public keyword mean in class derivation? 
    //public keyword means that the derived class will inherit the public members of the base class
    //the derived class will have access to the public, protected members of the base class 
    //the derived class will not have access to the private members of the base class!!
class ExtendedCounter: public Counter
{
public:
    ExtendedCounter(){
        cout << "ExtendedCounter default constructor called" << endl;
    }
    //we can override the parameterised constructor of the base class
    //the parent class parameterised constructor will be called first with count as the parameter
    ExtendedCounter(int count): Counter(count){
        cout << "ExtendedCounter parameterised constructor called" << endl;
    }
    int dec(){
        count--;
        return count;
    }
    ~ExtendedCounter(){
        cout << "ExtendedCounter destructor called" << endl;
    };

    void print(){
        cout << "Derived Class count: " << count << endl;
    }
};


//counter in this case is a base/parent/super class
//extendedCounter is a derived/child/sub class



int main()
{
    ExtendedCounter c1(10);
    cout << c1.inc() << endl;
    cout << c1.dec() << endl;

    //extended Counter has a IS-A / IS-KIND-OF relationship with Counter
    
    //hence the following line is valid
    //assign the pointer of the derived class to the pointer of the base class
    Counter *c2 = &c1;
    //is c1 being casted? no
    //then? c1 is being assigned to c2 -> how can this be possible?
    //c1 is a derived class object, yes but? c1 is also a base class object


    //the following line will call the print method of the base class
    c2->print();

    Counter *c4;
    ExtendedCounter *c5;

    c4 = c5;

    c5->print();
    c4->print();



    return 0;
}