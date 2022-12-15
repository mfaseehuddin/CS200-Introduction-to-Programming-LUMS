#include <iostream>
using namespace std;

class Integer
{
private:
    int num;

public:
    Integer(int num)
    {
        this->num = num;
    }
    // getter
    int getNum()
    {
        return num;
    }
    // setter
    void setNum(int num)
    {
        this->num = num;
    }

    // virtual add, subtract, multiply
    virtual void add(Integer *i)
    {
        this->num += i->getNum();
    }
    virtual void subtract(Integer *i)
    {
        this->num -= i->getNum();
    }
    virtual void multiply(Integer *i)
    {
        this->num *= i->getNum();
    }

    virtual void Display()
    {
        cout << num << endl;
    }
};

class OrderedPair : public Integer
{
private:
    Integer n2 = 0;

public:
    // parameterized constructor
    OrderedPair(int num, int num2) : Integer(num)
    {
        n2.setNum(num2);
    }


    //overriding add, subtract, multiply
    void add(Integer *i)
    {
        OrderedPair *op = (OrderedPair *)i;
        this->setNum(this->getNum() + op->getNum());
        this->n2.setNum(this->n2.getNum() + op->n2.getNum());
        //do it need to delete op?-> no. Why? -> because it is not a pointer. But why it is not a pointer? -> because it is not a dynamic memory allocation. aaaah i see, u noti noti. 
    }
    void subtract(Integer *i)
    {
        OrderedPair *op = (OrderedPair *)i;
        this->setNum(this->getNum() - op->getNum());
        this->n2.setNum(this->n2.getNum() - op->n2.getNum());
    }
    void multiply(Integer *i)
    {
        OrderedPair *op = (OrderedPair *)i;
        this->setNum(this->getNum() * op->getNum());
        this->n2.setNum(this->n2.getNum() * op->n2.getNum());
    }

    void Display()
    {
        cout << "(" << this->getNum() << ", " << this->n2.getNum() << ")" << endl;
    }
};

int main()
{
    Integer *i1 = new Integer(10);
    Integer *i2 = new Integer(20);
    i1->add(i2);
    i1->Display();

    OrderedPair *op1 = new OrderedPair(10, 20);
    OrderedPair *op2 = new OrderedPair(30, 40);

    // Integer *i = new Integer(10);
    // OrderedPair *op = (OrderedPair *)i;
    //  How this works?-> 
    // 1. Integer *i = new Integer(10);
    // an object of Integer class is created and a pointer to it is assigned to i
    //  2. OrderedPair *op = (OrderedPair *)i;
    //  a pointer to the object of Integer class is typecasted to a pointer of OrderedPair class
    // why this works?
    // 1. OrderedPair is a derived class of Integer
    // 2. Integer is a base class of OrderedPair
    // hence the pointer to the object of Integer class can be typecasted to a pointer of OrderedPair class

    //generally, if a pointer to an object of a derived class is typecasted to a pointer of a base class, it works
    //does it work the other way around?
    //no, it doesn't, because the pointer to the object of a base class can't be typecasted to a pointer of a derived class

    op1->add(op2);
    op1->Display();

    op1->subtract(op2);
    op1->Display();

    op1->multiply(op2);
    op1->Display();



    return 0;
}