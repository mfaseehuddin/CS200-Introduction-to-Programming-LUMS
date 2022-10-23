#include <iostream>
using namespace std;

//topic: static class members

//example class: Student
class Student
{
private:
    //static class member
    static int numStudents;
    int roll;
    string name;
public:
    //how to initialise the static class member
    Student(int roll, string name)
    {
        this->roll = roll;
        this->name = name;
        numStudents++;
    }
    //def con
    Student(){
        numStudents++;
        roll = 0;
        name = nullptr;
    }

    int numStudentsInClass(){
        return numStudents;
    }
    //destructors
    ~Student(){
        numStudents--;
    }

};


//init the static class member
int Student::numStudents = 0;
//how to initialise a static data member
//we can't use the dot operator, hence the scope resolution operator
//we have to initialise the static data member outside the class
//in a format as follows:

//variable_type class_name::variable_name = value;


int main()
{

    //declare 5 students
    Student s1(1, "A");
    Student s2(2, "B");
    Student s3(3, "C");
    Student s4(4, "D");
    {Student s5(5, "E");}


    cout << s1.numStudentsInClass();
    
    return 0;
}