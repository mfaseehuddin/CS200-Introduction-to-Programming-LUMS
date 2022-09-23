#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    {
        int x = 5;
        cout << "a: " << a << endl;
        cout << "x: "<< x << endl;
    }
    cout << "a: " << a << endl;
    cout << "x: "<< x << endl; // this line will cause an error, because x is out of scope

    return 0;
}