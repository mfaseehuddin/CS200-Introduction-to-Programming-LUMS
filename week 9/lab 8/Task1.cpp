#include <iostream>
#include <iomanip>
using namespace std;

class Date
{

private:
    int day;
    int month;
    int year;

    //my variables
    bool leap;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    // def const
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
        leap = false;
    }
    
    // date check function
    bool checkDate(int d, int m, int y)
    {
        if (y < 0 || m < 1 || m > 12 || d < 1)
        {
            return false;
        }
        // check for leap year
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0 && y % 100 == 0)
        {
            days[1] = 29;
            leap = true;
        }
        else
        {
            days[1] = 28;
            leap = false;
        }
        // check if day is valid: guard clause
        if (d > days[m - 1] || (m == 2 && d > 29 && leap))
            return false;

        return true;
    }

    // param const with complete checks
    Date(int d, int m, int y)
    {
        if (checkDate(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            __throw_invalid_argument("Invalid date");
        }
    }

    // member functions
    void Display()
    {
        // display date as DD-MM-YYYY
        cout << setfill('0') << setw(2) << day << "-" << setw(2) << month << "-" << setw(4) << year << endl;
    }
    void operator+(int Days)
    {
        // adding days to the date
        day += Days;
        bool isLeap = isLeapYear(year);
        while (day > days[month - 1] || (month == 2 && day > 29 && isLeap))
        {
            if (month == 2 && day > 29 && isLeap)
            {
                day -= 29;
                month++;
            }
            else
            {
                day -= days[month - 1];
                month++;
            }
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }

        updateLeap();
    }
    void Add(int Day, int Month, int Year)
    {
        day += Day;
        if (Day > days[month - 1])
        {
            month++;
            day -= days[month - 1];
        }
        month += Month;
        if (Month > 12)
        {
            year++;
            month -= 12;
        }
        year += Year;

        updateLeap();

    }
    bool isLeapYear(int Year)
    {
        // check if year is leap
        if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0 && Year % 100 == 0)
            return true;
        else
            return false;
    }

    // update function
    void updateLeap(){
        // update leap year
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 100 == 0)
        {
            days[1] = 29;
            leap = true;
        }
        else
        {
            days[1] = 28;
            leap = false;
        }
    }

    // getters
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    
    friend class DateTimeTest;
};

class Time : public Date
{
private:
    int hour;
    int minute;
    int second;

public:
    // def const
    Time() : Date()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    // param const
    Time(int h, int m, int s, int d, int mo, int y) : Date(d, mo, y)
    {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        {
            __throw_invalid_argument("Invalid time");
        }
        else
        {
            hour = h;
            minute = m;
            second = s;
        }
    }
    void Display()
    {

        // display time as HH-MM-SS
        cout << setfill('0') << setw(2) << hour << "-" << setw(2) << minute << "-" << setw(2) << second << " ";
        Date::Display();
    }
    void operator+(int s)
    {
        // add seconds with overflow

        // 86400 * 366 = 31622400
        // 86400 * 365 = 31536000
        second += s; // 0+31536000 = 31536000 // 0 + 31622400 = 31622400
        if (second > 59)
        {
            minute += second / 60; // 31536000/60 = 525600 // 31622400/60 = 527040
            second %= 60;          // 31536000%60 = 0 // 31622400%60 = 0
        }
        if (minute > 59)
        {
            hour += minute / 60; // 525600/60 = 8760 // 527040/60 = 8784
            minute %= 60;        // 525600%60 = 0 // 527040%60 = 0
        }
        if (hour > 23)
        {
            Date::operator+(hour / 24); // 8760/24 = 365 // 8784/24 = 366
            hour %= 24;                 // 8760%24 = 0 // 8784%24 = 0
        }
    }
    void Add(Time &t)
    {
        // add time to the date
        second += t.second;
        if (second > 59)
        {
            minute += second / 60;
            second %= 60;
        }
        minute += t.minute;
        if (minute > 59)
        {
            hour += minute / 60;
            minute %= 60;
        }
        hour += t.hour;
        if (hour > 23)
        {
            Date::operator+(hour / 24);
            hour %= 24;
        }

        // now as only the time is added, we need to add the date
        int DaysToAdd = t.getDay();
        int MonthsToAdd = t.getMonth();
        int YearsToAdd = t.getYear();

        Date::Add(DaysToAdd, MonthsToAdd, YearsToAdd);
    }

    friend class DateTimeTest;
};

// int main(){

//     Time t(1,1,1,1,1,2000);
//     t.Display();
//     // add 1 year;
//     t + 1;
//     cout << "Adding 1 second\n";
//     t.Display();
//     t + 60;
//     cout << "Adding 60 seconds -- 1 minute\n";
//     t.Display();
//     t + 3600;
//     cout << "Adding 3600 seconds -- 1 hour\n";
//     t.Display();
//     t + 86400;
//     cout << "Adding 86400 seconds -- 1 day\n";
//     t.Display();
//     t + 86400 * 30;
//     cout << "Adding 86400 * 30 seconds -- 1 month\n";
//     t.Display();
//     t + 86400 * 366;
//     cout << "Adding 86400 * 366 seconds -- 1 year in a leap\n";
//     t.Display();
//     //365 * 24 * 60 * 60 = 31536000
//     //31536000 / 24 = 1314000

// }

// // int main(){
// //     Time t1(1,1,1,1,1,2000);
// //     Time t2(1,1,1,1,1,2000);

// //     t1.Add(t2);

// //     t1.Display();
// // }