#include "ProductionWorker.h"

ProductionWorker::ProductionWorker(
	const string& name, 
	int number,
	const string& hireDate, 
	int shift, 
	double hourlyPayRate)
	: Employee(name, number, hireDate),
	shift(shift),
	hourlyPayRate(hourlyPayRate)
{ }

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