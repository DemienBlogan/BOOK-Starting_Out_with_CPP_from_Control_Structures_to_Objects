/*
20. Random Numbe rGuessing Game
Write a program that generates a random numbe rand asks the user to guess what the
number is. If the user's guess is higher than the random number, the program should
display "Too high, try again". If the user's guess is lower than the random number, the
program should display "Too low, try again". The program should use a loop that
repeats until the user correctly guesses the random number.
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
	
	while (userNumber != randomNumber)
	{
		cout << "You are wrong! ";
		if (userNumber < randomNumber)
			cout << "My number is greater.\n";
		else
			cout << "My number is less.\n";

		cout << "Enter a number that I gussed: ";
		int userNumber;
		cin >> userNumber;
	}

	cout << "Congratulations! Your guessed my number!\n";

	return 0;
}