/*
14. Lottey Application
Write a program that simulates a lottery. The program should have an array of five
integers named lottery and should generate a random number in the range of 0
through 9 for each element in the array. The user should enter five digits, which should
be stored in an integer array named user. The program is to compare the corresponding
elements in the two arrays and keep a count of the digits that match. For example,
the following shows the lottery array and the user array with sample numbers stored
in each. There are two matching digits (elements 2 and 4).

Lottery array: 7 4 9 1 3
User array:    4 2 9 7 3

The program should display the random numbers stored in the lottery array and the
number of matching digits. If all of the digits match, display a message proclaiming the
user as a grand prize winner.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	const size_t SIZE = 5;
	int lottery[SIZE], user[SIZE];

	for (size_t i = 0; i < SIZE; i++)
		lottery[i] = rand() % 10;

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter digit #" << i + 1 << ": ";
		cin >> user[i];
	}

	bool isWinner = true;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (lottery[i] != user[i])
		{
			isWinner = false;
			break;
		}
	}

	cout << "Lottery digits: |";
	for (size_t i = 0; i < SIZE; i++)
		cout << lottery[i] << "|";
	cout << endl;

	cout << "User digits:    |";
	for (size_t i = 0; i < SIZE; i++)
		cout << user[i] << "|";
	cout << endl;

	if (isWinner)
		cout << "You win a grand prize!\n";
	else
		cout << "You lose.\n";

	return 0;
}