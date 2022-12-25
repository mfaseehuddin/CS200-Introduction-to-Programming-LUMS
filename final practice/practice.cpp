#include <iostream>
#include <vector>
using namespace std;

void printLargestThree(int arr[], int size)
{

    int arrCpy[size];

    for (int i = 0; i < size; i++)
    {
        arrCpy[i] = arr[i];
    }

    // bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arrCpy[j] < arrCpy[j + 1])
            {
                int temp = arrCpy[j];
                arrCpy[j] = arrCpy[j + 1];
                arrCpy[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrCpy[i] << " ";
    }
    cout << endl;

    cout << "Three Largest: " << arrCpy[0] << " " << arrCpy[1] << " " << arrCpy[2];
}

void recursive_add(int total, int size)
{
    int inp;
    cout << "Enter a new number: ";
    cin >> inp;
    if (inp == 0)
    {
        cout << "Avg: " << total / size;
        return;
    }

    recursive_add(total + inp, size + 1);
}
void recursive_add_v2()
{
    static int total = 0, size = 0;
    int inp;
    cout << "Enter a new number: ";
    cin >> inp;
    if (inp == 0)
    {
        cout << "Avg: " << total / size;
        return;
    }

    total += inp;
    size++;

    recursive_add_v2();
}

struct Student
{
    char name[30];
    int age;
    int grade;
};

struct Empty
{
};

class Ptr
{
private:
    int *ptr;

public:
    Ptr(int *_ptr)
    {
        ptr = _ptr;
    }
    int getVal()
    {
        return *ptr;
    }
};
class ok
{
private:
    int a = 0;

public:
    void wow()
    {
        cout << "100";
        a += 2;
    }
    void print() { cout << a; }
};

class Base
{
private:
    int x;

public:
    Base() : x(2)
    {
        cout << x;
    }
    ~Base() {}
    void Display()
    {
        cout << x;
    }
};
class Derived : public Base
{
private:
    int y;

public:
    Derived()
    {
        y = 3;
    }
    ~Derived() {}
    void Display()
    {
        cout << y;
        Base *ptr = this;
        ptr->Display();
    }
};

class hehe
{
    friend ostream &operator<<(ostream &out, hehe &h)
    {
        out << "Output";
        return out;
    }
};

struct Node
{
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
        head = NULL;
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

    void MergeSorted_Dep(LinkedList &other)
    {
        Node *thisListTraverser = head;
        Node *otherListTraverser = other.head;

        while (thisListTraverser->next != NULL)
        {

            // we have three cases here, we will only deal with ascending order of both lists

            // case 1: thisListTraverser->data < otherListTraverser->data < thisListTraverser->next->data
            if (thisListTraverser->data < otherListTraverser->data && otherListTraverser->data < thisListTraverser->next->data)
            {
                // we made new node to store otherListTraverser->data
                Node *newNode = new Node(otherListTraverser->data);
                // we set the newNode->next to thisListTraverser->next
                newNode->next = thisListTraverser->next;
                // we set thisListTraverser->next to newNode
                thisListTraverser->next = newNode;
                // we set otherListTraverser to otherListTraverser->next
                otherListTraverser = otherListTraverser->next;
            }
            // reset otherListTraverser

            // traversal
            thisListTraverser = thisListTraverser->next;
        }
        // move forward one
        otherListTraverser = otherListTraverser->next;
        // here we have to deal with remaining nodes in otherListTraverser
        // so we set the last of the thisListTraverser to the remaining nodes in otherListTraverser
        //  thisListTraverser->next = otherListTraverser;
        while (otherListTraverser != NULL)
        {
            // copy data aand set next to null
            Node *newNode = new Node(otherListTraverser->data);
            // set thisListTraverser->next to newNode
            thisListTraverser->next = newNode;
            // traversal
            thisListTraverser = thisListTraverser->next;
            otherListTraverser = otherListTraverser->next;
        }
    }
    // void MergeSorted(LinkedList &other)
    // {
    //     Node *thisListTraverser = head;
    //     Node *otherListTraverser = other.head;

    //     while (thisListTraverser != NULL && otherListTraverser != NULL)
    //     {
    //         if (thisListTraverser->data < otherListTraverser->data)
    //         {
    //             thisListTraverser = thisListTraverser->next;
    //         }
    //         else
    //         {
    //             Node *temp = otherListTraverser;
    //             otherListTraverser = otherListTraverser->next;
    //             temp->next = thisListTraverser->next;
    //             thisListTraverser->next = temp;
    //             thisListTraverser = thisListTraverser->next;
    //         }
    //     }
    //     if (otherListTraverser != NULL)
    //     {
    //         thisListTraverser->next = otherListTraverser;
    //     }
    // }

    void MergeSorted(LinkedList &other)
    {
        Node *ptr1 = head;
        Node *ptr2 = other.head;
        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data < ptr2->data)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                Node *temp = ptr2;
                ptr2 = ptr2->next;
                temp->next = ptr1->next;
                ptr1->next = temp;
                ptr1 = ptr1->next;
            }
        }
        if (ptr2 != NULL)
        {
            ptr1->next = ptr2;
        }
    }
};

vector<string> FindNumbers(vector<string> &str)
{
    vector<string> result;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            if (isdigit(str[i][j]))
            {
                result.push_back(str[i]);
                break;
            }
        }
    }
    return result;
}

int main()
{
    // srand(time(NULL));
    // int arrLen = 10;
    // int arr[arrLen];
    // for (int i = 0; i < arrLen; i++)
    // {
    //     arr[i] = rand() % 200;
    // }

    // for (int i = 0; i < arrLen; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // printLargestThree(arr, arrLen);
    // cout << endl;

    // recursive_add_v2();

    // struct Student *student = new Student({"John", 90,90});

    // cout << student->name << endl;
    // cout << student->age << endl;
    // cout << student->grade << endl;

    // cout << sizeof(Empty) << endl;
    // Empty emp;
    // cout << sizeof(emp) << endl;

    // int p = 10;
    // Ptr ptr(&p);
    // cout << ptr.getVal() << endl;

    // ok oko;
    // oko.wow();
    // oko.wow();
    // oko.wow();
    // oko.print();

    // Derived d;
    // d.Display();
    // return 0;

    // hehe a, b;
    // cout << a << b;
    // return 0;

    // LinkedList l1;
    // for (int i = 10; i > 0; i -= 2)
    // {
    //     l1.InsertAtTail(i);
    // }

    // LinkedList l2;
    // for (int i = 15; i > 3; i -= 3)
    // {
    //     l2.InsertAtTail(i);
    // }

    // l1.Display();
    // l2.Display();

    // cout << "\n\n";

    // l1.MergeSorted(l2);
    // l1.Display();
    // l2.Display();

    vector<string> str = {"1a2b3c", "4d5e6f", "7g8h9i", "Faseeh"};
    vector<string> result = FindNumbers(str);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}