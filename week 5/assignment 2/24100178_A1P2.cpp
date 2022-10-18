#include <iostream>
using namespace std;

// Task: Implement a custom vector class, that basically acts as a resizable array, and mimicks the functionality of the c++ vector class

// The vector class
class Vector
{
private:
    int *array;         // The array
    int current_size; // The size of the array
    int capacity;     // The capacity of the array
    char type;        // The type of storage of the array --> queue or stack

    // private member functions
    /**
     * @brief increase the capacity of the vector by a factor of 2 i.e: double it
     */
    void increaseCap()
    {
        capacity *= 2;
        int *tempArr = new int[capacity];
        for (int i = 0; i < current_size; i++)
        {
            *(tempArr + i) = *(array + i);
        }
        delete[] array;
        array = tempArr;
    }

public:
    /**
     * @brief default constructor
     */
    Vector()
    {
        array = new int[10];
        current_size = 0;
        capacity = 10;
        type = 's';
    }

    /**
     * @brief copy constructor
     */
    Vector(Vector &anotherVector)
    {
        current_size = anotherVector.current_size;
        capacity = anotherVector.capacity;
        type = anotherVector.type;
        array = new int[capacity];
        for (int i = 0; i < current_size; i++)
        {
            *(array + i) = *(anotherVector.array + i);
        }
    }

    /**
     * @brief destructor
     */
    ~Vector()
    {
        delete[] array;
    }

    // public member functions
    // getters
    /**
     * @brief get the size of the vector
     * @return int
     */
    int getLength() { return current_size; }

    /**
     * @brief get the head element of the vector
     * @return int
     * @exception length-error The function will throw an exception if the current_size is zero and the function is called.
     */
    int getHead()
    {
        if (current_size > 0)
        {
            return *(array + 0);
        }
        else
        {
            string errorMessage = "The element at head is undefined, current_size is 0";
            __throw_length_error(errorMessage.c_str());
        }
    }

    /**
     * @brief get the tail element of the vector
     * @exception length-error The function will throw an exception if the current_size is zero and the function is called.
     * @return int
     */
    int getTail()
    {
        if (current_size > 0)
        {
            return *(array + (current_size - 1));
        }
        else
        {
            string errorMessage = "The element at tail is undefined, current_size is 0";
            __throw_length_error(errorMessage.c_str());
        }
    }

    // state getters
    /**
     * @brief check if the vector is empty
     * @return true: if current_size > 0 else
     * @return false
     */
    bool isEmpty()
    {
        bool result = current_size > 0 ? false : true;
        return result;
    }

    /**
     * @brief check if the vector is full
     * @return true: if current_size == capacity else
     * @return false
     */
    bool isFull()
    {
        bool result = current_size == capacity ? true : false;
        return result;
    }

    // setters
    /**
     * @brief set the type of storage model of the vector
     * @param new_type
     * @exception invalid_argument if characters other than 's' or 'q' are passed to changeType in the function call, an invalid_argument exception will be thrown.
     */
    void changeType(char new_type)
    {
        if (new_type == 's' || new_type == 'q')
        {
            type = new_type;
            return;
        }
        string errorMessage = "Invalid Data structure type passed to changeType, only 's' or 'q' are allowed.";
        __throw_invalid_argument(errorMessage.c_str());
    }

    // type independant insertion deletion
    /**
     * @brief insert an element at the head of the vector -> resize if needed
     * @param num
     */
    void insertAtHead(int num)
    {
        if (this->isFull())
        {
            this->increaseCap();
        }
        for (int i = current_size; i > 0; i--)
        {
            *(array + i) = *(array + (i - 1));
        }
        *(array + 0) = num;
        current_size++;
    }

    /**
     * @brief insert an element at the tail of the vector -> resize if needed
     * @param num
     */
    void insertAtTail(int num)
    {
        if (this->isFull())
        {
            this->increaseCap();
        }
        *(array + current_size) = num;
        current_size++;
    }

    /**
     * @brief delete an element from the head of the vector
     * @exception length-error The function will throw an exception if the current_size is zero and the function is called.
     */
    void deleteHead()
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < current_size; i++)
            {
                *(array + i) = *(array + (i + 1));
            }
            current_size--;
            return;
        }
        string errorMessage = "Invalid deleteTail call, the length of the vector is zero";
        __throw_length_error(errorMessage.c_str());
    }

    /**
     * @brief delete an element from the tail of the vector
     * @exception length-error The function will throw an exception if the current_size is zero and the function is called.
     */
    void deleteTail()
    {
        if (!this->isEmpty())
        {
            //? should I set it to null or just leave it as it is?
            // solution: set it to lowest possible value, as we can not set it to null without generating a compiler error. So even if the array is resized and printed somehow it will be apparent.
            *(array + current_size) = numeric_limits<int>::lowest();
            current_size--;
            return;
        }
        string errorMessage = "Invalid deleteTail call, the length of the vector is zero";
        __throw_length_error(errorMessage.c_str());
    };

    // type dependent insertion and deletion
    /**
     * @brief insert an element at the head or tail of the vector depending on the type of storage model -> STACK IS FILO & Queue is FIFO
     * @param num
     */
    void push(int num)
    {
        if (this->isFull())
        {
            this->increaseCap();
        }

        if (this->type == 's')
        {
            this->insertAtTail(num);
        }
        else
        {
            this->insertAtTail(num);
        }
    }

    /**
     * @name pop
     * @brief delete an element from the head or tail of the vector depending on the type of storage model -> returns the first element in case of a queue and the last element in case of a stack
     * @exception length-error The function will throw an exception if the current_size is zero and the function is called.
     * @return int
     */
    int pop()
    {
        if (this->isEmpty() == false)
        {
            if (this->type == 's')
            {
                int temp = this->getTail();
                this->deleteTail();
                return temp;
            }
            else
            {
                int temp = this->getHead();
                this->deleteHead();
                return temp;
            }
        }
        string errorMessage = "The vector is empty";
        __throw_length_error(errorMessage.c_str());
    }

    // non assignment member functions
    /**
     * @brief Print the vector, current_size, and capacity
     */
    void printVector()
    {
        cout << "Vector: [";
        for (int i = 0; i < current_size; i++)
        {
            cout << *(array + i) << ", ";
        }
        (current_size == 0) ? cout << "" : cout << "\b\b";
        cout << "] current_size: " << current_size << ", capacity: " << capacity << endl;
    }
    friend class VectorTest;
};