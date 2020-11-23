/*
8. Circle Class
Write a Circle class that has the following member variables:
- radius - a double
- pi - a double initialized with the value 3.14159
The class should have the following member functions:
- Default Constructor - a default constructor that sets radius to 0.0
- Constructor - accepts the radius of the circle as an argument
- setRadius - a mutator function for the radius variable
- getRadius - an accessor function for the radius variable
- getArea - returns the area of the circle, which is calculated as
  area = pi * radius * radius
- getDiameter - returns the diameter of the circle, which is calculated as
  diameter = radius * 2
- getCircumference - returns the circumference of the circle, which is calculated as
  circumference = 2 * pi * radius

Write a program that demonstrates the Circle class by asking the user for the circle's
radius, creating a Circle object, then reporting the circle's area, diameter, and
circumference.
*/

#include <iostream>

#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Enter radius: ";
	double radius;
	cin >> radius;

	Circle circle{ radius };

	cout << "Radius: " << circle.GetRadius() << endl;
	cout << "Area: " << circle.GetArea() << endl;
	cout << "Diameter: " << circle.GetDiameter() << endl;
	cout << "Circumference: " << circle.GetCircumference() << endl;

	return 0;
}