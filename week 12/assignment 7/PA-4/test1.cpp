#include <cstdio>
#include <signal.h>
#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.cpp"
#include <memory>
using namespace std;

int testno;
float totpoints;
float lastpoints;
float lasttotpoints;
float points;

vector<int> GenerateRandom();

void test_list_init()
{
    lasttotpoints = 0;

    LinkedList<int> a;
    cout << ".";

    LinkedList<string> b;
    cout << ".";

    LinkedList<LinkedList<int> > c;
    cout << ".";
}

void test_list_insert_head()
{
    lasttotpoints = 2.5;

    LinkedList<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.insertAtHead(i);
        shared_ptr<ListItem<int>> tmp = l.getHead();
        int k = i;
        while (tmp != NULL)
        {
            if (tmp->value != k)
                int a = 1/0;
            k--;
            tmp = tmp->next;
        }
    }
    cout << ".";

    lastpoints += 2.5;
}

void test_list_insert_tail()
{
    lasttotpoints = 5;

    LinkedList<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.insertAtTail(i);
        shared_ptr<ListItem<int>> tmp = l.getTail();
        int k = i;
        while (tmp != NULL)
        {
            if (tmp->value != k)
                int a = 1/0;
            k--;
            tmp = tmp->prev;
        }
    }
    cout << ".";

    lastpoints += 5;
}

void test_list_insert_after()
{
    lasttotpoints = 5;

    LinkedList<int> l;
    l.insertAtHead(0);
    for (int i = 1; i < 25000; i++)
    {
        l.insertAfter(i, i-1);
        shared_ptr<ListItem<int>> tmp = l.searchFor(i);
        if (tmp->next != NULL || tmp->prev->value != (i-1) || tmp->value != i)
            int a = 1/0;
	}
    cout << ".";

    lastpoints += 5;
}



void test_delete()
{
    lasttotpoints = 10;

    // Insert some items
    LinkedList<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.insertAtHead(i);
    }

    // Delete the head a few times
    for (int i = 0; i < 50; i++)
        l.deleteHead();

	int length = l.length();
	if(length != 24950)
		int a = 1/0;

    cout << ".";
    lastpoints += 2.5;

    // Delete most of the items in the list
    while (l.length() > 50)
    {
        shared_ptr<ListItem<int>> tmp = l.getHead();
        if (tmp != NULL)
            l.deleteElement(tmp->value);
        tmp = l.getTail();
        if (tmp != NULL)
            l.deleteElement(tmp->value);
	}
    lastpoints += 5;
    cout << ".";

    // Delete the tail till we're done
    int max = l.length();
    for (int i = 0; i < max; i++)
        l.deleteTail();
	cout << ".";
    lastpoints += 2.5;
}

void test_copy()
{
    lasttotpoints = 2.5;

    LinkedList<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.insertAtHead(i);
    }
    LinkedList<int> l2(l);
    LinkedList<int> l3;
    for (int i = 0; i < 25000; i++)
    {
        l3.insertAtHead(i);
        l.deleteHead();
    }
    shared_ptr<ListItem<int>> tmp = l2.getHead();
    int k = 24999;
    while (tmp != NULL)
    {
        if (tmp->value != k)
            int a = 1/0;
        k--;
        tmp = tmp->next;
    }
    if (k != -1)
        int a = 1/0;

    cout << ".";

    lastpoints += 2.5;
}

void test_search()
{
    lasttotpoints = 5;

    // Insert some items
    LinkedList<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.insertAtHead(i);
    }

    shared_ptr<ListItem<int>> tmp;
	//Search for values that are present
	for(int i = 0; i < 25000; i++)
	{
		tmp = l.searchFor(i);
		if(tmp->value != i)
			int a = 1/0;
	}
	cout << ".";
	lastpoints += 2.5;

	//Search for values that are NOT present
	for(int i = 25000; i < 50000; i++)
	{
		tmp = l.searchFor(i);
		if(tmp != NULL)
			int a = 1/0;
	}
	cout << ".";
	lastpoints += 2.5;
}


// Test case dispatcher
void dispatcher()
{
    while (true)
    {
        lastpoints = 0;
        lasttotpoints = 0;
        switch (testno)
        {
            case 0:
                {
                    cout << "Testing LinkedList Initialization ";
                    test_list_init();
                }
                break;
            case 1:
                {
                    cout << "Testing Insertion at Head ";
                    test_list_insert_head();
                }
                break;
            case 2:
                {
                    cout << "Testing Insertion at Tail ";
                    test_list_insert_tail();
                }
                break;
            case 3:
                {
                    cout << "Testing Insertion After ";
                    test_list_insert_after();
                }
                break;
            case 4:
                {
                    cout << "Testing Delete ";
                    test_delete();
                }
                break;
            case 5:
                {
                    cout << "Testing Copy ";
                    test_copy();
                }
                break;
			case 6:
				{
                    cout << "Testing Search ";
                    test_search();
				}
				break;
            default:
                {
                    cout << "Total Points: " << points << " / " << totpoints << endl << endl;
                    exit(0);
                }
        }
        cout << " Passed! " << lastpoints << " / " << lasttotpoints << endl;
        testno++;
        points += lastpoints;
        totpoints += lasttotpoints;
    }
}

// Signal handler for exceptions
void signal_handler(int signum)
{
    cout << " Failed! " << lastpoints << " / " << lasttotpoints << endl;

    testno++;
    points += lastpoints;
    totpoints += lasttotpoints;

    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    dispatcher();
}

int main()
{
    // Set signal handlers
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);

    cout << "Starting Tests" << endl;

    testno = 0;
    points = 0;
    totpoints = 0;
    dispatcher();
}

// Just some friendly number theory :)
vector<int> GenerateRandom()
{
	vector <int> nums;
	int residue;
	for(int k=0; k<25000; k++)
	{
		residue = (k*31)%3571;
		nums.push_back(residue);
	}
	return nums;
}
