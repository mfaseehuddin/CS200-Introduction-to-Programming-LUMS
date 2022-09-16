#include <iostream>
using namespace std;

void populateMatrixUserInput(int matrix[][2], int r, int c)
{
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            cout << "Matrix[" << row << "][" << col << "]: ";
            cin >> matrix[row][col];
        }
    }
}

void printMatrix(int matrix[][2], int r, int c){
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int matrix1[][2], int matrix2[][2], int result[][2], int r, int c)
{
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            result[row][col] = 0;
            for (int i = 0; i < c; i++)
            {
                result[row][col] += matrix1[row][i] * matrix2[i][col];
            }
        }
    }
}

int main()
{

    //create 2D Matrices
    int matrix1[2][2];
    int matrix2[2][2];
    //populate matrices with user input
    cout << "Enter values for Matrix 1" << endl;
    populateMatrixUserInput(matrix1, 2,2);
    cout << "Enter values for Matrix 2" << endl;
    populateMatrixUserInput(matrix2, 2,2);
    //print matrices
    cout << "Matrix 1" << endl;
    printMatrix(matrix1, 2,2);
    cout << "Matrix 2" << endl;
    printMatrix(matrix2, 2,2);

    int resultMatrix[2][2];
    multiplyMatrices(matrix1, matrix2, resultMatrix, 2,2); 
    cout << "Result Matrix:" << endl;
    printMatrix(resultMatrix, 2,2);  
}