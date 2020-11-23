/*
10. Average Rainfall
Write a program that uses nested loops to collect data and calculate the average rainfall
over a period of years. The program should first ask for the number of yers. The outer
loop will iterate once for each year. The inner loop will iterate 12 times, once for each
month. Each iteration of the inner loop will ask the user for the inches of rainfall for
that month.

After all iterations, the program should display the number of months, the total inches
of rainfall, and the average rainfall per month for the entire period.

Input Validation: Do not accept a number less than 1 for the numbe rof years. Do not
accept negative numbers for the monthly rainfall.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the number of years: ";
	int years;
	cin >> years;

	if (years < 1)
	{
		cout << "Incorrect number of years. This value has to be greater than 0.\n";
		return 0;
	}

	const int MONTHS_IN_YEAR = 12;
	double totalInches = 0.0;

	for (int year = 1; year <= years; year++)
	{
		cout << "Year #" << year << ":\n";
		for (int month = 1; month <= MONTHS_IN_YEAR; month++)
		{
			cout << "\tMonth #" << month << ". Enter the inches of rainfall: ";
			double monthInches;
			cin >> monthInches;

			if (monthInches < 0)
			{
				cout << "Incorrect number of inches. This value has to be possitive.\n";
				return 0;
			}

			totalInches += monthInches;
		}
	}

	int allMonths = years * MONTHS_IN_YEAR;
	double averageRainfallPerMonth = totalInches / allMonths;

	cout << "All months: " << allMonths << endl;
	cout << "Average rainfall per month: " << averageRainfallPerMonth << endl;

	return 0;
}