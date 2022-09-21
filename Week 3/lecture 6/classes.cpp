#include <iostream>
using namespace std;

//class topic: classes
//class definition
class Date {
    //private members
    int day;
    int month;
    int year;
    //public members
    public:
        //constructor
        Date(int d, int m, int y);
        //member functions
        void print();

        //basic operator overloading
        //not taught in lecture
        //overload + operator
        Date operator+(int days);
};
//class function definition, outside the class definition, using the :: scope resolution operator
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void Date::print() {
    cout << day << "/" << month << "/" << year << endl;
}



//Date overload + operator function definition: not taught in lecture
Date Date::operator+(int days) {
    Date newDate(day, month, year);
    newDate.day += days;
    if(newDate.day > 30) {
        newDate.day -= 30;
        newDate.month++;
    }
    if(newDate.month > 12) {
        newDate.month -= 12;
        newDate.year++;
    }
    return newDate;
}

int main()
{

    //Declare d1 as instance/object of class Date
    Date d1(21, 9, 2022);
    d1.print();
    //d1 is passed to print() implicitly
    //d1.day is a private member, so it cannot be accessed outside the class definition!
    //cout << d1.day << endl; will result in an error - specifically, a compiler error

    //Declare d2 as instance/object of class Date
    //adding 10 days to d1: not taught in lecture
    Date d2 = d1 + 10;
    d2.print();

    return 0;

}