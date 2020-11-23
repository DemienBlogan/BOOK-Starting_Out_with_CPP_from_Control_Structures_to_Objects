/*
1. Date
Design a class called Date. The class should store a date in three integers: month, day,
and year. There should be member functions to print the date in the following forms:
12/25/2018
December 25, 2018
25 December 2018

Demonstrate the class by writing a complete program implementing it

Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
not accept values for the month greater than 12 or less than 1.
*/

#include <iostream>

#include "Date.h"

using std::cout;

int main()
{
	Date date;

	cout << "Default date: ";
	date.Show();

	Date date1{ 12, 25, 2018 };
	cout << "Date1: ";
	date1.Show(Date::Representing::BY_SLASH);

	Date date2{ 12, 25, 2018 };
	cout << "Date2: ";
	date2.Show(Date::Representing::MONTH_DAY_COMA_YEAR);

	Date date3{ 12, 25, 2018 };
	cout << "Date3: ";
	date3.Show(Date::Representing::DAY_MONTH_YEAR);

	return 0;
}