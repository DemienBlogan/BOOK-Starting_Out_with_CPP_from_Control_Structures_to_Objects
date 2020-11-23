/*
20. How Much Paint
A particular brand of paint covers 340 square feet per gallon. Write a program to
determine and report approximately how many gallons of paint will be needed to paint
two coats on a wooden fence that is 6 feet high and 100 feet long.
*/

#include <iostream>

int main()
{
	using namespace std;

	const double SQUARE_FEET_PER_GALLON = 340;
	int countOfCoats = 2;
	double coatHight = 6, coatLength = 100;
	double coatArea = coatHight * coatLength;
	double totalArea = coatArea * countOfCoats;
	double gallonsNeeded = totalArea / SQUARE_FEET_PER_GALLON;

	cout << "Square feet per gallon that a particular brand of paint covers = ";
	cout << SQUARE_FEET_PER_GALLON << endl;
	cout << "Count of coats = " << countOfCoats << endl;
	cout << "Coat sizes: Height = " << coatHight << " feet, Length = " << coatLength << " feet \n";
	cout << "Coat area = " << coatArea << " feet \n";
	cout << "Total area of " << countOfCoats << " coat(s) = " << totalArea << endl;
	cout << "You need " << gallonsNeeded << " gallon(s) to paint this area \n";

	return 0;
}