#include <iostream>
using namespace std;

int y;

void p(int x){
    x = y - 1;
    y += ++y * (x--);
    cout << x << " " << y << endl;
    if(x<2)
        p(--x+2);
    cout << x << " " << y << endl;
}


int main()
{
    int x = 1, y = 2;
    p(x++*--x/++x);
    cout << x << " " << y << endl;

    return 0;
}