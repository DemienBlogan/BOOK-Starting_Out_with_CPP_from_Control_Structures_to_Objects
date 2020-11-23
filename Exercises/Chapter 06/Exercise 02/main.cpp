/*
2. Rectangle Area - Complete the Program
If you have downloaded this book's source code, you will find a partially written program
named AreaRectangle.cpp in the Chapter 06 folder. Your job is to complete the
program. When it is complete, the program will ask the user to enter the width and
length of a rectangle, then display the rectangle's area. The program calls the following
functions, which have not been written:

- getLength - This function should ask the user to enter the rectangle's length then
  return that value as a double
- getWidth - This function should ask the user to enter the rectangle's width then
  return that value as a double
- getArea - This function should accept the rectangle's length and width as arguments
  and return the rectangle's area. The area is calculated by multiplying the
  length by the width.
- display Data - This function should accept the rectangle's length, width, and area
  as arguments and display them in an approptiate message on the screen.
*/

#include <iostream>

double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double area, double length, double width);

int main()
{
	double length = getLength();
	double width = getWidth();
	double area = getArea(length, width);
	displayData(area, length, width);

	return 0;
}

double getLength()
{
	using namespace std;

	cout << "Enter the length of the rectangle: ";
	double length;
	cin >> length;

	return length;
}

double getWidth()
{
	using namespace std;

	cout << "Enter the width of the rectangle: ";
	double width;
	cin >> width;

	return width;
}

double getArea(double length, double width)
{
	double area = length * width;
	return area;
}

void displayData(double area, double length, double width)
{
	using namespace std;

	cout << "Length = " << length << endl;
	cout << "Width = " << width << endl;
	cout << "Area = " << area << endl;
}