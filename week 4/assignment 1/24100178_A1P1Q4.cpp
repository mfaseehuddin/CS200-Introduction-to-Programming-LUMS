#include <iostream>
#include <cmath>

using namespace std;

int convertNumberFromNBaseTo10Base(string number, int base);
int convertNumberFrom10BaseToNBase(int number, int base);

int main(int argc, char **argv)
{
    // check if the correct number of command line arguments is provided to the program
    if (argc < 6)
    {
        cout << "Incorrect number of command line arguments provided." << endl
             << "Usage: ./filename base1 number1 operation base2 number2" << endl
             << "For example: ./24100116_A1P1Q2 10 6 + 2 10" << endl;
        return 1;
    }

    // store the command line arguments in relevant variables
    int base1 = stoi(argv[1]);
    string number1 = argv[2];
    char operation = argv[3][0];
    int base2 = stoi(argv[4]);
    string number2 = argv[5];

    int result; // declare a variable to store the converted number
    // terminate

    /* Write code that takes in two numbers (which can be in any number system - having any base) */
    /* It then performs the given arithmetic operation and stores the result */
    /* The final number MUST BE an OCTAL (i.e., base 8) */
    /* You are allowed to make additional functions as needed */
    // YOUR CODE HERE
    // testing the functions
    cout << number1 << " in base: " << base1 << " in base 10 is: " << convertNumberFromNBaseTo10Base(number1, base1) << endl;
    cout << number2 << " in base: " << base2 << " in base 10 is: " << convertNumberFromNBaseTo10Base(number2, base2) << endl;

    // perform the operation
    switch (operation)
    {
    // the numbers are converted to base 10 and then the operation is performed, and then the result is converted to base 8
    case '+':
        result = convertNumberFrom10BaseToNBase(convertNumberFromNBaseTo10Base(number1, base1) + convertNumberFromNBaseTo10Base(number2, base2), 8);
        break;
    case '-':
        result = convertNumberFrom10BaseToNBase(convertNumberFromNBaseTo10Base(number1, base1) - convertNumberFromNBaseTo10Base(number2, base2), 8);
        break;
    case '*':
        result = convertNumberFrom10BaseToNBase(convertNumberFromNBaseTo10Base(number1, base1) * convertNumberFromNBaseTo10Base(number2, base2), 8);
        break;
    case '/':
        result = convertNumberFrom10BaseToNBase(convertNumberFromNBaseTo10Base(number1, base1) / convertNumberFromNBaseTo10Base(number2, base2), 8);
        break;
    default:
        cout << "Invalid operation" << endl;
        return 1;
    }

    // Final output
    cout << "The final result is: " << result << endl;
    return 0;
}

int convertNumberFromNBaseTo10Base(string number, int base)
{
    // convert the given number from the given base system to base 10
    // we convert the number to a string so we can work on the digits one by one
    string numberString = number;
    int lengthOfNumberString = numberString.length();
    int numberInBase10 = 0;

    // converting all lower case letters to upper case
    for (int i = 0; i < lengthOfNumberString; i++)
    {
        if (numberString[i] >= 'a' && numberString[i] <= 'z')
        {
            numberString[i] = numberString[i] - 32;
        }
    }

    // digit by digit calculations
    for (int digit = 0; digit < lengthOfNumberString; digit++)
    {
        // checking current digit for validity

        // if numberstring[i] is of denary value greater than base then it is invalid
        if (numberString[digit] >= 'A' && numberString[digit] <= 'Z')
        {
            // cout << "Denary equivalent of " << numberString[digit] << " is " << numberString[digit] - 'A' + 10 << endl;
            if (numberString[digit] - 'A' + 10 >= base)
            {
                cout << "UNDEFINED" << endl;
                cout << "INVALID BASE DIGIT: The number is invalid for the given base because " << numberString[digit] << " is greater than the orignal base: " << base << endl;
                cout << endl;
                //quit code execution if the number is invalid
                exit(1);
            }
        }
        else if (numberString[digit] >= '0' && numberString[digit] <= '9')
        {
            // cout << "Denary equivalent of " << numberString[digit] << " is " << numberString[digit] - '0' << endl;
            if (numberString[digit] - '0' >= base)
            {
                cout << "UNDEFINED" << endl;
                cout << "INVALID BASE DIGIT: The number is invalid for the given base because " << numberString[digit] << " is greater than the orignal base: " << base << endl;
                cout << endl;
                //quit code execution if the number is invalid
                exit(1);
            }
        }

        // we get the digit by subtracting the ASCII value of '0' from the ASCII value of the digit
        // we then multiply the digit by the base raised to the power of the digit's position
        // we then add the result to the number in base 10
        //digit is a letter
        if (numberString[digit] >= 'A' && numberString[digit] <= 'Z')
        {
            numberInBase10 += (numberString[digit] - 'A' + 10) * pow(base, lengthOfNumberString - digit - 1);
        }else if(numberString[digit] >= '0' && numberString[digit] <= '9'){
            numberInBase10 += (numberString[digit] - '0') * pow(base, lengthOfNumberString - digit - 1);
        }
    }
    return numberInBase10;
}

int convertNumberFrom10BaseToNBase(int number, int base)
{
    // initialise the variable to store the converted number
    string convertedNumber = "";
    // now we convert the number in base 10 to the given base system
    //  we will use the division method to convert to the specified base system from the last task
    while (number > 0)
    {
        // get the remainder of the division, which basically represents the digit in the base system
        int remainder = number % base;
        // divide the number by the base system to get the next digit to the right
        number /= base;
        // if the remainder is greater than 9, we need to convert it to a letter/symbol
        // else we can just convert it to a string and append it to the converted number
        if (remainder < 10)
        {
            // we then insert the number to the converted number at pos 0
            convertedNumber.insert(0, 1, to_string(remainder)[0]);
        }
        else
        {
            // we get the letter/symbol of the letter/symbol by subtracting 10 from the remainder, because the remainder is the number of letters/symbols after 9
            // we then add 65 i.e: directly to char 'A' to the remainder to get the ASCII value of the letter/symbol
            char letter = 'A' + (remainder - 10);
            // we then insert the letter to the converted number at pos 0
            convertedNumber.insert(0, 1, to_string(remainder)[0]);
        }
    }
    return stoi(convertedNumber);
}