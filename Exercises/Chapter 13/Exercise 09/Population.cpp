#include "Population.h"

Population::Population(int population, int birthNumber, int deathNumber)
	: population(1), birthNumber(0), deathNumber(0)
{
	SetPopulation(population);
	SetBirthNumber(birthNumber);
	SetDeathNumber(deathNumber);
}

void Population::SetPopulation(int population)
{
	if (population >= 1)
		this->population = population;
}

void Population::SetBirthNumber(int birthNumber)
{
	if (birthNumber >= 0)
		this->birthNumber = birthNumber;
}

void Population::SetDeathNumber(int deathNumber)
{
	if (deathNumber >= 0)
		this->deathNumber = deathNumber;
}
