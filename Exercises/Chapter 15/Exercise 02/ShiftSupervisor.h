#pragma once

#include "Employee.h"

class ShiftSupervisor : public Employee
{
private:
	double annualSalary;
	double annualBonus;

public:
	ShiftSupervisor(
		const string& name = "NoName",
		int number = 0,
		const string& hireDate = "0/0/0",
		double annualSalary = 0,
		double annualBonus = 0);

	void SetAnnualSalary(double annualSalary);
	void SetAnnualBonus(double annualBonus);
	double GetAnnualSalary() const;
	double GetAnnualBonus() const;
};