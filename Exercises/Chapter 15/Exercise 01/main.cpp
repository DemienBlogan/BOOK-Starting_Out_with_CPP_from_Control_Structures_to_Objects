/*
1. Employee and ProductionWorker Classes
Design a class named Employee. The class should keep the following information:

- Employee name
- Employee number
- Hire date

Write one or more constructors, and the appropriate accessor and mutator functions,
for the class.

Next, write a class named ProductionWorker that is derived from the Employee class.
The ProductionWorker class should have member variables to hold the following
information:

- Shift (an integer)
- Hourly pay rate (a double)

The workday is divided into two shifts: day and night. The shift variable will hold an
integer value representing the shift that employee works. The day shift is shift 1,
and the night shift is shift 2. Write one or more constructors, and the appropriate accessor
and mutator functions, for the class. Demonstrate the classes by writing a program
that uses a ProductionWorker object.
*/

#include <iostream>

#include "ProductionWorker.h"

using std::cout;
using std::endl;

int main()
{
	ProductionWorker worker{ "Demien", 18, "24/12/1996", 2, 32.5 };

	cout << "Name: " << worker.GetName() << endl;
	cout << "Number: " << worker.GetNumber() << endl;
	cout << "Hire Date: " << worker.GetHireDate() << endl;
	cout << "Shift: " << (worker.GetShift() == 1 ? "Day" : "Night") << endl;
	cout << "Hourly Pay Rate: " << worker.GetHourlyPayRate() << endl;

	return 0;
}