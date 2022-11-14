#include <iostream>
#include <fstream>
using namespace std;

// class topic: Binary File I/O

//we need to import the fstream library

//ok, to work with a binary file, we need to use the ofstream and ifstream classes
//and these are the steps to effectively read and write to a binary file

//1. create a structure that will hold the data that we want to write to the file
//2. create an object of the ofstream class
//3. open the file
//4. write the data to the file
//5. close the file
//6. create an object of the ifstream class
//7. open the file
//8. read the data from the file
//9. close the file



//creating a car structure

struct car
{
    char name[30];
    char engine[2];
    int horsepower;

    //default constructor

    //param const
    car(char *n, char *e, int h)
    {
        strcpy(name, n);
        strcpy(engine, e);
        horsepower = h;
    }

    //we need to overload the << operator so that we can print the data from the structure
    friend ostream& operator<<(ostream& out, const car& c)
    {
        out << c.name << "," << c.engine << "," << c.horsepower << endl;
        return out;
    }

};

int main()
{

    //creating an object of the car structure
    car corolla("Corolla", "I4", 200);
    car civic("Civic", "I4", 300);
    car camry("Camry", "V6", 400);


    //creating an object of the ofstream class
    ofstream fout;

    //opening the file
    fout.open("cars.dat", ios::out | ios::binary);

    //writing the data to the file
    fout.write((char*)&corolla, sizeof(corolla));
    fout.write((char*)&civic, sizeof(civic));
    fout.write((char*)&camry, sizeof(camry));

    //closing the file
    fout.close();

    //creating an object of the ifstream class
    ifstream fin;

    //opening the file
    fin.open("cars.dat", ios::in | ios::binary);

    //reading the data from the file and putting it into temp struct and printing it
    car temp(" ", " ", 0);
    while(fin.read((char*)&temp, sizeof(temp)))
    {
        cout << temp;
    }

    //closing the file
    fin.close();





    return 0;
}