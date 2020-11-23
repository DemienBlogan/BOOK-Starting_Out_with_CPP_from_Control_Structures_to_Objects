/*
22. Freezing and Boiling Points
The following table lists the freezing and boiling points of several substances. Write a
program that asks the user to enter a temperature then shows all the substances that
will freeze at that temperature, and all that will boil at that temperature. For example, if
the user enters -20, the program should report that water will freeze and oxygen will
boil at that temperature.
------------------------------------------------------------------------
Substance              Freezing Point (F)              Boiling Point (F)
------------------------------------------------------------------------
Ethyl alcohol          -173                            172
Mercury                -38                             676
Oxygen                 -363                            -306
Water                  32                              212
------------------------------------------------------------------------
*/
#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a temperature: ";
	double temperature;
	cin >> temperature;

	cout << "All the substances that will freeze: ";
	if (temperature <= -173)
		cout << "\nEthyl alcohol";
	if (temperature <= -38)
		cout << "\nMercury";
	if (temperature <= -362)
		cout << "\nOxygen";
	if (temperature <= 32)
		cout << "\nWater";

	cout << "\n\nAll the substances that will boil: ";
	if (temperature >= 172)
		cout << "\nEthyl alcohol";
	if (temperature >= 676)
		cout << "\nMercury";
	if (temperature >= -306)
		cout << "\nOxygen";
	if (temperature >= 212)
		cout << "\nWater";

	cout << endl;

	return 0;
}