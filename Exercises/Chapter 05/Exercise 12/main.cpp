/*
12. Celsius to Fahrenheit Table
In Programming Challenge 12 of Chapter 3, you were asked to write a program that
converts a Celsius temperature to Fahrenheit. Modify that program so that it uses a loop
to display a table of the Celsius temperatures 0 - 20, and the Fahrenheit equivalents.
*/

#include <iostream>

int main()
{
	using namespace std;

	for (double celsius = 0; celsius <= 20; celsius++)
	{
		double fahrenheit = (9.0 / 5.0) * celsius + 32.0;
		cout << celsius << "C = " << fahrenheit << "F \n";
	}

	return 0;
}