#include <iostream>
using namespace std;

char* insertCharToName(char *name, char insertThis, int &size)
{
    // if the list is empty do party
    if (name == nullptr)
    {
        size++;
        name = new char[size];
        name[0] = insertThis;
        return name;
    }

    char *newNameArray = new char[size + 1];

    // copy the contents in to the new name array
    for (int idx = 0; idx < size; idx++)
    {
        newNameArray[idx] = name[idx];
    }

    // insert the new character
    newNameArray[size] = insertThis;

    // delete the old name
    delete[] name;
    size++;

    return newNameArray;
}

void printName(char *name, int &size)
{
    for (int idx = 0; idx < size; idx++)
    {
        cout << name[idx];
    }
    cout << endl;
}

int main()
{
    char *name = nullptr;
    int size = 0;

    name = insertCharToName(name, 'A', size);
    name = insertCharToName(name, 'M', size);
    name = insertCharToName(name, 'M', size);
    name = insertCharToName(name, 'A', size);
    name = insertCharToName(name, 'R', size);

    printName(name, size);

    return 0;
}