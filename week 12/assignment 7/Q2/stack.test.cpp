#include <iostream>
#include "../PA-4/stack.cpp"

using namespace std;


void prettyPrint(Stack<int> stack)
{
    cout << "Stack: ";
    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;
}


int main()
{
    Stack<int> s;

    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }
    prettyPrint(s);
    for (int i = 0; i < 5; i++)
    {
        s.pop();
    }
    prettyPrint(s);
    for (int i = 0; i < 6; i++)
    {
        s.push(i);
    }



    prettyPrint(s);
    

    Stack<int> s2(s);
    prettyPrint(s2);



    return 0;
}