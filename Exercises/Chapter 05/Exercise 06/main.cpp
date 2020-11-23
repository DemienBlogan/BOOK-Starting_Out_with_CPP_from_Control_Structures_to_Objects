/*
6. Distance Traveled
The distance a vehicle travels can be calculated as follows:
distance = speed * time
For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is
120 miles.

Write a program that asks the user for the speed of a vehicle (in miles per hour) and how
many hours it has traveled. The program should then use a loop to display the distance the
vehicle has traveled for each hour of that time period.

Input Validation: Do not accept a negative numbe rfor speed and do not accept any
value less than 1 for time traveled.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "What is the speed of the vehicle in mph? ";
	double speed;
	cin >> speed;

	if (speed < 0)
	{
		cout << "Incorrect speed.\n";
		return 0;
	}

	cout << "How many hours has it traveled? ";
	int hours;
	cin >> hours;

	if (hours < 1)
	{
		cout << "Incorrec time. Number of hours has to be greater than 0.\n";
		return 0;
	}

	cout << "Hour Distance Traveled\n";
	cout << "----------------------\n";

	for (int hour = 1; hour <= hours; hour++)
	{
		double distance = speed * hour;
		cout << setw(4) << hour << " " << setw(8) << distance << endl;
	}

	return 0;
}