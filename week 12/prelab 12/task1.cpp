#include <iostream>
#include <vector>
using namespace std;

template <class T>
void addToVector(vector<T> &v, T x)
{
    v.push_back(x);
}

template <class T>
void printVector(vector<T> &v)//using iterators auto syntax
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}



void menu(){
    vector<string> v;
    while (true)
    {
        cout << "1. Add" << endl;
        cout << "2. End" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the item to be added: ";
            string item;
            cin >> item;
            // add the item to the list
            addToVector(v, item);
        }
        else if (choice == 2)
        {
            cout << "The list is: ";
            //sort the vector before printing
            sort(v.begin(), v.end());//how does this sort? Ascending to descending?-> Ascending
            printVector(v);
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
    //calling menu
    menu();
    return 0;
}