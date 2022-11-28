#include <iostream>
using namespace std;



//how to use smart pointers?->to use smart pointers, we need to include <memory> header file
//then we need to use shared_ptr, unique_ptr, weak_ptr
//example:
//shared_ptr<int> p1(new int(10));
//shared_ptr<int> p2(p1);
//cout << *p1 << endl;
//cout << *p2 << endl;
//p1.reset();//what does this do?->it will delete the pointer
//cout << *p2 << endl;
//cout << p1 << endl;//what happens after p1.reset()?->it will print 0
//what if we try to dereference p1?->it will give segmentation fault
//so even smart pointers are not safe, we need to be careful while using them
//ezpz




int main()
{
    
    return 0;
}