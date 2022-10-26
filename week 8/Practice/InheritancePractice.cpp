#include <iostream>
using namespace std;

// objective: Practice Inheritance

// 1. Create a class called "Animal" with a member variable "name" and a member function "speak"
// 2. Create a class called "Dog" that inherits from "Animal" and has a member function "fetch"
// 3. Create a class called "Cat" that inherits from "Animal" and has a member function "scratch"
// 4. Create a class called "Bird" that inherits from "Animal" and has a member function "fly"

class Animal
{
protected:
    string type;
    string name;

public:
    Animal(string type, string name)
    {
        this->type = type;
        this->name = name;
    }

    void getName()
    {
        cout << "My name is " << name << endl;
    }
    void speak()
    {
        cout << "I am an animal" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal("Dog", name)
    {
    }

    // override speak -> why is this not called overloading the function? -> because it is not the same function
    void speak()
    {
        cout << "I am a dog" << endl;
    }
    // this is overloading the function that is also overriden
    void speak(int num)
    {
        for (int i = 0; i < num; i++)
        {
            cout << "I am a dog" << endl;
        }
    }

    void fetch()
    {
        cout << "I am a dog" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal("Cat", name)
    {
    }

    void scratch()
    {
        cout << "I am a cat" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird(string name) : Animal("Bird", name)
    {
    }

    void fly()
    {
        cout << "I am a bird" << endl;
    }
};

//more sensible example
class Number{
    protected:
        int num;
    public:
        Number(){
            num = 0;
        }
        Number(int num){
            this->num = num;
        }
        void print(){
            cout << "Number: " << num << endl;
        }

        //overloading the basic operators
        Number operator+(Number n){
            Number temp;
            temp.num = this->num + n.num;
            return temp;
        }
        Number operator-(Number n){
            Number temp;
            temp.num = this->num - n.num;
            return temp;
        }
        Number operator*(Number n){
            Number temp;
            temp.num = this->num * n.num;
            return temp;
        }
        Number operator/(Number n){
            Number temp;
            temp.num = this->num / n.num;
            return temp;
        }
        //overload the binary operators
        //prefix
        Number operator++(){
            this->num++;
            return *this;
        }
        Number operator++(int postfix){
            Number temp = *this;
            this->num++;
            return temp;
        }

        //comparison operators
        bool operator==(Number n){
            return this->num == n.num;
        }
        bool operator!=(Number n){
            return this->num != n.num;
        }
        bool operator<(Number n){
            return this->num < n.num;
        }
        bool operator>(Number n){
            return this->num > n.num;
        }
        bool operator<=(Number n){
            return this->num <= n.num;
        }
        bool operator>=(Number n){
            return this->num >= n.num;
        }

        //assignment operators
        Number operator=(Number n){
            this->num = n.num;
            return *this;
        }
        Number operator+=(Number n){
            this->num += n.num;
            return *this;
        }
        Number operator-=(Number n){
            this->num -= n.num;
            return *this;
        }
        Number operator*=(Number n){
            this->num *= n.num;
            return *this;
        }
        Number operator/=(Number n){
            this->num /= n.num;
            return *this;
        }

        //overload stream operators
        friend ostream& operator<<(ostream& out, Number n){
            out << n.num;
            return out;
        }
        friend istream& operator>>(istream& in, Number& n){
            in >> n.num;
            return in;
        }
};

//now we create a derived class from Number called Complex
class Complex : public Number{
    private:
        int imaginary;

    public:
        Complex() : Number(){
            imaginary = 0;
        }
        Complex(int num, int imaginary) : Number(num){
            this->imaginary = imaginary;
        }
        //is print being overriden or overloaded? -> overriden
        void print(){
            cout << "Complex: " << num << " + " << imaginary << "i" << endl;
        }
        //overloading the basic operators
        //is the operator+ being overloaded or is it being overridden? -> it is being overloaded -> why not overridden? -> because it is not the same function
        Complex operator+(Complex n){
            Complex temp;
            temp.num = this->num + n.num;
            temp.imaginary = this->imaginary + n.imaginary;
            return temp;
        }
        Complex operator-(Complex n){
            Complex temp;
            temp.num = this->num - n.num;
            temp.imaginary = this->imaginary - n.imaginary;
            return temp;
        }
        Complex operator*(Complex n){
            Complex temp;
            temp.num = this->num * n.num;
            temp.imaginary = this->imaginary * n.imaginary;
            return temp;
        }
        Complex operator/(Complex n){
            Complex temp;
            temp.num = this->num / n.num;
            temp.imaginary = this->imaginary / n.imaginary;
            return temp;
        }

        //overload the binary operators
        //prefix
        Complex operator++(){
            this->num++;
            this->imaginary++;
            return *this;
        }
        Complex operator++(int postfix){
            Complex temp = *this;
            this->num++;
            this->imaginary++;
            return temp;
        }
        //comparison operators
        bool operator==(Complex n){
            return this->num == n.num && this->imaginary == n.imaginary;
        }
        bool operator!=(Complex n){
            return this->num != n.num || this->imaginary != n.imaginary;
        }
        bool operator<(Complex n){
            return this->num < n.num && this->imaginary < n.imaginary;
        }
        bool operator>(Complex n){
            return this->num > n.num && this->imaginary > n.imaginary;
        }
        bool operator<=(Complex n){
            return this->num <= n.num && this->imaginary <= n.imaginary;
        }
        bool operator>=(Complex n){
            return this->num >= n.num && this->imaginary >= n.imaginary;
        }

        //assignment operators
        Complex operator=(Complex n){
            this->num = n.num;
            this->imaginary = n.imaginary;
            return *this;
        }
        Complex operator+=(Complex n){
            this->num += n.num;
            this->imaginary += n.imaginary;
            return *this;
        }
        Complex operator-=(Complex n){
            this->num -= n.num;
            this->imaginary -= n.imaginary;
            return *this;
        }
        Complex operator*=(Complex n){
            this->num *= n.num;
            this->imaginary *= n.imaginary;
            return *this;
        }
        Complex operator/=(Complex n){
            this->num /= n.num;
            this->imaginary /= n.imaginary;
            return *this;
        }

        //overload stream operators
        friend ostream& operator<<(ostream& out, Complex n){
            out << n.num << " + " << n.imaginary << "i";
            return out;
        }
        friend istream& operator>>(istream& in, Complex& n){
            in >> n.num >> n.imaginary;
            return in;
        }
};




int main()
{
    // 5. Create a Dog object and call its member functions
    // 6. Create a Cat object and call its member functions
    // 7. Create a Bird object and call its member functions
    Dog dog("Rover");
    Cat cat("Fluffy");
    Bird bird("Tweety");

    // dog.getName();
    // dog.speak();
    // dog.fetch();

    // cat.getName();
    // cat.speak();
    // cat.scratch();

    // bird.getName();
    // bird.speak();
    // bird.fly();

    // playing with class pointers
    Animal *animal;
    animal = &dog;

    animal->getName();
    animal->speak();
    dog.speak();
    dog.speak(5);

    return 0;
}
