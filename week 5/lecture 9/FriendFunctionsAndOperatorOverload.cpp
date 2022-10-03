#include <iostream>
using namespace std;

//class Topic: Friend Functions && Operator overloading

/*

    The benefits of using a friend function is that it can access the private members of the class.
    It is not a member of the class, but it can access the private members of the class.
    However, it is declared in the class, because it is a friend of the class. It doesnt make sense, but it is.



*/

//define a class of box
class Box{
    private:
        double length;
        double breadth;
        double height;
        string unit;
    public:
        //default constructor
        Box(){
            length = 0;
            breadth = 0;
            height = 0;
            unit = "m";
        }
        //parameterised constructor
        Box(double l, double b, double h, string u){
            length = l;
            breadth = b;
            height = h;
            unit = u;
        }
        //friend function
        friend string volume(Box box){
            //return volume to only 2 decimal places //doesnt work properly
            return to_string(box.length * box.breadth * box.height).substr(0,4) + " " + box.unit + "^3";
        }
};

//object -> a=10 b=10 c=10

int main()
{
    Box box;
    string vol = volume(box);
    
    cout << "Volume of box is: " << vol << endl;
    return 0;
}