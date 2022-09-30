#include <iostream>
using namespace std;


void recur(int n){
    if(n==1){
        cout << "bc" << endl;
    }else{
        recur(n-1);
        cout << "nc" << endl;
        recur(n-1);
    }
}


int main()
{
    recur(3);
    return 0;
}