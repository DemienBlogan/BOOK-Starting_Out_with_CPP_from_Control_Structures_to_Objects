#include "ShiftSupervisor.h"

ShiftSupervisor::ShiftSupervisor(
	const string& name,
	int number, 
	const string& hireDate, 
	double annualSalary, 
	double annualBonus)
	: Employee(name, number, hireDate),
	annualSalary(annualSalary),
	annualBonus(annualBonus)
{ }

void ShiftSupervisor::SetAnnualSalary(double annualSalary)
{
	this->annualSalary = annualSalary;
}

void ShiftSupervisor::SetAnnualBonus(double annualBonus)
{
	this->annualBonus = annualBonus;
}

double ShiftSupervisor::GetAnnualSalary() const
{
	return annualSalary;
}

double ShiftSupervisor::GetAnnualBonus() const
{
	return annualBonus;
}
