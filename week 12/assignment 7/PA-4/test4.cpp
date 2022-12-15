#include <iostream>
#include "BurgerJoint.cpp"
#include <algorithm>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <fstream>

void compareFiles(string p1, string p2)
{

    fstream f1, f2;
    string s1, s2;
    int flag = 1;
    f1.open(p1, ios::in);
    f2.open(p2, ios::in);

    while (1)
    {
        getline(f1, s1);
        getline(f2, s2);

        // Uncomment this if you want to compare the output of both files
        //  cout<<"s1: " << s1 << endl;
        //  cout<<"s2: " << s2 << endl;

        if (s1 != s2)
        {
            flag = 0;
            break;
        }

        if ((s1 == "") || (s2 == ""))
        {
            break;
        }
    }

    f1.close();

    f2.close();

    if (flag)
    {
        cout << "Test passed!\n";
        cout << "Total score: 20/20\n";
    }
    else
    {
        cout << "Test failed!\n";
        cout << "Total score: 0/20\n";
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Please specify the number of burgers" << endl;
        exit(0);
    }

    if (argc > 2)
    {
        cout << "Extra input provided" << endl
             << "Write ./a.out followed by number of burgers (10/50/100)" << endl;
        exit(0);
    }

    string filename = "";

    if ((string)argv[1] == "10")
    {
        ofstream fout("assembly.txt");
        ifstream fin("assembly10.txt");
        string line;
        while (getline(fin, line))
        {
            fout << line << endl;
        }
        fout.close();
        fin.close();
        filename = "takeaway10.txt";
    }
    else if ((string)argv[1] == "50")
    {
        ofstream fout("assembly.txt");
        ifstream fin("assembly50.txt");
        string line;
        while (getline(fin, line))
        {
            fout << line << endl;
        }
        fout.close();
        fin.close();
        filename = "takeaway50.txt";
    }
    else
    {
        cout << "Wrong input" << endl;
        exit(0);
    }
    BurgerJoint ab;
    ab.takeawayCounter();

    compareFiles("takeaway.txt", filename);

    return 0;
}