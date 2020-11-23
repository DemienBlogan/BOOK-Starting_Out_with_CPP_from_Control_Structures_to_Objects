/*
7. Time Calculator
Write a program that asks the user to enter a number of seconds.
- There are 60 seconds in a minute. If the number of seconds entered by the user is
greater than or equal to 60, the program should display the number of minutes in
that many seconds.
- There are 3,600 seconds in an hour. If the number of entered by the user is
greater than or equal to 3,600, the program should display the number of hours in
that many seconds.
- There are 86,400 seconds in a day. If the number of seconds entered by the user is
greater than or equal to 86,400, the program display the number of days in 
that many seconds.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a number of seconds: ";
	int seconds;
	cin >> seconds;

	const int SECONDS_IN_DAY = 86'400;
	const int SECONDS_IN_HOUR = 3'600;
	const int SECONDS_IN_MINUTE = 60;

	if (seconds >= SECONDS_IN_DAY)
	{
		int days = seconds / SECONDS_IN_DAY;
		cout << "In these seconds " << days << " day(s).\n";
	}
	else if (seconds >= SECONDS_IN_HOUR)
	{
		int hours = seconds / SECONDS_IN_HOUR;
		cout << "In these seconds " << hours << " hour(s).\n";
	}
	else if (seconds >= SECONDS_IN_MINUTE)
	{
		int minutes = seconds / SECONDS_IN_MINUTE;
		cout << "In these seconds " << minutes << " minute(s).\n";
	}

	return 0;
}