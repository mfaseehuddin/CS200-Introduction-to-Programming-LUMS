#include <iostream>
using namespace std;

//reverse arr by take the address and size of the array
void reverseArr(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}



int main()
{
    const int size = 10;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    reverseArr(arr, size);
    
    //print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}