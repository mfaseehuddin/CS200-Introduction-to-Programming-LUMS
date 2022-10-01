#include <iostream>

using namespace std;

void sortArray(int *, int);
int search(int *, int, int);
void printArray(int *, int);
void recursiveBubbleSort(int *arr, int effectiveSize, int currentIndex);
int recursiveBinarySearch(int *arr, int size, int num, int start, int end);

int main(int argc, char **argv)
{
    int size = stoi(argv[1]); // size is the length of the array
    int n = stoi(argv[2]);    // n is the number we have to search
    int *arr = new int[size]; // create a dynamic array in the heap

    /* Write code to fill in that array with numbers from the command line */
    /* The numbers the should be in the array can be accessed as argv[3], argv[4] and so on */
    /* Make sure you convert them to integers using stoi() */
    /* You can assume that the array will have atleast 2 numbers */
    // YOU CODE HERE

    // argv[0] is file name
    // argv[1] is array size
    // argv[2] is search number
    // argv[3...] is array elements

    // numbers from the command line being added to the array using pointer notation
    int arrayDataArgvIndex = 3;
    for (int i = arrayDataArgvIndex; i < size + arrayDataArgvIndex; i++)
    {
        *(arr + (i - arrayDataArgvIndex)) = stoi(*(argv + i));
    }

    printArray(arr, size); // print the generated array
    sortArray(arr, size);  // call the sort function
    printArray(arr, size); // print the sorted array

    int searchResult = search(arr, size, n); // call the search function
    cout << "The result of the search is: " << searchResult << endl;
    delete[] arr; // free up memory
    return 0;
}

void sortArray(int *arr, int size)
{
    // call the recursive bubble sort function 
    //allowed asked from saad
    recursiveBubbleSort(arr, size, 0);
}

void recursiveBubbleSort(int *arr, int effectiveSize, int currentIndex)
{
    //recursively bubble sort the array using pointer notation
    if (currentIndex < effectiveSize - 1)
    {
        if (*(arr + currentIndex) > *(arr + currentIndex + 1))
        {
            int temp = *(arr + currentIndex);
            *(arr + currentIndex) = *(arr + currentIndex + 1);
            *(arr + currentIndex + 1) = temp;
        }
        recursiveBubbleSort(arr, effectiveSize, currentIndex + 1);
    }
    else
    {
        if (effectiveSize > 1)
        {
            recursiveBubbleSort(arr, effectiveSize - 1, 0);
        }
        //base case
        else
        {
            return;
        }
    }
}

int search(int *arr, int size, int num)
{
    /*
        Use recursion to find the number (num) in the given array (arr)
        You may create a helper function
        If that number is not in the array return 200
        If you find that number, return that number
    */
    // YOUR CODE HERE
    // recursive binary array search
    // will create helper function, as more parameters are required for a recursive binary search
    return recursiveBinarySearch(arr, size, num, 0, size - 1);
}
int recursiveBinarySearch(int *arr, int size, int num, int start, int end)
{
    if (start > end)
    {
        return 200;
    }
    else
    {
        int mid = (start + end) / 2;
        if (*(arr + mid) == num)
        {
            return *(arr + mid);
        }
        else if (*(arr + mid) > num)
        {
            return recursiveBinarySearch(arr, size, num, start, mid - 1);
        }
        else
        {
            return recursiveBinarySearch(arr, size, num, mid + 1, end);
        }
    }
}
void printArray(int *arr, int size)
{
    /* This function is used to print the array */
    cout << "The array is: [";
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1] << "]" << endl;
}