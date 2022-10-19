#include <iostream>
using namespace std;

// class topic: aggregation in classes

// what is aggregation?
// aggregation is a relationship between two classes where one class is a part of another class
// aggregation is a special case of composition and is a form of association, where the part can exist independently of the whole

// example of aggregation
// question: what is the relationship between a car and its engine?
// answer: the engine is a part of the car, but the engine can exist independently of the car

// so lets create a class for the engine
class Engine
{
private:
    int horsePower;
    int torque;

public:
    // def constructor
    Engine()
    {
        horsePower = 0;
        torque = 0;
    }
    // param constructor
    Engine(int hp, int t)
    {
        horsePower = hp;
        torque = t;
    }
    // copy constructor
    Engine(const Engine &obj)
    {
        horsePower = obj.horsePower;
        torque = obj.torque;
    }
    // destructor
    ~Engine()
    {
        cout << "Engine destroyed" << endl;
    }
    // getters
    int getHorsePower()
    {
        return horsePower;
    }
    int getTorque()
    {
        return torque;
    }
    // setters
    void setHorsePower(int hp)
    {
        horsePower = hp;
    }
    void setTorque(int t)
    {
        torque = t;
    }
};
// lets create a class for the car
class Car
{
private:
    int year;
    string make;
    string model;
    Engine engine;

public:
    // def constructor
    Car()
    {
        year = 0;
        make = "";
        model = "";
    }
    // param constructor
    Car(int y, string m, string mo, Engine e)
    {
        year = y;
        make = m;
        model = mo;
        engine = e;
    }
    // copy constructor
    Car(const Car &obj)
    {
        year = obj.year;
        make = obj.make;
        model = obj.model;
        engine = obj.engine;
    }
    // destructor
    ~Car()
    {
        cout << "Car destroyed" << endl;
    }
    // getters
    int getYear()
    {
        return year;
    }
    string getMake()
    {
        return make;
    }
    string getModel()
    {
        return model;
    }
    Engine getEngine()
    {
        return engine;
    }
    // setters
    void setYear(int y)
    {
        year = y;
    }
    void setMake(string m)
    {
        make = m;
    }
    void setModel(string mo)
    {
        model = mo;
    }
    void setEngine(Engine e)
    {
        engine = e;
    }
};

// class example
// lets create a class for a counter
class Counter
{
private:
    int count;

public:
    // member functions
    // def constructor
    Counter()
    {
        count = 0;
    }
    // param constructor
    Counter(int c)
    {
        count = c;
    }
    // copy constructor
    Counter(const Counter &obj)
    {
        count = obj.count;
    }
    // destructor
    ~Counter()
    {
        cout << "Counter destroyed" << endl;
    }
    // increment
    void increment()
    {
        count++;
    }
    // get count
    int getCount()
    {
        return count;
    }
    // set count
    void setCount(int c)
    {
        count = c;
    }
};

// now we want to create a class for a MyCounter, which is a counter that can count up to a certain number
// we want to use aggregation to create this class
class MyCounter
{
private:
    Counter counter;
    int max;

public:
    // member functions
    // def constructor
    MyCounter()
    {
        max = 0;
        //default constructor of the counter class is called, because we did not specify a constructor
    }
    // param constructor
    MyCounter(int m, int cStart) : counter(cStart)
    {
        max = m;
    }
    // copy constructor
    MyCounter(const MyCounter &obj)
    {
        max = obj.max;
        counter = obj.counter;
    }
    // destructor
    ~MyCounter()
    {
        cout << "MyCounter destroyed" << endl;
    }
    // increment
    void increment()
    {
        if (counter.getCount() < max)
        {
            counter.increment();
        }
    }
    // get count
    int getCount()
    {
        return counter.getCount();
    }
    // set count
    void setCount(int c)
    {
        counter.setCount(c);
    }
    // get max
    int getMax()
    {
        return max;
    }
    // set max
    void setMax(int m)
    {
        max = m;
    }
    // max reached
    bool maxReached()
    {
        if (counter.getCount() == max)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // for (MyCounter c1(10, 1); !c1.maxReached(); c1.increment())
    // {
    //     cout << c1.getCount() << endl;
    // }
    //THIS WORKS! because the counter is a part of the MyCounter class, so when the MyCounter class is destroyed, the counter is destroyed as well

    return 0;
}