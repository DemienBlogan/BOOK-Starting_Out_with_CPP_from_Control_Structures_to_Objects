/*
7. Pennies for Pay
Write a program that calculates how much a person would earn over a period of time
if his or her salary is one penny the first day and two pennies the second day, and continues
to double each day. The program should ask the user for the number of days.
Display a table showing how much the salary was for each day, and then show the
total pay at the end of the period. The output should be displayed in a dollar amount,
not the number of pennies.

Input Validation: Do not accept a number less than 1 for the number of days worked.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the number of days: ";
	int days;
	cin >> days;

	if (days < 1)
	{
		cout << "The number of days has to be greater than 1.\n";
		return 0;
	}

	int pennies = 1;
	double daylySalary;
	double totalSalary = 0.0;

	for (int day = 1; day <= days; day++, pennies *= 2)
	{
		daylySalary = pennies * 0.01;
		totalSalary += daylySalary;

		cout << fixed << setprecision(2);
		cout << "Day #" << day << ": $" << daylySalary << endl;
	}

	cout << "\nTotal salary = $" << totalSalary << endl;

	return 0;
}