#include <iostream>
using namespace std;

//bankAccount class
/*
    //function signature means that the function is declared in the class but not defined

    //private data members
        int accountNumber
        string FirstName
        string LastName
        int balance
        int accountNumber
        int accountType -> enum {basic, current}
    //public member functions
        constructor(firstName, lastName, accountNumber, accountType, balance)
        transaction(int amount)
        changeAccountType() -> if balance > 50000 then change accountType to current
        printAccountDetails()
        SETTERS
        changeName(string firstName, string lastName)
        GETTERS
            getAccountNumber()
            getFirstName()
            getLastName()
            getBalance()
            getAccountType()

*/
class bankAccount
{
private:
    int accountNumber;
    string firstName;
    string lastName;
    int balance;
    int accountType;
    enum accountType {basic, current};
    string* accountTypeString;
public:
    //parameterized constructor
    bankAccount(string firstName, string lastName, int accountNumber, int balance)
    {   
        accountTypeString = new string[2];
        accountTypeString[basic] = "basic";
        accountTypeString[current] = "current";
        this->firstName = firstName;
        this->lastName = lastName;
        this->accountNumber = accountNumber;
        this->balance = balance;
        if(balance > 50000)
        {
            accountType = current;
        }
        else
        {
            accountType = basic;
        }
    }
    //destructors
    ~bankAccount()
    {
        delete[] accountTypeString;
    }
    //transaction function
    void transaction(int amount)
    {
        if(amount > 0){
            balance += amount;
            cout << "Transaction from " << accountNumber << " -- " << lastName << " successful. New balance is " << balance << endl;
        }
        else if(amount < 0){
            if(balance + amount < 0){
                cout << "Insufficient balance in account " << accountNumber << " -- " << lastName << " ::: Transaction Failed" << endl;
            }
            else{
                balance += amount;
                cout << "Transaction from " << accountNumber << " -- " << lastName << " successful. New balance is " << balance << endl;
            }
        }else{
            cout << "Invalid transaction amount" << endl;
        }



        if(balance < 50000)
        {
            accountType = basic;
            cout << "Account " << accountNumber << " -- " << lastName << " is now a basic account" << endl;
        }
    }
    //changeAccountType function
    void changeAccountType()
    {
        if(balance > 50000)
        {
            accountType = current;
            cout << "Account " << accountNumber << " -- " << lastName << " is now a current account" << endl;
        }else{
            cout << "Account " << accountNumber << " -- " << lastName << " is a basic account due to funds being below 50000" << endl;
        }
    }
    //printAccountDetails function
    void printAccountDetails()
    {
        cout << "***********BANK ACCOUNT DETAILS***********" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountTypeString[accountType] << endl;
        cout << "******************************************\n\n\n";
    }
    //setter
    //changeName function
    void changeName(string firstName, string lastName)
    {
        this->firstName = firstName;
        this->lastName = lastName;
    }
    //getters
    int getAccountNumber()
    {
        return accountNumber;
    }
    string getFirstName()
    {
        return firstName;
    }
    string getLastName()
    {
        return lastName;
    }
    int getBalance()
    {
        return balance;
    }
    string getAccountType()
    {
        return accountTypeString[accountType];
    }

};



int main()
{
    bankAccount account1("John", "Biden", 100001, 100000);
    account1.printAccountDetails();

    bankAccount account2("Bill", "Clinton", 100002, 5000);
    account2.printAccountDetails();

    bankAccount account3("Donald", "Trump", 100003, 1000000);
    account3.printAccountDetails();

    bankAccount account4("George", "Bush", 100004, 10000000);
    account4.printAccountDetails();


    account1.transaction(-10000000); //extraneous amount - error
    account1.transaction(10000000); //normal amount addition - success
    account1.transaction(-10000); //normal amount subtraction - success
    account1.printAccountDetails();

    account2.transaction(-5000); //withdrawing all amount - success
    account2.transaction(60000); //adding amount - success -> war funds
    account2.changeAccountType(); //changing account type - success -> current
    account2.printAccountDetails();

    account3.transaction(0); //withdraw zero amount - error
    account3.transaction(-1000000); //withdraw all amount - success
    account3.transaction(30000); //adding amount - success
    account3.changeAccountType(); //changing account type - stays -> basic
    account3.printAccountDetails();

    //normal account transactions
    account4.transaction(+10000); //deposit - success
    account4.changeAccountType(); //changing account type - stays -> current
    account4.printAccountDetails();


    return 0;
}