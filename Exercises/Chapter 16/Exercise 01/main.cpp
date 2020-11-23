/*
1. Date Exceptions
Modify the Date class you wrote for Programming Challenge 1 of Chapter 13 (Date).
The class should implement the following exception classes:

InvalidDay - Throw when an invalid day (< 1 or > 31) is passed to the class.
InvalidMonth - Throw when an invalid month (< 1 or > 12) is passed to the class.

Demonstrate the class in a driver program.
*/

#include "Date.h"

int main()
{
	try
	{
		Date date1{ 15, 40, 2994 };
	}
	catch (const InvalidDay& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const InvalidMonth& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		Date date1{ 100, 10, 2994 };
	}
	catch (const InvalidDay& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const InvalidMonth& exc)
	{
		exc.ShowErrorMessage();
	}

	return 0;
}