#include <iostream>
using namespace std;

void recursiveHailStoneSequence(int n){
    if (n == 1) {
        cout << n << " " << endl;
        return;
    }
    cout << n << " " << endl;
    if (n % 2 == 0) {
        recursiveHailStoneSequence(n / 2);
    } else {
        recursiveHailStoneSequence((3 * n) + 1);
    }
}

int main()
{
    int n = 0; cout << "n: "; cin >> n;
    recursiveHailStoneSequence(n);
    return 0;
}