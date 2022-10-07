#include <iostream>
using namespace std;


//prelab task: define an Integer class

class Integer{
    private:
        int num;
    public:
        //parameterized constructor
        Integer(int num){
            this->num = num;
        }
        //setter function
        void setNum(int num){
            this->num = num;
        }
        //getter function
        int getNum(){
            return num;
        }
        //operator overloading
        //overload = operator
        void operator=(Integer i){
            num = i.num;
        }

        //overload == operator
        bool operator==(Integer i){
            if(num == i.num){
                return true;
            }
            else{
                return false;
            }
        }

        //overload + operator
        Integer operator+(Integer i){
            Integer temp(0);
            temp.num = num + i.num;
            return temp;
        }

        //overload - operator
        Integer operator-(Integer i){
            Integer temp(0);
            temp.num = num - i.num;
            return temp;
        }

        //overload * operator
        Integer operator*(Integer i){
            Integer temp(0);
            temp.num = num * i.num;
            return temp;
        }

        //overload / operator
        Integer operator/(Integer i){
            Integer temp(0);
            temp.num = num / i.num;
            return temp;
        }

        //member functions
        //friend average function
        friend double average(Integer i1, Integer i2){
            double avg = (i1.num + i2.num) / 2.0;
            return avg;
        }
};

int main()
{
    //testing Integer class
    Integer i1(20);
    Integer i2(10);
    Integer i3(0);


    i3 = i1 + i2;
    cout << i3.getNum() << endl;
    i3 = i1 - i2;
    cout << i3.getNum() << endl;
    i3 = i1 * i2;
    cout << i3.getNum() << endl;
    i3 = i1 / i2;
    cout << i3.getNum() << endl;

    if(i1 == i2){
        cout << "i1 and i2 are equal" << endl;
    }
    else{
        cout << "i1 and i2 are not equal" << endl;
    }
    cout << "The average of i1 and i2 is: " << average(i1, i2) << endl;

    return 0;
}