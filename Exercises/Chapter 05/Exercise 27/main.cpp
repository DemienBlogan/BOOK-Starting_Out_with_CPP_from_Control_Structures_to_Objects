/*
27. Average Steps Taken
A Personal Fitness Tracker is a wearable device that tracks your physical activity, calories
burned, heart rate, sleeping patterns, and so on. One common physical activity that
most of these devices track is the number of steps you take each day.

If you have downloaded this book's source code, you will find a file names steps.txt in
the Chapter 05 folder. The steps.txt file contains the number of steps a person has taken
each day for a year. THere are 365 lines in the file, and each line contains the number
of steps taken during a day. The first line is the number of steps taken on January 2, and so forth).
Write a program that reads the file, then displays the average number of steps taken for each
month. (The data is from a year that was not a leap year, so February has 28 days).
*/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	std::ifstream file("Text.txt");

	if (!file)
	{
		cout << "The file 'Text.txt' could not been opened.\n";
		return 1;
	}

	const int MONTHS = 12;
	int monthsDays[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int monthAverageSteps;
	int monthSumSteps;
	int daySteps;

	for (int i = 0; i < MONTHS; i++)
	{
		monthSumSteps = 0;

		for (int day = 0; day < monthsDays[i]; day++)
		{
			file >> daySteps;
			monthSumSteps += daySteps;
		}

		monthAverageSteps = monthSumSteps / monthsDays[i];
		cout << "The average number of steps taken for " << i + 1 << " month = ";
		cout << monthAverageSteps << endl;
	}

	return 0;
}