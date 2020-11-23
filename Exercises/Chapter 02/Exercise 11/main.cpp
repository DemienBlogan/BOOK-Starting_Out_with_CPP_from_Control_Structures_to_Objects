/*
11. Distance per Tank of Gas
A car with a 20-gallon gas tank averages 23.5 miles per gallon when driven in town,
and 28.9 miles per gallon when driven on the highway. Write a program that calculates
and displays the distance the car can travel on one rank of gas when driven in town
and when driven on the highway.

Hint: The following formula can be used co calculate the distance:
Distance = Number of Gallons * Average Miles per Gallon
*/

#include <iostream>

int main()
{
	using namespace std;

	double gasTank = 20;
	double milesPerGallonInTown = 23.5, milesPerGallonOnHighway = 28.9;

	double townDistance = gasTank * milesPerGallonInTown;
	double highwayDistance = gasTank * milesPerGallonOnHighway;

	cout << "Gas tank = " << gasTank << " gallons\n";
	cout << "MPG (town)    = " << milesPerGallonInTown << " gallons\n";
	cout << "MPG (highway) = " << milesPerGallonOnHighway << " gallons\n";
	cout << "Max distance (town) = " << townDistance << " miles\n";
	cout << "Max distance (highway) = " << highwayDistance << " miles\n";

	return 0;
}