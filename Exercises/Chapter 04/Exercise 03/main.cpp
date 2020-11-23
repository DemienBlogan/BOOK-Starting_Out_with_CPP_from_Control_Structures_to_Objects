/*
3. Magic Dates
The date June 10, 1960 is special because when we write it in the following format, the
month times the day equals the year.

6/10/60

Write a program that asks the user to enter a month (in numeric form), a day, and a
two-digit year. The program should then determine whether the month times the day
is equal to the year. If so, it should display a message saying the date is magic.
Otherwise, it should display a message saying the date is not magic.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a month (in numeric form): ";
	int month;
	cin >> month;

	cout << "Enter a day: ";
	int day;
	cin >> day;

	cout << "Enter two-digit year: ";
	int year;
	cin >> year;

	if (day * month == year)
		cout << "Your date is magic.\n";
	else
		cout << "Your date is not magic.\n";

	return 0;
}