/*
8. Coin Toss
Write a function named coinToss that simulates the tossing of a coin. When you call
the function, it should generate a random number in the range of 1 through 2. If the
random number is 1, the function should display "heads". If the random number is 2,
the function should display "tails". Demonstrate the function in a program that asks
the user how many times the coin should be tossed, then simulates the tossing of the
coin that number of times.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

void TossCoin();

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	cout << "Enter the number of toss: ";
	int tossNumber;
	cin >> tossNumber;

	for (int i = 0; i < tossNumber; i++)
		TossCoin();

	return 0;
}

void TossCoin()
{
	using namespace std;

	int number = rand() % 2 + 1;
	
	cout << (number == 1 ? "Heads" : "Tails") << endl;
}