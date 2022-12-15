#include <iostream>
#include "luckyDraw.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char** argv){

    if (argc < 2)
    {
    	cout << "Please specify the number of winners/gifts! " << endl;
    	exit(0);
    }

    int count = stoi(argv[1]);
    
    int arr[count];
    int flag = 0;
    int score = 0;
    for(int i = 0; i < count; i++){
        arr[i] = rand();
    }
    
    luckyDraw test(count);
    test.populateQueue(arr);
    test.populateTable(arr);
    test.reverseQueue();
    test.transferStack();

    if(test.lane_1.length() != count || test.lane_2.length()){
        flag = 1;
        cout<<"Queue rearrangement failed! ...  ";
        cout<<"0/15"<<endl;
    }
    
    if(!flag){
        for(int i = count-1 ; i >= 0; i--){
            if (!(arr[i] == test.lane_1.dequeue())){
                cout<<"Queue rearrangement failed! ...  ";
                cout<<"0/15"<<endl;
                flag = 1;
                break;
            }
        }
    }

    if(!flag){
        cout<<"Queue rearrangement passed! ...  ";
        score += 15;
        cout<<"15/15"<<endl;
    }
    
    flag = 0;

    if (test.table_2.length() != count || test.table_1.length()){
        cout<<"Stack transfer failed! ...   ";
        cout<<"0/15"<<endl;
        flag = 1;
    }
    
    if(!flag){
        for(int i = count-1 ; i >= 0; i--){

            if (!(arr[i] == test.table_2.pop())){
                cout<<"Stack transfer failed! ...   ";
                cout<<"0/15"<<endl;
                flag = 1;
                break;
            }
        }
    }

    if(!flag){
        cout<<"Stack transfer passed! ...   ";
        score += 15;
        cout<<"15/15"<<endl;
    }
    
    cout<<"Total Score: "<<score<<"/30"<<endl;


    return 0;
}