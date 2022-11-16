#include <iostream>
using namespace std;

// class topic: Futher Exception Handling

// Exception Handling Mechanism in C++ is based on the following three keywords:
// try, catch, throw

// try: is used to enclose the code that may throw an exception
// catch: is used to catch the exception thrown by the try block
// throw: is used to throw an exception

// Within the try block this is what happens on an exception:
//  1. The exception is thrown
//  2. The stack is unwound, this means that the program control is returned to the previous function
// what is stack unwinding? -> Stack unwinding is the process of returning the program control to the previous function
// In the context of c++:
// C++ runtime calls the destructors of all the objects that were created in the current context (try block)

// 3. The catch block is searched for a matching exception
// 4. If a matching exception is found, the catch block is executed
// 5. If no matching exception is found, the program is terminated

// what is a matching exception?
// a matching exception is an exception that is caught by the catch block
// the catch block can catch an exception by its type or by its value

// what is an exception type?
// an exception type is the type of the exception thrown by the try block
// the catch block can catch an exception by its type

// what is an exception value?
// an exception value is the value of the exception thrown by the try block
// the catch block can catch an exception by its value

// what is the difference between an exception type and an exception value?
// the difference is that an exception type is the type of the exception thrown by the try block

// class Example: Exception Handled Stack
class stackException
{
private:
    string message;

public:
    stackException(string message) { this->message = message; }
    virtual void print() = 0;
    string what() { return message; }
};

class stackFullException : public stackException
{
public:
    stackFullException(string message) : stackException(message){};

public:
    void print() { cout << "stack is full | stack overflow\n"; }
};

class stackEmptyException : public stackException
{
public:
    stackEmptyException(string message) : stackException(message){};
    void print() { cout << "stack is empty | stack underflow\n"; }
};

const int MAX = 3;
class stack
{
    int st[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    ~stack()
    {
        cout << "stack destructor called" << endl;
    }

    void push(int x)
    {
        if (top >= MAX - 1)
        {
            throw stackFullException("stack is full, cannot push; current index: " + to_string(top));
        }
        else
        {
            st[++top] = x;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            throw stackEmptyException("stack is empty, cannot pop; current index: " + to_string(top));
        }
        else
        {
            int x = st[top--];
            return x;
        }
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }

};

int main()
{

    // stack s;

    try
    {
        stack s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.print();
        s1.push(4);// -> this will throw an exception -> stackFullException



        // while(1){
        //     int *p = new int[11111111111];
        // } -> this will cause a memory leak -> bad_alloc exception
    }
    catch(stackException &e)
    {
        e.print();
        cout << e.what() << endl;
    }
    //examples of built in exceptions
    catch(bad_alloc &e){
        cout << "bad_alloc exception caught" << endl;
    }
    catch(exception &e){
        cout << "exception caught" << endl;
    }
    catch (...)
    {
        cout << "some other exception occured | exception unhandled" << endl;
    }

    cout << "AFTER ALL CATCH BLOCKS" << endl;

    return 0;
}