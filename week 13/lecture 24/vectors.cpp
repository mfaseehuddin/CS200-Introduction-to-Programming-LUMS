// class topic: stdlib
#include <iostream>
// we will be using the vector class
#include <vector>

using namespace std;




struct ptest
{
    int x;
    int y;
    int z;
};

template <class T>
class test
{
private:
    T p;

public:
    test(T p)
    {
        this->p = p;
    }
    void print()
    {
        cout << p.x << " " << p.y << " " << p.z << endl;
    }
    void changeP(T p) const
    {
        this->p.x = p.x;
    }
};







int main()
{
    // making a vector of integers
    vector<int> v;
    // adding elements to the vector
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // using the auto data type to add elements
    for (auto t : v) // what does this line do?-> it is a for loop that goes through the vector v
    {
        cout << t << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        // or
        //  cout << v.at(i) << " ";
    }

    // using iterators
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // reverse iterator
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // another way to print the vector
    for (auto it = v.end() - 1; it != v.begin() - 1; it--) // why is this incorrect way to print the list in reverse?-> it is not incorrect, it is just a different way to print the list in reverse
    {
        cout << *it << " ";
    }
    cout << endl;

    // creating another vector with allocator defined
    //  vector<int, allocator<int>> v2;//what is the difference between this and the previous vector?-> this one has a defined allocator
    // what is an allocator?-> it is a class that allocates memory for the vector

    test<ptest> t({1, 2, 3});
    t.print();
    // t.changeP({4, 5, 6});

    return 0;
}