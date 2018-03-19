#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int printMenu();
int displayCredits();
int playGame();

int main()
{
	bool isActive = true;

	int currentState = printMenu();
	if (currentState == 3)
	{
		isActive = false;
		cout << "Thank you for playing...\n";
	}
	while (isActive)
	{
		if (currentState == 1)
		{
			playGame();
		}
		else if (currentState == 2)
		{
			currentState = displayCredits();
		}
		else if (currentState == 0)
		{
			currentState = printMenu();
		}

	}


	system("PAUSE");
	return 0;
}

int playGame()
{
	static mt19937 randomNumberGenerator(time(0));
	static uniform_int_distribution<int> diceRoll(1, 6);


	bool playing = true;	
	int input; // The input here is also used to determined the play state. 1 = Not Playing, 2 = Playing
	cout << "Would you like to play or read the instructions? \n 1. Just let me play! \n 2. Read the instructions\n";
	cin >> input;
	while (playing)
	{
		if (input == 1)
		{
			int playerWins = 0;
			int botWins = 0;
			int roundNumber = 1;
			
			int playerCurrentRoll;
			int botCurrentRoll;
			while (roundNumber <= 3)
			{
				system("cls");
				if (playerWins >= 2)
				{
					cout << "CONGRATULATIONS! THE PLAYER HAS WON!!!" << endl;
				}
				else if (botWins >= 2)
				{
					cout << "I TOLD YOU ROBOTS ARE TAKING OVER THE WORLD!!!" << endl;
				}
				cout << "*** CURRENTLY ROLLING FOR ROUND " << roundNumber << " ***" << endl << "Current Score is Bots: " 
					<< botWins << ", Player: " << playerWins << endl << endl;

				playerCurrentRoll = diceRoll(randomNumberGenerator);
				cout << "Rolling dice for the player...\n" << "The player rolled a: " << playerCurrentRoll << endl << endl;
				botCurrentRoll = diceRoll(randomNumberGenerator);
				cout << "Rolling dice for the bot...\n" << "The bot rolled a: " << botCurrentRoll << endl << endl;

				if (playerCurrentRoll > botCurrentRoll)
				{
					cout << "The player won round: " << roundNumber << endl;
					roundNumber++;
					playerWins++;
					system("PAUSE");
				}
				else
				{
					cout << "The bot took round: " << roundNumber << endl;
					roundNumber++;
					botWins++;
					system("PAUSE");
				}
			}
			if (roundNumber > 3)
			{
				if (playerWins >= 2)
				{
					cout << "CONGRATULATIONS! THE PLAYER HAS WON!!!" << endl;
				}
				else if (botWins >= 2)
				{
					cout << "I TOLD YOU ROBOTS ARE TAKING OVER THE WORLD!!!" << endl;
				}
			}
		}
		else if (input == 2)
		{
			system("cls");
			cout << "The name of the game is Dice Roller, it's very simple: "
				<< endl << "There are two players, you, the user, and a bot."
				<< endl << "Each of you will have a turn to roll the dice, the highest roller wins the round."
				<< endl << "The person(or robot, we don't judge) with the most round wins at the end wins!"
				<< endl << "Goodluck!\n";
			cout << "Are you ready to start? \n 1. Yes \n 2. No\n";
			cin >> input;
		}
		else
		{
			cout << "Please enter a valid option: ";
			cin >> input;
		}
	}
	return 3;
}


int displayCredits()
{
	cout << "This game is in thanks to: \n" << "Me, Brennen Green. No one else, you're welcome.\n\n";
	return 0;
}

int printMenu()
{
	int input;
	cout << "*** Hello user, welcome to Dice Roller! ***" <<endl<<endl;
	cout << "Please select from the options below!\n" << "1. Play\n" << "2. Credits\n" << "3. Quit\n";
	cin >> input;
	if (input == 1)
	{
		system("cls");
		return 1;
	}
	else if (input == 2)
	{
		system("cls");
		return 2;
	}
	else if (input == 3)
	{
		return 3;
	}

	return 0;
}
