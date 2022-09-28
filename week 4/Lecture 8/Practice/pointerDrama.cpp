#include <iostream>
using namespace std;

//majazi length of array is a name we came up for a floating end of the set array.
//we will use this to keep track of the end of the array
//even though the array is static, we will be able to add and remove items from the array - total max elements 100

class SetFixedLength{
    int set[100];
    int* MajaziLengthOfArray;

public:
    //default constructor
    SetFixedLength(){
        MajaziLengthOfArray = &set[0];
    }
    //parameterized constructor
    SetFixedLength(int *setArray, int setArraySize){
        for(int i = 0; i < setArraySize; i++){
            set[i] = setArray[i];
        }
        MajaziLengthOfArray = &set[setArraySize];
    }   
    void printSet(){
        int *temp = &set[0];
        while(temp != MajaziLengthOfArray){
            cout << *temp << " ";
            temp++;
        }
        cout << endl;
    }


};

int main()
{


    int setArray[5] = {1,2,3,4,5};
    SetFixedLength set1(setArray, 5);

    set1.printSet();

    return 0;
}