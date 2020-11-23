/*
4. Areas of Rectangles
The area of a rectangle is the rectangle's length times its width. Write a program that
asks for the length and width of two rectangles. he program should tell the user which
rectangle has the greater area, or if the areas are the same.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the length and the width of the first rectangle: ";
	int length1, width1;
	cin >> length1 >> width1;

	cout << "Enter the length and the width of the second rectangle: ";
	int length2, width2;
	cin >> length2 >> width2;

	int area1 = length1 * width1;
	int area2 = length2 * width2;

	cout << "Recnagle #1 area: " << area1 << endl;
	cout << "Recnagle #2 area: " << area2 << "\n\n";

	if (area1 > area2)
		cout << "First rectangle has the greater area.\n";
	else if (area1 < area2)
		cout << "Second rectangle has the greater area.\n";
	else
		cout << "Rectangles have the same area.\n";

	return 0;
}