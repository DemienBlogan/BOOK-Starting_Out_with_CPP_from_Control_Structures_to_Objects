/*
2. Time Format Exceptions
Modify the MilTime class you created for Programming Challenge 4 of Chapter 15
(Time Format). The class should implement the following exceptions:

BadHour    - Throw when an invalid hour (< 0 or > 2359) is passed to the class.
BadSeconds - Throw when an invalid number of seconds (< 0 or > 59) is passed to the class.

Demonstrate the class in a driver program.
*/

#include "MilTime.h"

int main()
{
	try
	{
		MilTime time1{ 20, 10000 };
	}
	catch (const BadHour& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const BadSeconds& exc)
	{
		exc.ShowErrorMessage();
	}

	try
	{
		MilTime time2{ 10000, 20 };
	}
	catch (const BadHour& exc)
	{
		exc.ShowErrorMessage();
	}
	catch (const BadSeconds& exc)
	{
		exc.ShowErrorMessage();
	}

	return 0;
}