/*
11. FeeteInches Class Copy Constructor and multiply Function
Add a copy constructor to the FeetInches class. This constructor should accept a
FeetInches object as an argument. The constructor should assign to the feet attribute
the value in the argument's feet attribute, and assign to the inches attribute the
value in the argument's inches attribute. As a result, the new object will be a copy of
the argument object.

Next, add a multiply member function to the FeetInches class. The multiply
function should accept a FeetInches object as an argument. The argument object's
feet and inches attributes will be multiplied by the calling object's feet and inches
attributes, and a FeetInches object containing the result will be returned.
*/

#include <iostream>
#include "FeetInches.h"

using std::cout;

int main()
{
	FeetInches first{ 3, 9 };
	FeetInches second{ first };
	FeetInches product{ first * second };

	cout << product;

	return 0;
}