#include <iostream>
using namespace std;

void primeNumbersFrom2ToN(int n)
{
    cout << "Prime Numbers from 2 to " << n << ": ";
    for (int conseqNumber = 2; conseqNumber < n; conseqNumber++)
    {
        bool isPrime = true;
        for (int prevNumber = (conseqNumber / 2) + 1; prevNumber > 1; prevNumber--)
        {
            if (conseqNumber % prevNumber == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true)
        {
            cout << conseqNumber << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n; cout << "N: "; cin >> n;
    primeNumbersFrom2ToN(n);
    return 0;
}