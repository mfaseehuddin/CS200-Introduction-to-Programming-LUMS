#include <iostream>
using namespace std;

struct dimension
{
    int feet;
    float inches;

    // constructor
    dimension()
    {
        feet = 0;
        inches = 0.0;
    }
    // parameterized constructor
    dimension(int f, float i)
    {
        feet = f;
        inches = i;
    }

    // copy and assignment constructors will be automatically created by the compiler
    //-- as we have not defined them, and do not require special behavior

    // member functions
    void getDistance()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDistance()
    {
        cout << feet << "\'-" << inches << "\"" << endl;
    }

    // overloaded operators
    dimension operator+(dimension d2)
    {
        dimension temp;
        temp.feet = feet + d2.feet;
        temp.inches = inches + d2.inches;
        if (temp.inches >= 12.0)
        {
            temp.inches -= 12.0;
            temp.feet++;
        }
        return temp;
    }

    // ostream overload
    friend ostream &operator<<(ostream &out, dimension d)
    {
        out << d.feet << "\'-" << d.inches << "\"" << endl;
        return out;
    }
};

struct Date
{
    int day;
    int month;
    int year;

    // constructor
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    // parameterized constructor
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    // overloads
    // comparison operator
    bool operator==(Date d2)
    {
        if (day == d2.day && month == d2.month && year == d2.year)
            return true;
        else
            return false;
    }

    // ostream overload
    friend ostream &operator<<(ostream &out, Date d)
    {
        out << d.day << "/" << d.month << "/" << d.year << endl;
        return out;
    }

    bool isLeapYear()
    {
        if (year % 4 != 0)
            return false;
        if (year % 100 != 0)
            return true;
        if (year % 400 != 0)
            return false;
        return true;
    };

    // member functions
    int getDaysInMonth()
    {
        // define lambda function to check if year is a leap year
        //  (28 + (mm + (mm/8)) % 2 + 2 % mm + 2 * (1/mm) + ((mm == 2) * leapyear(yyyy)))

        return 28 + (month + (month / 8)) % 2 + 2 % month + 2 * (1 / month) + ((month == 2) * isLeapYear());
    }
};

// Let us work on the menu of a library. Create a structure containing book information like accession number, author name, book title and flag to know whether the book is issued or not.
// Create a menu in which the following can be done.
// 1 - Display book information
// 2 - Add a new book
// 3 - Display all the books in the library of a particular author
// 4 - Display the number of books of a specific title
// 5 - Display the total number of books in the library
// 6 - Issue a book
// (If we issue a book, then its number gets decreased by one (1), and if we add a book, its number gets increased by 1)
// library menu system
// struct required: book
// vague -- what number gets decreased by one?  the number of books of a specific title?  the number of books of a specific author?  the total number of books in the library?

struct book
{
    int accessionNumber;
    string authorName;
    string bookTitle;
    bool isIssued;

    // constructor
    book()
    {
        accessionNumber = 0;
        authorName = "";
        bookTitle = "";
        isIssued = false;
    }
    // parameterized constructor
    book(int a, string an, string bt, bool i)
    {
        accessionNumber = a;
        authorName = an;
        bookTitle = bt;
        isIssued = i;
    }

    // overloads
    // ostream overload
    friend ostream &operator<<(ostream &out, book b)
    {
        out << "Accession Number: " << b.accessionNumber << endl;
        out << "Author Name: " << b.authorName << endl;
        out << "Book Title: " << b.bookTitle << endl;
        out << "Is Issued: " << b.isIssued << endl;
        return out;
    }
};

// optional functions parameters, example
void incrementDate(Date &d, int N = 1)
{
    if(d.day + N > d.getDaysInMonth()){
        d.day = (d.day + N) % d.getDaysInMonth();
        int remainingDays = (d.day + N) / d.getDaysInMonth();
        //figure this out later!
    }
    
}

int main()
{

    // dimension d1, d2;
    // cout << "dimension 1: \n";
    // d1.getDistance();
    // cout << "dimension 2: \n";
    // d2.getDistance();
    // cout << d1 + d2;

    Date date1(1, 1, 2019);
    Date date2(1, 1, 2019);
    Date date3(1, 1, 2020);
    cout << "date1 == date2: ";
    (date1 == date2) ? cout << "dates are equal" << endl : cout << "dates are not equal" << endl;

    cout << "incrementing date1 by 1 day" << endl;
    incrementDate(date1);
    cout << date1;

    cout << "incrementing date1 by 5 days" << endl;
    incrementDate(date2, 5);
    cout << date2;

    cout << date3;
    cout << "incrementing date3 by 365 days" << endl;
    incrementDate(date3, 365);
    cout << date3;

    return 0;
}