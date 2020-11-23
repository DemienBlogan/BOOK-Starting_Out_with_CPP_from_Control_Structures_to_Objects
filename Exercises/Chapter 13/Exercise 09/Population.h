#pragma once

class Population
{
private:
	int population;
	int birthNumber;
	int deathNumber;

public:
	Population(int population, int birthNumber, int deathNumber);

	void SetPopulation(int population);
	void SetBirthNumber(int birthNumber);
	void SetDeathNumber(int deathNumber);

	int GetPopulation() const { return population; }
	int GetBirthNumber() const { return birthNumber; }
	int GetDeathNumber() const { return deathNumber; }
	double GetBirthRate() const { return birthNumber / static_cast<double>(population); }
	double GetDeathRate() const { return deathNumber / static_cast<double>(population); }
};