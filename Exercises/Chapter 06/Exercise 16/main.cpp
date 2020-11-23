/*
16. Population
In a population, the birth rate is the percentage increase of the population due to births,
and the death rate is the percentage decrease of the population due to deaths. Write a
program that displays the size of a population for any number of years. The program
should ask for the following data:
- The starting size of a population
- The annual birth rate
- The annual death rate
- The number of years to display
Write a function that calculates the size of the population for a year. The formula is
N = P + BP - DP
where N is the new population size, P is the previous population size, B is the birth rate,
and D is the death rate.

Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for bitrh rate or death rate. Do not accept number less than 1 for
the number of years.
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
	double N = 0;

	for (int year = 0; year < years; year++)
	{
		N = P + B * P - D * P;
		P = N;
	}

	return N;
}