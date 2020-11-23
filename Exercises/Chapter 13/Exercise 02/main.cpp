/*
2. Employee Class
Write a class named Employee that has the following member variables:
- name - a string that holds the employee's name
- idNumber - an int variable that holds the employee's ID number
- department - a string that holds the name of the department where the employee works
- position - a string that holds the employee's job title

The class should have the following constructors:
- A constructor that accepts the following values as arguments and assigns them to
  the appropriate member variables: employee's name, employee's ID number, department,
  and position.
- A consturctor that accepts the following values as arguments and assigns them to the
appropriate member variables: employee's name and ID number. The department
  and position fields should be assigned an empty string ("").
- A default constructor that assigns empty strings ("") to the name, department, and
  position member variables, and 0 to the idNumber member variable.

Write appropriate mutator functions that store values in these member variables and
accessor functions that return the values in these member variables. Once you have
written the class, write a separate program that creates three Employee object to hold
the following data:
----------------------------------------------------------------------
Name           ID Number           Department           Position
----------------------------------------------------------------------
Susan Meyers   47899               Accounting           Vice President
Mark Jones     39119               IT                   Programmer
Joy Rogers     81774               Manufacturing        Enginner
----------------------------------------------------------------------

The program should store this data in the three objects and then display the data for
each employee on the screen.
*/

#include <iostream>

#include "Employee.h"

using std::cout;
using std::endl;

void Show(const Employee& employee);

int main()
{
	Employee employee1{ "Susan Meyers", 47899, "Accounting", "Vice President" };
	Employee employee2{ "Mark Jones", 39119, "IT", "Programmer" };
	Employee employee3{ "Joy Rogers", 81774, "Manufacturing", "Engineer" };

	Show(employee1);
	Show(employee2);
	Show(employee3);

	return 0;
}

void Show(const Employee& employee)
{
	cout << "Name: " << employee.GetName() << endl;
	cout << "ID: " << employee.GetID() << endl;
	cout << "Department: " << employee.GetDepartment() << endl;
	cout << "Position: " << employee.GetPosition() << "\n\n";
}