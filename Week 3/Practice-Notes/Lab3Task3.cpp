#include <iostream>
using namespace std;
struct LUMS
{
private:
    string school;
    string name;
    string rollNumber;

public:
    LUMS()
    {
        cout << "LUMS - Not for Profit - University" << endl;
    }
    LUMS(string s, string n, string r)
    {
        cout << "Everyone calls me but no one asks me How am I?\n";
        cout << s << "\n"
             << n << "\n"
             << r << endl;
        school = s;
        name = n;
        r = rollNumber;
    }
    //copy constructor
    LUMS(const LUMS &l)
    {
        cout << "Copy constructor called" << endl;
        school = l.school;
        name = l.name;
        rollNumber = l.rollNumber;
    }
    ~LUMS()
    {
        cout << "I really miss the Pre-Covid LUMS" << endl;
    }
};

void anotherFunction(LUMS HSS)
{
    cout << "Humanity is a social construct\n";
    LUMS anaconda("School of Demons and Social Bullies", "Snake", "I Won't tell");
}
void sadFunction()
{
    LUMS happyStudent("School of Simple and Efficient Learning", "HomoSapien", "You know who I am");
    cout << "If you look for the light you will often find it but if you look for the dark that is all you will find.\n";
}



int main()
{
    LUMS student("School of Stress and Existential Crisis", "Human", "Not Known");
    {
        LUMS sadStudent;
        anotherFunction(sadStudent);
    }
    sadFunction();
}

/*
student(
    school = "School of Stress and Existential Crisis",
    name = "Human",
    rollNumber = "Not Known"
)
sadStudent()
anotherFunction(
    HSS(
        school = "School of Demons and Social Bullies",
        name = "Snake",
        rollNumber = "I Won't tell"
    )
)


*/