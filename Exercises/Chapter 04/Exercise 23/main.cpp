/*
23. Geometry Calculator
Write a program that displays the following menu:

Geometry Calculator
	1. Calculate the Area of a Circle
	2. Calculate the Area of a Rectangle
	3. Calculate the Area of a Triangle
	4. Quit
	Enter your choice (1 - 4):

If the user enters 1, the program should ask for the radius of the circle then display its
area. Use the following formula:

area = PI * r^2

Use 3.14159 for PI and the radius of the circle for r. If the user enters 2, the program
should ask for the length and width of the rectangle, then display the rectangle's area.
Use the following formula:

area = length * width

If the user enters 3, the program should ask for the length of the triangle's base and its
height, then display its area. Use the following formula:

area = base * height * 0.05

If the user enters 4, the program should end.

Input Validation: Display an error message if the user enters a numbe routside the range
of 1 through 4 when selectiong an item from the menu. Do not accept negative values
for the circle's radius, the rectangle's length or width, or the triangle's base of height.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Geometry Calculator                   \n\n";
	cout << "\t 1. Calculate the Area of a Circle    \n";
	cout << "\t 2. Calculate the Area of a Rectangle \n";
	cout << "\t 3. Calculate the Area of a Triangle  \n";
	cout << "\t 4. Quit                            \n\n";
	cout << "\t Enter your choice (1-4): ";
	char choice;
	cin >> choice;

	const double PI = 3.141519;
	double area;
	double radius;        // Circle
	double length, width; // Rectangle
	double base, height;  // Triangle

	switch (choice)
	{
	case '1':
		cout << "Enter the radius: ";
		cin >> radius;

		if (radius <= 0)
		{
			cout << "Incorrect radius.\n";
			return 0;
		}

		area = PI * radius * radius;
		cout << "Area = " << area << endl;
		break;

	case '2':
		cout << "Enter the length: ";
		cin >> length;
		cout << "Enter the width: ";
		cin >> width;

		if (length <= 0 || width <= 0)
		{
			cout << "Incorrect length or width.\n";
			return 0;
		}

		area = length * width;
		cout << "Area = " << area << endl;
		break;

	case '3':
		cout << "Enter the base: ";
		cin >> base;
		cout << "Enter the height: ";
		cin >> height;

		if (base <= 0 || height <= 0)
		{
			cout << "Incorrect base or height.\n";
			return 0;
		}

		area = base * height * 0.5;
		cout << "Area = " << area << endl;
		break;

	case '4':
		cout << "Goodbye!\n";
		break;

	default:
		cout << "Incorrect choice.\n";
		break;
	}

	return 0;
}