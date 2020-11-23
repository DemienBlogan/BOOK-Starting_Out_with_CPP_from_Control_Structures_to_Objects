#include "Employee.h"

Employee::Employee(const string& name, int idNumber, const string& department, const string& position)
	: name(name), idNumber(idNumber), department(department), position(position)
{ }

Employee::Employee(const string& name, int idNumber)
	: name(name), idNumber(idNumber), department(""), position("")
{ }

Employee::Employee()
	: name(""), idNumber(0), department(""), position("")
{ }
