/*
24. Long-Distance Calls
A long-distance carrier charges the following rates for telephone calls:
----------------------------------------------
Starting Time of Call          Rate per Minute
----------------------------------------------
00:00 - 06:59                  0.05
07:00 - 19:00                  0.45
19:01 - 23:59                  0.20
----------------------------------------------
Write a program that asks for the starting time and the number of minutes of the call,
and siplays the charges. The program should ask for the time to be entered as a
floating-point number in the form HH.MM. For example, 07:00 hours will be
entered as 07.00, and 16:28 hours will be entered as 16.28.

Input Validation: The program should not accept times that are greater than 23:59. Also,
no numbe rwhose last two digits are greater than 59 should be accepted. Hint: Assuming
num is a floating-point variable, the following expression will give you its fractional part:
num - static_cast<int>(num)
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the starting time (HH.MM): ";
	double startingTime;
	cin >> startingTime;

	int hours = startingTime;
	int minutes = startingTime - static_cast<int>(startingTime);

	if (hours < 0 || hours >= 24)
	{
		cout << "Incorrect number of hours.\n";
		return 0;
	}

	if (minutes < 0 || minutes >= 60)
	{
		cout << "Incorrect number of minutes.\n";
		return 0;
	}

	cout << "Enter the number of minutes of the call: ";
	int callMinutes;
	cin >> callMinutes;

	if (callMinutes <= 0)
	{
		cout << "Incorrect number of minutes of the call.\n";
		return 0;
	}

	double charges;
	double ratePerMinute;


	if (hours >= 0 && minutes >= 0 && hours <= 6 && minutes <= 59)	    // 00:00 - 06:59
		ratePerMinute = 0.05;
	else if (hours >= 7 && minutes >= 0 && hours <= 19 && minutes <= 0)	// 07:00 - 19:00
		ratePerMinute = 0.45;
	else                                                             	// 19:01 - 23:59
		ratePerMinute = 0.20;

	charges = callMinutes * ratePerMinute;
	cout << fixed << setprecision(2);
	cout << "Charges = $" << charges << endl;

	return 0;
}