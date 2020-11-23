#include <iostream>
#include "Employee.h"

using std::cout;

Employee::Employee(const string& name, int number, const string& hireDate)
	: name(name), number(number), hireDate(hireDate)
{ 
	if (number < 0 || number > 9999)
		throw InvalidEmployeeNumber();
}

void Employee::SetName(const string & name)
{
	this->name = name;
}

void Employee::SetNumber(int number)
{
	this->number = number;
}

void Employee::SetHireDate(const string& hireDate)
{
	this->hireDate = hireDate;
}

string Employee::GetName() const
{
	return name;
}

int Employee::GetNumber() const
{
	return number;
}

string Employee::GetHireDate() const
{
	return hireDate;
}

void InvalidEmployeeNumber::ShowErrorMessage() const
{
	cout << "Employee number is less than 0 or greater that 9999.\n";
}