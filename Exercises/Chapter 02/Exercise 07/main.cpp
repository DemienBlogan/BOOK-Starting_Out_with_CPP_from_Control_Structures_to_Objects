/*
7. Ocean Levels
Assuming the ocean's level is currently rising at about 1.5 millimeters per year, write
a program that displays:

- The number of millimeters higher than the current level that the ocean 's level will
  be in 5 years.

- The number of millimeters higher than the current level that the ocean's level will
  be in 7 years.

- The number of millimeters higher than the current level that t he ocean's level will
  be in 10 years.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	const double RISING_MM_PER_YEAR = 1.5;
	double oceanLevelIn5Years = RISING_MM_PER_YEAR * 5;
	double oceanLevelIn7Years = RISING_MM_PER_YEAR * 7;
	double oceanLevelIn10Years = RISING_MM_PER_YEAR * 10;

	cout << "Ocean's level rising per year = " << RISING_MM_PER_YEAR << endl;
	cout << "Ocean level in 5 years = " << oceanLevelIn5Years << endl;
	cout << "Ocean level in 7 years = " << oceanLevelIn7Years << endl;
	cout << "Ocean level in 10 years = " << oceanLevelIn10Years << endl;

	return 0;
}