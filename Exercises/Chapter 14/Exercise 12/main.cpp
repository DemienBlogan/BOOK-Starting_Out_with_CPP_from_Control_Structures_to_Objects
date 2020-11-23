/*
12. LandTract Class
Make a LandTract class that is composed of two FeetInches objects: one for the
tract's length, and one for the width. The class should have a member function that
returns that tract's area. Demonstrate the class in a program that asks the user to enter
the dimensions for two tracts of land. The program should display the area of each
tract of land, and indicate whether the tracts are of equal size.
*/

#include <iostream>
#include "LandTract.h"
#include "FeetInches.h"

using std::cout;
using std::endl;

int main()
{
	FeetInches length{ 11, 3 }, width{ 12, 5 };
	LandTract land1{ length, width }, land2{ length, width };

	cout << "Area of first land: " << land1.GetArea() << endl;
	cout << "Area of second land: " << land2.GetArea() << endl;

	if (land1 == land2)
		cout << "Lands' areas are equal.\n";

	return 0;
}