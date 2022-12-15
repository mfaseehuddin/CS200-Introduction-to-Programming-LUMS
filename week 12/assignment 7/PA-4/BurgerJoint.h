#ifndef BurgerJoint_H
#define BurgerJoint_H
#include <fstream>
#include <vector>
#include <string>
#include "stack.cpp"
#include "queue.cpp"

using namespace std;

//struct representing a customer and their order
struct customer{
    int id;
    Stack<string> order;
};

//class representing a burger joint
class BurgerJoint
{
    public:
        //DYNAMIC ARRAY contating topping priorities
        string topping_priority[10];
        
        //TOTAL NUMBER of toppings
        int number_of_toppings;

        //QUEUE OF CUSTOMERS
        Queue<shared_ptr<customer>> customers;

        //CONSTRUCTOR
        BurgerJoint();

        ~BurgerJoint();

        //Function to return a priority number for a given topping
        int getPriority(string item);

        //Function to implement all the other functions in a sequence
        void takeawayCounter();

        //KEY FUNCTION: Function to sort out the toppings
        void assemble(Stack<string> &unsorted_toppings);

        //Function to generate final output file named takeaway.txt
        void generateOutput();
};

#endif