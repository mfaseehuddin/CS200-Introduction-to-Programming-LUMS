#include <iostream>
using namespace std;

// recursive binary search
    //binary search is an algorithm that searches a sorted array by repeatedly dividing the search interval in half.
    //a recursive implementation of binary search, provides us with a more elegant solution to the problem.
    //the recursive implementation of binary search is much easier to understand and implement than the iterative implementation.
        //However, the recurvisive implementation of binary search is not as efficient as the iterative implementation.
        //The recursive implementation of binary search requires a function call for each element in the array. Hence, it leads to a stack overflow if the array is too large.
        //The iterative implementation of binary search requires only one function call.
            //what is life? *a stack overflow.* 
                //suggested by github copilot, aah man, i love github copilot
                //copilot
int recursiveBinarySearch(int targetNumber){
    
}
int recursiveBinarySearch(int targetNumber, int arr[], int start, int end)
{
    //base case
    if (start > end) 
        return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == targetNumber)
        return mid;
    else if (arr[mid] > targetNumber)
        return recursiveBinarySearch(targetNumber, arr, start, mid - 1);
    else
        return recursiveBinarySearch(targetNumber, arr, mid + 1, end);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetNumber = 2;
    
    int index = recursiveBinarySearch(targetNumber, arr, 0, size - 1);
    cout << index;

    return 0;
}
