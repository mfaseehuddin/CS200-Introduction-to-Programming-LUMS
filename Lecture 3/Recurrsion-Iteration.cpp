#include <iostream>
using namespace std;

// function prototypes
void reverseIntegerIteration(int inputNum);
void reverseIntegerRecursive(int currNum);
int FactorialRecursion(int inputNum, int total);

int main()
{
    reverseIntegerIteration(123456789);
    reverseIntegerRecursive(123456789);
    cout << endl;
    FactorialRecursion(5,1);
    return 0;
}

// example
// input an integer and print reversed
// iteration -- Anything involving repitition of steps
void reverseIntegerIteration(int inputNum)
{
    int currNum = inputNum;
    while (currNum > 0)
    {
        cout << currNum % 10;
        currNum /= 10;
    }
    cout << endl;
}

// recursion -- Calling a function within itself
void reverseIntegerRecursive(int currNum)
{
    if (currNum == 0)
        return;
    cout << currNum % 10;
    reverseIntegerRecursive(currNum / 10);
}

// call stack
//|---------------|
//|r = 0          |
//|currNum = 0    |reverseIntegerRecursive(0)
//|---------------|
//|r = 1          |
//|currNum = 1    |reverseIntegerRecursive(1)
//|---------------|
//|r = 3          |
//|currNum = 13   |reverseIntegerRecursive(13)
//|---------------|
//|r = 5          |
//|currNum = 135  |reverseIntegerRecursive(135)
//|---------------|
//|r = 7          |
//|currNum = 1357 |reverseIntegerRecursive(1357)
//|---------------|
//|               |main()
//|---------------|

int FactorialRecursion(int inputNum,int total)
{
    if(inputNum == 1){return 1;}
    cout << total << endl;
    total = inputNum * FactorialRecursion(inputNum-1, total);
    
}