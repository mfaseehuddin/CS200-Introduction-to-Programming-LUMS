#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Task2.cpp"

using namespace std;

/* Write a test file that tests a function called SumSort. SumSort has three parameters:
a pointer-to-pointer to int (int**), which basically means a 2D array,
the number of rows
the number of columns

Your test should test that the function should first sort the internal 1D arrays based on ascending order. [15 Marks]
Secondly, it should test that the function sorts the 1D arrays so that the smallest sum array is the first array, and so on. [15 Marks]
*/

int SCORE = 0;

void SumSort(int **arr, int rows, int cols);

int main()
{

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);

    system("cls");
    system("Color 07");
#elif __linux__
    system("clear");
#elif __APPLE__
    system("clear");
#endif

    int rows = 3;
    int cols = 3;

    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    arr[0][0] = 45;
    arr[0][1] = 11;
    arr[0][2] = 2;
    arr[1][0] = 7;
    arr[1][1] = 3;
    arr[1][2] = 6;
    arr[2][0] = 12;
    arr[2][1] = 0;
    arr[2][2] = 1;

    int result[3][3] = {{2, 11, 45}, {3, 6, 7}, {0, 1, 12}};  // Sorted 1D arrays based on ascending order, but not sorted based on sum
    int result2[3][3] = {{0, 1, 12}, {3, 6, 7}, {2, 11, 45}}; // This is the result after sorting the 1D arrays so that the smallest sum array is the first array, and so on.
    int result3[3][3] = {{12, 0, 1}, {7, 3, 6}, {45, 11, 2}}; // Sorted by sum, but not by ascending order

    SumSort(arr, rows, cols);

    // Test 1: Sort the 1D arrays so that the smallest sum array is the first array, and so on.
    bool test2 = true;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != result2[i][j])
            {
                test2 = false;
            }
        }
    }

    cout << "Test 1: Sorted 1D Array and Sorted 2D Array\n";

    if (test2)
    {
        cout << "\033[1;32m";
        cout << "Test 1: PASS \u2713" << endl;
        cout << "\033[0m";
        SCORE += 30;
    }
    else
    {
        cout << "\033[1;31m";
        cout << "Test 1: FAIL \u2716" << endl;
        cout << "\033[0m";

        // Test 2: Sort the internal 1D arrays based on ascending order
        bool test1 = true;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] != result[i][j])
                {
                    test1 = false;
                }
            }
        }

        cout << "Test 2: Sorted 1D Array, but not Sorted 2D Array\n";

        if (test1)
        {
            cout << "\033[1;32m";
            cout << "Test 2: PASS \u2713" << endl;
            cout << "\033[0m";
            SCORE += 15;
        }
        else
        {
            cout << "\033[1;31m";
            cout << "Test 2: FAIL \u2716" << endl;
            cout << "\033[0m";

            // Test 3: Sorted by sum, but not by ascending order
            bool test3 = true;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (arr[i][j] != result3[i][j])
                    {
                        test3 = false;
                    }
                }
            }

            cout << "Test 3: Sorted by sum, but not by ascending order\n";

            if (test3)
            {
                cout << "\033[1;32m";
                cout << "Test 3: PASS \u2713" << endl;
                cout << "\033[0m";
                SCORE += 15;
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test 3: FAIL \u2716" << endl;
                cout << "\033[0m";
            }
        }
    }

    if (SCORE == 30)
    {
        cout << "\033[1;32m";
        cout << "Total Score: " << SCORE << endl;
        cout << "\033[0m";
    }
    else
    {
        cout << "\033[1;31m";
        cout << "Total Score: " << SCORE << endl;
        cout << "\033[0m";
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
