#include <iostream>
using namespace std;

int recursiveFibonacciSequence(int startIndex, int targetIndex, int currentIndex, int previousNumber, int currentNumber)
{
    if (currentIndex == targetIndex)
    {
        return previousNumber;
    }
    else
    {
        int nextNumber = previousNumber + currentNumber;
        previousNumber = currentNumber;
        currentNumber = nextNumber;
        currentIndex++;
        return recursiveFibonacciSequence(startIndex, targetIndex, currentIndex, previousNumber, currentNumber);
    }
}

int main()
{
    int targetIndex; cout << "Target Index: "; cin >> targetIndex;
    int fibonacciNumber = recursiveFibonacciSequence(1, targetIndex, 0, 0, 1);
    cout << "Target Index N: " << targetIndex << ", Fibonacci Number: " << fibonacciNumber << endl;
    return 0;
}