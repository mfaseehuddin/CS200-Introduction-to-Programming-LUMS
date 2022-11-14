#include <iostream>
using namespace std;

// class topic: exception handling

// exception handling is a way to handle errors in our program
// we can use the try and catch keywords to handle errors in our program

// the try block is used to test a block of code for errors
// the try block will throw an exception if an error occurs

// the catch block is used to handle the error
// the catch block will contain the code that will be executed if an error occurs in the try block

// the throw keyword is used to throw an exception
// what does throwing an exception mean?
// it means that we are creating an error
// we can throw an exception if a certain condition occurs
// we can also throw an exception if a function returns an error or if a variable has an illegal value

const int MAX = 3;
// creating a stack class, which is properly handled
class stackException
{
public:
    virtual void print() = 0;
};
class stackFullException : public stackException
{
public:
    void print() { cout << "stack is full | stack overflow"; }
};
class stackEmptyException : public stackException
{
public:
    void print() { cout << "stack is empty | stack underflow"; }
};
class stack
{
    int st[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top >= MAX - 1)
        {
            throw stackFullException();
        }
        else
        {
            st[++top] = x;
        }
    }

    int pop()
    {
        int x;
        if (top < 0)
        {
            throw stackEmptyException();
        }
        else
        {
            int x = st[top--];
        }
        return x;
    }
};

int main()
{

    stack s;

    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);


        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
        cout << "popped element: " << s.pop() << endl;
    }
    //how to catch all exceptions
    catch (stackException &e)
    {
        e.print();
    }


    //inline throws
    // try{throw "\n\nbc\n\n";}
    // //how to catch this string
    // catch (const char *e)
    // {
    //     cout << e;
    // }

    //what are string literals, what is the difference between string literals and string objects
    // string literals are constant strings
    // string literals are stored in read only memory
    // string literals are stored in the .rodata section of the executable file
    // string literals are stored in the .text section of the executable file


    // string objects are stored in the .data section of the executable file
    // string objects are stored in the .bss section of the executable file

    //example:
    const char *s = "hello";
    // this is a string literal, it is immutable(unchangeable)
    //trying to change the value of s will result in an error
    // s[0] = 'a'; //error

    string s1 = "hello";
    // this is a string object, it is mutable(changeable)
    // trying to change the value of s1 will not result in an error
    s1[0] = 'a'; //no error

    // what is the ... operator
    // the ... operator is used to pass a variable number of arguments to a function
    // but how do we know how many arguments are passed to the function, and access them?
    // we can use the va_list, va_start, va_arg, and va_end macros to access the arguments passed to the function
    // the va_list macro is used to declare a variable that will hold the information about the arguments passed to the function
    // the va_start macro is used to initialize the variable declared with va_list to access the arguments passed to the function
    // the va_arg macro is used to access the arguments passed to the function
    // the va_end macro is used to clean up the variable used to access the arguments passed to the function
    //demonstration of the ... operator
    // void print(int n, ...)
    // {
    //     va_list valist;
    //     int i;
    //     va_start(valist, n);
    //     for (i = 0; i < n; i++)
    //     {
    //         cout << va_arg(valist, int) << " ";
    //     }
    //     va_end(valist);
    // }
    

    return 0;
}