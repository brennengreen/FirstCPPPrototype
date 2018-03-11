//Humans vs Orcs
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	mt19937 randomNumberGenerator(time(0));
	uniform_int_distribution<int> attackRoll(1,5);
	uniform_int_distribution<int> message(0, 3);
	uniform_real_distribution<float> luckRoll(0.0f, 1.0f);

	string humanMessages[4] = {
		"The humans are flanking...",
		"Here comes another wave of humans...",
		"Watch out for the human arrows over the horizon...",
		"Another human attack is underway..."
	};

	string orcMessages[4] = {
		"HERE COME THE GREEN SAVAGES...",
		"Watch out for their clubs...",
		"The green beasts are attacking from the rear...",
		"The orcs are on their way..."
	};


	//Game Setup
	int humanTroops;
	int orcTroops;
	bool gameOver = false;
	int attackTurn = 1;


	cout << "***GAME SET-UP***\n\n" << "How many humans will there be?\n";
	cin >> humanTroops;
	int humanDamage = attackRoll(randomNumberGenerator) * 5;
	if (luckRoll(randomNumberGenerator) == 0.7f)
	{
		humanDamage = humanDamage * 2;
		cout << "The humans found a very magical potion and doubled the impact of their troops!\n";
	}

	cout << "How many orcish troops will there be?\n";
	cin >> orcTroops;
	int orcDamage = attackRoll(randomNumberGenerator) * 5;
	if (luckRoll(randomNumberGenerator) == 0.5f)
	{
		orcDamage = orcDamage * 2;
		cout << "The orcs found an ancient weapon of the gods and our now twice as deadly!\n";
	}

	cout << "***LET THE BATTLE COMMENCE!***\n\n";

	do
	{
		this_thread::sleep_for(chrono::milliseconds(250));
		if (attackTurn == 1)
		{
			cout << humanMessages[message(randomNumberGenerator)] << endl;
			orcTroops = orcTroops - humanDamage;
			cout << "Orcs remaining: " << orcTroops << endl;
			attackTurn = 2;
			if (orcTroops <= 0)
			{
				cout << "THE HUMANS ARE VICTORIOUS\n" << "Humans remaining: " << humanTroops << endl;
				system("PAUSE");
			}
		}
		else if (attackTurn == 2)
		{
		
			cout << orcMessages[message(randomNumberGenerator)] << endl;
			humanTroops = humanTroops - orcDamage;
			cout << "Humans remaining: " << humanTroops << endl;
			attackTurn = 1;
			if (humanTroops <= 0)
			{
				cout << "BOW DOWN TO THE BEASTS IN GREEN!\n" << "Orcs remaining: " << orcTroops << endl;
				system("PAUSE");
			}

		}
	} while (orcTroops > 0 && humanTroops > 0);

	return 0;

}
