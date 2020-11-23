/*
20. Pizza Pi
Joe's Pizza Palace needs a program to calculate the number of slices a pizza of any size
can be divided into. The program should perform the following steps:
A) Ask the user for the diameter of the pizza in inches.
B) Calculate the number of slices that may be taken from a pizza of that size.
A) Display a message telling rhe number of slices.
To calculate the number of slices that may be taken from the pizza, you must know
the following facts:
- Each slice should have an area of 14.125 inches.
- To calculate the number of slices, simply divide the area of the pizza by 14.125.
- The area of the pizza is calculated with chis formula:

Area = PI * R ^ 2

NOTE: PI is the Greek letter pi. 3.14159 can be used as its value. The variable R is the
radius of the pizza. Divide the diameter by 2 to get the radius.

Make sure the output of the program displays the number of slices in fixed-point notation,
rounded to one decimal place of precision. Use a named constant for pi.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the diameter of the pizza in inches: ";
	double diameterPizza;
	cin >> diameterPizza;

	const double AREA_OF_1_SLICE = 14.125; // inches
	double radiusPizza = diameterPizza / 2;
	const double PI = 3.14159;
	double areaPizza = PI * radiusPizza * radiusPizza;
	double piecesPizza = areaPizza / AREA_OF_1_SLICE;

	cout << fixed << setprecision(1);
	cout << "With this diameter I can slice the pizza by " << piecesPizza << " pieces.\n";

	return 0;
}