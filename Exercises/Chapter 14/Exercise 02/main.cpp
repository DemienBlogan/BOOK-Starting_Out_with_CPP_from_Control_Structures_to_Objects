/*
2. Day of the Year
Assuming a year has 365 days, write a class named DayOfYear that takes an integer
representing a day of the year and translates it to a string consisting of the month
followed by day of the month. For example,

Day 2 would be January 2.
Day 32 would be February 1.
Day 365 would be December 31.

The constructor for the class should take as parameter an integer representing the
day of the year, and the calss should have a member function print() that prints the
day in the month-day format. The class should have an integer member variable to
represent the day, and should have static member variables holding string objects that
can be used to assist in the translation from the integer format to the month-day format.

Test your class by inputting various integers representing days and printing out their
representation in the month-day format.
*/

#include "DayOfYear.h"

int main()
{
	DayOfYear day1{ 2 }, day2{ 32 }, day3{ 365 };

	day1.print();
	day2.print();
	day3.print();

	return 0;
}