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
        //default constructor
        Date();
        //parameterized constructor
        Date(int d, int m, int y);
        //parameterized constructor overloading
        Date(int d, int m);
        Date(int d);
        //member functions
        void print();
        //setter functions
        void setDate(int d, int m, int y);
        void setDate(Date d);
        //destructor
        ~Date();
        

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
Date::Date(int d, int m) {
    day = d;
    month = m;
    year = 2019;
}
Date::Date(int d) {
    day = d;
    month = 1;
    year = 2019;
}
Date::Date() {
    day = 1;
    month = 1;
    year = 2019;
}
void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::setDate(Date d) {
    //we can access the private members of d using the . operator, because we are inside the class
    day = d.day; 
    month = d.month;
    year = d.year;
}
void Date::print() {
    cout << day << "/" << month << "/" << year << endl;
}
Date::~Date() {
    //here we can delete any dynamically allocated memory
    //in this case we don't have any
    //hence, we just print a message
    cout << "destructor called" << endl;
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
    //to access private members, we need to use public member functions, called getters and setters.

    Date d4; //in this case the default constructor is called, since no arguments are passed. The constructor to be called is determined by the arguments passed.
    d4.print();
    d4.setDate(21, 9, 2022);//calling the setter function
    d4.print();

    Date d5;
    d5.setDate(d4);//calling the setter function. d5 is passed to setDate() implicitly, and d4 is passed to setDate() explicitly
    d5.print();

    Date d6 = d5; //calling the copy constructor

    //Declare d2 as instance/object of class Date
    //adding 10 days to d1: not taught in lecture
    Date d2 = d1 + 10;
    d2.print();

    return 0;

}