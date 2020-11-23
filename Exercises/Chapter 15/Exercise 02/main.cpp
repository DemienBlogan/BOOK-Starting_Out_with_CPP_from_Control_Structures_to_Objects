/*
2. ShiftSupervisor Class
In a particular factory, a shift supervisor is a salaried employee who supervises a shift. In
addition to a salary, the shift supervisor earns a yearly bonus when his or her shift meets
production goals. Design a ShiftSupervisor class that is derived from the Employee class
your created in Programming Challenge 1 (Employee and Production Worker Classes). The
ShiftSupervisor class should have a member variable that holds the annual salary, and a
member variable that holds the annual production bonus that a shift supervisor has earned.
Write one or more constructors and the appropriate accessor and mutator functions for the
class. Demonstrate the class by writing a program that uses a ShiftSupervisor object.
*/

#include <iostream>

#include "ShiftSupervisor.h"

using std::cout;
using std::endl;

int main()
{
	ShiftSupervisor supervisor{ "Demien", 18, "24/12/1996", 58000.00, 3500.00 };

	cout << "Name: " << supervisor.GetName() << endl;
	cout << "Number: " << supervisor.GetNumber() << endl;
	cout << "Hire Date: " << supervisor.GetHireDate() << endl;
	cout << "Annual Salary: $" << supervisor.GetAnnualSalary() << endl;
	cout << "Annual Bonus: $" << supervisor.GetAnnualBonus() << endl;

	return 0;
}