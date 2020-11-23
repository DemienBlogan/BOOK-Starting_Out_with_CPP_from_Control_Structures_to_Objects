/*
10. Days in a Month
Write a program that asks the user to enter the month (letting the user enter an integer
in the range of 1 through 12) and year. The program should then display the number
of days in that month. Use the following criteria to identify leap years:

1. Determine whether the year is divisible by 100. If it is, then it is a leap year if and
   only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
2. If the year is not divisible by 100, then it is a leap year if and obly if it is divisible by 4.
   For example, 2008 is a leap year but 2009 is not.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a number of a month: ";
	int month;
	cin >> month;

	if (month < 1 || month > 12)
	{
		cout << "Incorrect number. Try again.\n";
		return 0;
	}

	cout << "Enter a year: ";
	int year;
	cin >> year;

	if (year < 0)
	{
		cout << "Incorrect number. Try again.\n";
		return 0;
	}

	bool isLeapYear;

	if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		isLeapYear = true;
	else
		isLeapYear = false;

	switch (month)
	{
	case 2:
		cout << (isLeapYear ? "29 days" : "28 days") << ".\n";
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cout << "31 days.\n";
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "30 days.\n";
		break;
	}

	return 0;
}