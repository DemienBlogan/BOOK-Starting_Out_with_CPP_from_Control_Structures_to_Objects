/*
4. Average Rainfall
Write a program that calculates the average rainfall for three months. The program
should ask the user to enter the name of each month, such as June or July, and the
amount of rain (in inches) that fell each month. The program should display a message
similar to the following:

The average rainfall for June, July, a nd August is 6.72 inches.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter the name of the first month: ";
	string month1Name;
	cin >> month1Name;

	cout << "Enter the name of the second month: ";
	string month2Name;
	cin >> month2Name;

	cout << "Enter the name of the third month: ";
	string month3Name;
	cin >> month3Name;

	cout << "Enter the amount of rain (in inches) of " << month1Name << ": ";
	double month1RainInches;
	cin >> month1RainInches;

	cout << "Enter the amount of rain (in inches) of " << month2Name << ": ";
	double month2RainInches;
	cin >> month2RainInches;

	cout << "Enter the amount of rain (in inches) of " << month3Name << ": ";
	double month3RainInches;
	cin >> month3RainInches;

	const int AMOUNT_OF_MONTHS = 3;
	double average = (month1RainInches + month2RainInches + month3RainInches) / AMOUNT_OF_MONTHS;

	cout << "The average rainfall of " << month1Name << ", " << month2Name;
	cout << ", and " << month3Name << " is " << average << " inches.\n";

	return 0;
}