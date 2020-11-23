/*
12. Land Calculation
One acre of land is equivalent to 43,560 square feet. Write a program that calculates
the number of acres in a tract of land with 391,876 square feet.
*/

#include <iostream>

int main()
{
	using namespace std;

	double feetValue = 391'876;
	const double SQUARE_FEET_IN_ACRE = 43'560;

	double acresValue = feetValue / SQUARE_FEET_IN_ACRE;

	cout << "Value (feet) = " << feetValue << endl;
	cout << "Value (acres) = " << acresValue << endl;
	
	return 0;
}