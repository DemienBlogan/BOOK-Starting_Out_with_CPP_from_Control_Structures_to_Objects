/*
13. Carptet Calculator
The Westfield Carpet Company has asked you to write an application that calculates the
price of carpeting for rectangular rooms. To calculate the price, you multiply the area
of the floor (width times length) by the price per square foot of carpet. For example,
the area of floor that is 12 feet long and 10 feet wide is 120 square feet. To cover that
floor with carpet that costs $8 per square foot would cost $960. (12 * 10 * 8 = 960).

First, you should create a class named RoomDimension that has two FeetInches
objects as attributes: one for the length of the room, and one for the width. (You should
use the version of the FeetInches class you created in Programming Challenge 11 with
the addition of a multiply member function. You can use this function to calculate
the area of the room). The RoomDimension class should have a member function that
returns the area of the room as a FeetInches object.

Next, you should create a RoomCarpet class that has a RoomDimension object as an
attribute. It should also have an attribute for the cost of the carpet per square foot.
The RoomCarpet class should have a member function that returns the total cost of
the carpet.

Once you have written these classes, use them in an application that asks the user to
enter the dimensions of a room and the price per square foot of the desired carpeting.
The application should display the total cost of the carpet.
*/

#include <iostream>
#include "FeetInches.h""
#include "RoomDimension.h"
#include "RoomCarpet.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int feet, inches;

	cout << "Enter feet and inches for length: ";
	cin >> feet >> inches;

	FeetInches length{ feet, inches };

	cout << "Enter feet and inches for length: ";
	cin >> feet >> inches;

	FeetInches width{ feet, inches };

	RoomDimension roomDimension{ length, width };

	cout << "Enter cost of carpet per square foot: ";
	double cost;
	cin >> cost;

	RoomCarpet roomCarpet{ roomDimension, cost };

	cout << "Total cost = $" << roomCarpet.GetCost() << endl;

	return 0;
}