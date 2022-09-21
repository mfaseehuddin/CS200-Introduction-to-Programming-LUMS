#include <iostream>
using namespace std;

//class topic: structs and classes
//notes:
    // structs allow us to create our own data types
    // these data types can be used to group related data together
    // structs are similar to classes, but they are by default public
    // structs have constructors, destructors, and member functions
    // a struct is created by using the keyword "struct"
    //given below is a struct example of a date
        // struct date {
        //     int month;
        //     int day;
        //     int year;
        //     date(int m, int d, int y){
        //         month = m;
        //         day = d;
        //         year = y;
        //     }
        //     void printDate(){
        //         cout << month << "/" << day << "/" << year << endl;
        //     }
        // };
    //to create a date, we can use the following syntax:
        // date today;
        // today.month = 10;
        // today.day = 31;
        // today.year = 2019;
    //or we can use the following syntax:
        // date today(10, 31, 2019);
    //we can also use the following syntax:
        // date today = {10, 31, 2019};
    //we can also use the following syntax:
        // date today = date(10, 31, 2019);
    //to access the member functions of a struct, we can use the following syntax:
        // today.printDate();


    //classes
    //classes are similar to structs, but they are by default private
    //classes have constructors, destructors, and member functions
    //a class is created by using the keyword "class"
    //given below is a class example of a date
        // class date {
        //     int month;
        //     int day;
        //     int year;
        // public:
        //     date(int m, int d, int y){
        //         month = m;
        //         day = d;
        //         year = y;
        //     }
        //     void printDate(){
        //         cout << month << "/" << day << "/" << year << endl;
        //     }
        // };

//lecture example
//type definition
struct date{
    int month;
    int day;
    int year;
    // date(int m, int d, int y){
    //     month = m;
    //     day = d;
    //     year = y;
    // }
    // void printDate(){
    //     cout << month << "/" << day << "/" << year << endl;
    // }
};
struct employee{
    string name;
    date birthday;
};

void printDate(date &d){
    cout << d.month << "/" << d.day << "/" << d.year << endl;
}

void inputDate(date &d){
    cout << "month: "; cin >> d.month;
    cout << "day: "; cin >> d.day;
    cout << "year: "; cin >> d.year;
}

int main()
{
    //create a date
    date d1;
    date d2 = {10, 31, 2019};
    printDate(d2);

    //input a date
    inputDate(d1);
    printDate(d1);

    //create an employee
    employee e1 = {"John", {10, 31, 2019}};
    e1.name = "John";
    e1.birthday.month = 10;
    //change birthday year
    e1.birthday.year = 2018;
    cout << e1.name << " was born on ";
    printDate(e1.birthday);



    return 0;
}