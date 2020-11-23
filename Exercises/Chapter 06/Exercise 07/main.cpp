/*
7. Celsius Temperature Table
The formula for converting a temperature from Fahrenheit to Celsius is

C = (5 / 9) * (F - 32)

where F is the Fahrenheit temperature and C is the Celsius temperature. Write a function
named celsius that accepts a Fahrenheit temperatute as an argument. The function should
return the temperature, converted to Celsius. Demonstrate the function by
calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
and their Celsius equivalents.
*/

#include <iostream>

double celsius(double F);

int main()
{
	using namespace std;

	for (double F = 0.0; F <= 20.0; F++)
	{
		double C = celsius(F);
		cout << F << "F = " << C << "C\n";
	}

	return 0;
}

double celsius(double F)
{
	double C = (5.0 / 9.0) * (F - 32.0);
	return C;
}