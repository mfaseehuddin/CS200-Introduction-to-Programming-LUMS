#include <iostream>
using namespace std;


void printnDArray(int* arrayHead, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(arrayHead + i * col + j) << " ";
        }
        cout << endl;
    }
}



int main()
{
    int r = 4;
    int c = 5;

    int** array = new int*[r];


    
    for(int i = 0; i < r; i++){
        array[i] = new int[c];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            array[i][j] = 0;
        }
    }
        
    cout << (*(array + 0)) << endl;

    printnDArray(*array, r, c);




    return 0;
}

