/*
16. Running the Race
Write a program that asks for the names of three runners and the time it took each
of them to finish a race. The program should display who came in first, second, and
third place.
Input Validation: Only accept positive numbers for the times.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter the name of the first runner: ";
	string runner1Name;
	cin >> runner1Name;

	cout << "Enter the name of the second runner: ";
	string runner2Name;
	cin >> runner2Name;

	cout << "Enter the name of the third runner: ";
	string runner3Name;
	cin >> runner3Name;

	cout << "Enter the time it took of first runner to finish the race (seconds): ";
	double runner1Time;
	cin >> runner1Time;

	cout << "Enter the time it took of second runner to finish the race (seconds): ";
	double runner2Time;
	cin >> runner2Time;

	cout << "Enter the time it took of third runner to finish the race (seconds): ";
	double runner3Time;
	cin >> runner3Time;

	if (runner1Time <= 0 || runner2Time <= 0 || runner3Time <= 0)
	{
		cout << "One of times is incorrect.\n";
		return 0;
	}

	string first, second, third;

	// Searching first runner
	if (runner1Time < runner2Time)
	{
		if (runner1Time < runner3Time)
			first = runner1Name;
		else
			first = runner3Name;
	}
	else if (runner2Time < runner3Time)
		first = runner2Name;
	else
		first = runner3Name;

	// Searching third runner
	if (runner1Time > runner2Time)
	{
		if (runner1Time > runner3Time)
			third = runner1Name;
		else
			third = runner3Name;
	}
	else if (runner2Time > runner3Time)
		third = runner2Name;
	else
		third = runner3Name;

	// Searching second runner
	if ((first == runner1Name && third == runner2Name) || (third == runner1Name && first == runner2Name))
		second = runner3Name;
	else if ((first == runner2Name && third == runner3Name) || (third == runner2Name && first == runner3Name))
		second = runner1Name;
	else
		second = runner2Name;

	cout << "Runner #1: " << first << endl;
	cout << "Runner #2: " << second << endl;
	cout << "Runner #3: " << third << endl;

	return 0;
}