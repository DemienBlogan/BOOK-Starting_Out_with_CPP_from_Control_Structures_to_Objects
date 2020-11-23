/*
24. Planting Grapevines
A vineyard owner is planting several new rows of grapevines, and needs to know how
many grapevines to plant in each row. She has determined that after measuring the
length of a future row, she can use the following formula to calculate the number of
vines that will fit in the row, along with rhe trellis end-post assemblies that will need
to be constructed at each end of the row:

V = (R - 2 * E) / S

The terms in the formula are:
V is the number of grapevines that will fit in rhe row.
R is the length of the row, in feet.
E is the amount of space, in feet, used by an end-post assembly.
S is the space between vines, in feet.

Write a program that makes the calculation for the vineyard owner. The program
should ask the user to input the following:
- The length of the row, in feet
- The amount of space used by an end-post assembly, in feet
- The amount of space between che vines, in feet

Once the input data has been entered, the program should calculate and display the
number of grapevines that will fit in the row.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the length of the row, in feet: ";
	double lengthRow;
	cin >> lengthRow;

	cout << "Enter the amount of space used by an end-post assembly, in feet: ";
	double endpostSpace;
	cin >> endpostSpace;

	cout << "Enter the amount of space between the vines, in feet: ";
	double spaceBetweenVines;
	cin >> spaceBetweenVines;

	double numberGrapevines = (lengthRow - 2 * endpostSpace) / spaceBetweenVines;

	cout << "The number of grapevines that will fit in the row: " << numberGrapevines << endl;

	return 0;
}