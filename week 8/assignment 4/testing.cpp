#include <iostream>
using namespace std;

struct card
{
private:
    int value;
    char suit;

public:
    // default constructor
    card()
    {
        cout << "this shouldnt happen boss";
        value = 69;
    }
    int getValue(){
        return value;
    }
    void operator++(int x){
        value = value + x;
    }
};

struct deck
{
    static const int SIZE=52;
    // dynamic array of 52 cards
    // i want each card to be dynamically allocated
    card **cards;

    //default constructor
    deck()
    {
        cards = new card*[SIZE];
        for(int i=0; i<SIZE; i++)
        {
            cards[i] = new card;
        }
    }
};


int main()
{
    return 0;
}