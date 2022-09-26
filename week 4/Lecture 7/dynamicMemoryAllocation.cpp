#include <iostream>
using namespace std;

//class topic: dynamic memory allocation
/*
    In c++ we have 2 types of memory allocation
    1. static memory allocation ->
        this is done by the compiler, when the program is compiled, the compiler allocates memory for the variables
        this memory is allocated in the stack
        the memory is allocated at compile time
    2. dynamic memory allocation ->
        is done by the programmer, when the program is running, the programmer allocates memory for the variables
        this memory is allocated in the heap ->
            heap is a part of the memory that is not managed by the compiler
            it is also called free store because the memory is free to be used by the programmer
            the memory is allocated on the heap at run time
            the programmer has to deallocate the memory when it is no longer needed - memory management in c++ is quite difficult and error prone
        
        in c++ we can allocate memory using the following syntax
            type *pointerName = new type;
            type *pointerName = new type[size];
            type *pointerName = new type[size1][size2];
            type *pointerName = new type[size1][size2]...[sizeN];
            
        the dynamically allocated variables can be accessed using the pointer -- using the dereference operator i.e: pointer notation
        the memory allocated using new is not initialized, and will not be deallocated automatically

        To deallocate the memory we use the delete operator
        delete pointerName;
        delete [] pointerName;


        important points:
            - the size of the heap is limited - it is not as big as the stack
            - the memory allocated in the heap is not managed by the compiler
            - the memory allocated in the heap is not initialized
            - the memory allocated in the heap is not deallocated automatically

            garbage collection in c++
            garbage collection is a process of finding and freeing the memory that is no longer used by the program
            garbage collection is done by the compiler automatically at run time
*/


//class definition: date
class date
{
    private:
        int day;
        int month;
        int year;
    public:
        //default constructor
        date()
        {
            day = 1;
            month = 1;
            year = 1900;
        }
        //parameterized constructor
        date(int day, int month, int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void print()
        {
            cout << day << "/" << month << "/" << year << endl;
        }

        //destructor
        ~date()
        {
            cout << "destructor called on date: ";
            print();
            cout << endl;
        }
};






// in the main we have a example of dynamic memory allocation


int main()
{
    //example of dynamic memory allocation

    int *p = new int;
        //explaination:
            //int *p - p is a pointer to an integer
            // new int - the memory is allocated for an integer - the new keyword returns the address of the allocated memory
            // the address of the allocated memory is assigned to the pointer p
    
    *p = 10;
        //explaination:
            //the value 10 is assigned to the memory pointed to by p
            //the value is assigned using the pointer notation
    cout << *p << endl;
        //explaination:
            //the value pointed to by p is printed
            //the value is printed using the pointer notation
    delete p;
        //explaination:
            //the memory pointed to by p is deallocated
            //the memory is deallocated using the delete operator

    //dynamic memory allocation for arrays
    int *p1 = new int[10];
        //explaination:
            //int *p1 - p1 is a pointer to an integer
            // new int[10] - the memory is allocated for an array of 10 integers - the new keyword returns the address of the allocated memory
            // the address of the allocated memory is assigned to the pointer p1
    for(int i = 0; i < 10; i++)
    {
        p1[i] = i;
    }
        //explaination:
            //the values 0,..., 9 are assigned to the memory pointed to by p1 using pointer notation
    for(int i = 0; i < 10; i++)
    {
        cout << p1[i] << " ";
    }
        //explaination:
            //the values pointed to by p1 are printed using pointer notation
    cout <<  endl;
    delete [] p1;
        //explaination:
            //the memory pointed to by p1 is deallocated
            //the memory is deallocated using the delete operator
            //the delete operator is used with the [] operator when the memory allocated is an array

            //how the delete [] finds the length of array it is deleting:
                //the delete [] operator finds the length of the array it is deleting by looking at the first 4 bytes of the memory it is deleting
                //the first 4 bytes of the memory it is deleting are the size of the array
                //the delete [] operator uses this information to find the length of the array it is deleting
                //however this varies from compiler to compiler -- and is not a standard, which is pure evil




    //dynamic memory allocation for class objects
    date *d = new date;
        //explaination:
            //date *d - d is a pointer to a date object
            // new date - the memory is allocated for a date object - the new keyword returns the address of the allocated memory
            // the address of the allocated memory is assigned to the pointer d
    d->print();
        //explaination:
            //the date object pointed to by d is printed using pointer notation
            //over here d.print() will not work because the print function is not a member of the pointer d, but of the object pointed to by d
            //however: (*d).print() will work


    return 0;
}


