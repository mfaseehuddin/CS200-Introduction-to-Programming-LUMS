#include <iostream>
using namespace std;

class Date{
    private:
        const int NUMBER_OF_DAYS_IN_MONTH = 30;
        int month;
        int day;
        int year;
    public:
        //def const
        Date(){
            month = 1;
            day = 1;
            year = 2000;
        }
        //param const
        Date(int m, int d, int y){
            if(m > 0 && m < 13){
                month = m;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid month");
            }
            if(d > 0 && d < NUMBER_OF_DAYS_IN_MONTH){
                day = d;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid day");
            }
            if(y > 0){
                year = y;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid year");
            }
        }
        void Display(){
            cout << day << "/" << month << "/" << year << endl;
        }


};


//derive class from Date -> Time
class Time : public Date{
    private:
        int hour;
        int minute;
        int second;
    public:
        //def const
        Time(){
            hour = 0;
            minute = 0;
            second = 0;
        }
        //param const
        Time(int h, int m, int s, int mo, int d, int y) : Date(mo, d, y){
            if(h > 0 && h < 24){
                hour = h;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid hour");
            }
            if(m > 0 && m < 60){
                minute = m;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid minute");
            }
            if(s > 0 && s < 60){
                second = s;
            }
            else{
                //throw exception
                __throw_invalid_argument("Invalid second");
            }
        }
        void Display(){
            cout << hour << "-" << minute << " " << second << " ";
            Date::Display();
        }
};




int main()
{
    Date d1(2, 29, 2000);
    d1.Display();
    // Time(int h, int m, int s, int mo, int d, int y) : Date(mo, d, y){
    Time t1(12, 30, 45, 12, 29, 2019);
    t1.Display();
    return 0;
}