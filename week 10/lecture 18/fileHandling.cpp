#include <iostream>
//include the fstream library
#include <fstream>
using namespace std;

//class topic: file Handling - reading & writing from a file
//file handling in c++ can be done in 2 ways:
//1. using the fstream library
    //steps:
    //1. include the fstream library
    //2. create an object of the fstream class
    //3. open the file
    //4. read/write from/to the file
    //5. close the file

//2. using the c library
    //steps:
    //1. include the c library
    //2. open the file
    //3. read/write from/to the file
    //4. close the file

//so lets implement the fstream library
//we will make a void function
void fileHandling(){
    //create an object of the fstream class
    fstream file;
    //open the file
    file.open("file.txt", ios::in);
    //check if the file is open
    if(file.is_open()){
        //read from the file
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    }
    //close the file
    file.close();
}





int main()
{
    // //declare a file pointer
    // FILE *fp;
    // //open a file
    // fp = fopen("test.txt", "w");
    // //write to a file
    // fprintf(fp, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fp);
    // fclose(fp);


    //our method
    //open a file

    //to read a file we need a ofstream object
    ofstream out("text2.txt");
    //write to a file
    for (int i = 0; i < 10; i++)
    {
        out << i;
    }
    //close the file
    out.close();

    
    //read from a file
    //open file as ifstream
    ifstream in("text2.txt");

    //read from file
    string line;
    // while(!in.eof())
    // {
    //     cout << line;
    //     in >> line;
    // }

    // while(true){
    //     getline(in, line);
    //     cout << line << endl;
    // }

    in.seekg(0, ios::beg);//this is not working properly, why? -> 
    //print the first line
    in >> line;
    cout << line << endl;

    //close the file
    in.close();
    

    return 0;
}