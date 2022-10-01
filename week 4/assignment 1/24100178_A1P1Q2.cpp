#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // check if the correct number of command line arguments is provided to the program
    if (argc < 3) {
        cout << "Incorrect number of command line arguments provided." << endl
            << "Usage: ./filename decimal_number base_to_convert_to" << endl
            << "For example: ./24100116_A1P1Q2 43563 2" << endl;
        return 1;
    }

    // store the command line arguments in relevant integers
    int decimalNumber = stoi(argv[1]);
    int baseToConvertTo = stoi(argv[2]);

    // check if the value for the base is valid
    if (baseToConvertTo < 2 || baseToConvertTo > 36) {
        cout << "The valid range of base to convert to is 2-36" << endl;
        return 1;
    }
    
    string convertedNumber = ""; // initialize a variable to store the converted number

    /* Write code the converts the given decimal number (base 10) to a number in the given base system */
    /* You are allowed to make additional functions as needed */
    /* Please store the final result in the variable convertedNumber */
    // YOUR CODE HERE

    // convert the decimal number to the given base system
    // we will use the division method to convert to the specified base system
    while (decimalNumber > 0) {
        // get the remainder of the division, which basically represents the digit in the base system
        int remainder = decimalNumber % baseToConvertTo;
        // divide the number by the base system to get the next digit to the right
        decimalNumber /= baseToConvertTo;
        // if the remainder is greater than 9, we need to convert it to a letter/symbol
        // else we can just convert it to a string and append it to the converted number
        if (remainder < 10) {
            convertedNumber = to_string(remainder) + convertedNumber;
        } else {
            // we get the letter/symbol of the letter/symbol by subtracting 10 from the remainder, because the remainder is the number of letters/symbols after 9
            // we then add 65 i.e: directly to char 'A' to the remainder to get the ASCII value of the letter/symbol
            char letter = 'A' + (remainder - 10);
            // we then append the letter to the converted number
            convertedNumber += letter;
        }
    }

    // Final output
    cout << "The converted number is: " << convertedNumber << ".\n";
    return 0;
}