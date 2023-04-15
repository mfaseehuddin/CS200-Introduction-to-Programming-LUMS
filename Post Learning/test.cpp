#include <iostream>
#include "funcs.cpp"
using namespace std;




void addNumberToArray (int*& myArray, int& size){
    if(myArray == nullptr){
        myArray = new int[1];
        myArray[0] = size;
        size = 1;
    }
    else{
        int* temp = new int[size + 1];
        for(int i = 0; i < size; i++){
            temp[i] = myArray[i];
        }
        temp[size] = size;
        delete[] myArray;
        myArray = temp;
        size++;
    }
}


int main()
{
    int* myArray = nullptr;
    int size = 0;

    addNumberToArray(myArray, size);
    addNumberToArray(myArray, size);
    addNumberToArray(myArray, size);
    addNumberToArray(myArray, size);
    addNumberToArray(myArray, size);

    //print the array
    for(int i = 0; i < size; i++){
        cout << myArray[i] << endl;
    }


    test();

    return 0;
}