/*
17. Personal Best
Write a program that asks for the name of a pole vaulter and the dates and vault
heights (in meters) of the athlete's three best vauls. It should then report, in order of
height (best first), the date on which each vault was made and its height.
Input Validation: Only accept values between 2.0 and 5.0 for the heights.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter the name of a pole vaulter: ";
	string name;
	cin >> name;

	cout << "Enter a date (day) when was first vault: ";
	int vault1Day;
	cin >> vault1Day;

	cout << "Enter height (in meters) of the first vault (2.0 ... 5.0): ";
	double vault1Height;
	cin >> vault1Height;

	cout << "Enter a date (day) when was second vault: ";
	int vault2Day;
	cin >> vault2Day;

	cout << "Enter height (in meters) of the second vault (2.0 ... 5.0): ";
	double vault2Height;
	cin >> vault2Height;

	cout << "Enter a date (day) when was third vault: ";
	int vault3Day;
	cin >> vault3Day;

	cout << "Enter height (in meters) of the third vault (2.0 ... 5.0): ";
	double vault3Height;
	cin >> vault3Height;

	if (vault1Height < 2.0 || vault1Height > 5.0 ||
		vault2Height < 2.0 || vault2Height > 5.0 ||
		vault3Height < 2.0 || vault3Height > 5.0)
	{
		cout << "One of heights is incorrect. Try again.\n";
		return 0;
	}

	int firstDay, secondDay, thirdDay; // TOP-3 days
	double firstHeight, secondHeight, thirdHeight; // TOP-3 heights

	// Searching first runner
	if (vault1Height < vault2Height)
	{
		if (vault1Height < vault3Height)
		{
			thirdDay = vault1Day;
			thirdHeight = vault1Height;
		}
		else
		{
			thirdDay = vault3Day;
			thirdHeight = vault3Height;
		}
	}
	else if (vault2Height < vault3Height)
	{
		thirdDay = vault2Day;
		thirdHeight = vault2Height;
	}
	else
	{
		thirdDay = vault3Day;
		thirdHeight = vault3Height;
	}

	// Searching third runner
	if (vault1Height > vault2Height)
	{
		if (vault1Height > vault3Height)
		{
			firstDay = vault1Day;
			firstHeight = vault1Height;
		}
		else
		{
			firstDay = vault3Day;
			firstHeight = vault3Height;
		}
	}
	else if (vault2Height > vault3Height)
	{
		firstDay = vault2Day;
		firstHeight = vault2Height;
	}
	else
	{
		firstDay = vault3Day;
		firstHeight = vault3Height;
	}

	// Searching second runner
	if ((firstDay == vault1Day && thirdDay == vault2Day) || (thirdDay == vault1Day && firstDay == vault2Day))
	{
		secondDay = vault3Day;
		secondHeight = vault3Height;
	}
	else if ((firstDay == vault2Day && thirdDay == vault3Day) || (thirdDay == vault2Day && firstDay == vault3Day))
	{
		secondDay = vault1Day;
		secondHeight = vault1Height;
	}
	else
	{
		secondDay = vault2Day;
		secondHeight = vault2Height;
	}

	cout << "Voulter's name: " << name << endl;
	cout << "Height #1 = " << firstHeight << "m (day " << firstDay << ")\n";
	cout << "Height #2 = " << secondHeight << "m (day " << secondDay << ")\n";
	cout << "Height #3 = " << thirdHeight << "m (day " << thirdDay << ")\n";

	return 0;
}