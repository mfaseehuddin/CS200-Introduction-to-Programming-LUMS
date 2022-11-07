#include <iostream>
//include the fstream library
#include <fstream>
using namespace std;

//class topic: file Handling - reading & writing from a file





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
    while(!in.eof())
    {
        cout << line;
        in >> line;
    }
    in.seekg(0, ios::beg);//this is not working properly, why? -> 
    //print the first line
    in >> line;
    cout << line << endl;

    //close the file
    in.close();
    

    return 0;
}