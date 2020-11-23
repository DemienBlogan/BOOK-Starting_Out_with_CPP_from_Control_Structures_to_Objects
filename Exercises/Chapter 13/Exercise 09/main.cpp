/*
9. Population
In a population, the birth rate and death rate are calculated as follows:

Birth Rate = Number of Births / Population
Death Rate = Number of Deaths / Population

For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
year, the birth rate and death rate are:

Birth Rate = 8,000 / 100,000 = 0.08
Death Rate = 6,000 / 100,000 = 0.06

Design a Population class that stores a popualtion, number of births, and number of
deaths for a period of time. Member functions should return the birth rate and death
rate. Implement the class in a program.

Input Validation: Do not accept population figures less than 1, or birth or death numbers
less than 0.
*/

#include <iostream>

#include "Population.h"

using std::cout;
using std::endl;

void ShowInformation(const Population& population);

int main()
{
	Population population{ 100000, 8000, 6000 };

	ShowInformation(population);

	return 0;
}

void ShowInformation(const Population& population)
{
	cout << "Population: " << population.GetPopulation() << endl;
	cout << "Number of Births: " << population.GetBirthNumber() << endl;
	cout << "Number of Deaths: " << population.GetDeathNumber() << endl;
	cout << "Birth Rate: " << population.GetBirthRate() << endl;
	cout << "Death Rate: " << population.GetDeathRate() << endl;
}