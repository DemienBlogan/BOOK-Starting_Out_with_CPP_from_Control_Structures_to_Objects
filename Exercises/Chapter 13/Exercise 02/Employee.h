#pragma once

#include <string>

using std::string;

class Employee
{
private:
	string name;
	int idNumber;
	string department;
	string position;

public:
	Employee(const string& name, int idNumber, const string& department, const string& position);
	Employee(const string& name, int idNumber);
	Employee();

	void SetName(const string& name) { this->name = name; }
	void SetID(int idNumber) { this->idNumber = idNumber; }
	void SetDepartment(const string& department) { this->department = department; }
	void SetPosition(const string& position) { this->position = position; }

	string GetName() const { return name; }
	int GetID() const { return idNumber; }
	string GetDepartment() const { return department; }
	string GetPosition() const { return position; }
};