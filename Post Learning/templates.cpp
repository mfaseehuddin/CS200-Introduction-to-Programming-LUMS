#include <iostream>
using namespace std;

// make a templated class
template <class a, class b>
class calculator
{
private:
    a num1;
    b num2;

public:
    calculator(a num1, b num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }

    a add()
    {
        return num1 + num2;
    }
};

class vector2D
{
private:
    int x;
    int y;

public:
    // default constructor
    vector2D()
    {
        x = 0;
        y = 0;
    }

    vector2D(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    vector2D operator+(vector2D &v)
    {
        vector2D temp(0, 0);
        temp.x = this->x + v.x;
        temp.y = this->y + v.y;
        return temp;
    }

    // overloading the = operator
    void operator=(vector2D &v)
    {
        this->x = v.x;
        this->y = v.y;
    }

    // overload cout
    friend ostream &operator<<(ostream &output, const vector2D &v)
    {
        output << "x: " << v.x << " y: " << v.y << endl;
        return output;
    }
};

int main()
{
    vector2D v1(1, 2);
    vector2D v2(3, 4);

    calculator<vector2D, vector2D> calc(v1, v2);
    cout << calc.add() << endl;

    return 0;
}