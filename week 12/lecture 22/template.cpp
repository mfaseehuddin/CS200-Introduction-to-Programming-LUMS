#include <iostream>
using namespace std;

//class topic: templates


//template function example
//swap
template <class T>
void swapData(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

//template functions in c++ are not compiled until they are called
//They are used to create generic functions that can work with different data types
//Use cases for templates:
    //1. when you want to write a function that can work with different data types
    //2. when you want to write a class that can work with different data types

//can we use templating for catching exceptions?-> yes
    //example:
    template <class T>
    void divide(T a, T b)
    {
        if(b == 0)
        {
            throw "Division by zero condition!";
        }
        else
        {
            cout << a/b << endl;
        }
    }

    //example 2: isGreater
    template <class T>
    bool isGreater(T a, T b)
    {
        return (a > b);
    }

    //example 3: class interaction
    class Counter{
        private:
            int count;
        public:
            Counter(): count(0){}
            void increment(){count++;}
            int getCount(){return count;}
            //overload > operator
            bool operator > (Counter c)
            {
                return (count > c.count);
            }
    };

int main()
{
    
    //using swap template function
    int a = 10, b = 20;
    cout << "a = " << a << " b = " << b << endl;
    //call the swap function
    swapData(a, b);
    cout << "a = " << a << " b = " << b << endl;



    //catching exception using template function
    try
    {
        divide(10, 0);
    }
    catch(const char *e)
    {
        cout << e << endl;
    }

    //declaring two objects of class Counter
    Counter c1, c2;
    c1.increment();
    c1.increment();

    c2.increment();


    //using isGreater template function
    if(isGreater(c1, c2))
    {
        cout << "c1 is greater" << endl;
    }
    else
    {
        cout << "c2 is greater" << endl;
    }

    return 0;
}