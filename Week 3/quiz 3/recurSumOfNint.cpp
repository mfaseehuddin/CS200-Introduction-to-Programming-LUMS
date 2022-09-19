#include <iostream>
using namespace std;

int recurSumOfN(int n) {
    if (n == 1) {
        return 1;
    }
    cout << "current Number: " << n << endl;
    return n + recurSumOfN(n - 1);
}

int main()
{
    int n = 0; cin >> n;
    cout << "recursive sum of 1-n integers: " << recurSumOfN(n) << endl;
    return 0;
}