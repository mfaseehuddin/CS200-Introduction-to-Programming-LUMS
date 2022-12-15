#ifndef BurgerJoint_CPP
#define BurgerJoint_CPP
#include "BurgerJoint.h"

/*
    Helper function to tell whether the
    given string is a number or not
*/
bool isNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!(isdigit((unsigned char)str[i])))
        {
            return false;
        }
    }

    return true;
}
//^is complete

/*
    Constructor:
    1. Load topping priority from topping_priority.txt into
       topping_priority attribute
    2. Load every customers' unsorted toppings form
       assembly line - load data from assembly.txt
       into customers queue

    For you convenience this has been done!
*/
BurgerJoint::BurgerJoint()
{
    ifstream fin("topping_priority.txt");

    string line;

    int count = 0;

    while (getline(fin, line))
    {
        topping_priority[count] = line;
        count++;
    }

    // saving number of toppings
    number_of_toppings = count;

    fin.close();

    // loading customers' unsorted toppings from assembly line
    fin.open("assembly.txt");

    bool first_line = true;

    int total_customers;
    int cust_id;

    LinkedList<string> lines;

    // reading all lines
    while (getline(fin, line))
    {
        lines.insertAtTail(line);
    }

    fin.close();

    shared_ptr<ListItem<string>> ptr = lines.getHead();

    ptr = lines.getHead();

    // adding customers with correct id and toppings into
    // customers queue
    while (ptr != NULL)
    {
        line = ptr->value;
        if (first_line)
        {
            // noting down total customers
            total_customers = stoi(line);
            first_line = false;
            ptr = ptr->next;
        }

        else
        {
            // noting down customer id
            cust_id = stoi(line);

            ptr = ptr->next;

            shared_ptr<customer> new_cust(new customer);
            new_cust->id = cust_id;

            // noting down customer unsorted toppings
            while (ptr != NULL)
            {
                line = ptr->value;
                if (isNumber(ptr->value))
                {
                    break;
                }
                new_cust->order.push(line);
                ptr = ptr->next;
            }

            // enqueuing customer
            customers.enqueue(new_cust);
        }
    }
}
//^is complete

/*
    Function to fetch priority of a topping.
    Matches prioirity from topping_priority list.
*/
int BurgerJoint::getPriority(string item)
{

    for (int i = 0; i < number_of_toppings; i++)
    {
        if (topping_priority[i] == item)
        {
            return i;
        }
    }
    return number_of_toppings+10;
}

// destructor
BurgerJoint::~BurgerJoint()
{
}

/*
    You have two stacks:
    1. unsorted_toppings
    2. temp_stack

    You have one variable:
    1. temp

    DONOT CREATE ANYMORE VARIABLES OR DATASTRUCTURES IN THIS FUNCTION

    Use the above mentioned variable and datastructures to sort the
    unsorted_toppings stack.
    You need to sort it according to "topping_priority"
*/
// void prettyPrintStack(Stack<string> stack)
// {
//     while (!stack.isEmpty())
//     {
//         cout << stack.pop() << " ";
//     }
//     cout << endl;
// }

void BurgerJoint::assemble(Stack<string> &unsorted_toppings)
{
    Stack<string> temp_stack;
    string temp;
    // no more variables can be declared
    temp_stack.push("flag");
    while (true)
    { // start doing stuff
        temp = unsorted_toppings.pop();
        while (!unsorted_toppings.isEmpty()) // empty the stack completely into temp_stack
        {
            // keep storing the smallest in the temp var
            if (getPriority(temp) > getPriority(unsorted_toppings.top())) // when temp is bigger than the top in unsorted_toppings
            {
                temp_stack.push(temp);          // put the temp in the stack
                temp = unsorted_toppings.pop(); // put the top of unsorted_toppings in the temp_stack
            }
            else
            {
                temp_stack.push(unsorted_toppings.pop()); // just put top of unsorted_topping into temp_stack;
            }
        }

        while (temp_stack.top() != "flag")
        {
            unsorted_toppings.push(temp_stack.pop()); // transfering the unsorted stuff to unsorted_toppings
        }
        unsorted_toppings.push(temp_stack.pop()); // transfering the flag too

        temp_stack.push(temp);

        if (unsorted_toppings.top() == "flag" && unsorted_toppings.length() == 1)
        {
            break;
        }
    }

    unsorted_toppings.pop();

    while (!temp_stack.isEmpty())
    {
        unsorted_toppings.push(temp_stack.pop());
    }
}

/*
    Generate an output file similar to assembly.txt.
    The toppings need to be in a sorted order in this file.
    Moreover, every customer needs to hace the correct toppings.

    NAME THE OUTPUT TEXT FILE takeaway.txt
*/
void BurgerJoint::generateOutput()
{
    for (int i = 0; i < customers.length(); i++) // rotate the customers
    {
        // handle each customer
        assemble(customers.front()->order); // assembling the orders
        customers.enqueue(customers.dequeue());
    }

    ofstream fout("takeaway.txt");
    fout << customers.length() << endl;
    while (!customers.isEmpty())
    {
        shared_ptr<customer> temp = customers.dequeue();
        // printing
        fout << temp->id << endl;
        while (!temp->order.isEmpty())
        {
            fout << temp->order.pop() << endl;
        }
    }
}

void BurgerJoint::takeawayCounter()
{
    generateOutput();
}

#endif