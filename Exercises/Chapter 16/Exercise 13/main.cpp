/*
13. Exception Project
This assignment assumes you have completed Programming Challenge 1 of Chapter 15
(Employee and ProductionWorker Classes). Modify the Employee and ProductionWorker Classes
so they throw exceptions when the following errors occur:

- The Employee class should throw an exception named InvalidEmployeeNumber
  when it receives an employee number that is less than 0 or greater that 9999.

- The ProductionWorker class should throw an exception InvalidShift
  when it receives an invalid shift.

- The ProductionWorker class should throw an exception named InvalidPayRate
  when it receives a negative number for the hourly pay rate.

Write a driver program that demonstrates how each of these exception conditions
works.
*/

#include "ProductionWorker.h"

int main()
{
	try
	{
		ProductionWorker worker{ "Demien", -3 };
	}
	catch (const InvalidEmployeeNumber& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		ProductionWorker worker{ "Demien", 5, "12/12/1212", 5, 504.33 };
	}
	catch (const InvalidShift& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		ProductionWorker worker{ "Demien", 5, "12/12/1212", 1, -100 };
	}
	catch (const InvalidPayRate& exc)
	{
		exc.ShowErrorMessage();
	}

	return 0;
}