#include <iostream>
using namespace std;


int factorial(int num){
    if (num == 1){return 1;}
    return num * factorial(num-1);
}

string binary(string num){

    if(stoi(num) == 0){
        return "";
    }
    string currentBin = to_string(stoi(num) % 2);
    return binary(to_string(stoi(num)/2)) + currentBin;

}

void hailstone(int num, int count){
    if(num == 1){
        cout << " 1" << endl;
        cout << "Steps: " << count+1 << endl;
        return;
    }

    cout << " " << num << " ";
    (num % 2 == 0) ? hailstone(num/2, ++count) : hailstone((3*num)+1, ++count);
}

int main()
{
    int factorialNum = 10;
    cout << "factorial(" << factorialNum << "): "<<  factorial(5) << endl;


    int binaryNum = 100;
    cout << binaryNum << " in binary: " << binary(to_string(binaryNum)) << endl;

    int hailstoneNum = 69;
    cout << "Hailstone from " << hailstoneNum << " :";
    hailstone(hailstoneNum, 0);

    return 0;
}