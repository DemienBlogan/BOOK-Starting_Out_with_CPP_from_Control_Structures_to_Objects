/*
12. Software Sales
A software company sells a package that retails for $99. Quantity discounts are given
according to the following table.
-------------------------
Quantity         Discount
-------------------------
10-19            20%
20-49            30%
50-99            40%
100 or more      50%
-------------------------
Write a program that asks for the number of units sold and computes the total cost of
the purchase.
Input Validation: Make sure the number of units is greater than 0.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the number of units sold: ";
	int numberOfUnits;
	cin >> numberOfUnits;

	if (numberOfUnits <= 0)
	{
		cout << "Incorrect number of units. Try again.\n";
		return 0;
	}
	
	double discountPercent;

	if (numberOfUnits >= 10 && numberOfUnits <= 19)
		discountPercent = 0.2; // 20%
	else if (numberOfUnits >= 20 && numberOfUnits <= 49)
		discountPercent = 0.3; // 30%
	else if (numberOfUnits >= 50 && numberOfUnits <= 99)
		discountPercent = 0.4; // 40%
	else
		discountPercent = 0.5; // 50%

	const double PACKAGE_PRICE = 99.00; // $
	double costWithoutDiscount = PACKAGE_PRICE * numberOfUnits;
	double discount = costWithoutDiscount * discountPercent;
	double totalCost = costWithoutDiscount - discount;

	cout << fixed << setprecision(2);
	cout << "Total Cost (Without discount): $" << costWithoutDiscount << endl;
	cout << "Discount: $" << discount << " (" << discountPercent * 100 << "%)\n";
	cout << "Total Cost (with discount): $" << totalCost << endl;

	return 0;
}