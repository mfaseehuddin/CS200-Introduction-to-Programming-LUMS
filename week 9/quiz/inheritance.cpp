#include <iostream>
using namespace std;


class student{
    protected:
        string name;
        int ID;
    public:
        //param const
        student(string name, int ID){
            this->name = name;
            this->ID = ID;
        }
};

class details{
    protected:
        student *std;
        int stdClass;
        string stdSection;

    public:
        //param const
        details(student *std, int stdClass, string stdSection){
            this->std = std;
            this->stdClass = stdClass;
            this->stdSection = stdSection;
        }
        void show(){
            // cout << "Name: " << std->name << endl; // this will give error
            // cout << "ID: " << std->ID << endl; // this will give error
            cout << "Class: " << stdClass << endl;
            cout << "Section: " << stdSection << endl;
        }
};


int main()
{
    student s1 = student("John", 123);
    details d1 = details(&s1, 10, "A");
    d1.show();
    return 0;
}