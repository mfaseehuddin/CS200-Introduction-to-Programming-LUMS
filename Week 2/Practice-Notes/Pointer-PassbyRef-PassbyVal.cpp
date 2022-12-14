#include <iostream>
using namespace std;

void passByReferenceVariableValueSquaring(int &x) {
    x = x * x;
}
void passByValueVariableValueSquaring(int x) {
    x = x * x;
}

void passByReferencePointerValueSquaring(int *x) {
    *x = *x * *x;
}

int main()
{
    // Pass by Reference
        int a = 5;
        passByReferenceVariableValueSquaring(a);
        cout << a << endl;
        // You should notice we declare the value of the integer as 5, and then we pass the address of the variable to the function.
        // The function will then change the value of the variable to 25, and then we print the value of the variable.
        // The value of the variable is changed because we passed the address of the variable to the function.

    // Pass by Value
        int b = 5;
        passByValueVariableValueSquaring(b);
        cout << b << endl;
        // You should notice we declare the value of the integer as 5, and then we pass the value of the variable to the function.
        // The function will then make a copy of the value of the variable's value, and then change the value of the copy to 25.
        //However, the value change will not be reflected in the original variable, because we passed the value of the variable to the function.
        //Hence, to use the value generated by the function, we need an integer return function, that shall return the change value.
        //Then, we can assign the returned value to the original variable.

    //Pointers
        //Pointers, are basically variables that store the address of another variable.
        //Those addresses can then be passed around to change the value of the orignal variable.
        //Pointers are declared using the * symbol.
        //The address of a variable can be obtained using the & symbol.
        //The value of a variable can be obtained using the * symbol. This is called dereferencing.
        //Pointers can be passed to functions, and the function can then change the value of the original variable.
        //The value of a pointer can be changed using the = symbol.
            //Changing pointers is not recommended, because it can cause memory leaks.
            //Memory leaks are when the memory allocated to a variable is not freed, and is instead left to be used by other variables.
            //This can cause the program to crash, because the memory allocated to the variable is not enough to store the value of the variable.
            //To avoid memory leaks, we need to free the memory allocated to the variable, using the delete keyword.
            //However, iterating i.e: incrementing pointers can be done for iteratable abstract data types, such as arrays.
        //Basic Pointers example
            int num = 100;
            int *pointerToNum = &num;
            cout << "The value of num is: " << num << endl;
            cout << "The address of num is: " << &num << endl;
            cout << "The value of pointerToNum is: " << pointerToNum << endl;
            cout << "The address of pointerToNum is: " << &pointerToNum << endl;
            //Now we can increment the value of num, by using the pointer, as follows
                *pointerToNum = *pointerToNum + 1;
                cout << "The value of num is: " << num << endl;
            //We can also change the value of the pointer, as follows
                pointerToNum = &a;
            //However, in this case this is not useful, so we are going to change it back
                pointerToNum = &num;

            //Passing pointers to functions
            //Passing pointers to functions is similar to passing variables to functions.
                passByReferencePointerValueSquaring(pointerToNum);
                cout << "The value of num is: " << num << endl;

            //pointers for arrays
                //Arrays are basically a collection of variables that are stored in a contiguous memory location.
                //The address of the first element of the array can be obtained using the & symbol.
                //However, the identifier of the array, is actually the address of the first element of the array.
                //Hence, we can use the identifier of the array, to access the elements of the array, and pass that to a function.

    return 0;
}