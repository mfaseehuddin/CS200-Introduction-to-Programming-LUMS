#include <iostream>
#include <stack>

using namespace std;

void menu()
{
    stack<string> stack;

    while (true)
    {
        cout << "1. Push a string" << endl;
        cout << "2. Pop a string" << endl;
        cout << "3. End" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the string to be pushed: ";
            string s;
            cin >> s;
            // push the string to the stack
            stack.push(s);
        }
        else if (choice == 2)
        {
            cout << "The popped string is: ";
            // pop the string from the stack
            if(!stack.empty()){
                cout << stack.top() << endl;
                stack.pop();
            }else{
                cout << "Stack is empty, y u pop?" << endl;
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}