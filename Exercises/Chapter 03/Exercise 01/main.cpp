/*
1. Miles per Gallon
Write a program that calculates a car's gas mileage. The program should ask the user
to enter the number of gallons of gas the car can hold, and the number of miles it
can be driven on a full tank. lt should then display the number of miles that may be
driven per gallon of gas.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a number of gallons of gas the car can hold: ";
	double gasGallons;
	cin >> gasGallons;

	cout << "Enter a number of miles per gallon: ";
	double miles;
	cin >> miles;

	double mileage = gasGallons * miles;
	cout << "Number of miles that may be driven per gallon of gas = " << mileage << endl;

	return 0;
}