/*
2. Lottery Winners
A lottery ticket buyer purchases ten tickets a week, always playing the same ten 5-digit
"lucky" combinations. Write a program that initializes an array or a vector with these
numbers, then lets the player enter thiw week's winning 5-digit number. The program
should perform a linear search through the list of the player's numbers and report
whether or not one of the tickets is a winner this week. Here are the numbers:

13579  26791  26792  33445  55555
62483  77777  79422  85647  93121
*/

#include <iostream>

int main()
{
	using namespace std;

	const size_t SIZE = 10;
	int luckyNumbers[SIZE] =
	{
		13579, 26791, 26792, 33445, 55555,
		62483, 77777, 79422, 85647, 93121
	};

	cout << "Enter your 5-digit number: ";
	int userNumber;
	cin >> userNumber;

	bool isLucky = false;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (userNumber == luckyNumbers[i])
		{
			isLucky = true;
			break;
		}
	}

	if (isLucky)
		cout << "You win the lottery!\n";
	else
		cout << "You lose :(\n";

	return 0;
}