#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    // no need to do anything
}

template <class T>
Stack<T>::Stack(Stack<T> &otherStack)
{
    shared_ptr<ListItem<T>> tmp = otherStack.list.getHead();
    while (tmp != NULL)
    {
        this->list.insertAtTail(tmp->value);
        tmp = tmp->next;
    }
}

template <class T>
Stack<T>::~Stack()
{
    // no need to do anything as we are using the destructor of the linked list, which is based on smart pointers
}

template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    if(list.length() != 0)
        return list.getHead()->value;
    else{
        class emptyStackAccess{};
        throw emptyStackAccess();
    }
}

template <class T>
T Stack<T>::pop()
{

    if (list.getHead() == NULL)
    {
        throw "Stack is empty, y u pop?";
    }
    T temp = list.getHead()->value;
    list.deleteHead();
    return temp;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    return list.length() == 0;
}

#endif
