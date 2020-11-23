#include <iostream>
#include "ProductionWorker.h"

using std::cout;

ProductionWorker::ProductionWorker(
	const string& name, 
	int number,
	const string& hireDate, 
	int shift, 
	double hourlyPayRate)
	: Employee(name, number, hireDate),
	shift(shift),
	hourlyPayRate(hourlyPayRate)
{
	if (shift < 0 || shift > 2)
		throw InvalidShift();

	if (hourlyPayRate <= 0)
		throw InvalidPayRate();
}

void ProductionWorker::SetShift(int shift)
{
	this->shift = shift;
}

void ProductionWorker::SetHourlyPayRate(double hourlyPayRate)
{
	this->hourlyPayRate = hourlyPayRate;
}

int ProductionWorker::GetShift() const
{
	return shift;
}

double ProductionWorker::GetHourlyPayRate() const
{
	return hourlyPayRate;
}

void InvalidShift::ShowErrorMessage() const
{
	cout << "An invalid shift.\n";
}

void InvalidPayRate::ShowErrorMessage() const
{
	cout << "Negative number for the hourly pay rate.\n";
}