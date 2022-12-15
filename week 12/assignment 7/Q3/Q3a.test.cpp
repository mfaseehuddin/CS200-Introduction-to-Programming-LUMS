#include <iostream>
#include "../PA-4/luckyDraw.cpp"

using namespace std;

void prettyPrintQueue(Queue<int> q)
{
    cout << "Queue: ";
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;
}


void prettyPrintStack(Stack<int> s)
{
    cout << "Stack: ";
    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;
}

int main()
{
    luckyDraw ld(5);
    int winnersId[5] = {1, 2, 3, 4, 5};
    int giftsId[5] = {5, 4, 3, 2, 1};
    ld.populateQueue(winnersId);
    ld.reverseQueue();
    prettyPrintQueue(ld.lane_1);
    prettyPrintQueue(ld.lane_2);

    ld.populateTable(giftsId);
    ld.transferStack();


    // cout << endl << numeric_limits<int>::lowest() << endl;

    cout << "Table 1: ";
    prettyPrintStack(ld.table_1);
    cout << "Table 2: ";
    prettyPrintStack(ld.table_2);

    return 0;
}