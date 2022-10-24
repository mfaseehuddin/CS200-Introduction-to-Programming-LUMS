#include <iostream>
using namespace std;

// topics covered until now:
//  Inheritance:
//  - Base / Derived classes
//  - Constructors
//  - Destructors
//  - Function overriding
//  - Function/Operator overloading
//  - Base class pointer = Derived class object is allowed

// topic: Further Inheritance

class Engine
{
    int cylinders;
    int horsePower;

public:
    Engine(){
        cylinders = 0;
        horsePower = 0;
        cout << "Engine Default constructor called" << endl;
    }
    
    Engine(int cylinders, int horsePower)
    {
        this->cylinders = cylinders;
        this->horsePower = horsePower;
    }
    int getCylinders()
    {
        return cylinders;
    }
    int getHorsePower()
    {
        return horsePower;
    }
};
class V8Engine : public Engine
{
private:
    int turbo;
    int superCharger;
    int cylinders;
    int horsePower;
    // instance of base class;
    Engine engine;

public:

    //is default constructor nessasary for a class?
    //yes, if you want to create an object of that class


    V8Engine(int cylinders, int horsePower) : Engine(cylinders, horsePower)
    {
        this->cylinders = cylinders;
        this->horsePower = horsePower;
        turbo = 0;
        superCharger = 0;
        cout << "V8Engine constructor called" << endl;
    }
    ~V8Engine()
    {
        cout << "V8Engine destructor called" << endl;
    }
    void start()
    {
        cout << "V8Engine started" << endl;
    }
    void stop()
    {
        cout << "V8Engine stopped" << endl;
    }
};


class Base{
    private:
        int x;
        static int total; //this variable is sometimes reffered to as a class variable
        //for a static variable, there is only one copy of it, no matter how many objects of the class are created
        //static variables are shared by all objects of the class
        //static variables are declared outside of the class
        static string pstring;
    public:
        Base(int a){
            x = a;
            total++;
            pstring += 'a' + total - 1;
        }

        //static function can only access static variables
        static void printStatics(){
            cout << "Total Base Classes: " << total << endl;
            cout << "UUiD: " << pstring << endl;
        }

        //non-static function can access both static and non-static variables
        void printX(){
            cout << x << " " << total << endl;
        }
        void printString(){
            cout << pstring << endl;
        }
        ~Base(){
            total--;
        }
};

int Base::total = 0;
string Base::pstring = "";

int main()
{

    Base b1(5);
    Base b2(10);
    Base b3(15);
    Base::printStatics();
    b3.printX();
    b2.printString();

    return 0;
}