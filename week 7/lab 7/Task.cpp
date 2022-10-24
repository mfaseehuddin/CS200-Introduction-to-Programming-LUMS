#include <iostream>
using namespace std;

class Polynomial;

class PolyTerm
{
private:
    int coef;
    int exp;

public:
    PolyTerm(int c, int e)
    {
        coef = c;
        exp = e;
    }

    int getCoef()
    {
        return coef;
    }

    int getExp()
    {
        return exp;
    }

    void setCoef(int c)
    {
        coef = c;
    }

    void setExp(int e)
    {
        exp = e;
    }

    PolyTerm *operator+(PolyTerm &p)
    {
        if (exp == p.exp)
        {
            return new PolyTerm(coef + p.coef, exp);
        }
        else
        {
            return nullptr;
        }
    }

    PolyTerm *operator-(PolyTerm &p)
    {
        if (exp == p.exp)
        {
            return new PolyTerm(coef - p.coef, exp);
        }
        else
        {
            return nullptr;
        }
    }

    PolyTerm *operator*(PolyTerm &p)
    {
        return new PolyTerm(coef * p.coef, exp + p.exp);
    }

    friend ostream &operator<<(ostream &out, PolyTerm &p)
    {
        p.exp == 0 ? out << p.coef : out << p.coef << "x^" << p.exp;
        return out;
    }
};

class Polynomial
{
private:
    PolyTerm **poly;
    int size;
    int lowestExp;

public:
    Polynomial()
    {
        poly = nullptr;
        size = 0;
        lowestExp = 0;
    }

    Polynomial(PolyTerm **terms, int newSize, int newlowestExp)
    {
        size = newSize;
        lowestExp = newlowestExp;
        poly = new PolyTerm *[size];
        // deep CAPY
        for (int i = 0; i < size; i++)
        {
            poly[i] = terms[i];
        }
    }

    Polynomial(int newSize)
    {
        size = newSize;
        poly = new PolyTerm *[size];
        lowestExp = 0;
    }

    Polynomial(Polynomial &pc)
    {
        size = pc.size;
        lowestExp = pc.lowestExp;
        poly = new PolyTerm *[size];
        // deep CAPY by creating new stuff so it is cute cute
        for (int i = 0; i < size; i++)
        {
            poly[i] = new PolyTerm(*pc.poly[i]);
        }
    }

    Polynomial operator=(Polynomial pa)
    {
        size = pa.size;
        lowestExp = pa.lowestExp;
        poly = new PolyTerm *[size];
        // full shystem deep copy
        for (int i = 0; i < size; i++)
        {
            poly[i] = new PolyTerm(*pa.poly[i]);
        }
        return *this;
    }

    ~Polynomial()
    {
        for (int i = 0; i < size; i++)
        {
            delete poly[i];
        }
        delete[] poly;
    }

    friend istream &operator>>(istream &in, Polynomial &p)
    {
        int c, e;
        bool exit = false;

        while (!exit)
        {
            cout << "Enter coefficient: ";
            in >> c;
            cout << "Enter exponent: ";
            in >> e;
            p.size++;

            if (p.size == 1)
            {
                p.lowestExp = e;
                p.poly = new PolyTerm *[p.size];
                p.poly[p.size - 1] = new PolyTerm(c, e);
            }
            else if (p.size > 1 && e < p.lowestExp)
            {
                PolyTerm **temp = new PolyTerm *[p.size];
                for (int i = 0; i < p.size - 1; i++)
                {
                    temp[i] = p.poly[i];
                }
                temp[p.size - 1] = new PolyTerm(c, e);
                delete[] p.poly;
                p.poly = temp;
            }
            else if (p.size > 1 && e >= p.lowestExp)
            {
                cout << "Invalid Exponent enter exp lower than " << p.lowestExp << endl;
            }
            cout << "Do you want to enter more terms? 1:Yes, 0:No \n";
            cin >> exit;
            exit = !exit;
        }

        return in;
    }

    friend ostream &operator<<(ostream &out, Polynomial p)
    {
        for (int i = 0; i < p.size; i++)
        {
            cout << "+" << *(p.poly[i]) << " ";
        }
        cout << "\b\n";
        return out;
    }

    // overload the + operator
    Polynomial operator+(Polynomial &p2a)
    {
        Polynomial *longerPoly = size > p2a.size ? this : &p2a;
        Polynomial *shorterPoly = size > p2a.size ? &p2a : this;

        Polynomial newPoly;

        for (int bigPoly = 0; bigPoly < longerPoly->size; bigPoly++)
        {
            PolyTerm *newTerm = nullptr;
            for (int smallPoly = 0; smallPoly < shorterPoly->size; smallPoly++)
            {
                newTerm = *longerPoly->poly[bigPoly] + *shorterPoly->poly[smallPoly];
                if (newTerm != nullptr)
                {
                    newPoly.poly[bigPoly] = newTerm;
                    break;
                }
            }
            if (newTerm == nullptr)
            {
                *newTerm = *longerPoly->poly[bigPoly];
                newPoly.poly[bigPoly] = newTerm;
            }
        }
        return newPoly;
    }
};

int main()
{
    Polynomial p1, p2, p3;

    cin >> p1;
    cout << p1;

    cin >> p3;
    cout << p3;

    // assignment operator works
    //  p2 = p1;
    //  cout << p2;

    // copy constructor works
    //  Polynomial p3(p1);
    //  cout << p3;


    cout << p1 + p3;


    return 0;
}