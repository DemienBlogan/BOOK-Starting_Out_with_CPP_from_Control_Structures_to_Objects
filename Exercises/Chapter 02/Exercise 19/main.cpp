/*
19. Annual High Temperatures
The average July high temperarure is 85 degrees Fahrenheit in New York City, 88 degrees
Fahrenheit in Denver, and 106 degrees Fahrenheit in Phoenix. Write a program that
calculates and reports what the new average July high temperature would be for each of
these cities if temperatures rise by 2 percent.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double oldTemperatureNewYork = 85.0;
	double oldTemperatureDenver = 88.0;
	double oldTemperaturePhoenix = 106.0;

	double risePercent = 0.02; // 2%

	double newTemperatureNewYork = oldTemperatureNewYork + oldTemperatureNewYork * risePercent;
	double newTemperatureDenver = oldTemperatureDenver + oldTemperatureDenver * risePercent;
	double newTemperaturePhoenix = oldTemperaturePhoenix + oldTemperaturePhoenix * risePercent;

	cout << fixed << setprecision(1);
	cout << " --- Old temperatures --- \n";
	cout << "New York City = " << oldTemperatureNewYork << "F \n";
	cout << "Denver        = " << oldTemperatureDenver << "F \n";
	cout << "Phoenix       = " << oldTemperaturePhoenix << "F \n";

	cout << endl;

	cout << " --- New temperatures --- \n";
	cout << "New York City = " << newTemperatureNewYork << "F \n";
	cout << "Denver        = " << newTemperatureDenver << "F \n";
	cout << "Phoenix       = " << newTemperaturePhoenix << "F \n";

	return 0;
}