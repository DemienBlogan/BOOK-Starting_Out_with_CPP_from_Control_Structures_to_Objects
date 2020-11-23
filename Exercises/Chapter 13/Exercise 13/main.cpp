/*
13. Tossing Coins for a Dollar
For this assignment, you will create a game program using the Coin class from
Programming Challenge 12 (Coin Toss Simulator). The program should have three
instances of the Coin class: one representing a quarter, one representing a dime,
and one representing a nickel.

When the game begins, your starting balance is $0. During each round of the game, the
program will toss the simulated coins. When a coin is tossed, the value of the coin is
added to your balance if it lands heads-up. For example, if the quarter lands heads-up,
25 cents is added to your balance. Nothing is added to your balance for coins that land
tails-up. The game is over when your balance reaches #1 or more. If your balance is
exactly $1, you win the game. You lose if your balance exceeds $1.
*/

#include <iostream>
#include <ctime>

#include "Coin.h"

using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	Coin quarter, dime, nickel;
	double balance = 0.0;
	const int ROUNDS = 5;

	for (size_t i = 0; i < ROUNDS; i++)
	{
		if (balance >= 1.00)
			break;

		quarter.Toss();
		dime.Toss();
		nickel.Toss();

		if (quarter.GetSideUp() == "heads")
			balance += 0.25;
		if (dime.GetSideUp() == "heads")
			balance += 0.10;
		if (nickel.GetSideUp() == "heads")
			balance += 0.5;

		cout << "Round #" << i + 1 << ": balance = $" << balance << endl;
	}

	if (balance == 1.00)
		cout << "You win the game!\n";
	else
		cout << "You lose the game!\n";

	return 0;
}