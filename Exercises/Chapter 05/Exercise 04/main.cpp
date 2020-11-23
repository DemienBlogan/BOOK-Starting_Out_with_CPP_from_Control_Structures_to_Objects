/*
4. Calories Burned
Running on a particular treadmill you burn 3.6 calories per minute. Write a program that
uses a loop to display the number of calories burned after 5, 10, 15, 20, 25, and 30 minutes.
*/

#include <iostream>

int main()
{
	using namespace std;

	const double CALORIES_PER_MINUTE = 3.6;
	double calories = 0.0;

	for (int minutes = 5; minutes <= 30; minutes += 5)
	{
		calories = minutes * CALORIES_PER_MINUTE;
		cout << "After " << minutes << " minutes you burn " << calories << " calories.\n";
	}

	return 0;
}