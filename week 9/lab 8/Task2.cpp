#include <iostream>
using namespace std;


void SortArray(int* Array1D, int l){
    int temp;
    for (int i = 0; i < l; i++){//traverse through the array
        for (int j = 0; j < l; j++){//traverse through remaining array
            if (Array1D[i] < Array1D[j]){
                //swap if the current element is less than the next element
                temp = Array1D[i];
                Array1D[i] = Array1D[j];
                Array1D[j] = temp;
            }
        }
    }
}

int ArraySum(int* Array1D, int l){
    int sum = 0;
    for (int i = 0; i < l; i++){
        sum += Array1D[i];
    }
    return sum;
}

void SumSort(int** Array2D, int rows, int cols){
    //sort internal arrays
    for (int row = 0; row < rows; row++){
        SortArray(Array2D[row], cols);
    }
    //sort rows based on sum
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            if(ArraySum(Array2D[i], cols) < ArraySum(Array2D[j], cols)){
                int* temp = Array2D[i];
                Array2D[i] = Array2D[j];
                Array2D[j] = temp;
            }
        }
    }


}

void print2DArray(int** Array2D, int rows, int col){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < col; j++){
            cout << Array2D[i][j] << " ";
        }
        cout << endl;
    }
}


// int main()
// {
//     int a[3][3] = {{45,11,2},{7,3,6},{12,0,1}};
//     int** b = new int*[3];
//     for (int i = 0; i < 3; i++){
//         b[i] = new int[3];
//         for (int j = 0; j < 3; j++){
//             b[i][j] = a[i][j];
//         }
//     }
//     SumSort(b, 3, 3);
//     print2DArray(b, 3, 3);
//     cout << endl;


//     return 0;
// }