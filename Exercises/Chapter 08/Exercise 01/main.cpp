/*
1. Charge Account Validation
Write a program that lets the user enter a charge account number. The program should
determine if the number is valid by checking for it in the following list:
	5658845  4520125  7895122  8777541  8451277  1302850
	8080152  4562555  5552012  5050552  7825877  1250255
	1005231  6545231  3852085  7576651  7881200  4581002
The list of numbers above should be initialized in a signle-deminsional array. A simple
linear search should be used to locate the number entered by the user. If the user enters 
is valid. If the user enters a number that is not in the array, the program should display
a message indicationg the number if invalid;
*/

#include <iostream>

int main()
{
	using namespace std;

	const size_t SIZE = 18;
	int validNumbers[SIZE] =
	{
		5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
		8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
		1005231, 6545231, 3852085, 7576651, 7881200, 4581002
	};

	cout << "Enter a charge account number: ";
	int userNumber;
	cin >> userNumber;

	bool isValid = false;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (userNumber == validNumbers[i])
		{
			isValid = true;
			break;
		}
	}

	if (isValid)
		cout << "Your number is valid.\n";
	else
		cout << "Your number is not valid.\n";

	return 0;
}