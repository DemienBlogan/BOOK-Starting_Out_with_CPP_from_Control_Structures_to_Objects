/*
3. Ocean Levels
Assuming the ocean's level is currently rising at about 1.5 millimeters per year, write
a program that displays a table showing the numbe rof millimeters that the ocean will
have risen each year for the next 25 years.
*/

#include <iostream>

int main()
{
	using namespace std;

	double rising = 1.5;

	for (int year = 1; year <= 25; year++, rising += 1.5)
		cout << "In " << year << " ocean level rised at " << rising << " millimeters.\n";

	return 0;
}