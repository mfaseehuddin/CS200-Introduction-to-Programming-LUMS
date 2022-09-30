#include <iostream>
using namespace std;

struct RationalNumber {
    int p;
    int q;
};

RationalNumber Reduce(RationalNumber &a){
    int p = a.p;
    int q = a.q;
    int greatestCommonDivisor = 1;
    for(int i = 1; i <= p && i <= q; i++){
        if(p % i == 0 && q % i == 0){
            greatestCommonDivisor = i;
        }
    }
    a.p = p / greatestCommonDivisor;
    a.q = q / greatestCommonDivisor;
    return a;
}

RationalNumber Add(RationalNumber &a, RationalNumber &b){
    RationalNumber c;
    c.p = (a.p * b.q) + (b.p * a.q);
    c.q = a.q * b.q;
    return Reduce(c);
}

RationalNumber Subtract(RationalNumber &a, RationalNumber &b){
    RationalNumber c;
    c.p = (a.p * b.q) - (b.p * a.q);
    c.q = a.q * b.q;
    return Reduce(c);
}

RationalNumber Multiply(RationalNumber &a, RationalNumber &b){
    RationalNumber c;
    c.p = a.p * b.p;
    c.q = a.q * b.q;
    return Reduce(c);
}

RationalNumber Divide(RationalNumber &a, RationalNumber &b){
    RationalNumber c;
    c.p = a.p * b.q;
    c.q = a.q * b.p;
    return Reduce(c);
}

int Compare(RationalNumber &a, RationalNumber &b){
    RationalNumber c = Subtract(a, b);
    if(c.p > 0){
        return 1;
    } else if(c.p < 0){
        return -1;
    } else {
        return 0;
    }
}

int main()
{

    //testing the functions
    RationalNumber a;
    a.p = 10;
    a.q = 200;
    RationalNumber b;
    b.p = 1;
    b.q = 30;

    //testing the reduce function
    cout << "Reduced: " << Reduce(a).p << "/" << Reduce(a).q << endl;

    //testing the add function
    cout << "Add: " << Add(a, b).p << "/" << Add(a, b).q << endl;

    //testing the subtract function
    cout << "Subtract: " << Subtract(a, b).p << "/" << Subtract(a, b).q << endl;

    //testing the multiply function
    cout << "Multiply: " << Multiply(a, b).p << "/" << Multiply(a, b).q << endl;

    //testing the divide function
    cout << "Divide: " << Divide(a, b).p << "/" << Divide(a, b).q << endl;

    //testing the compare function
    cout << "Compare: " << Compare(a, b) << endl;


    return 0;
}