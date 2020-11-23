/*
6. Mass and Weight
Scientists measure an object's mass in kilograms and its weight in newtons. If you know
the amoung of mass that an object has, you can calculate its weight, in newtons, with
the following formula:

Weight = mass * 9.8

Write a program that asks the user to enter an object's mass, then calculates and displays
its weight. If the object weighs more than 1,000 newtons, display a message
idicating that it is too heavy. If the object weighs less than 10 newtons, display a
message idicating that the object is too light.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the mass of the object (kg): ";
	double mass;
	cin >> mass;

	const double g = 9.8;
	double weight = mass * g;

	if (weight > 1000)
		cout << "The object is too heavy.\n";
	else if (weight < 10)
		cout << "The object is too light.\n";
	else
		cout << "The object has normal weight.\n";

	return 0;
}