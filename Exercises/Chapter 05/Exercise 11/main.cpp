/*
11. Population
Write a program that will predict the size of a population of organisms. The program
should ask the user for the starting number of organisms, their average daily population
increase (as a percentage), and the numbe rof days they will multiply. A loop
should display the size of the population for each day.

Input Validation: Do not accept a number less than 2 for the starting size of the population.
Do not accept a negative number for average daily population increase. Do not
accept a number less than 1 for the number of days they will multiply.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the starting number of organisms: ";
	int population;
	cin >> population;

	if (population < 2)
	{
		cout << "Population cannot be less than 2.\n";
		return 0;
	}

	cout << "Enter the average daily population increase (as a percentage): ";
	double increasePercentage;
	cin >> increasePercentage;

	if (increasePercentage < 0)
	{
		cout << "Population increase cannot be less than 0.\n";
		return 0;
	}

	cout << "Enter the number of days they will miltiply: ";
	int days;
	cin >> days;

	if (days < 1)
	{
		cout << "Days cannot be less than 1.\n";
		return 0;
	}

	for (int day = 1; day <= days; day++)
	{
		population *= population * (increasePercentage / 100.0);
		cout << "Day #" << day << ". Population = " << population << endl;
	}

	return 0;
}