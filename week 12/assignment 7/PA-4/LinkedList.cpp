#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <memory>
#include "LinkedList.h"
using namespace std;

template <class T>
/**
 * @brief Construct a new Linked List< T>:: Linked List object -> default constructor
 * @exception none
 * @param none
 * @return none
 */
LinkedList<T>::LinkedList()
{
    //HEAD<-NOTHING->TAIL
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
/**
 * @brief Construct a new Linked List< T>:: Linked List object -> copy constructor
 * @exception none
 * @param otherLinkedList 
 */
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    //we will copy the other list into this list
    //but lets do this after we have implemented the other functions
    //so that we can use them here

    //we will use the insertAtTail function to insert the elements of the other list into this list
    //so we are going to traverse otherLinkedList head to tail, and use it's insertAtTail function to insert the elements into this list
    //as the nodes i.e: the ListItems are structs with public datamembers, we can access them directly

    //we will use a temporary pointer to traverse the other list
    shared_ptr<ListItem<T>> tmp = otherLinkedList.head;
    //now we will traverse the other list
    while (tmp != NULL)
    {
        //we will insert the value of the current node into this list
        this->insertAtTail(tmp->value);
        //now we will move to the next node
        tmp = tmp->next;
    }

}

template <class T>
/**
 * @brief insert an element at the head of the list
 * @exception none
 * @param item 
 */
void LinkedList<T>::insertAtHead(T item)
{
    //create a new LinkedItem
    shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(item);
    //if the list is empty
    if (this->head == NULL)
    {
        //HEAD<-NEWITEM->TAIL
        this->head = newItem;
        this->tail = newItem;
        //also as this is the only item in the list, so its next and prev will be NULL
    }
    else
    {
        //HEAD<-NEWITEM->OLDHEAD
        newItem->next = this->head; //new item points to the old head
        this->head->prev = newItem; //old head points back to the new item
        this->head = newItem;   //new item becomes the new head
        //ok sure
    }
}

template <class T>
/**
 * @brief insert an element at the tail of the list
 * @exception none
 * @param item 
 */
void LinkedList<T>::insertAtTail(T item)
{
    //create a new LinkedItem
    shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(item);
    //if the list is empty
    if (this->head == NULL)
    {
        //HEAD<-NEWITEM->TAIL
        this->head = newItem;
        this->tail = newItem;
        //also as this is the only item in the list, so its next and prev will be NULL
    }
    else
    {
        //OLDTAIL<-NEWITEM->TAIL
        newItem->prev = this->tail; //new item points back to the old tail
        this->tail->next = newItem; //old tail points forward to the new item
        this->tail = newItem;   //new item becomes the new tail
    }
}

template <class T>
/**
 * @brief insert an element after a given element
 * @exception none
 * @param toInsert 
 * @param afterWhat 
 */
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    //create new LinkedItem
    shared_ptr<ListItem<T>> newItem = make_shared<ListItem<T>>(toInsert);
    //insert afterWhat's value's first occurence
    shared_ptr<ListItem<T>> afterWhatItem = this->searchFor(afterWhat);
    //if afterWhatItem is not found
    if (afterWhatItem == NULL)
    {
        //do nothing
        return;
    }
    //if afterWhatItem is the last item
    if (afterWhatItem == this->tail)
    {
        //OLDTAIL<-NEWITEM->TAIL
        newItem->prev = this->tail; //new item points back to the old tail
        this->tail->next = newItem; //old tail points forward to the new item
        this->tail = newItem;   //new item becomes the new tail
    }
    else
    {
        //AFTERWHATITEM<-NEWITEM->AFTERWHATITEM->NEXT
        newItem->next = afterWhatItem->next; //new item points to the item after afterWhatItem
        newItem->prev = afterWhatItem;   //new item points back to afterWhatItem
        afterWhatItem->next->prev = newItem; //the item after afterWhatItem points back to the new item
        afterWhatItem->next = newItem;  //afterWhatItem points forward to the new item
    }

}


template <class T>
/**
 * @brief insert an element before a given element
 * @exception none
 * @param toInsert 
 * @param beforeWhat 
 */
shared_ptr<ListItem<T>> LinkedList<T>::getHead()
{
    return this->head;
}

template <class T>
/**
 * @brief get the tail of the list
 * @exception none
 * @param none
 * @return shared_ptr<ListItem<T>> 
 */
shared_ptr<ListItem<T>> LinkedList<T>::getTail()
{
    return this->tail;
}

template <class T>
/**
 * @brief search for an element in the list
 * @exception none
 * @param item 
 * @return shared_ptr<ListItem<T>> 
 */
shared_ptr<ListItem<T>> LinkedList<T>::searchFor(T item)
{
    //return the first occurence of item's value
    //we traverse the list from head to tail
    shared_ptr<ListItem<T>> temp = this->head;
    while (temp != NULL)
    {
        if (temp->value == item)
        {
            return temp;
        }
        temp = temp->next;
    }
    //is this correct?-> if we reach here, it means we have traversed the entire list and not found the item
    //so we return an empty smart pointer?
    return NULL;
}

template <class T>
/**
 * @brief delete an element from the list
 * @exception none
 * @param item 
 */
void LinkedList<T>::deleteElement(T item)
{
    //delete the first occurence of item's value
    //we traverse the list from head to tail
    shared_ptr<ListItem<T>> temp = this->head;
    while (temp != NULL)
    {
        if (temp->value == item)
        {
            //we have found the item
            //now we need to delete it
            //if the item is the head
            if (temp == this->head)
            {
                //HEAD<-NEXT->TAIL
                this->head = temp->next;
                this->head->prev = NULL;
            }
            //if the item is the tail
            else if (temp == this->tail)
            {
                //HEAD<-PREV->TAIL
                this->tail = temp->prev;
                this->tail->next = NULL;
            }
            //if the item is in the middle
            else
            {
                //PREV<-NEXT
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            //we have deleted the item
            //now we need to delete the temp pointer
            temp = NULL;
            //as we are using smart pointers, we don't need to delete the temp pointer
            //we have deleted the item
            //so we can return
            return;
        }
        temp = temp->next;
    }
}

template <class T>
/**
 * @brief delete the head of the list
 * @exception none
 * @param none
 */
void LinkedList<T>::deleteHead()
{
    //deleting head is simple, we just set the second item as the head
    //if the list is empty
    if (this->head == NULL)
    {
        //do nothing
        return;
    }else{
        //if the list has only one item
        if (this->head == this->tail)
        {
            //HEAD<-NOTHING->TAIL
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            //HEAD<-NEXT->TAIL
            this->head = this->head->next;
            this->head->prev = NULL;
        }
    }
}

template <class T>
/**
 * @brief delete the tail of the list
 * @exception none
 * @param none
 */
void LinkedList<T>::deleteTail()
{
    //deleting tail is simple, we just set the second last item as the tail
    //if the list is empty
    if (this->head == NULL)
    {
        //do nothing
        return;
    }else{
        //if the list has only one item
        if (this->head == this->tail)
        {
            //HEAD<-NOTHING->TAIL
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            //HEAD<-PREV->TAIL
            this->tail = this->tail->prev;
            this->tail->next = NULL;
        }
    }
}

template <class T>
/**
 * @brief return the length of the list
 * @exception none
 * @param none
 */
int LinkedList<T>::length()
{
    //as we are not storing the length of the list, we need to traverse the list to find the length
    //we will traverse head to tail
    int nodeCount = 0;
    shared_ptr<ListItem<T>> temp = this->head;
    while (temp != NULL)
    {
        nodeCount++;
        temp = temp->next;
    }
    return nodeCount;
}


//are all the functions correct?-> I have tested them and they seem to work fine
//how did you test them?-> I have tested them by creating a list and calling the functions on it

#endif
