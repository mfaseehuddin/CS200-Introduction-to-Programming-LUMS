#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    // check if the correct number of command line arguments is provided to the program
    if (argc < 4) {
        cout << "Incorrect number of command line arguments provided." << endl
            << "Usage: ./filename base number base_to_convert_to" << endl
            << "For example: ./24100116_A1P1Q2 10 43563 2" << endl;
        return 1;
    }

    // store the command line arguments in relevant integers
    // you can assume that the input base and number will be always valid
    int base = stoi(argv[1]);
    string number = argv[2];
    int baseToConvertTo = stoi(argv[3]);

    // check if the value for the base is valid
    if (baseToConvertTo < 2 || baseToConvertTo > 36) {
        cout << "The valid range of base to convert to is 2-36" << endl;
        return 1;
    }
    
    string convertedNumber = ""; // initialize a variable to store the converted number
    /* Write code that converts the given number (in the provided number system) to a number with the base "baseToConvertTo" */
    /* You are allowed to make additional functions as needed */
    /* Please store the final result in the variable convertedNumber */
    // YOUR CODE HERE

    // convert the given number from the given base system to base 10
    //we convert the number to a string so we can work on the digits one by one
    string numberString = number;
    int lengthOfNumberString = numberString.length();
    int numberInBase10 = 0;
    
    // we will convert all the lowercase letters to uppercase letters to avoid any errors 
    for (int i = 0; i < lengthOfNumberString; i++) {
        if (numberString[i] >= 'a' && numberString[i] <= 'z') {
            numberString[i] = numberString[i] - 32;
        }
    }

    //checking for characters which are invalid according to base
    for (int i = 0; i < lengthOfNumberString; i++) {
        //if numberstring[i] is of denary value greater than base then it is invalid
        if (numberString[i] >= 'A' && numberString[i] <= 'Z') {
            // cout << "Denary equivalent of " << numberString[i] << " is " << numberString[i] - 'A' + 10 << endl;
            if (numberString[i] - 'A' + 10 >= base) {
                cout << "The number is invalid for the given base because " << numberString[i] << " is greater than the orignal base:" << base << endl; 
                return 1;
            }
        }
        else if (numberString[i] >= '0' && numberString[i] <= '9') {
            // cout << "Denary equivalent of " << numberString[i] << " is " << numberString[i] - '0' << endl;
            if (numberString[i] - '0' >= base) {
                cout << "The number is invalid for the given base because " << numberString[i] << " is greater than the orignal base:" << base << endl;
                return 1;
            }
        }
    }


    // we will use the multiplication method to convert to base 10
    for (int digit = 0; digit < lengthOfNumberString; digit++)
    {
        // we then multiply the digit by the base raised to the power of the digit's position and then add the result to the number in base 10
        if(numberString[digit] >= 'A' && numberString[digit] <= 'Z'){
            // we get the digit by subtracting the ASCII value of 'A' from the ASCII value of the digit and adding 10
            numberInBase10 += ((numberString[digit] - 'A') + 10) * pow(base, lengthOfNumberString - 1 - digit);
        }else if(numberString[digit] >= '0' && numberString[digit] <= '9'){
            // we get the digit by subtracting the ASCII value of '0' from the ASCII value of the digit
            numberInBase10 += (numberString[digit] - '0') * pow(base, lengthOfNumberString - 1 - digit);
        }else{
            cout << "There is an invalid character in the number." << endl;
            return -1;
        }

    }
    
    
    //now we convert the number in base 10 to the given base system
    // we will use the division method to convert to the specified base system from the last task
    while (numberInBase10 > 0) {
        // get the remainder of the division, which basically represents the digit in the base system
        int remainder = numberInBase10 % baseToConvertTo;
        // divide the number by the base system to get the next digit to the right
        numberInBase10 /= baseToConvertTo;
        // if the remainder is greater than 9, we need to convert it to a letter/symbol
        // else we can just convert it to a string and append it to the converted number
        if (remainder < 10) {
            convertedNumber.insert(0, 1, to_string(remainder)[0]);
        } else {
            // we get the letter/symbol of the letter/symbol by subtracting 10 from the remainder, because the remainder is the number of letters/symbols after 9
            // we then add 65 i.e: directly to char 'A' to the remainder to get the ASCII value of the letter/symbol
            char letter = 'A' + (remainder - 10);
            // we then append the letter to the converted number
            convertedNumber.insert(0, 1, letter);
        }
    }

    // Final output
    cout << "The converted number is: " << convertedNumber << ".\n";
    return 0;
} 