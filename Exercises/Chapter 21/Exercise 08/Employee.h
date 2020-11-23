#pragma once
#include <string>
#include <iostream>

class Employee
{
private:
	int id;
	std::string name;

public:
	Employee()
		: id(0), name()
	{ }

	Employee(int id, const std::string name)
		: id(id), name(name)
	{ }

	int GetID() const { return id; }
	std::string GetName() const { return name; }

	friend bool operator<(const Employee& employee1, const Employee& employee2);
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
};

bool operator<(const Employee& employee1, const Employee& employee2)
{
	return employee1.id < employee2.id;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << "\tName: " << employee.GetName() << ", ID: " << employee.GetID() << std::endl;

	return out;
}