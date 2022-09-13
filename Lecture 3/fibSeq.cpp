#include <iostream>
using namespace std;

void fibSeq(int limit, int start);

int main()
{

    return 0;
}

void fibSeq(int limit, int start){
    int currNum = start;
    if(currNum == 0){
        cout << currNum << " ";
        currNum++;
        cout << currNum << " ";
    }
}