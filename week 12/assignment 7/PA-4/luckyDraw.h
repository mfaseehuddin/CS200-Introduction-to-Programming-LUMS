#ifndef LUCKYDRAW_H
#define LUCKYDRAW_H
#include "stack.cpp"
#include "queue.cpp"

class luckyDraw{

    public:
    Queue<int> lane_1;    //this lane has the winners standing         
    Queue<int> lane_2;    //this lane is empty

    Stack<int> table_1;    //this table has the gifts stacked up         
    Stack<int> table_2;    //this is the empty table and the gifts are to be shifted (stacked) here

    int totalCount;        //store the total number of gifts/winners (assuming both are the same)
    int specialVariable;   //use this variable if you need one in part (b) i.e transferStack() otherwise you are not allowed to use more than one variable in this part

    luckyDraw(int count);
    
    //populates the appropriate data structures(lane_1 and table_1) with winnersIDs and giftsIDs passed as an array.
    void populateQueue(int* winnersId);    
    void populateTable(int* giftsId);    

    void reverseQueue();     //reverses the queue in lane_1
    void transferStack();    //transfers stack of gifts from table_1 to table_2
    
};


#endif