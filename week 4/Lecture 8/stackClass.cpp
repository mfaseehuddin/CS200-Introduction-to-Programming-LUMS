#include <iostream>
using namespace std;


//class topic: developing a stack in C++ using classes
    //what is a stack?
        //a stack is a data structure that stores data in a LIFO (last in first out) manner
        //the last item added to the stack is the first item to be removed
        //the stack is a linear, dynamic, sequential, homogeneous data structure
            //however we are developing a static stack, meaning the size of the stack is fixed

        //from a stack we can do two operations:
            //push: add an item to the stack (top of the stack)
            //pop: remove an item from the stack
        

    //how to implement a stack in c++
        //we will be using an array to store the data
        //and we will have the following member functions
            //push: add an item to the stack
                //explain the algorithm
                    //check if the top is greater than size of stack
                        //if yes, then then resize the stack
                            //create a new array of size 2*top
                            //copy the data from the old array to the new array
                            //delete the old array
                            //update the top
                            //add the new item to the stack
                    //else
                        //add the item to the top of the stack and increment the top
            //pop: remove an item from the stack
                //explain the algorithm
                    //check if the top is less than 1/4 of the size of the stack
                        //if yes, then resize the stack
                            //create a new array of size 1/2*top
                            //copy the data from the old array to the new array
                            //delete the old array
                            //update the top
                            //return the item removed from the stack
                    //else
                        //decrement the top and return the item removed from the stack
            //peek: return the top item of the stack
                //explain the algorithm
                    //return the item at the top of the stack
            //isFull: check if the stack is full
                //explain the algorithm
                    //check if the top is equal to the size of the stack
                        //if yes, return true
                        //else return false
            //isEmpty: check if the stack is empty
                //explain the algorithm
                    //check if the top is equal to 0
                        //if yes, return true
                        //else return false
            //display: display the stack
                //explain the algorithm
                    //start from the top of the stack and print the items in the stack



class stack{
    private:
        int top;
        int size;
        int *arr;
    public:
        //default constructor
        stack(){
            top = -1;
            size = 10;
            arr = new int[size];
        }
        //parameterized constructor
        stack(int size){
            this->size = size;
            top = -1;
            arr = new int[size];
        }

        //resizeStack
        void resizeStack(){
            int *temp = new int[size*2];
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
            size = size*2;
        }

        //push
        void push(int x){
            if(top >= size-1){
                resizeStack();
                push(x);
            }else{
                top++;
                arr[top] = x;
            }
        }
        int pop(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return -1;
            }else{
                int x = arr[top];
                top--;
                return x;
            }
        }
        //peek function: returns the top element of the stack
        int peek(){
            if(top == -1){
                cout << "Stack is empty" << endl;
                return -1;
            }else{
                return arr[top];
            }
        }
        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }
        void display(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }else{
                for(int i = top; i >= 0; i--){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};


int main()
{
    stack s(5);
    // add {1,...,10}
    for(int i = 1; i <= 10; i++){
        s.push(i);
    }
    s.display();
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Is stack empty? " << s.isEmpty() << endl;
    //remove all elements
    for(int i = 0; i < 9; i++){
        s.pop();
    }
    cout << "Is stack empty? " << s.isEmpty() << endl;

    return 0;
}