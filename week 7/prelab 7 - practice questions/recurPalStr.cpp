#include <iostream>
#include <cmath>
using namespace std;

// recursive string palindrome check!
bool recursivePalindromeCheck(int number)
{
    int len = log10(number) + 1;
    int firstDigit = number / (pow(10, len - 1));
    int lastDigit = number % 10;

    // cout << "number: " << number << endl;
    // cout << "len: " << len << endl;
    // cout << firstDigit << "   " << lastDigit << endl;

    if (firstDigit == lastDigit && len <= 2)
    {
        return true;
    }
    else if (firstDigit == lastDigit && len > 1)
    {
        // trim the number
        number = number % static_cast<int>(pow(10, len - 1));
        number = number / 10;
        // send the number in again
        return recursivePalindromeCheck(number);
    }
    return false;
}

void swap(char& a, char& b){
    char temp = a;
    a = b;
    b = temp;
}

void recursiveReverse(string &str, int front, int back){
    if(front-back >= 1){
        return;
    }
    swap(str[front++], str[back--]);
    recursiveReverse(str, front, back);
}


int main()
{
    //recursive palindrome check -- integer only
    int number = 0;
    cout << "Please input a number to check if it is a palindrome: ";
    cin >> number;

    cout << number << " "; 
    (recursivePalindromeCheck(number) == true) ? cout << "is Palindrome" << endl : cout << "is not Palindrome" << endl;

    //recursive string reverse

    string str = "";
    cout << "Please input a string to reverse it recursively: ";
    cin.ignore();
    getline(cin, str);

    recursiveReverse(str, 0, str.length()-1);

    cout << str;


    return 0;
}