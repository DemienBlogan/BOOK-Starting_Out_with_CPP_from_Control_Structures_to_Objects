/*
21. Random Number Guessing Game Enhancement
Enhance the program that you wrote for Programming Challenge 20 so it keeps a count
of the numbe rof guesses the use makes. When the user correctly guesses the random
number, the program should display the numbe rof guesses.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	int randomNumber = rand();

	cout << "Enter a number that I guessed: ";
	int userNumber;
	cin >> userNumber;

	int tries = 1;

	while (userNumber != randomNumber)
	{
		cout << "You are wrong! ";
		if (userNumber < randomNumber)
			cout << "My number is greater.\n";
		else
			cout << "My number is less.\n";

		cout << "Enter a number that I gussed: ";
		cin >> userNumber;

		tries++;
	}

	cout << "Congratulations! Your guessed my number!\n";
	cout << "Count of tries = " << tries << endl;

	return 0;
}