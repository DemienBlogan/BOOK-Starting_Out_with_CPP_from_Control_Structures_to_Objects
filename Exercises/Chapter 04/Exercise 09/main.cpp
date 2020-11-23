/*
9. Change for a Dollar Game
Create a change-counting game that gets the user to enter the numbe rof coins required
to make exactly one dollar. The prgoram should ask the user to enter the number of
pennies, nickels, dimes, and quarters. If the total value of the coins entered is equal to
one dollar, the prgoram should congratulate the user for winning the game. Otherwise,
the program should display a message idicating whether the amount entered was more
than or less than one dollar.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the number of coins required to make one dollar: ";
	int coins;
	cin >> coins;

	cout << "Enter the number of pennies: ";
	int pennies;
	cin >> pennies;

	cout << "Enter the number of nickels: ";
	int nickels;
	cin >> nickels;

	cout << "Enter the number of dimes: ";
	int dimes;
	cin >> dimes;

	cout << "Enter the number of quarters: ";
	int quarters;
	cin >> quarters;

	if (pennies + nickels + dimes + quarters != coins)
	{
		cout << "Incorrect amount of you values. Try again.\n";
		return 0;
	}

	const int CENTS_IN_PENNY = 1;
	const int CENTS_IN_NICKEL = 5;
	const int CENTS_IN_DIME = 10;
	const int CENTS_IN_QUARTER = 25;
	const int CENTS_IN_DOLLAR = 100;

	int cents = pennies * CENTS_IN_PENNY + nickels * CENTS_IN_NICKEL +
		dimes * CENTS_IN_DIME + quarters * CENTS_IN_QUARTER;

	if (cents == CENTS_IN_DOLLAR)
		cout << "You win!\n";
	else if (cents < CENTS_IN_DOLLAR)
		cout << "You lose! " << cents << " < 100.\n";
	else
		cout << "You lose! " << cents << " > 100.\n";

	return 0;
}