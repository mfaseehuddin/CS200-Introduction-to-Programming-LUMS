#include <iostream>
using namespace std;

void do_Something(int** p, int size){
    *p = new int[size];
    for(int i = 0; i < size; i++){
        (*p)[i] = i+size;
    }
    for(int i = 0; i < size; i++){
        cout << (*p)[i] << " ";
    }
    cout << endl;
}


struct student{
    char * name;
    int roll;
};

void delStds(student** stds, int size){

}




int main()
{

    int rows = 3;
    int **a = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        do_Something(&a[i], rows + i);
    }

    for(int i = 0; i < rows; i++){
        delete[] a[i];
    }

    char * Dog = new char[30];
    char * Cat = new char[30];

    strcpy(Dog, "Courage a Brave Dog \n"); // what does this do? 
    // this copies the string "Dog" into the char array Dog, in the memory location of Dog, even though the array is 30 characters long, it only copies the first 4 characters, and then adds a null terminator at the end of the string
    strcpy(Cat, "Milo a Furry Cat\n"); // what does this do?

    for (size_t i = 0; i < 6; i++) cout << "pp" << endl;

    
    
    return 0;
}