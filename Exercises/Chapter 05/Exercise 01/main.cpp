/*
1. Sum of Numbers
Write a program that asks the user for a positive integer value. The program should use
a loop to get the sum of all the integers from 1 up to the number entered. For example,
if the user enters 50, the loop will find the sum of 1, 2, 3, 4, ..., 50.
Input Validation: Do not accept a negative starting number.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a positive integer value: ";
	int value;
	cin >> value;

	if (value < 0)
	{
		cout << "Your value is negative.\n";
		return 0;
	}

	int sum = 0;
	for (int number = 1; number <= value; number++)
		sum += number;

	cout << "Sum = " << sum << endl;

	return 0;
}