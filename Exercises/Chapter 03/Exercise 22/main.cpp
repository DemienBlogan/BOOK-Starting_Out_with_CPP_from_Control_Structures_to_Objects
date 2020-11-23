/*
22. Angle Calculator
Write a program that asks the user for an angle, entered in radians. The program
should then display the sine, cosine, and tangent of the angle. (Use the sin, cos, and
tan library functions to determine these values). The output should be displayed in
fixed-point notation, rounded to four decimal places of precision.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;

	cout << "Enter angle in radians: ";
	double angle; 
	cin >> angle;

	double sinusValue = sin(angle);
	double cosinusValue = cos(angle);
	double tangensValue = tan(angle);

	cout << fixed << setprecision(4);
	cout << "Sin = " << sinusValue << endl;
	cout << "Cos = " << cosinusValue << endl;
	cout << "Tan = " << tangensValue << endl;

	return 0;
}