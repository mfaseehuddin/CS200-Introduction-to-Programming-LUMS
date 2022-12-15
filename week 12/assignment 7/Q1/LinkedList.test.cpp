#include <iostream>
#include "LinkedList.cpp"

using namespace std;

template<class T>
//pretty print list
void prettyPrint(LinkedList<T> &list)
{
    shared_ptr<ListItem<T>> temp = list.getHead();
    while (temp != NULL)
    {
        // cout << temp->value << " ";
        if(temp->next != NULL)
        {
            cout << temp->value << " <-> ";
        }
        else
        {
            cout << temp->value;
        }
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    LinkedList<int> l;

    //try all the delete functions on the empty list
    l.deleteElement(1);
    l.deleteHead();
    l.deleteTail();


    for (int count = 0; count < 10; count++)
    {
        l.insertAtHead(count);
    }
    for (int count = 0; count < 5; count++)
    {
        l.insertAtTail(count);
    }
    LinkedList<int> l2(l);
    //delete 5
    l.deleteElement(5);
    //delete head and tail
    l.deleteHead();
    l.deleteTail();
    //delete 0
    l.deleteElement(0);

    
    cout <<"First List: \n";
    prettyPrint(l);
    
    cout << "Head: " << l.getHead()->value << endl;
    cout << "Tail: " << l.getTail()->value << endl;
    cout << "Length: " << l.length() << endl;

    //search for 5
    cout << "Search for 5: " << ((l.searchFor(5) != NULL) ? "Found" : "Not Found") << endl;


    
    cout <<"Second List: \n";
    prettyPrint(l2);
    return 0;
}