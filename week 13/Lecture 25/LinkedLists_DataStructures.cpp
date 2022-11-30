#include <iostream>
using namespace std;

// class topic: linked lists in C++

//as we studied, arrays are stored in contiguous memory locations
//this means that the memory locations are next to each other

//and vectors are dynamic arrays, which means that they can grow and shrink, hence they are addressable
//example: vector<int> v;
//v.push_back(5); //this adds 5 to the end of the vector
//v.push_back(6); //this adds 6 to the end of the vector
//indexing is still possible, so v[0] = 5, v[1] = 6

//linked lists are a different data structure
//they are not stored in contiguous memory locations
//this means that the memory locations are not next to each other
//rather, they are separate nodes which hold value and a pointer to the next and/or previous node

//example: 5 -> 6 -> 7 -> 8 -> 9 //singly linked list
//example2: 5<->6<->7<->8<->9 //doubly linked list
//the arrow is the pointer

//can we make a linked list that holds multiple data types?->yes
//how?->use a struct

class MyIntger{
    private:
        int data;
        MyIntger* next;
    public:
        MyIntger(int data){
            this->data = data;
            this->next = NULL;
        }
        void setNext(MyIntger* next){
            this->next = next;
        }
        MyIntger* getNext(){
            return this->next;
        }
        int getData(){
            return this->data;
        }
};

void printList(MyIntger* head){
    MyIntger* current = head;
    while(current != NULL){
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void addNodeAfterValue(MyIntger* head, int value, int newValue){
    MyIntger* current = head;
    while(current != NULL){
        if(current->getData() == value){
            MyIntger* newNode = new MyIntger(newValue);
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            return;
        }
        current = current->getNext();
    }
}

// void reverseList(MyIntger* head){
//     MyIntger* current = head, *prev = NULL, *next = NULL;
//     while(current != NULL){
//         next = current->getNext();
//         current->setNext(prev);
//         prev = current;
//         current = next;
//     }
//     head = prev;
// }



void deleteNode(MyIntger* head, int value){
    MyIntger* current = head, *prev = NULL;
    while(current != NULL){
        if(current->getData() == value){
            if(prev == NULL){
                head = current->getNext();
            }
            else{
                prev->setNext(current->getNext());
            }
            delete current;
            return;
        }
        prev = current;
        current = current->getNext();
    }
}

int main(){

    MyIntger* head = NULL;
    MyIntger *node1 = new MyIntger(4);
    head = node1;
    MyIntger *node2 = new MyIntger(10);
    node1->setNext(node2);
    MyIntger *node3 = new MyIntger(20);
    node2->setNext(node3);

    addNodeAfterValue(head, 10, 15);

    printList(head);

    // reverseList(head);
    deleteNode(head, 10);

    printList(head);



    return 0;
}
