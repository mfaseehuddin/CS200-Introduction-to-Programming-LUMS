#include <iostream>
using namespace std;

//class topic: dynamic 2D arrays


int main()
{

    //dyanmic 2D arrays are a runtime allocation of memory
    //to have a dynamic 2D array, we need to have a pointer to a pointer
    int** array2D;
    //for 2 rows and 3 columns
    int rows = 2;
    int cols = 3;
    //now we allocate the memory for the rows
    array2D = new int *[rows];
    //now we allocate the memory for the columns, for each row
    for (int i = 0; i < rows; i++)
    {
        array2D[i] = new int[cols];
    }

    //lets input some values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int value; cout << "Enter Element[" << i << "][" << j << "]: "; cin >> value;
            array2D[i][j] = value;
        }
    }

    //lets print the values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    //now we need to free the memory
    //first we free the memory for the columns
    for (int i = 0; i < rows; i++)
    {
        delete[] array2D[i];
    }
    //then we free the memory for the rows
    delete[] array2D;

    return 0;
}