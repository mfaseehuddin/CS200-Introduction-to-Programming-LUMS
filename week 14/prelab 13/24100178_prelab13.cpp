#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    friend ostream &operator<<(ostream &out, Node printNode)
    {
        if (printNode.next != nullptr)
            out << printNode.data << "->";
        else
            out << printNode.data;

        return out;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    // LinkedList(LinkedList &listToCopy)
    // {
    //     Node *traversalNode = listToCopy.head;
    //     if (traversalNode == nullptr){
    //         head = nullptr;
    //         return;
    //     }
    //     while (traversalNode->next != nullptr)
    //     {
    //         InsertAtTail(traversalNode->data);
    //         traversalNode = traversalNode->next;
    //     }
    // }
    void InsertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
        }
        else
        {
            Node *tempHead = new Node(data);
            tempHead->next = head;
            head = tempHead;
        }
    }
    void InsertAtTail(int data)
    {
        // if head is null
        if (head == nullptr)
        {
            head = new Node(data);
            return;
        }

        // find tail
        Node *tempTail = head;
        while (tempTail->next != nullptr)
        {
            tempTail = tempTail->next;
        }
        tempTail->next = new Node(data);
    }
    void InsertAtIndex(int data, int idx)
    {
        int index = 0;
        Node *traversalNode = head;
        if (idx == 0)
        {
            InsertAtHead(data);
            return;
        }
        while (traversalNode != nullptr)
        {
            if (index == idx - 1)
            {
                Node *tempNode = new Node(data);
                tempNode->next = traversalNode->next;
                traversalNode->next = tempNode;
                return;
            }
            index++;
            traversalNode = traversalNode->next;
        }
        class invalidIndex
        {
        };
        throw invalidIndex();
    }
    void RemoveHead()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *tempHead = head->next;
        delete head;
        head = tempHead;
    }
    void RemoveTail()
    {
        if (head == nullptr)
            return;
        Node *tempTail = head;
        while (tempTail->next != nullptr && tempTail->next->next != nullptr)
        {
            tempTail = tempTail->next;
        }
        delete tempTail->next->next;
        tempTail->next = nullptr;
    }
    void RemoveIndex(int idx)
    {
        int index = 0;
        Node *traversalNode = head;
        if (idx == 0)
        {
            RemoveHead();
            return;
        }
        while (traversalNode != nullptr)
        {
            if (index == idx - 1)
            {
                Node *nextNode = traversalNode->next->next;
                delete traversalNode->next;
                traversalNode->next = nextNode;
                return;
            }
            index++;
            traversalNode = traversalNode->next;
        }
        class invalidIndex
        {
        };
        throw invalidIndex();
    }
    void Display()
    {
        Node *traversalNode = head;
        while (traversalNode != nullptr)
        {
            cout << (*traversalNode);
            traversalNode = traversalNode->next;
        }
        cout << endl;
    }
    friend ostream &operator<<(ostream &out, LinkedList &printList)
    {
        Node *traversalNode = printList.head;
        while (traversalNode != nullptr)
        {
            out << (*traversalNode);
            traversalNode = traversalNode->next;
        }
        out << endl;
        return out;
    }
    ~LinkedList()
    {
        Node *traversalNode = head;
        if (traversalNode->next == nullptr)
        {
            delete traversalNode;
            head = nullptr;
            return;
        }
        Node *nextTraversalNode = traversalNode->next;
        while (nextTraversalNode != nullptr)
        {
            delete traversalNode;
            traversalNode = nextTraversalNode;
            nextTraversalNode = traversalNode->next;
        }
    }
};

int main()
{
    // testing Linked List

    LinkedList list;
    for (int i = 0; i < 10; i++)
    {
        list.InsertAtTail(i);
    }

    // list.InsertAtIndex(69,5);
    // cout << list;


    for (int i = 0; i < 11; i++)
    {
        list.InsertAtIndex(69,i);
        cout << list;
        list.RemoveIndex(i);
    }

    return 0;
}