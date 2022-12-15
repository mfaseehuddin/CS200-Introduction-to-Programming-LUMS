#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
    // no need to do anything
}
    
template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
    shared_ptr<ListItem<T>> tmp = otherQueue.list.getHead();
    while (tmp != NULL)
    {
        this->list.insertAtTail(tmp->value);
        tmp = tmp->next;
    }
}

template <class T>
Queue<T>::~Queue()
{
    // no need to do anything as we are using the destructor of the linked list, which is based on smart pointers
}

template <class T>
void Queue<T>::enqueue(T item)
{
    //adding to the tail
    list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
    //returning the head
    return list.getHead()->value;
}

template <class T>
T Queue<T>::dequeue()
{
    if (list.getHead() == NULL)
    {
        throw "Queue is empty, y u pop?";
    }
    T temp = list.getHead()->value;
    list.deleteHead();
    return temp;
}

template <class T>
int Queue<T>::length()
{
    return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return list.length() == 0;
}


#endif
