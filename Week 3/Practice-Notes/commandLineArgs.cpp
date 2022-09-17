#include <iostream>
using namespace std;

//to run the program, first compile it, then run it with command line arguments in the following way
    //open a command prompt termainal window where the code was compiled to
    //type the name of the executable file followed by the command line arguments i.e: ./a 1 2 3 4 5
    //this program will print out the number of command line arguments and the arguments themselves
    //then if the first argument is hello, it will print out hello world
    //else if it is loop followed by a number, it will print looping that number of times 

int main(int argc, char **argv)
{
    // argc is an integer variable that stores the number of arguments passed to the program
    // argv is an array of character pointers that stores the arguments passed to the program
    // argv[0] is the name of the program
    // argv[1] is the first argument & so on
    // passing arguments to a program is optional, however it can allow you to customize the program flow
    // for example, you can pass a file name to a program to open that file
    // or you can pass a number to a program to change the number of times it loops
    // or you can pass a string,float,bool,char,... to a program to change the string it prints

    // sample program that performs different actions based on the arguments passed to it
    // the program will print the number of arguments passed to it
    // if the first argument is "hello", it will print "hello world"
    // if the first argument is "loop", it will print "looping" the number of times specified by the second argument

    cout << "Number of arguments: " << argc << endl;
    // print all the arguments using pointer notation
    for (int i = 0; i < argc; i++)
    {
        cout << *(argv + i) << endl;
    }
    //checking if arguments were passed, else running code below will result in a segmentation fault
    if (argc > 1)
    {
        // print hellow world if the first argument is "hello"
        //stcmp function is used to compare two strings, because argv is an array of character pointers and not a string
        //using == to compare two strings will not work, and will result in a compiler error
        if (strcmp(*(argv + 1), "hello") == 0)
        {
            cout << "hello world" << endl;
        }
        // print looping the number of times specified by the second argument if the first argument is "loop"
        if (strcmp(*(argv + 1), "loop") == 0)
        {
            for (int i = 0; i < atoi(*(argv + 2)); i++)
            {
                cout << "looping" << endl;
            }
        }
    }

    return 0;
}