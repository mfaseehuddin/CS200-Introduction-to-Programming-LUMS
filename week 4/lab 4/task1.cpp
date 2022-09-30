#include <iostream>
using namespace std;

/*
//create two classes:
    Counter -> a class which represents a food court point of sale system
    CounterQueue -> a class which represents a queue of customers waiting to be served
*/
int NUMBER_OF_DISHES = 4;
class Counter
{
private:
    string *dishes;
    int *quantity;

public:
    // default constructor
    Counter()
    {
        dishes = new string[NUMBER_OF_DISHES];
        quantity = new int[NUMBER_OF_DISHES];
    }
    // destructors
    ~Counter()
    {
        delete[] dishes;
        delete[] quantity;
    }
    // member functions
    void FillCounter(string *dishes, int *quantity)
    {
        for (int i = 0; i < NUMBER_OF_DISHES; i++)
        {
            this->dishes[i] = dishes[i];
            this->quantity[i] = quantity[i];
        }
    }
    void ShowCounter()
    {
        for (int i = 0; i < NUMBER_OF_DISHES; i++)
        {
            cout << dishes[i] << " -> " << quantity[i] << endl;
        }
    }
    string ServeDish(string requestedDish)
    {
        for (int i = 0; i < NUMBER_OF_DISHES; i++)
        {
            if (dishes[i] == requestedDish)
            {
                if (quantity[i] > 0)
                {
                    quantity[i]--;
                    return "Here Is Your Serving Of " + requestedDish;
                }
                else
                {
                    return "No More Servings Left";
                }
            }
        }
        return "Dish Not Found";
    }
};
class CounterQueue
{
private:
    string *queue;
    int length;
    Counter *q_counter;

public:
    // default constructor
    CounterQueue()
    {
        length = 0;
        queue = NULL;
        q_counter = NULL;
    }
    // parameterized constructor
    CounterQueue(string *customers, int length, Counter *q_counter)
    {
        this->length = length;
        this->q_counter = q_counter;
        this->queue = new string[length];
        // fill queue with customers
        for (int i = 0; i < length; i++)
        {
            queue[i] = customers[i];
        }
    }
    // destructor
    ~CounterQueue()
    {
        delete[] queue;
    }
    // member functions
    void ShowQueue()
    {
        for (int i = 0; i < length; i++)
        {
            cout << queue[i] << endl;
        }
    }
    void AddToQueue(string CustomerName)
    {
        // check if the queue is null
        if (queue == NULL)
        {
            queue = new string[1];
            queue[0] = CustomerName;
            length = 1;
        }
        else
        {
            string *temp = new string[length + 1];
            for (int i = 0; i < length; i++)
            {
                temp[i] = queue[i];
            }
            temp[length] = CustomerName;
            delete[] queue;
            queue = temp;
            length++;
        }
    }
    string ServeCustomer()
    {
        if (length > 0 && queue != NULL)
        {
            string customer = queue[0];
            string *temp = new string[length - 1];
            for (int i = 0; i < length - 1; i++)
            {
                temp[i] = queue[i + 1];
            }
            delete[] queue;
            queue = temp;
            length--;

            // deal with the current customer
            string requestedDish = "";
            cout << "Hello " << customer << ", what dish do you want? ";
            cin >> requestedDish;
            return q_counter->ServeDish(requestedDish);
        }
        return "No Customers In Queue";
    }
};
int main()
{
    string dishes[4] = {"Biryani", "Kofta", "Daal", "Roti"};
    string people[6] = {"Babar", "Humayan", "Akbar", "Shahjahan", "Jahangir", "Aurangzeb"};
    int quant[4] = {1, 2, 3, 4};
    Counter *c1 = new Counter;
    c1->FillCounter(dishes, quant);
    c1->ShowCounter();
    cout << c1->ServeDish("Biryani") << endl;
    c1->ShowCounter();
    cout << c1->ServeDish("Veggies") << endl;

    CounterQueue *q1 = new CounterQueue(people, 6, c1);
    q1->ShowQueue();
    q1->AddToQueue("Bahadur");
    q1->ShowQueue();

    for (int i = 0; i < 7; i++)
    {
        cout << q1->ServeCustomer() << endl;
    }
    delete c1;
    delete q1;

    return 0;
}