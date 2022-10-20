#include <iostream>
using namespace std;
int N = 4;
void rotate90Clockwise(int **arr)
{
    //rotate arr 90 degrees clockwise
    int **temp = new int *[N];
    for (int i = 0; i < N; i++)
    {
        temp[i] = new int[N];
    }

    //copy arr to temp in rotated order
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            temp[row][col] = arr[N - 1 - col][row];
        }
    }
    

    //copy temp back to arr
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            arr[row][col] = temp[row][col];
        }
    }

    //delete temp array
    for (int i = 0; i < N; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
    

    cout << "Rotated Array will be :" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int **arr;
    int count = 0;
    arr = new int *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = ++count;
        }
    }
    rotate90Clockwise(arr);
    rotate90Clockwise(arr); // now rotating gain return 0;
}