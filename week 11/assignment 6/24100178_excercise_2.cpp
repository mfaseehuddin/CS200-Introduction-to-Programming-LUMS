#include <iostream>

// if mac or linux
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// #define DEBUG

#ifdef DEBUG
#include <fstream>
#endif

using namespace std;

class Die
{
protected:
	int number;
	// define the other requirements(setter,getter, constructors etc)
	//  No other functions are allowed
public:
	Die(int pco = 6)
	{
		srand(time(NULL));
		number = pco;
	}
	int getNumber()
	{
		// set rand seed

		int num = (rand() % number) + 1;

#ifdef DEBUG
		ofstream fout("debug.txt"`, ios::app);
		fout << num << endl;
		fout.close();
#endif

		return num; // return range 1 to number of sides
					// rand() returns a random number between 0 and RAND_MAX
					// Rand_MAX is defined in cstdlib, it is 32767
	}
};

class Player
{
protected:
	int *scores;
	int size;
	// define the other requirements (setter,getter, constructors, deconstructors etc)
	// No other functions are allowed
public:
	Player(int *playersInitalPosition, int numberOfPlayers)
	{
		// deep copy
		size = numberOfPlayers;
		scores = new int[size];
		for (int i = 0; i < size; i++)
		{
			scores[i] = playersInitalPosition[i];
		}
	}
};

class Game : public Die, public Player
{
private:
	int round;
	int *money;

public:
	Game(int startingRound, int *initialMoney, int possibleDieOutcomes, int *playersInitialPositions, int numberOfPlayers) : Die(possibleDieOutcomes), Player(playersInitialPositions, numberOfPlayers)
	{

		round = startingRound;
		// deepcopy initialMoney to money
		money = new int[numberOfPlayers];
		for (int i = 0; i < numberOfPlayers; i++)
		{
			money[i] = initialMoney[i];
		}
	}
	void playGame()
	{
		// play the game
		int badInvestmentSquares[4] = {5, 15, 25, 35};
		int goodInvestmentSquares[4] = {10, 20, 30, 40};
		int investmentSize = 4; // bingbong
		// so we iterate through the players, asking them to roll a dice
		for (int pIndex = 0; pIndex < size; pIndex++)
		{

			// roll dice
			int diceRoll = getNumber();
			int diceRoll2 = getNumber();
			// move player
			scores[pIndex] += diceRoll + diceRoll2;
			// check if player is on a bad investment square
			for (int i = 0; i < investmentSize; i++)
			{
				if (scores[pIndex] == badInvestmentSquares[i])
				{
					if ((money[pIndex] - 5000) < 5000)
					{
						money[pIndex] = 0;
					}
					else
					{
						money[pIndex] -= 5000;
					}
				}
			}
			// check if player is on a good investment square
			for (int i = 0; i < investmentSize; i++)
			{
				if (scores[pIndex] == goodInvestmentSquares[i])
				{
					money[pIndex] += 10000;
				}
			}
		}

		round++;
		print();

		// call checkWinner to see if there is a winner
		CheckWinner();
	}
	void print()
	{
		const int GAME_SIZE = 40;
		const int GAME_PRINT_AREA = 50;
		// if mac or linux
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif
		cout << "Round: " << round << endl;
		// printing in this format
		/*
		___________________________________________________________________________________
		|1| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
		|2| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
		|3| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
		|4| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
		|5| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
		|6| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |

		*/
		for (int i = 0; i < GAME_PRINT_AREA; i++)
		{
			cout << "__";
		}
		cout << endl;

		for (int pIndex = 0; pIndex < size; pIndex++)
		{
			for (int columns = 0; columns < GAME_PRINT_AREA; columns++)
			{
				if (scores[pIndex] == columns)
					cout << "|" << pIndex + 1;
				if (columns == GAME_SIZE)
					cout << "\033[0;32m"
						 << "|🏁"
						 << "\033[0m";

				// print same in green
				else
					cout << "| ";
			}
			cout << endl;
		}

		for (int i = 0; i < GAME_PRINT_AREA; i++)
		{
			cout << "--";
		}
		cout << endl;

		cout << "Player Stats: \n"
			 << "Player\tMoney\tPosition\n";
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "\t" << money[i] << "\t" << scores[i] << endl;
		}
		sleep(1);
	}
	void CheckWinner()
	{
		bool winner = false;
		// check if there is a winner
		for (int pIndex = 0; pIndex < size; pIndex++)
		{
			if (scores[pIndex] > 40)
			{
				winner = true;
			}
		}
		// if there is no winner, we continue the game
		// if there is a winner we stop the game, and print the winner, and terminate the program
		if (!winner)
			return; // guard clause

		// check who is the winner
		//  The winner is the player with the most money after the first player advances
		// beyond the 40th square. Ties (multiple winners) are possible.
		int winnerIndexes[6] = {0, 0, 0, 0, 0, 0};
		int winnerIndexSize = 0;
		int maxMoney = 0;
		for (int pIndex = 0; pIndex < size; pIndex++)
		{
			if (money[pIndex] > maxMoney)
			{
				maxMoney = money[pIndex];
				winnerIndexes[0] = pIndex;
				winnerIndexSize = 1;
			}
		}

		// run loop again to see if there are any other winners
		for (int pIndex = 0; pIndex < size; pIndex++)
		{
			if (money[pIndex] == maxMoney && pIndex != winnerIndexes[0])
			{
				winnerIndexes[winnerIndexSize] = pIndex;
				winnerIndexSize++;
			}
		}

		// print the winners
		cout << "The winner is player(s): ";
		for (int i = 0; i < winnerIndexSize; i++)
		{
			cout << "\033[32m" << winnerIndexes[i] + 1 << "\033[0m"
				 << " ";
		}
		cout << endl;
		// terminate the program
		exit(0);
	}
	// define other requirements.No other helper functions are allowed
};

int main()
{
	int *arr1;
	int size;
	cout << "Enter the number of players : ";
	cin >> size;
	while (size < 2 || size > 6)
	{
		cout << "Enter valid number of players: ";
		cin >> size;
	}

	arr1 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr1[i] = 0;
	}

	int *arr2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = 7000;
	}
	Game g1(1, arr2, 6, arr1, size);
	// this constructor represents
	cout << "Before Starting game : " << endl;
	g1.print();
	cout << endl
		 << "After Starting game " << endl;
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.playGame();
	g1.CheckWinner();
	g1.playGame();
	g1.CheckWinner();
	g1.playGame();
	g1.CheckWinner();
	g1.CheckWinner();
	#ifdef _WIN32
	system("pause"); //system pause is not available on mac and linux
	#else
	cin.get();
	#endif
	return 0;
}
