#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Task1.cpp"

using namespace std;

/* Write a test file to test the implementation of Task1.cpp */

int SCORE = 0;
int MAX_SCORE = 70;

class DateTimeTest
{
private:
    Time test_time;
    Date test_date;

public:
    void TestingDateParamtericConstructor()
    {
        try
        {
            cout << "Testing Date Paramteric Constructor" << endl;
            Date test_date(1, 1, 2000);
            if (test_date.day == 1 && test_date.month == 1 && test_date.year == 2000)
            {
                cout << "\033[1;32m";
                // system("Color 02");
                cout << "Test Passed \u2713" << endl;
                // system("Color 07");
                cout << "\033[0m";
                SCORE += 5;
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }

    void TestingDateDisplay()
    {
        try
        {
            cout << "Testing Date Display" << endl;

            test_date.day = 1;
            test_date.month = 1;
            test_date.year = 2000;

            /* Redirect output stream to out.txt */
            streambuf *coutbuf = cout.rdbuf();
            ofstream out("out.txt");
            cout.rdbuf(out.rdbuf());

            test_date.Display();

            /* Redirect output stream back to cout */
            cout.rdbuf(coutbuf);

            /* Read from out.txt */
            ifstream in("out.txt");
            string line;
            getline(in, line);

            if (line == "01-01-2000")
            {
                /* Test for the date 29-10-2022 */
                test_date.day = 29;
                test_date.month = 10;
                test_date.year = 2022;

                /* Redirect output stream to out.txt */
                streambuf *coutbuf = cout.rdbuf();
                ofstream out("out.txt");
                cout.rdbuf(out.rdbuf());

                test_date.Display();

                /* Redirect output stream back to cout */
                cout.rdbuf(coutbuf);

                /* Read from out.txt */
                ifstream in("out.txt");
                string line;
                getline(in, line);

                if (line == "29-10-2022")
                {
                    cout << "\033[1;32m";
                    cout << "Test Passed \u2713" << endl;
                    cout << "\033[0m";
                    SCORE += 10;
                }
                else
                {
                    cout << "\033[1;31m";
                    cout << "Test Failed for Date: 29-10-2022 \u2716" << endl;
                    cout << "\033[0m";
                }
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed for Date: 01-01-2000 \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }

    void TestingTimeParamtericConstructor()
    {
        try
        {
            cout << "Testing Time Paramteric Constructor" << endl;
            Time test_time(1, 1, 1, 1, 1, 2000);
            if (test_time.day == 1 && test_time.month == 1 && test_time.year == 2000 && test_time.hour == 1 && test_time.minute == 1 && test_time.second == 1)
            {
                cout << "\033[1;32m";
                cout << "Test Passed \u2713" << endl;
                cout << "\033[0m";
                SCORE += 10;
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }

    void TestingTimeDisplay()
    {
        try
        {
            cout << "Testing Time Display" << endl;

            test_time.day = 1;
            test_time.month = 1;
            test_time.year = 2000;
            test_time.hour = 1;
            test_time.minute = 1;
            test_time.second = 1;

            /* Redirect output stream to out.txt */
            streambuf *coutbuf = cout.rdbuf();
            ofstream out("out.txt");
            cout.rdbuf(out.rdbuf());

            test_time.Display();

            /* Redirect output stream back to cout */
            cout.rdbuf(coutbuf);

            /* Read from out.txt */
            ifstream in("out.txt");
            string line;
            getline(in, line);

            if (line == "01-01-01 01-01-2000")
            {
                /* Test for the Time 23-59-59 29-10-2022 */
                test_time.day = 29;
                test_time.month = 10;
                test_time.year = 2022;
                test_time.hour = 23;
                test_time.minute = 59;
                test_time.second = 59;

                /* Redirect output stream to out.txt */
                streambuf *coutbuf = cout.rdbuf();
                ofstream out("out.txt");
                cout.rdbuf(out.rdbuf());

                test_time.Display();

                /* Redirect output stream back to cout */
                cout.rdbuf(coutbuf);

                /* Read from out.txt */
                ifstream in("out.txt");
                string line;
                getline(in, line);

                if (line == "23-59-59 29-10-2022")
                {
                    cout << "\033[1;32m";
                    cout << "Test Passed \u2713" << endl;
                    cout << "\033[0m";
                    SCORE += 10;
                }
                else
                {
                    cout << "\033[1;31m";
                    cout << "Test Failed for Time: 23-59-59 29-10-2022 \u2716" << endl;
                    cout << "\033[0m";
                }
            }

            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed for Time: 1-1-1 1-1-2000 \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }

    void TestingOverloadedPlusOperator()
    {
        /* Override the plus (+) operator, taking the number of seconds as its arguments and updating the date-time object accordingly. */
        try
        {
            cout << "Testing Overloaded Plus Operator" << endl;

            test_time.day = 1;
            test_time.month = 1;
            test_time.year = 2000;
            test_time.hour = 1;
            test_time.minute = 1;
            test_time.second = 1;

            test_time + 1;

            if (test_time.day == 1 && test_time.month == 1 && test_time.year == 2000 && test_time.hour == 1 && test_time.minute == 1 && test_time.second == 2)
            {
                test_time + 60;

                if (test_time.day == 1 && test_time.month == 1 && test_time.year == 2000 && test_time.hour == 1 && test_time.minute == 2 && test_time.second == 2)
                {
                    test_time + 3600;

                    if (test_time.day == 1 && test_time.month == 1 && test_time.year == 2000 && test_time.hour == 2 && test_time.minute == 2 && test_time.second == 2)
                    {
                        test_time + 86400;

                        if (test_time.day == 2 && test_time.month == 1 && test_time.year == 2000 && test_time.hour == 2 && test_time.minute == 2 && test_time.second == 2)
                        {
                            test_time + 86400 * 30;

                            if (test_time.day == 1 && test_time.month == 2 && test_time.year == 2000 && test_time.hour == 2 && test_time.minute == 2 && test_time.second == 2)
                            {
                                test_time + 86400 * 366;
                                if (test_time.day == 1 && test_time.month == 2 && test_time.year == 2001 && test_time.hour == 2 && test_time.minute == 2 && test_time.second == 2)
                                {
                                    cout << "\033[1;32m";
                                    cout << "Test Passed \u2713" << endl;
                                    cout << "\033[0m";
                                    SCORE += 15;
                                }
                                else
                                {
                                    cout << "\033[1;31m";
                                    cout << "Test Failed for Time: 1-1-1 1-1-2000 + 86400 * 365 \u2716" << endl;
                                    cout << "\033[0m";
                                }
                            }
                            else
                            {
                                cout << "\033[1;31m";
                                cout << "Test Failed for Time: 1-1-1 1-1-2000 + 86400 * 30 \u2716" << endl;
                                cout << "\033[0m";
                            }
                        }
                        else
                        {
                            cout << "\033[1;31m";
                            cout << "Test Failed for Time: 1-1-1 1-1-2000 + 86400 \u2716" << endl;
                            cout << "\033[0m";
                        }
                    }
                    else
                    {
                        cout << "\033[1;31m";
                        cout << "Test Failed for Time: 1-1-1 1-1-2000 + 3600 \u2716" << endl;
                        cout << "\033[0m";
                    }
                }
                else
                {
                    cout << "\033[1;31m";
                    cout << "Test Failed for Time: 1-1-1 1-1-2000 + 60 \u2716" << endl;
                    cout << "\033[0m";
                }
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed for Time: 1-1-1 1-1-2000 + 1 \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }

    void TestingAddFunction()
    {
        /* Write a function called Add, which takes a reference to another Time object, and adds the two times (and dates together) */
        try
        {
            cout << "Testing Add Function" << endl;

            test_time.day = 1;
            test_time.month = 1;
            test_time.year = 2000;
            test_time.hour = 1;
            test_time.minute = 1;
            test_time.second = 1;

            Time test_time2;
            test_time2.day = 1;
            test_time2.month = 1;
            test_time2.year = 2000;
            test_time2.hour = 1;
            test_time2.minute = 1;
            test_time2.second = 1;

            test_time.Add(test_time2);

            if (test_time.day == 2 && test_time.month == 2 && test_time.year == 4000 && test_time.hour == 2 && test_time.minute == 2 && test_time.second == 2)
            {
                /* Testing for 1-1-1 1-1-2000 + 10-30-59 27-4-786 */
                test_time.day = 1;
                test_time.month = 1;
                test_time.year = 2000;
                test_time.hour = 1;
                test_time.minute = 1;
                test_time.second = 1;

                test_time2.day = 27;
                test_time2.month = 4;
                test_time2.year = 786;
                test_time2.hour = 10;
                test_time2.minute = 30;
                test_time2.second = 59;

                test_time.Add(test_time2);

                if (test_time.day == 28 && test_time.month == 5 && test_time.year == 2786 && test_time.hour == 11 && test_time.minute == 32 && test_time.second == 0)
                {
                    cout << "\033[1;32m";
                    cout << "Test Passed \u2713" << endl;
                    cout << "\033[0m";
                    SCORE += 20;
                }
                else
                {
                    cout << "\033[1;31m";
                    cout << "Test Failed for Time: 1-1-1 1-1-2000 + 27-4-786 10-30-59 \u2716" << endl;
                    cout << "\033[0m";
                }
            }
            else
            {
                cout << "\033[1;31m";
                cout << "Test Failed for Time: 1-1-1 1-1-2000 + 1-1-1 1-1-2000 \u2716" << endl;
                cout << "\033[0m";
            }
        }
        catch (...)
        {
            cout << "\033[1;31m";
            cout << "Test Failed \u2716" << endl;
            cout << "\033[0m";
        }
    }
};

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);

    system("cls");
    system("Color 07");
#elif __linux__
    system("clear");
#elif __APPLE__
    system("clear");
#endif

    DateTimeTest test;
    test.TestingDateParamtericConstructor();
    test.TestingDateDisplay();
    test.TestingTimeParamtericConstructor();
    test.TestingTimeDisplay();
    test.TestingOverloadedPlusOperator();
    test.TestingAddFunction();

    if (SCORE >= MAX_SCORE)
    {
        cout << "\033[1;32m";
        cout << "Total Score: " << SCORE << endl;
        cout << "\033[0m";
    }
    else
    {
        cout << "\033[1;31m";
        cout << "Total Score: " << SCORE << endl;
        cout << "\033[0m";
    }

    return 0;
}