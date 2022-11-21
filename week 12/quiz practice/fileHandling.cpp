#include <iostream>
#include <fstream>
using namespace std;



//The fstream library is used to read and write files
// we have 3 classes we can use
// ofstream - used to create and write to files
// ifstream - used to read from files
// fstream - used to read and write from/to files




void writeAppend(string fileName){

    fstream file(fileName, ios::in | ios::out | ios::app);
    //what is ios::app? -> it is a flag that allows us to append to the file
    //what ae all the available flags?
    // ios::in -> opens the file for reading
    // ios::out -> opens the file for writing
    // ios::app -> appends to the file
    // ios::ate -> sets the initial position at the end of the file
    // ios::trunc -> if the file already exists, its contents are truncated before opening the file
    // ios::binary -> opens the file in binary mode

    file << "Hello World" << endl;
    file.close();



}


void writeTrunc(string fileName){
    fstream file(fileName, ios::out | ios::trunc);
    file << "Hello World" << endl;
    file.close();
}

void writeAte(string fileName){
    fstream file(fileName, ios::out | ios::ate);
    file << "Hello World" << endl;
    file.close();
}

void readWrite(string fileName){
    fstream file(fileName, ios::in | ios::app | ios::out);
    file << "Hello World" << endl;
    //go to start
    file.seekg(6, ios::beg);
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

struct Student{
    string name;
    int age;
    double gpa;
};
void readWriteBinary(string fileName){
    fstream file(fileName, ios::in | ios::trunc | ios::out | ios::binary);
    Student s1 = {"John", 20, 3.5};
    Student s2 = {"Jane", 21, 3.6};
    file.write((char*)&s1, sizeof(Student));
    file.write((char*)&s2, sizeof(Student));
    file.seekg(0, ios::beg);
    Student s3;

    while(file.read((char*)&s3, sizeof(Student))){
        cout << s3.name << " " << s3.age << " " << s3.gpa << endl;
    }
    
    
    file.close();
}



int main() {

    // writeAppend("testApp.txt");
    // writeAppend("testApp.txt");

    // writeTrunc("testTrunc.txt");
    // writeTrunc("testTrunc.txt");

    // writeAte("testAte.txt");
    // writeAte("testAte.txt");
    // writeAte("testAte.txt");
    // writeAte("testAte.txt");

    // readWrite("testReadWrite.txt");

    readWriteBinary("testBinary.txt");

    return 0;
}


// Path: week 12/quiz practice/quiz.cpp