/*
12. Celsius to Fahrenheit
Write a program tbat converts Celsius temperatures to Fahrenheit temperatures. The
formula is:
F = (9 / 5) * C + 32

F is the Fahrenheit temperature, and C is the Celsius temperature.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter temperature (celsius): ";
	double celsius;
	cin >> celsius;

	double fahrenheit = (9.0 / 5.0) * celsius + 32.0;

	cout << celsius << "C = " << fahrenheit << "F \n";

	return 0;
}