#include <iostream>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int id;
    double cgpa;
};
void printArray(int* arr, int lengthOfArray){
    for(int i = 0; i < lengthOfArray; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int* insertNewIndexInArrayAtEnd(int* arr, int lengthOfArray, int indexToInsert){
    //use pointer notation to insert the indexToInsert at the end of the array  
    int* newArr = new int[lengthOfArray + 1];
    
    //put the values from the old array into the new array
    for(int i = 0; i < lengthOfArray; i++){
        *(newArr + i) = *(arr + i);
    }
    //delete the old array
    delete[] arr;
    //add the new index to the end of the array
    *(newArr + lengthOfArray) = indexToInsert;
    return newArr;
}


int* Find(Student* arrOfStudents, int lengthOfStudentArray, string searchFirstName){
    int* returnArr = new int[0];
    //check if the array is empty
    if(lengthOfStudentArray == 0){
        return returnArr;
    }
    //check all the firstNames in arrOfStudents to check if they match searchFirstName
    int matchingStudents = 0;
    for(int i = 0; i < lengthOfStudentArray; i++){
        
        //check if current student firstName matches searchFirstName
        if(arrOfStudents[i].firstName == searchFirstName){
            returnArr = insertNewIndexInArrayAtEnd(returnArr, matchingStudents, i);
            matchingStudents++;
        }
    }
    return returnArr;
}



int main()
{
    Student students[5] = {
        {"John", "Smith", 123456, 3.5},
        {"Jane", "Doe", 234567, 3.8},
        {"John", "Doe", 345678, 3.2},
        {"Jane", "Smith", 456789, 3.9},
        {"John", "Smith", 567890, 3.4}
    };
    int *result = Find(students, 5, "John");
    printArray(result, 3);
    return 0;
}