#pragma once
#include "Employee.h"

class InvalidShift
{
public:
	void ShowErrorMessage() const;
};

class InvalidPayRate
{
public:
	void ShowErrorMessage() const;
};

class ProductionWorker : public Employee 
{
private:
	int shift;
	double hourlyPayRate;

public:
	ProductionWorker(
		const string& name = "NoName",
		int number = 0,
		const string& hireDate = "0/0/0",
		int shift = 1,
		double hourlyPayRate = 0);

	void SetShift(int shift);
	void SetHourlyPayRate(double hourlyPayRate);
	int GetShift() const;
	double GetHourlyPayRate() const;
};