#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char *name;
    int roll;
    Student(string name, int roll){
        this->name = new char[name.length() + 1];
        strcpy(this->name, name.c_str());
        this->roll = roll;
    }

};



void deallocate(Student **stds, int size){

    for (int i = 0; i < size; i++)
    {
        delete [] stds[i]->name;
        delete stds[i];
    }
    stds = nullptr;

}


int main()
{
    int numStudents = 3;
    Student ** stds = new Student*[numStudents];
    for(int i = 0; i < numStudents; i++){
        //student name is A then B then C
        //student roll is 1 then 2 then 3
        stds[i] = new Student(string(1, 'A' + i), i+1);
    }
    deallocate(stds, numStudents);

    return 0;
}