#include <iostream>
#include "BurgerJoint.cpp"

using namespace std;

void printArray(string arr[], int size, string msg)
{
    cout << msg << ": ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printStack(Stack<string> stack)
{
    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;
}

void prettyPrintCustomers(Queue<shared_ptr<customer>> bjCustomers)
{
    while (!bjCustomers.isEmpty())
    {
        shared_ptr<customer> temp = bjCustomers.dequeue();
        // printing
        cout << "Customer Id: " << temp->id << endl;
        while (!temp->order.isEmpty())
        {
            cout << temp->order.pop() << endl;
        }
    }
}

int main()
{
    BurgerJoint b;
    // prettyPrintCustomers(b.customers);
    b.takeawayCounter();

    // b.takeawayCounter();
    Stack<string> toppings;
    string toppingsData[] = {
        "chipotle",
        "mayo",
        "bbun",
        "tbun",
        "patty",
        "lettuce",
        "ketchup",
        "mustard",
        "pickles"};

    for (int i = 0; i < 9; i++)
    {
        toppings.push(toppingsData[i]);
    }

    printArray(b.topping_priority, 10, "topping priority: ");

    cout << "Unsorted Priority Initial: ";
    printStack(toppings);
    cout << "\n\n\n";

    b.assemble(toppings);

    cout << "Sorted Priority: ";
    printStack(toppings);

    return 0;
}