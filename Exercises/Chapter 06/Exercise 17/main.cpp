/*
17. Transient Population
Modify Programming Challenge 16 to also consider the effect on population caused by
people moving into or out of a geographic area. Given as input a starting population
size, the annual birth rate, the annual death rate, the number of individuals who typically
move into the area each year, and the number of individuals who typically leave
the area each year, the program should project what the population will be numYears
from now. You can either prompt the user to input a value for numYears, or you can
set it within the program.

Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for birth rate, death rate, arrivals, or departures.
*/

#include <iostream>

double calculatesPopulation(int P, double B, double D, int years);

int main()
{
	using namespace std;

	cout << "Enter the starting size of a population: ";
	int P;
	cin >> P;

	if (P < 2)
	{
		cout << "Incorrect starting size of a population: ";
		return 0;
	}

	cout << "Enter the annual birth rate: ";
	double B;
	cin >> B;

	if (B < 0)
	{
		cout << "Incorrect annual birth rate: ";
		return 0;
	}

	cout << "Enter the annual death rate: ";
	double D;
	cin >> D;

	if (D < 0)
	{
		cout << "Incorrect annual death rate: ";
		return 0;
	}

	cout << "Enter the number of years to display: ";
	int years;
	cin >> years;

	if (years < 0)
	{
		cout << "Incorrect number of years: ";
		return 0;
	}

	double N = calculatesPopulation(P, B, D, years);

	cout << "Total population: " << N << endl;

	return 0;
}

double calculatesPopulation(int P, double B, double D, int years)
{
	using namespace std;

	double N = 0;

	for (int year = 0; year < years; year++)
	{
		cout << "Enter the number of individuals who move int the area in " << year + 1 << " year: ";
		int arrivals;
		cin >> arrivals;

		if (arrivals < 0)
		{
			cout << "Incorrect number of arriavals.\n";
			exit(0);
		}

		cout << "Enter the number of individuals who leave the area in " << year + 1 << " year: ";
		int departues;
		cin >> departues;

		if (departues < 0)
		{
			cout << "Incorrect number of departues.\n";
			exit(0);
		}

		N = P + B * P - D * P + arrivals - departues;
		P = N;
	}

	return N;
}