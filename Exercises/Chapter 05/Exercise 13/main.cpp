/*
13. The Greatest and Least of These
Write a program with a loop that lets the user enter a series of integers. The user should
enter -99 to signal the end of the series. After all the numbers have been entered, the
program should display the largest and smallest numbers entered.
*/

#include <iostream>

int main()
{
	using namespace std;

	int theGreatestNumber, theLeastNumber;

	cout << "Enter a number: ";
	int number;
	cin >> number;

	theGreatestNumber = theLeastNumber = number;

	do
	{
		cout << "Enter next number (or -99 to stop): ";
		cin >> number;

		if (number != -99)
		{
			if (theGreatestNumber < number)
				theGreatestNumber = number;
			if (theLeastNumber > number)
				theLeastNumber = number;
		}

	} while (number != -99);

	cout << "The greatest number = " << theGreatestNumber << endl;
	cout << "The least number = " << theLeastNumber << endl;
	
	return 0;
}