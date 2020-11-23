/*
16. Freezing and Boiling Points
He following table lists the freezing and boiling points of several substances.
----------------------------------------------------
Substance        Freezing Point        Boiling Point
----------------------------------------------------
Ethyl alcohol    -173                  172
Oxygen           -362                  -306
Ethyl alcohol    32                    212
----------------------------------------------------

Design a class that stores a temperature in a temperature member variable and has the
appropriate accessor and mutator functions. In addition to appropriate constructors,
the class should have the following member functions:
- isEthylFreezing - This function should return the bool value true if the temperature
  stored in the temperature field is at or below the freezing point of ethyl alcohol. 
  Otherwise, the function should return false.
- isEthylBoiling - This function should return the bool value true if the temperature
  stored in the temperature field is at or above the boiling point of ethyl alcohol. 
  Otherwise, the function should return false.
- isOxygenFreezing - This function should return the bool value true if the temperature
  stored in the temperature field is at or below the freezing point of oxygen. 
  Otherwise, the function should return false.
- isOxygenBoiling - This function should return the bool value true if the temperature
  stored in the temperature field is at or above the boiling point of oxygen. 
  Otherwise, the function should return false.
- isWaterFreezing - This function should return the bool value true if the temperature
  stored in the temperature field is at or below the freezing point of water. 
  Otherwise, the function should return false.
- isWaterBoiling - This function should return the bool value true if the temperature
  stored in the temperature field is at or above the boiling point of water. 
  Otherwise, the function should return false.

Write a problem that demonstrates the class. The program should ask the user to enter
a temperature, then display a list of the substances that will freeze at that temperature,
and those that will boil at that temperature. For example, if the temperature is -20
the class should report that water will freeze and oxygen will boil at that temperature.
*/

#include <iostream>

#include "Boiler.h"

using std::cout;
using std::cin;

void ShowTable(const Boiler& boiler);

int main()
{
	cout << "Enter temperature: ";
	double temperature;
	cin >> temperature;

	Boiler boiler{ temperature };

	ShowTable(boiler);

	return 0;
}

void ShowTable(const Boiler& boiler)
{
	if (boiler.IsEthylFreezing())
		cout << "Ethyl freezing.\n";
	else if (boiler.IsEthylBoiling())
		cout << "Ethyl boiling.\n";

	if (boiler.IsOxygenFreezing())
		cout << "Oxygen freezing.\n";
	else if (boiler.IsOxygenBoiling())
		cout << "Oxygen boiling.\n";

	if (boiler.IsWaterFreezing())
		cout << "Water freezing.\n";
	else if (boiler.IsWaterBoiling())
		cout << "Water boiling.\n";
}