/*
13. Circuit Board Price
An electronics company sells circuit boards at a 35 percent profit. Write a program that
will calculate the selling price of a circuit board that costs $14.95. Display the result
on the screen.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double circuitBoardCost = 14.95; // $
	double profitPercent = 0.35;     // 35%
	double sellingPrice = circuitBoardCost - (circuitBoardCost * profitPercent);

	cout << fixed << setprecision(2);
	cout << "Circuit board cost = $" << circuitBoardCost << endl;
	cout << "Selling Price = $" << sellingPrice << endl;

	return 0;
}